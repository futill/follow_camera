import rclpy
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge
import cv2
import numpy as np
import math

class TapeTracker(Node):
    def __init__(self):
        super().__init__('tape_tracker')

        self.br = CvBridge()

        # 图像参数
        self.IMAGE_WIDTH = 1920
        self.IMAGE_HEIGHT = 1080
        self.HFOV = math.radians(87.2)  # 水平 FOV
        self.VFOV = math.radians(71.2)  # 垂直 FOV
        self.Z = 1.0  # 相机距离目标 1 米

        # 存储中间矩形的四个角点（像素坐标）
        self.middle_corners = []

        # 路径坐标点（偏航角和俯仰角，弧度）
        self.path_points = []

        # 当前目标路径点索引
        self.current_path_index = 0

        # 角度接近阈值（弧度）
        self.angle_threshold = 0.01  # 约 5.7°

        # 每段路径插值点数量
        self.num_interpolation_points = 10

        # 创建发布者，发布目标路径点的偏航角和俯仰角
        self.path_publisher = self.create_publisher(Point, '/target_path_point', 10)

        # 创建订阅者，监听云台位置反馈
        self.gimbal_subscription = self.create_subscription(
            Point,
            '/gimbal_pose',
            self.gimbal_callback,
            10)

        # 初始化时获取角点并保存图像
        self.initialize_corners()

        # 生成路径点（包含插值）
        self.generate_path_points()

    def pixel_to_angles(self, px, py):
        """将像素坐标转换为偏航角和俯仰角（弧度）"""
        nx = (px - self.IMAGE_WIDTH / 2) / (self.IMAGE_WIDTH / 2)
        ny = (py - self.IMAGE_HEIGHT / 2) / (self.IMAGE_HEIGHT / 2)
        yaw = nx * (self.HFOV / 2)
        pitch = ny * (self.VFOV / 2)
        return yaw, pitch

    def initialize_corners(self):
        """初始化时获取中间矩形角点并保存处理后的图像"""
        image = None
        received_image = False

        def temp_callback(msg):
            nonlocal image, received_image
            image = self.br.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            received_image = True

        # 创建临时订阅者
        self.temp_subscription = self.create_subscription(
            Image,
            '/color',
            temp_callback,
            10)

        # 使用单独的执行器处理临时订阅
        executor = SingleThreadedExecutor()
        executor.add_node(self)

        # 等待一帧图像
        timeout = 5.0
        start_time = self.get_clock().now()
        while not received_image and (self.get_clock().now() - start_time).nanoseconds / 1e9 < timeout:
            executor.spin_once(timeout_sec=0.1)

        # 销毁订阅者并清理执行器
        if hasattr(self, 'temp_subscription'):
            self.destroy_subscription(self.temp_subscription)
            del self.temp_subscription
            self.get_logger().info("临时订阅者已销毁")

        # 清理执行器
        executor.remove_node(self)
        executor.shutdown()

        if image is None:
            self.get_logger().error("无法获取图像，角点初始化失败")
            return

        # 图像处理
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(gray, 80, 255, cv2.THRESH_BINARY)
        blurred = cv2.GaussianBlur(thresh, (5, 5), 0)
        edges = cv2.Canny(blurred, 20, 80)
        contours, hierarchy = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

        outer_contour = None
        inner_contour = None

        if contours:
            for i, cnt in enumerate(contours):
                epsilon = 0.02 * cv2.arcLength(cnt, True)
                approx = cv2.approxPolyDP(cnt, epsilon, True)
                if len(approx) == 4:
                    area = cv2.contourArea(cnt)
                    if area > 100:
                        if hierarchy[0][i][3] == -1:
                            outer_contour = approx
                        elif hierarchy[0][i][3] >= 0:
                            inner_contour = approx

        # 计算中间矩形角点并绘制
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
                        self.get_logger().info(f"中间矩形角点 {i+1}: ({mid_x}, {mid_y})")

                    # 绘制外框（绿色）、内框（蓝色）和中间矩形（紫色）
                    result_image = image.copy()
                    cv2.drawContours(result_image, [outer_contour], -1, (0, 255, 0), 2)  # 绿色外框
                    cv2.drawContours(result_image, [inner_contour], -1, (255, 0, 0), 2)  # 蓝色内框
                    if self.middle_corners:
                        middle_contour = np.array(self.middle_corners, dtype=np.int32).reshape((-1, 1, 2))
                        cv2.drawContours(result_image, [middle_contour], -1, (255, 0, 255), 2)  # 紫色中间矩形
                        for i, (mx, my) in enumerate(self.middle_corners):
                            cv2.circle(result_image, (mx, my), 5, (255, 0, 255), -1)  # 紫色角点
                            cv2.putText(result_image, f"Corner {i+1}", (mx + 10, my + 10),
                                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 255), 2)

                    # 保存处理后的图像
                    save_path = '/home/orangepi/corners_result.png'
                    cv2.imwrite(save_path, result_image)
                    self.get_logger().info(f"已保存处理后的图像到 {save_path}")

                    self.get_logger().info("角点初始化完成")
                else:
                    self.get_logger().error("内外框面积为0，无法计算角点")
            else:
                self.get_logger().error("未检测到完整的内外框矩形")
        else:
            self.get_logger().error("未检测到内外框")

    def generate_path_points(self):
        """生成路径点（偏航角和俯仰角，包含插值）"""
        if not self.middle_corners:
            self.get_logger().error("没有角点数据，无法生成路径")
            return

        # 转换为偏航角和俯仰角
        corner_angles = [self.pixel_to_angles(px, py) for px, py in self.middle_corners]

        # 生成插值路径点
        self.path_points = []
        for i in range(4):
            start_yaw, start_pitch = corner_angles[i]
            end_yaw, end_pitch = corner_angles[(i + 1) % 4]
            for j in range(self.num_interpolation_points + 2):  # 包含起点和终点
                t = j / (self.num_interpolation_points + 1)
                yaw = start_yaw + t * (end_yaw - start_yaw)
                pitch = start_pitch + t * (end_pitch - start_pitch)
                self.path_points.append((yaw, pitch))

        # 添加起点形成闭合路径
        self.path_points.append(corner_angles[0])

        # 日志输出路径点
        for i, (yaw, pitch) in enumerate(self.path_points):
            self.get_logger().info(f"路径点 {i+1}: yaw={yaw:.3f}, pitch={pitch:.3f}")

        # 发布第一个目标路径点
        if self.path_points:
            point_msg = Point()
            point_msg.x = self.path_points[0][0]
            point_msg.y = self.path_points[0][1]
            point_msg.z = 0.0
            self.path_publisher.publish(point_msg)
            self.get_logger().info(f"发布初始目标路径点: yaw={point_msg.x:.3f}, pitch={point_msg.y:.3f}")

    def gimbal_callback(self, msg):
        """处理云台位置反馈，发布下一个目标路径点"""
        if not self.path_points:
            return

        current_yaw = msg.x
        current_pitch = msg.y
        target_yaw, target_pitch = self.path_points[self.current_path_index]

        # 计算角度差
        yaw_diff = abs(current_yaw - target_yaw)
        pitch_diff = abs(current_pitch - target_pitch)

        if yaw_diff < self.angle_threshold and pitch_diff < self.angle_threshold:
            # 接近当前目标点，切换到下一个
            self.current_path_index = (self.current_path_index + 1) % len(self.path_points)
            point_msg = Point()
            point_msg.x = self.path_points[self.current_path_index][0]
            point_msg.y = self.path_points[self.current_path_index][1]
            point_msg.z = 0.0
            self.path_publisher.publish(point_msg)
            self.get_logger().info(f"发布目标路径点 {self.current_path_index+1}: yaw={point_msg.x:.3f}, pitch={point_msg.y:.3f}")

def main(args=None):
    rclpy.init(args=args)
    node = TapeTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()