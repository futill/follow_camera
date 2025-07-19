import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class follow_node(Node):
    def __init__(self):
        super().__init__('follow_node')

        self.camera_pub = self.create_publisher(Image, '/color', 10)
        self.br = CvBridge()

        self.cap = cv2.VideoCapture(0)

        # 设置分辨率为 1080p 和帧率为 60 FPS
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)
        self.cap.set(cv2.CAP_PROP_FPS, 60)

        if not self.cap.isOpened():
            self.get_logger().error("无法打开相机")
            return
        
        # 设置回调频率为 60 Hz
        self.timer = self.create_timer(1/60, self.timer_callback)

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warning("无法读取相机帧")
            return
        img_msg = self.br.cv2_to_imgmsg(frame, encoding='bgr8')
        self.camera_pub.publish(img_msg)

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = follow_node()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
