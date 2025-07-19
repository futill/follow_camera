import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge
import cv2
import numpy as np
import math
from follow_msg.srv import GetRedDotPosition  # 导入自定义服务

class KalmanFilter2D:
    def __init__(self, dt=0.1):
        # 状态：[x, y, vx, vy]
        self.dt = dt
        self.A = np.array([[1, 0, dt, 0],
                           [0, 1, 0, dt],
                           [0, 0, 1, 0],
                           [0, 0, 0, 1]])  # 状态转移矩阵

        self.H = np.array([[1, 0, 0, 0],
                           [0, 1, 0, 0]])  # 测量矩阵

        self.Q = np.eye(4) * 1e-4  # 过程噪声协方差
        self.R = np.eye(2) * 1e-5  # 测量噪声协方差

        self.P = np.eye(4)  # 估计误差协方差

        self.x = np.zeros((4,1))  # 初始状态


    def predict(self):
        self.x = self.A @ self.x
        self.P = self.A @ self.P @ self.A.T + self.Q

    def update(self, z):
        z = z.reshape(2,1)
        y = z - self.H @ self.x
        S = self.H @ self.P @ self.H.T + self.R
        K = self.P @ self.H.T @ np.linalg.inv(S)
        self.x = self.x + K @ y
        I = np.eye(self.A.shape[0])
        self.P = (I - K @ self.H) @ self.P

    def get_state(self):
        return self.x[0,0], self.x[1,0]

class RedDotTracker(Node):
    def __init__(self):
        super().__init__('red_dot_tracker')

        self.subscription = self.create_subscription(
            Image,
            '/color',
            self.listener_callback,
            10)

        # 创建服务
        self.srv = self.create_service(
            GetRedDotPosition,
            '/get_red_dot_position',
            self.handle_get_red_dot_position)

        # 创建发布者，发布红点相对角度
        self.angle_publisher = self.create_publisher(
            Point,
            '/target_path_point',
            10)

        self.br = CvBridge()

        self.IMAGE_WIDTH = 1920
        self.IMAGE_HEIGHT = 1080
        self.HFOV = math.radians(60)
        self.VFOV = self.HFOV * self.IMAGE_HEIGHT / self.IMAGE_WIDTH
        self.Z = 1.0

        self.kalman = KalmanFilter2D(dt=0.1)

        self.debug_mode = True  # 调试模式开关

        # 存储最新的滤波位置
        self.latest_position = Point(x=0.0, y=0.0, z=self.Z)

    def handle_get_red_dot_position(self, request, response):
        # 服务回调：返回最新的红点位置
        response.response = self.latest_position
        self.get_logger().info(f"服务请求：返回红点位置 x={response.response.x:.3f}, "
                              f"y={response.response.y:.3f}")
        return response

    def listener_callback(self, msg):
        frame = self.br.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # 转换为 HSV 颜色空间
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        # 定义红色在 HSV 空间的范围
        lower_red1 = np.array([0, 43, 46])
        upper_red1 = np.array([10, 255, 255])
        lower_red2 = np.array([125, 43, 46])
        upper_red2 = np.array([180, 255, 255])

        # 创建两个红色范围的掩码
        mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
        mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
        mask = cv2.bitwise_or(mask1, mask2)

        # 可选：应用形态学操作清理掩码
        kernel = np.ones((5,5), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)

        # 查找轮廓
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        if contours:
            largest = max(contours, key=cv2.contourArea)
            M = cv2.moments(largest)
            if M["m00"] > 0:
                x = int(M["m10"] / M["m00"])
                y = int(M["m01"] / M["m00"])

                # 卡尔曼滤波更新
                self.kalman.predict()
                self.kalman.update(np.array([x, y]))
                x_filt, y_filt = self.kalman.get_state()

                # 更新最新位置（米，用于服务）
                self.latest_position.x = math.tan((x_filt - self.IMAGE_WIDTH / 2) / (self.IMAGE_WIDTH / 2) * (self.HFOV / 2)) * self.Z
                self.latest_position.y = math.tan((y_filt - self.IMAGE_HEIGHT / 2) / (self.IMAGE_HEIGHT / 2) * (self.VFOV / 2)) * self.Z
                self.latest_position.z = self.Z

                self.get_logger().info(f"滤波后红点像素坐标: x={x_filt:.3f}, y={y_filt:.3f}")

                # 计算红点相对于图像中心的相对角度
                nx = (x_filt - self.IMAGE_WIDTH / 2) / (self.IMAGE_WIDTH / 2)
                ny = (y_filt - self.IMAGE_HEIGHT / 2) / (self.IMAGE_HEIGHT / 2)
                yaw = nx * (self.HFOV / 2)
                pitch = ny * (self.VFOV / 2)

                # 发布控制命令（相对角度）
                angle_msg = Point()
                angle_msg.x = yaw
                angle_msg.y = pitch
                angle_msg.z = 0.0
                self.angle_publisher.publish(angle_msg)
                self.get_logger().info(f"发布红点相对角度: yaw={yaw:.3f}, pitch={pitch:.3f}")

                if self.debug_mode == True:
                    # # 可视化
                    cv2.circle(frame, (x, y), 10, (0, 255, 0), 2)  # 原始检测点（绿色）
                    # # 计算滤波后点的像素位置（逆映射）
                    px = int((math.atan(x_filt / self.Z) / (self.HFOV / 2)) * (self.IMAGE_WIDTH / 2) + self.IMAGE_WIDTH / 2)
                    py = int((math.atan(y_filt / self.Z) / (self.VFOV / 2)) * (self.IMAGE_HEIGHT / 2) + self.IMAGE_HEIGHT / 2)
                    cv2.circle(frame, (px, py), 10, (0, 0, 255), 2)  # 滤波后点（红色）
                    cv2.putText(frame, f"Raw: ({x}, {y})", (x + 15, y), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
                    cv2.putText(frame, f"Filt: ({px}, {py})", (px + 15, py), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
                    cv2.putText(frame, f"Pos filt: x={x_filt:.3f}m y={y_filt:.3f}m", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                    cv2.imshow("HSV Mask", cv2.resize(mask, (640, 480)))
                    cv2.imshow("Red Dot Tracker", frame)
                    cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = RedDotTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()