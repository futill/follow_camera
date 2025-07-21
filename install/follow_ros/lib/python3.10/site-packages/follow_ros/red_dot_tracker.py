import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge
import cv2
import numpy as np
import math
from follow_msg.action import TrackRedDot
from follow_msg.action import ResetTracker
from std_srvs.srv import Empty

class KalmanFilter2D:
    def __init__(self, dt=0.1):
        self.dt = dt
        self.A = np.array([[1, 0, dt, 0],
                           [0, 1, 0, dt],
                           [0, 0, 1, 0],
                           [0, 0, 0, 1]])
        self.H = np.array([[1, 0, 0, 0],
                           [0, 1, 0, 0]])
        self.Q = np.eye(4) * 1e-4
        self.R = np.eye(2) * 1e-5
        self.P = np.eye(4)
        self.x = np.zeros((4,1))

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
            self.temp_callback,
            10)
        # self.srv = self.create_service(
        #     GetRedDotPosition,
        #     '/get_red_dot_position',
        #     self.handle_get_red_dot_position)
        self.action_client = ActionClient(
            self,
            TrackRedDot,
            '/track_red_dot')
        self.reset_action_client =self.create_service(
            Empty,
            '/reset_tracker',
            self.listener_callback
            )
        
        self.br = CvBridge()
        self.IMAGE_WIDTH = 1920
        self.IMAGE_HEIGHT = 1080
        self.HFOV = math.radians(60)
        self.VFOV = self.HFOV * self.IMAGE_HEIGHT / self.IMAGE_WIDTH
        self.Z = 1.0
        self.kalman = KalmanFilter2D(dt=0.1)
        self.debug_mode = True
        self.latest_position = Point(x=0.0, y=0.0, z=self.Z)
        self.is_paused = False
        self.goal_sent = False
        self.is_active = False  # 初始不执行处理逻辑


    def temp_callback(self,msg):
        """临时订阅回调，用于获取图像"""
        self.image_msg = self.br.imgmsg_to_cv2(msg, desired_encoding='bgr8')

    def handle_get_red_dot_position(self, request, response):
        response.response = self.latest_position
        self.get_logger().info(f"服务请求：返回红点位置 x={response.response.x:.3f}, "
                              f"y={response.response.y:.3f}")
        return response

    def reset_callback(self, goal_handle):
        self.get_logger().info("收到复位动作信号，恢复动作发布")
        self.is_paused = False
        self.goal_sent = False
        self.is_active = True  # 启用图像处理
        result = ResetTracker.Result()
        result.success = True
        result.message = "复位完成，启用红点跟踪"
        goal_handle.succeed()
        return result

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error("动作目标被拒绝")
            self.goal_sent = False
            return
        self.get_logger().info("动作目标已接受")
        goal_handle.get_result_async().add_done_callback(self.goal_result_callback)

    def goal_result_callback(self, future):
        result = future.result().result
        if result.success:
            self.get_logger().info("动作执行成功，进入休眠")
            self.is_paused = True
            self.goal_sent = False
        else:
            self.get_logger().error(f"动作执行失败: {result.message}")
            self.goal_sent = False

    def send_path_point(self, yaw, pitch):
        """发送动作目标"""
        if not self.action_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("动作服务器不可用")
            self.goal_sent = False
            return

        goal_msg = TrackRedDot.Goal()
        point = Point(x=yaw, y=pitch, z=0.0)
        goal_msg.target_angles = [point]
        goal_msg.is_relative = True

        self.get_logger().info(f"发送动作目标: yaw={yaw:.3f}, pitch={pitch:.3f}, is_relative=True")
        self.action_client.send_goal_async(
            goal_msg
        ).add_done_callback(self.goal_response_callback)
        self.goal_sent = True

    def listener_callback(self,request, response):
        if self.goal_sent and self.image_msg is not None:
            self.get_logger().info("等待当前动作完成，不发送新目标")
            return response

        image = self.image_msg

        self.IMAGE_WIDTH = 1940
        self.IMAGE_HEIGHT = 1080
        self.VFOV = self.HFOV * self.IMAGE_HEIGHT / self.IMAGE_WIDTH

        hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
        lower_red1 = np.array([0, 43, 46])
        upper_red1 = np.array([10, 255, 255])
        lower_red2 = np.array([125, 43, 46])
        upper_red2 = np.array([180, 255, 255])
        mask = cv2.bitwise_or(cv2.inRange(hsv, lower_red1, upper_red1),
                             cv2.inRange(hsv, lower_red2, upper_red2))
        
        kernel = np.ones((5,5), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if not contours:
            self.get_logger().warn("未检测到红点")
            return response
        
        largest = max(contours, key=cv2.contourArea)
        M = cv2.moments(largest)
        if M["m00"] <= 0:
            self.get_logger().warn("红点轮廓面积无效")
            return response
        
        x = int(M["m10"] / M["m00"])
        y = int(M["m01"] / M["m00"])
        
        self.kalman.predict()
        self.kalman.update(np.array([x, y]))
        x_filt, y_filt = self.kalman.get_state()
        
        self.latest_position.x = math.tan((x_filt - self.IMAGE_WIDTH / 2) / (self.IMAGE_WIDTH / 2) * (self.HFOV / 2)) * self.Z
        self.latest_position.y = math.tan((y_filt - self.IMAGE_HEIGHT / 2) / (self.IMAGE_HEIGHT / 2) * (self.VFOV / 2)) * self.Z
        self.latest_position.z = self.Z
        
        self.get_logger().info(f"滤波后红点像素坐标: x={x_filt:.3f}, y={y_filt:.3f}")
        
        nx = (x_filt - self.IMAGE_WIDTH / 2) / (self.IMAGE_WIDTH / 2)
        ny = (y_filt - self.IMAGE_HEIGHT / 2) / (self.IMAGE_HEIGHT / 2)
        yaw = nx * (self.HFOV / 2)
        pitch = ny * (self.VFOV / 2)
        
        if self.debug_mode:
            cv2.circle(image, (x, y), 10, (0, 255, 0), 2)
            px = int((math.atan(self.latest_position.x / self.Z) / (self.HFOV / 2)) * (self.IMAGE_WIDTH / 2) + self.IMAGE_WIDTH / 2)
            py = int((math.atan(self.latest_position.y / self.Z) / (self.VFOV / 2)) * (self.IMAGE_HEIGHT / 2) + self.IMAGE_HEIGHT / 2)
            cv2.circle(image, (px, py), 10, (0, 0, 255), 2)
            cv2.putText(image, f"Raw: ({x}, {y})", (x + 15, y), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
            cv2.putText(image, f"Filt: ({px}, {py})", (px + 15, py), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
            cv2.putText(image, f"Pos filt: x={self.latest_position.x:.3f}m y={self.latest_position.y:.3f}m", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            cv2.imshow("HSV Mask", cv2.resize(mask, (640, 480)))
            cv2.imshow("Red Dot Tracker", image)
            cv2.waitKey(1)
        
        self.send_path_point(yaw, pitch)
        return response

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