import rclpy
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor
from rclpy.action import ActionClient, ActionServer
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge
import cv2
import numpy as np
import math
import time
from follow_msg.action import TrackRedDot
from std_srvs.srv import Empty

class TapeTracker(Node):
    def __init__(self):
        super().__init__('tape_tracker')

        self.br = CvBridge()

        # 图像参数
        self.IMAGE_WIDTH = 1920
        self.IMAGE_HEIGHT = 1080
        self.HFOV = math.radians(87.2)
        self.VFOV = math.radians(71.2)
        self.Z = 1.0

        # 存储中间矩形的四个角点（像素坐标）
        self.middle_corners = []

        # 路径坐标点（偏航角和俯仰角，弧度）
        self.path_points = []

        # 当前目标路径点索引（仅用于日志）
        self.current_path_index = 0

        self.num_interpolation_points = 10

        # 休眠标志
        self.is_paused = False

        # 创建 TrackRedDot 动作客户端
        self.action_client = ActionClient(
            self,
            TrackRedDot,
            '/track_red_dot'
        )

        self.reset_server = self.create_service(
            Empty,
            '/reset_tape_tracker',
            self.reset_execute_callback
        )

        self.temp_subscription = self.create_subscription(
                Image,
                '/color',
                self.temp_callback,
                10)

        

        # 动作目标句柄和定时器
        self._goal_handle = None
        self._response_timer = None
        self._result_timer = None

    def temp_callback(self,msg):
        """临时订阅回调，用于获取图像"""
        self.image_msg = self.br.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        

    def pixel_to_angles(self, px, py):
        """将像素坐标转换为偏航角和俯仰角（弧度）"""
        nx = (px - self.IMAGE_WIDTH / 2) / (self.IMAGE_WIDTH / 2)
        ny = (py - self.IMAGE_HEIGHT / 2) / (self.IMAGE_HEIGHT / 2)
        yaw = nx * (self.HFOV / 2)
        pitch = ny * (self.VFOV / 2)
        return yaw, pitch

    def bresenham_line(self, x0, y0, x1, y1):
        """Bresenham 算法生成两点间的像素坐标路径点"""
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

        # 插值点数控制
        target_points = self.num_interpolation_points + 2
        if len(points) < target_points:
            # 如果点数不足，重复终点填充
            while len(points) < target_points:
                points.append((x1, y1))
            self.get_logger().info(f"Bresenham 点数不足，填充至 {target_points} 个点")
        elif len(points) > target_points:
            # 均匀采样
            step = len(points) / (target_points - 1)
            points = [points[int(i * step)] for i in range(target_points - 1)] + [points[-1]]
        return points

    def initialize_corners(self):
        """初始化时获取中间矩形角点并保存处理后的图像，反复尝试直到成功"""
        retry_count = 0
        max_retries = 100  # 最大重试次数，防止无限循环

        while len(self.middle_corners) != 4 and retry_count < max_retries:
            retry_count += 1
            self.get_logger().info(f"尝试获取角点，第 {retry_count} 次")

            image = None

            image = self.image_msg

            if image is None:
                self.get_logger().error(f"第 {retry_count} 次尝试：无法获取图像")
                time.sleep(0.1)  # 短暂延迟后重试
                continue

            # 图像处理
            gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            _, thresh = cv2.threshold(gray, 110,255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
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

                        self.middle_corners = []  # 清空角点
                        for i in range(4):
                            outer_point = outer_corners[i][0]
                            inner_point = inner_corners[i][0]
                            mid_x = int((outer_point[0] + inner_point[0]) / 2)
                            mid_y = int((outer_point[1] + inner_point[1]) / 2)
                            self.middle_corners.append((mid_x, mid_y))
                            self.get_logger().info(f"中间矩形角点 {i+1}: ({mid_x}, {mid_y})")

                        result_image = image.copy()
                        cv2.drawContours(result_image, [outer_contour], -1, (0, 255, 0), 2)
                        cv2.drawContours(result_image, [inner_contour], -1, (255, 0, 0), 2)
                        if self.middle_corners:
                            middle_contour = np.array(self.middle_corners, dtype=np.int32).reshape((-1, 1, 2))
                            cv2.drawContours(result_image, [middle_contour], -1, (255, 0, 255), 2)
                            for i, (mx, my) in enumerate(self.middle_corners):
                                cv2.circle(result_image, (mx, my), 5, (255, 0, 255), -1)
                                cv2.putText(result_image, f"Corner {i+1}", (mx + 10, my + 10),
                                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 255), 2)

                        # 生成路径点（使用原始绝对像素坐标）并绘制到图像上
                        pixel_points = []
                        for i in range(4):
                            x0, y0 = self.middle_corners[i]
                            x1, y1 = self.middle_corners[(i + 1) % 4]
                            segment_points = self.bresenham_line(x0, y0, x1, y1)
                            pixel_points.extend(segment_points[:-1])
                        pixel_points.append(self.middle_corners[0])

                        # 绘制路径点
                        for i, (px, py) in enumerate(pixel_points):
                            cv2.circle(result_image, (int(px), int(py)), 3, (0, 255, 255), -1)  # 黄色小圆点
                            cv2.putText(result_image, f"Path {i+1}", (int(px) + 10, int(py) + 10),
                                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 255), 1)

                        save_path_rgb = '/home/orangepi/corners_result.png'
                        save_path_edges = '/home/orangepi/edges_result.png'
                        save_path_blurred = '/home/orangepi/blurred_result.png'
                        cv2.imwrite(save_path_rgb, result_image)
                        cv2.imwrite(save_path_edges, edges)
                        cv2.imwrite(save_path_blurred, blurred)
                        self.get_logger().info(f"已保存处理后的图像到 {save_path_rgb}")

                        self.get_logger().info("角点初始化完成")
                        return  # 成功获取角点，退出
                    else:
                        self.get_logger().error(f"第 {retry_count} 次尝试：内外框面积为0，无法计算角点")
                else:
                    self.get_logger().error(f"第 {retry_count} 次尝试：未检测到完整的内外框矩形")
            else:
                self.get_logger().error(f"第 {retry_count} 次尝试：未检测到内外框")
            
            time.sleep(0.1)  # 短暂延迟后重试

        if len(self.middle_corners) != 4:
            self.get_logger().error(f"重试 {max_retries} 次后仍未获取到四个角点，停止尝试")

    def generate_path_points(self):
        """生成路径点并发送所有动作目标"""
        if not self.middle_corners:
            self.get_logger().error("没有角点数据，无法生成路径")
            return

        # 使用 Bresenham 算法生成路径点（像素坐标，相对于图像中心）
        pixel_points = []
        for i in range(4):
            x0, y0 = self.middle_corners[i]
            x1, y1 = self.middle_corners[(i + 1) % 4]
            x0_rel = x0 - self.IMAGE_WIDTH / 2
            y0_rel = y0 - self.IMAGE_HEIGHT / 2
            x1_rel = x1 - self.IMAGE_WIDTH / 2
            y1_rel = y1 - self.IMAGE_HEIGHT / 2
            segment_points = self.bresenham_line(x0_rel, y0_rel, x1_rel, y1_rel)
            pixel_points.extend(segment_points[:-1])  # 避免重复添加终点
        x0, y0 = self.middle_corners[0]
        pixel_points.append((x0 - self.IMAGE_WIDTH / 2, y0 - self.IMAGE_HEIGHT / 2))

        # 转换为偏航角和俯仰角
        self.path_points = []
        for px, py in pixel_points:
            yaw, pitch = self.pixel_to_angles(px + self.IMAGE_WIDTH / 2, py + self.IMAGE_HEIGHT / 2)
            self.path_points.append((yaw, pitch))
            self.get_logger().info(f"路径点 {len(self.path_points)}: 像素=({px:.1f}, {py:.1f}), yaw={yaw:.3f}, pitch={pitch:.3f}")

        # 发送所有路径点（如果未休眠）
        if self.path_points and not self.is_paused:
            self.send_path_points()

    def send_path_points(self):
        """发送所有路径点的动作目标"""
        if not self.action_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("动作服务器不可用")
            return

        goal_msg = TrackRedDot.Goal()
        goal_msg.is_relative = False
        for i, (yaw, pitch) in enumerate(self.path_points):
            point = Point(x=yaw, y=pitch, z=0.0)  # 明确初始化 Point 对象
            goal_msg.target_angles.append(point)
            self.get_logger().info(f"添加动作目标 {i+1}: yaw={yaw:.3f}, pitch={pitch:.3f}, is_relative=False")

        self.get_logger().info(f"发送 {len(self.path_points)} 个路径点")
        future = self.action_client.send_goal_async(
            goal_msg
        )
        future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        """处理动作目标响应"""
        if self._response_timer:
            self._response_timer.cancel()
            self._response_timer = None

        self._goal_handle = future.result()
        if not self._goal_handle.accepted:
            self.get_logger().error("动作目标被拒绝")
            self.is_paused = True
            self._goal_handle = None
            return
        self.get_logger().info("动作目标已接受")


    def reset_execute_callback(self, request, response):
        """处理复位动作，重新初始化并生成路径"""
        self.get_logger().info("收到复位动作请求")
        self.is_paused = False
        self.current_path_index = 0
        self.middle_corners = []
        self.path_points = []
        self.initialize_corners()
        self.generate_path_points()
        self.send_path_points()  # 添加发送路径点的逻辑
        return response

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