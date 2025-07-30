import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from std_srvs.srv import Empty
from cv_bridge import CvBridge
import cv2
import numpy as np
import time
import math
import threading
import queue

class RectangleDetector(Node):
    class PIDController:
        def __init__(self, target_speed):
            self.target_speed = target_speed  # Fixed speed factor (degrees/second)
            self.max_output = 5.0  # Maximum angular velocity (degrees/second)

        def compute(self, direction_vector):
            """
            Compute angular velocity based on normalized direction vector and fixed speed.
            direction_vector: [dx, dy] in pixels
            Returns: [yaw_rate, pitch_rate] in degrees/second
            """
            # Normalize the direction vector
            norm = np.linalg.norm(direction_vector)
            if norm < 1e-6:  # Avoid division by zero
                return 0.0, 0.0
            
            normalized_vector = direction_vector / norm
            # Scale by target speed and clamp to max output
            output = normalized_vector * self.target_speed
            yaw_rate = max(min(output[0], self.max_output), -self.max_output)
            pitch_rate = max(min(output[1], self.max_output), -self.max_output)
            return yaw_rate, pitch_rate

    def __init__(self):
        super().__init__('rectangle_detector')
        self.subscription = self.create_subscription(
            Image,
            '/color',
            self.image_callback,
            100)
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
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

        # 创建HSV调节窗口和滑动条
        cv2.namedWindow('HSV Adjust')
        self.create_hsv_trackbars()
        cv2.moveWindow('HSV Adjust', 50, 50)

        # 初始化卡尔曼滤波器
        self.kalman_laser = self.init_kalman_laser()
        self.kalman_outer_vertices = [self.init_kalman_vertices() for _ in range(4)]
        self.kalman_inner_vertices = [self.init_kalman_vertices() for _ in range(4)]
        self.laser_initialized = False
        self.outer_initialized = False
        self.inner_initialized = False
        self.filtered_laser_point = None
        self.laser_alpha = 0.1
        self.detection_failure_count = 0
        self.max_failure_count = 6

        # PID控制器，使用固定速度因子
        self.pid_controller = self.PIDController(target_speed=3.0)  # 目标速度 5 度/秒，可根据需要调整
        self.last_time = time.time()

        # 物理参数
        self.vertex_threshold = 10  # 像素单位的到达阈值
        self.min_path_points = 5
        self.max_path_points = 10
        self.current_path_points = []
        self.current_path_index = 0
        self.middle_corners = []

        # 巡线状态
        self.tracking_active = False
        self.lap_completed = False
        self.start_vertex_index = 0
        self.target_vertex_index = 0
        self.path_direction = 1
        self.initial_move = False
        self.waiting_at_vertex = False
        self.wait_start_time = 0.0
        self.moving_to_target = False
        self.last_target_point = None

        # 图像处理线程相关
        self.image_queue = queue.Queue(maxsize=1)
        self.result_queue = queue.Queue(maxsize=1)
        self.shutdown_event = threading.Event()
        self.image_processing_thread = threading.Thread(target=self.image_processing_loop)
        self.image_processing_thread.daemon = True
        self.image_processing_thread.start()

    def init_kalman_vertices(self):
        kalman = cv2.KalmanFilter(4, 2)
        kalman.measurementMatrix = np.array([[1, 0, 0, 0],
                                            [0, 1, 0, 0]], np.float32)
        kalman.transitionMatrix = np.array([[1, 0, 1, 0],
                                           [0, 1, 0, 1],
                                           [0, 0, 1, 0],
                                           [0, 0, 0, 1]], np.float32)
        kalman.processNoiseCov = np.array([[1, 0, 0, 0],
                                          [0, 1, 0, 0],
                                          [0, 0, 1, 0],
                                          [0, 0, 0, 1]], np.float32) * 0.005
        kalman.measurementNoiseCov = np.array([[1, 0],
                                              [0, 1]], np.float32) * 1
        return kalman

    def init_kalman_laser(self):
        kalman = cv2.KalmanFilter(4, 2)
        kalman.measurementMatrix = np.array([
            [1, 0, 0, 0],
            [0, 1, 0, 0]
        ], np.float32)

        kalman.transitionMatrix = np.array([
            [1, 0, 1, 0],
            [0, 1, 0, 1],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ], np.float32)

        kalman.processNoiseCov = np.array([
            [1, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ], np.float32) * 0.1

        kalman.measurementNoiseCov = np.array([
            [1, 0],
            [0, 1]
        ], np.float32) * 5

        kalman.errorCovPost = np.eye(4, dtype=np.float32) * 1
        return kalman
    
    def create_hsv_trackbars(self):
        cv2.createTrackbar('LowH1', 'HSV Adjust', 0, 180, lambda x: x)
        cv2.createTrackbar('HighH1', 'HSV Adjust', 10, 180, lambda x: x)
        cv2.createTrackbar('LowH2', 'HSV Adjust', 156, 180, lambda x: x)
        cv2.createTrackbar('HighH2', 'HSV Adjust', 180, 180, lambda x: x)
        cv2.createTrackbar('LowS', 'HSV Adjust', 20, 255, lambda x: x)
        cv2.createTrackbar('HighS', 'HSV Adjust', 255, 255, lambda x: x)
        cv2.createTrackbar('LowV', 'HSV Adjust', 26, 255, lambda x: x)
        cv2.createTrackbar('HighV', 'HSV Adjust', 255, 255, lambda x: x)

    def generate_path_points(self, start_vertex, end_vertex):
        """使用Bresenham算法生成路径点"""
        x0, y0 = int(start_vertex[0]), int(start_vertex[1])
        x1, y1 = int(end_vertex[0]), int(end_vertex[1])
        points = []

        dx = abs(x1 - x0)
        dy = abs(y1 - y0)
        sx = 1 if x0 < x1 else -1
        sy = 1 if y0 < y1 else -1
        err = dx - dy

        while True:
            points.append((x0, y0))
            if x0 == x1 and y0 == y1:
                break
            e2 = 2 * err
            if e2 > -dy:
                err -= dy
                x0 += sx
            if e2 < dx:
                err += dx
                y0 += sy

        if len(points) > self.max_path_points:
            step = len(points) / self.max_path_points
            points = [points[int(i * step)] for i in range(self.max_path_points)]
        elif len(points) < self.min_path_points:
            points = [points[int(i * len(points) / self.min_path_points)] 
                     for i in range(self.min_path_points)]
        
        return points

    def sort_vertices_by_centroid(self, vertices, centroid):
        angles = np.arctan2(vertices[:, 1] - centroid[1], vertices[:, 0] - centroid[0])
        sorted_indices = np.argsort(angles)
        return vertices[sorted_indices]

    def stop_execute_callback(self, request, response):
        self.tracking_active = False
        self.initial_move = False
        self.waiting_at_vertex = False
        self.moving_to_target = False
        self.current_path_points = []
        self.current_path_index = 0
        self.detection_failure_count = 0
        return response
    
    def reset_execute_callback(self, request, response):
        self.get_logger().info('接收到重置请求，启动巡线')
        self.tracking_active = True
        self.initial_move = True
        self.lap_completed = False
        self.target_vertex_index = 0
        self.start_vertex_index = 0
        self.waiting_at_vertex = False
        self.wait_start_time = 0.0
        self.moving_to_target = False
        self.current_path_points = []
        self.current_path_index = 0
        self.detection_failure_count = 0
        return response

    def image_processing_loop(self):
        while not self.shutdown_event.is_set():
            try:
                image_msg = self.image_queue.get(timeout=1.0)
                image = self.bridge.imgmsg_to_cv2(image_msg, desired_encoding='bgr8')
                height, width, _ = image.shape
                center_y, center_x = height // 2 - 100, width // 2 - 100
                half_size = 400
                start_y = max(center_y - half_size, 0)
                start_x = max(center_x - half_size, 0)
                end_y = min(center_y + half_size, height)
                end_x = min(center_x + half_size, width)
                image = image[start_y:end_y, start_x:end_x]
                gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
                _, thresh = cv2.threshold(gray, 120, 255, cv2.THRESH_BINARY)
                kernel = np.ones((4, 4), np.uint8)
                edges = cv2.Canny(thresh, 50, 100)
                edges = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)
                contours, hierarchy = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

                outer_contour = None
                inner_contour = None
                filtered_outer_contour = None
                filtered_inner_contour = None

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

                self.middle_corners = []
                if outer_contour is not None and inner_contour is not None:
                    if len(outer_contour) == 4 and len(inner_contour) == 4:
                        outer_M = cv2.moments(outer_contour)
                        inner_M = cv2.moments(inner_contour)
                        if outer_M["m00"] > 0 and inner_M["m00"] > 0:
                            outer_cx = outer_M["m10"] / outer_M["m00"]
                            outer_cy = outer_M["m01"] / outer_M["m00"]
                            inner_cx = inner_M["m10"] / inner_M["m00"]
                            inner_cy = inner_M["m01"] / inner_M["m00"]

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

                low_h1 = cv2.getTrackbarPos('LowH1', 'HSV Adjust')
                high_h1 = cv2.getTrackbarPos('HighH1', 'HSV Adjust')
                low_h2 = cv2.getTrackbarPos('LowH2', 'HSV Adjust')
                high_h2 = cv2.getTrackbarPos('HighH2', 'HSV Adjust')
                low_s = cv2.getTrackbarPos('LowS', 'HSV Adjust')
                high_s = cv2.getTrackbarPos('HighS', 'HSV Adjust')
                low_v = cv2.getTrackbarPos('LowV', 'HSV Adjust')
                high_v = cv2.getTrackbarPos('HighV', 'HSV Adjust')

                hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
                lower_red1 = np.array([low_h1, low_s, low_v])
                upper_red1 = np.array([high_h1, high_s, high_v])
                lower_red2 = np.array([low_h2, low_s, low_v])
                upper_red2 = np.array([high_h2, high_s, high_v])

                mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
                mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
                red_mask = mask1 | mask2

                kernel = np.ones((5, 5), np.uint8)
                red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_OPEN, kernel)
                blurred = cv2.GaussianBlur(red_mask, (5, 5), 0)
                red_contours, _ = cv2.findContours(blurred, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

                laser_point = None
                best_contour = None
                if red_contours:
                    for cnt in red_contours:
                        area = cv2.contourArea(cnt)
                        perimeter = cv2.arcLength(cnt, True)
                        if area > 50 and perimeter > 10:
                            best_contour = cnt
                            break

                if best_contour is not None:
                    M = cv2.moments(best_contour)
                    if M['m00'] != 0:
                        cx = M['m10'] / M['m00']
                        cy = M['m01'] / M['m00']

                        if self.filtered_laser_point is None:
                            self.filtered_laser_point = (cx, cy)
                        else:
                            prev_x, prev_y = self.filtered_laser_point
                            filtered_x = self.laser_alpha * cx + (1 - self.laser_alpha) * prev_x
                            filtered_y = self.laser_alpha * cy + (1 - self.laser_alpha) * prev_y
                            self.filtered_laser_point = (filtered_x, filtered_y)

                        measurement = np.array([[np.float32(self.filtered_laser_point[0])],
                                              [np.float32(self.filtered_laser_point[1])]])
                        if not self.laser_initialized:
                            self.kalman_laser.statePre = np.array([[self.filtered_laser_point[0]],
                                                                  [self.filtered_laser_point[1]],
                                                                  [0], [0]], np.float32)
                            self.laser_initialized = True
                        self.kalman_laser.correct(measurement)
                        self.detection_failure_count = 0
                        prediction = self.kalman_laser.predict()
                        laser_point = (int(prediction[0]), int(prediction[1]))
                        cv2.circle(image, laser_point, 5, (255, 0, 0), -1)
                        cv2.putText(image, f'Laser: ({laser_point[0]}, {laser_point[1]})',
                                    (laser_point[0] + 10, laser_point[1] - 10),
                                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
                else:
                    self.detection_failure_count += 1
                    if self.laser_initialized and self.detection_failure_count <= self.max_failure_count:
                        prediction = self.kalman_laser.predict()
                        laser_point = (int(prediction[0]), int(prediction[1]))
                        cv2.circle(image, laser_point, 5, (255, 0, 0), -1)
                        cv2.putText(image, f'Predicted Laser: ({laser_point[0]}, {laser_point[1]})',
                                    (laser_point[0] + 10, laser_point[1] - 10),
                                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
                    else:
                        laser_point = None
                        self.get_logger().warn('激光点检测连续失败，停止跟踪')

                result = {
                    'laser_point': laser_point,
                    'image': image,
                    'blurred': blurred,
                    'edges': edges,
                    'filtered_outer_contour': filtered_outer_contour,
                    'filtered_inner_contour': filtered_inner_contour
                }
                try:
                    self.result_queue.put_nowait(result)
                except queue.Full:
                    pass

            except queue.Empty:
                continue
            except Exception as e:
                self.get_logger().error(f'图像处理线程出错: {str(e)}')

    def image_callback(self, msg):
        try:
            self.image_queue.put_nowait(msg)
        except queue.Full:
            pass

        try:
            result = self.result_queue.get_nowait()
            laser_point = result['laser_point']
            image = result['image']
            blurred = result['blurred']
            edges = result['edges']
            filtered_outer_contour = result['filtered_outer_contour']
            filtered_inner_contour = result['filtered_inner_contour']

            yaw_rate = 0.0
            pitch_rate = 0.0
            if self.tracking_active and self.middle_corners and laser_point is not None:
                mid_vertices = np.array(self.middle_corners, dtype=np.float32)
                num_vertices = len(mid_vertices)

                # 选择目标点
                if self.initial_move:
                    target_point = mid_vertices[self.target_vertex_index]
                else:
                    current_vertex = mid_vertices[self.target_vertex_index]
                    next_vertex_index = (self.target_vertex_index + self.path_direction) % num_vertices
                    next_vertex = mid_vertices[next_vertex_index]

                    if not self.current_path_points:
                        self.current_path_points = self.generate_path_points(current_vertex, next_vertex)
                        self.current_path_index = 0
                        self.get_logger().info(f'生成新路径点，数量：{len(self.current_path_points)}')
                    elif self.current_path_index >= len(self.current_path_points):
                        if not self.waiting_at_vertex:
                            self.waiting_at_vertex = True
                            self.wait_start_time = time.time()
                            self.get_logger().info('到达角点，开始等待')
                        elif time.time() - self.wait_start_time > 0.0:
                            self.target_vertex_index = next_vertex_index
                            self.waiting_at_vertex = False
                            self.current_path_points = []
                            self.current_path_index = 0
                            self.get_logger().info(f'切换到下一个角点：{self.target_vertex_index}')
                            if self.target_vertex_index == self.start_vertex_index and not self.lap_completed:
                                self.lap_completed = True
                                self.get_logger().info('完成一圈巡线')
                        target_point = None

                    if not self.current_path_points:
                        self.get_logger().warn('路径点为空，停止巡线')
                        yaw_rate = 0.0
                        pitch_rate = 0.0
                        target_point = None
                    else:
                        target_point = self.current_path_points[self.current_path_index]

                if target_point is not None:
                    laser_x, laser_y = laser_point
                    target_x, target_y = target_point
                    target_vector = np.array([target_x - laser_x, target_y - laser_y])
                    target_distance_pixels = np.linalg.norm(target_vector)
                    self.get_logger().info(f'当前目标点距离：{target_distance_pixels:.2f} 像素')

                    if target_distance_pixels > self.vertex_threshold:
                        # 使用方向向量计算角速度
                        yaw_rate, pitch_rate = self.pid_controller.compute(target_vector)
                        self.moving_to_target = True
                        self.last_target_point = target_point
                        self.get_logger().info(f'控制云台 - yaw_rate: {yaw_rate:.2f} deg/s, pitch_rate: {pitch_rate:.2f} deg/s')
                    else:
                        self.get_logger().info(f'到达目标点：({target_x}, {target_y})')
                        if self.initial_move:
                            self.initial_move = False
                            self.moving_to_target = False
                            self.current_path_points = []
                            self.current_path_index = 0
                            self.get_logger().info('已到达第一个路径角点，开始正常巡线')
                        else:
                            self.current_path_index += 1
                            self.get_logger().info(f'到达路径点 {self.current_path_index - 1}')
                            if self.current_path_index >= len(self.current_path_points):
                                if not self.waiting_at_vertex:
                                    self.waiting_at_vertex = True
                                    self.wait_start_time = time.time()
                                    self.get_logger().info('到达角点，开始等待')
                                elif time.time() - self.wait_start_time > 1.0:
                                    self.target_vertex_index = next_vertex_index
                                    self.waiting_at_vertex = False
                                    self.current_path_points = []
                                    self.current_path_index = 0
                                    self.get_logger().info(f'切换到下一个角点：{self.target_vertex_index}')
                                    if self.target_vertex_index == self.start_vertex_index and not self.lap_completed:
                                        self.lap_completed = True
                                        self.get_logger().info('完成一圈巡线')
                            self.moving_to_target = False
                            self.last_target_point = None
                            yaw_rate = 0.0
                            pitch_rate = 0.0

                # 发送控制消息
                angular_msg = Twist()
                angular_msg.angular.z = yaw_rate
                angular_msg.angular.y = pitch_rate
                self.publisher.publish(angular_msg)

                if self.current_path_points:
                    for i, point in enumerate(self.current_path_points):
                        x, y = int(point[0]), int(point[1])
                        if i == self.current_path_index:
                            cv2.circle(image, (x, y), 5, (0, 0, 255), -1)
                            cv2.putText(image, f'Target ({x}, {y})', (x + 10, y - 10),
                                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1)
                        else:
                            cv2.circle(image, (x, y), 3, (0, 255, 255), -1)
                    for i in range(len(self.current_path_points) - 1):
                        start_point = (int(self.current_path_points[i][0]), int(self.current_path_points[i][1]))
                        end_point = (int(self.current_path_points[i + 1][0]), int(self.current_path_points[i + 1][1]))
                        cv2.line(image, start_point, end_point, (255, 255, 0), 1)

                if filtered_outer_contour is not None:
                    cv2.drawContours(image, [filtered_outer_contour], -1, (0, 255, 0), 2)
                if filtered_inner_contour is not None:
                    cv2.drawContours(image, [filtered_inner_contour], -1, (0, 0, 255), 2)

                resized_blurred = cv2.resize(blurred, (650, 480))
                resized_edges = cv2.resize(edges, (650, 480))
                resized_image = cv2.resize(image, (650, 480))

                cv2.imshow('Detected Rectangles and Laser', resized_image)
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