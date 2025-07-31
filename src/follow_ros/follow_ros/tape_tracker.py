import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge
from std_srvs.srv import Empty
import cv2
import numpy as np
import time

class RectangleDetector(Node):
    def __init__(self):
        super().__init__('rectangle_detector')
        self.subscription = self.create_subscription(
            Image,
            '/color',
            self.image_callback,
            1)
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

        # 矩形中心
        self.rect_center = None
        self.has_sent_final_command = False
        self.initial_move = False
        self.stable_counter = 0
        self.stable_threshold = 2

        # 初始化标志
        self.init_start_time = time.time()
        self.init_duration = 1.0

        # PID 控制器参数
        self.kp = 0.6
        self.ki = 0.0
        self.kd = 0.32
        self.prev_error_x = 0.0
        self.prev_error_y = 0.0
        self.integral_x = 0.0
        self.integral_y = 0.0
        self.max_integral = 10.0

        # 卡尔曼滤波器初始化
        self.kalman = cv2.KalmanFilter(4, 2)  # 4维状态（x, y, vx, vy），2维测量（x, y）
        self.kalman.measurementMatrix = np.array([[1, 0, 0, 0],
                                                 [0, 1, 0, 0]], np.float32)
        self.kalman.transitionMatrix = np.array([[1, 0, 1, 0],
                                                [0, 1, 0, 1],
                                                [0, 0, 1, 0],
                                                [0, 0, 0, 1]], np.float32)
        self.kalman.processNoiseCov = np.array([[1, 0, 0, 0],
                                               [0, 1, 0, 0],
                                               [0, 0, 1, 0],
                                               [0, 0, 0, 1]], np.float32) * 0.03
        self.kalman.measurementNoiseCov = np.array([[1, 0],
                                                   [0, 1]], np.float32) * 0.1
        self.kalman.statePre = np.array([[0], [0], [0], [0]], np.float32)  # 初始状态
        self.kalman.statePost = np.array([[0], [0], [0], [0]], np.float32)

    def reset_execute_callback(self, request, response):
        self.get_logger().info('接收到重置请求，启动巡线')
        cmd_vel = Twist()
        cmd_vel.angular.x = 3.0
        self.publisher.publish(cmd_vel)
        # cmd_vel = Twist()
        # cmd_vel.angular.x = 4.0
        # self.publisher.publish(cmd_vel)
        self.initial_move = True
        self.time=time.time()
        return response

    def stop_execute_callback(self, request, response):
        self.get_logger().info('接收到停止请求，停止巡线')
        self.has_sent_final_command = False
        self.initial_move = False
        return response

    def is_rectangle(self, approx, angle_tolerance=30):
        """ 判断四边形是否为矩形，通过检查每个角是否接近90度 """
        if len(approx) != 4:
            return False

        def angle(pt1, pt2, pt3):
            vec1 = pt1 - pt2
            vec2 = pt3 - pt2
            cosine_angle = np.dot(vec1, vec2) / (np.linalg.norm(vec1) * np.linalg.norm(vec2))
            angle = np.arccos(cosine_angle)
            return np.degrees(angle)

        for i in range(4):
            pt1 = approx[i][0]
            pt2 = approx[(i + 1) % 4][0]
            pt3 = approx[(i + 2) % 4][0]
            ang = angle(pt1, pt2, pt3)
            if abs(ang - 90) > angle_tolerance:
                return False
        return True

    def get_quad_center(self, quad):
        """计算四边形的对角线交点作为中心点"""
        if len(quad) != 4:
            return None

        pts = [p[0] for p in quad]

        # 取对角线：0-2 和 1-3
        def line_intersect(p1, p2, p3, p4):
            # 解线性方程组求交点
            A = np.array([
                [p2[0] - p1[0], p3[0] - p4[0]],
                [p2[1] - p1[1], p3[1] - p4[1]]
            ])
            b = np.array([p3[0] - p1[0], p3[1] - p1[1]])
            try:
                t = np.linalg.solve(A, b)
                x = p1[0] + t[0] * (p2[0] - p1[0])
                y = p1[1] + t[0] * (p2[1] - p1[1])
                return (x, y)
            except np.linalg.LinAlgError:
                return None  # 平行线，无交点

        return line_intersect(pts[0], pts[2], pts[1], pts[3])

    def pid_control(self, error_x, error_y, dt=0.1):
        alpha = 0.8
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
            if not self.initial_move:
                return

            if (time.time() - self.init_start_time) <= self.init_duration:
                self.get_logger().info('等待图像处理初始化...')
                return

            # 图像处理
            image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            _, thresh_otsu = cv2.threshold(gray, 130, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
            kernel = np.ones((4, 4), np.uint8)
            edges = cv2.Canny(thresh_otsu, 50, 100)
            edges = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)
            contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            max_contour = None
            max_area = 0
            new_center = None

            # 卡尔曼滤波预测
            self.kalman.predict()
            predicted_state = self.kalman.statePre
            self.rect_center = (predicted_state[0, 0], predicted_state[1, 0])

            if contours:
                for cnt in contours:
                    epsilon = 0.02 * cv2.arcLength(cnt, True)
                    approx = cv2.approxPolyDP(cnt, epsilon, True)
                    if len(approx) == 4:  # 确保是四边形
                        area = cv2.contourArea(cnt)
                        if area > 500 and area > max_area and self.is_rectangle(approx):
                            max_area = area
                            max_contour = approx

            if max_contour is not None:
                center = self.get_quad_center(max_contour)
                if center is not None:
                    cx, cy = center
                    new_center = (cx, cy)
                    measurement = np.array([[np.float32(cx)], [np.float32(cy)]])
                    self.kalman.correct(measurement)
                    self.rect_center = (cx, cy)
            else :
                self.rect_center =None

            # 控制逻辑
            height, width = image.shape[:2]
            image_center_x, image_center_y = 388, 142
            cmd_vel = Twist()

            if max_contour is not None:
                cv2.drawContours(image, [max_contour], -1, (0, 255, 0), 2)
                cv2.circle(image, (int(cx), int(cy)), 5, (255, 0, 0), -1) 

            if self.rect_center is not None:
                #cv2.circle(image, (int(self.rect_center[0]), int(self.rect_center[1])), 5, (0, 255, 255), -1)
                error_x = self.rect_center[0] - image_center_x
                error_y = self.rect_center[1] - image_center_y
                #self.get_logger().info(f'误差: (x={error_x:.2f}, y={error_y:.2f})')

                yaw_speed, pitch_speed = self.pid_control(error_x, error_y)
                cmd_vel.angular.x = 1.0
                cmd_vel.angular.z = float(yaw_speed)
                cmd_vel.angular.y = float(pitch_speed)

                if abs(error_x) <= 2 and abs(error_y) <= 2:
                    self.stable_counter += 1
                    if self.stable_counter >= self.stable_threshold:
                        cmd_vel.angular.x = 1.0
                        cmd_vel.angular.z = 0.0
                        cmd_vel.angular.y = 0.0
                        self.publisher.publish(cmd_vel)
                        time.sleep(0.1)
                        cmd_vel.angular.x = 2.0
                        self.publisher.publish(cmd_vel)
                        self.initial_move = False
                        self.stable_counter = 0  # 重置
                        self.time = time.time()-self.time
                        self.get_logger().info(f'完成: {self.time:.2f}')
                        return
                else:
                    self.stable_counter = 0  # 不稳定，计数重置
            # else:
            #     cmd_vel.angular.x = 1.0
            #     cmd_vel.angular.z = -100.0
            #     cmd_vel.angular.y = 0.0
            #     #self.get_logger().info('无有效矩形中心，发布零速度')

            self.publisher.publish(cmd_vel)

            # 显示图像
            resized_blurred = cv2.resize(gray, (650, 480))
            resized_edges = cv2.resize(edges, (650, 480))
            resized_image = cv2.resize(image, (640, 480))
            cv2.imshow('Detected Rectangle', resized_image)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f'图像回调处理出错: {str(e)}')

    def destroy_node(self):
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