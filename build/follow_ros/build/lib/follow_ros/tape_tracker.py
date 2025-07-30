import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge
from std_srvs.srv import Empty
import cv2
import numpy as np
import threading
import queue
import math
import time

class RectangleDetector(Node):
    def __init__(self):
        super().__init__('rectangle_detector')
        self.subscription = self.create_subscription(
            Image,
            '/color',
            self.image_callback,
            100)
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.reset_server = self.create_service(
            Empty,
            '/reset_tape_tracker',
            self.reset_execute_callback
        )
        self.stop_server = self.create_service(
            Empty,
            '/stop_gimbal',
            self.stop_execute_callback
        )
        self.bridge = CvBridge()
        self.get_logger().info('矩形检测节点已启动')

        # 中间顶点和矩形中心
        self.middle_corners = []
        self.rect_center = None
        self.last_valid_center = None
        self.detection_lost = False
        self.lost_frame_count = 0
        self.max_lost_frames = 30
        self.initial_move = False

        # 图像处理线程相关
        self.image_queue = queue.Queue(maxsize=1)
        self.result_queue = queue.Queue(maxsize=1)
        self.shutdown_event = threading.Event()
        self.processing_enabled = threading.Event() 
        self.image_processing_thread = threading.Thread(target=self.image_processing_loop)
        self.image_processing_thread.daemon = True
        self.image_processing_thread.start()

        # 初始化标志
        self.init_start_time = time.time()
        self.init_duration = 0.5  # 5秒初始化时间

        # 卡尔曼滤波器初始化
        self.kalman = cv2.KalmanFilter(4, 2)
        self.kalman.measurementMatrix = np.array([[1, 0, 0, 0], [0, 1, 0, 0]], np.float32)
        self.kalman.transitionMatrix = np.array([[1, 0, 1, 0], [0, 1, 0, 1], [0, 0, 1, 0], [0, 0, 0, 1]], np.float32)
        self.kalman.processNoiseCov = np.eye(4, dtype=np.float32) * 0.03
        self.kalman.measurementNoiseCov = np.eye(2, dtype=np.float32) * 0.5
        self.kalman.statePre = np.array([[0], [0], [0], [0]], np.float32)

        # PID控制器参数
        self.kp = 0.03
        self.ki = 0.0
        self.kd = 0.03
        self.prev_error_x = 0.0
        self.prev_error_y = 0.0
        self.integral_x = 0.0
        self.integral_y = 0.0
        self.max_integral = 10.0

    def reset_execute_callback(self, request, response):
        self.get_logger().info('接收到重置请求，启动巡线')
        self.initial_move = True
        self.processing_enabled.set()  # 启用图像处理线程
        return response
    
    def stop_execute_callback(self, request, response):
        self.get_logger().info('接收到重置请求，启动巡线')
        self.initial_move = False
        self.processing_enabled.clear()  # 启用图像处理线程
        return response
    
    def image_processing_loop(self):
        while not self.shutdown_event.is_set():
            try:
                self.processing_enabled.clear()
                image_msg = self.image_queue.get(timeout=1.0)
                image = self.bridge.imgmsg_to_cv2(image_msg, desired_encoding='bgr8')
                gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
                _, thresh = cv2.threshold(gray, 120, 255, cv2.THRESH_BINARY)
                kernel = np.ones((4, 4), np.uint8)
                edges = cv2.Canny(thresh, 50, 100)
                edges = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)
                contours, hierarchy = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

                outer_contour = None
                inner_contour = None
                self.middle_corners = []
                new_center = None

                if contours:
                    for i, cnt in enumerate(contours):
                        epsilon = 0.02 * cv2.arcLength(cnt, True)
                        approx = cv2.approxPolyDP(cnt, epsilon, True)
                        if len(approx) == 4:
                            area = cv2.contourArea(cnt)
                            if area > 10000:
                                if hierarchy[0][i][3] == -1:
                                    outer_contour = approx
                                elif hierarchy[0][i][3] >= 0:
                                    inner_contour = approx

                if outer_contour is not None and inner_contour is not None:
                    if len(outer_contour) == 4 and len(inner_contour) == 4:
                        outer_M = cv2.moments(outer_contour)
                        inner_M = cv2.moments(inner_contour)
                        if outer_M["m00"] > 0 and inner_M["m00"] > 0:
                            outer_cx = outer_M["m10"] / outer_M["m00"]
                            outer_cy = outer_M["m01"] / outer_M["m00"]
                            inner_cx = inner_M["m10"] / inner_M["m00"]
                            inner_cy = inner_M["m01"] / inner_M["m00"]

                            new_center = ((outer_cx + inner_cx) / 2, (outer_cy + inner_cy) / 2)

                            measurement = np.array([[np.float32(new_center[0])], [np.float32(new_center[1])]])
                            self.kalman.correct(measurement)
                            self.last_valid_center = new_center
                            self.detection_lost = False
                            self.lost_frame_count = 0

                            def sort_corners(corners, center_x, center_y):
                                def get_angle(pt):
                                    x, y = pt[0][0] - center_x, pt[0][1] - center_y
                                    return math.atan2(y, x)
                                return sorted(corners, key=get_angle, reverse=True)

                            outer_corners = sort_corners(outer_contour, outer_cx, outer_cy)
                            inner_corners = sort_corners(inner_contour, inner_cx, inner_cy)

                            for i in range(4):
                                outer_point = outer_corners[i][0]
                                inner_point = inner_corners[i][0]
                                mid_x = int((outer_point[0] + inner_point[0]) / 2)
                                mid_y = int((outer_point[1] + inner_point[1]) / 2)
                                self.middle_corners.append((mid_x, mid_y))

                if new_center is None:
                    self.detection_lost = True
                    self.lost_frame_count += 1
                    if self.lost_frame_count <= self.max_lost_frames and self.last_valid_center is not None:
                        predicted = self.kalman.predict()
                        self.rect_center = (predicted[0][0], predicted[1][0])
                        self.get_logger().info(f'识别丢失，使用卡尔曼预测: ({self.rect_center[0]:.2f}, {self.rect_center[1]:.2f})')
                    else:
                        self.rect_center = None
                else:
                    predicted = self.kalman.predict()
                    self.rect_center = (predicted[0][0], predicted[1][0])

                
                result = {
                    'image': image,
                    'blurred': thresh,
                    'edges': edges,
                    'outer_contour': outer_contour,
                    'inner_contour': inner_contour
                }
                try:
                    self.result_queue.put_nowait(result)
                except queue.Full:
                    pass

            except queue.Empty:
                continue
            except Exception as e:
                self.get_logger().error(f'图像处理线程出错: {str(e)}')

    def pid_control(self, error_x, error_y, dt=0.1):
        # 平滑误差（可选：使用低通滤波）
        alpha = 0.8  # 平滑因子，值越大越平滑
        smoothed_error_x = alpha * self.prev_error_x + (1 - alpha) * error_x
        smoothed_error_y = alpha * self.prev_error_y + (1 - alpha) * error_y

        self.integral_x += smoothed_error_x * dt
        self.integral_x = max(min(self.integral_x, self.max_integral), -self.max_integral)
        derivative_x = (smoothed_error_x - self.prev_error_x) / dt
        yaw_speed = self.kp * smoothed_error_x + self.ki * self.integral_x + self.kd * derivative_x
        self.prev_error_x = smoothed_error_x

        self.integral_y += smoothed_error_y * dt
        self.integral_y = max(min(self.integral_y, self.max_integral), -self.max_integral)
        derivative_y = (smoothed_error_y - self.prev_error_y) / dt
        pitch_speed = self.kp * smoothed_error_y + self.ki * self.integral_y + self.kd * derivative_y
        self.prev_error_y = smoothed_error_y

        return yaw_speed, pitch_speed

    def image_callback(self, msg):

        try:
            self.image_queue.put_nowait(msg)
        except queue.Full:
            pass

        try:
            if self.initial_move == False:
                return
            result = self.result_queue.get_nowait()
            image = result['image']
            blurred = result['blurred']
            edges = result['edges']
            outer_contour = result['outer_contour']
            inner_contour = result['inner_contour']

            height, width = image.shape[:2]
            image_center_x, image_center_y =1050, 310

            if outer_contour is not None:
                cv2.drawContours(image, [outer_contour], -1, (0, 255, 0), 2)
            if inner_contour is not None:
                cv2.drawContours(image, [inner_contour], -1, (0, 0, 255), 2)
            for i, corner in enumerate(self.middle_corners):
                cv2.circle(image, corner, 5, (255, 0, 0), -1)
                cv2.putText(image, f'Corner {i}', (corner[0] + 10, corner[1] - 10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)

        
            cmd_vel = Twist()
            if self.rect_center is not None:
                color = (0, 255, 255) if not self.detection_lost else (255, 255, 0)
                cv2.circle(image, (int(self.rect_center[0]), int(self.rect_center[1])), 5, color, -1)
                error_x = self.rect_center[0] - image_center_x
                error_y = self.rect_center[1] - image_center_y
                # if error_x<3 and error_y<3:
                #     self.initial_move = False
                #     cmd_vel.angular.z = 0.0
                #     cmd_vel.angular.y = 0.0
                #     self.publisher.publish(cmd_vel)
                    # self.processing_enabled.clear()  # 暂停图像处理
                    # return
                self.get_logger().info(f'矩形中心: ({self.rect_center[0]:.2f}, {self.rect_center[1]:.2f}), '
                                      f'误差: (x={error_x:.2f}, y={error_y:.2f}), '
                                      f'识别状态: {"正常" if not self.detection_lost else "丢失"}')

                yaw_speed, pitch_speed = self.pid_control(error_x, error_y)
                cmd_vel.angular.z = float(yaw_speed)
                cmd_vel.angular.y = float(pitch_speed)
                self.get_logger().info(f'发布到/cmd_vel: yaw速度={yaw_speed:.2f}, pitch速度={pitch_speed:.2f}')
            else:
                cmd_vel.angular.z = 0.0
                cmd_vel.angular.y = 0.0
            self.get_logger().info('无有效矩形中心，发布零速度')
            if (time.time() - self.init_start_time) <= self.init_duration:
                self.get_logger().info('等待图像处理初始化...')
                return
            self.publisher.publish(cmd_vel)

            resized_blurred = cv2.resize(blurred, (650, 480))
            resized_edges = cv2.resize(edges, (650, 480))
            resized_image = cv2.resize(image, (640, 480))

            cv2.imshow('Detected Rectangles', resized_image)
            cv2.waitKey(1)

        except queue.Empty:
            pass
        except Exception as e:
            self.get_logger().error(f'图像回调处理出错: {str(e)}')

    def destroy_node(self):
        self.shutdown_event.set()
        self.image_processing_thread.join()
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = RectangleDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()