import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
import serial
import threading
import time

class GimbalController(Node):
    def __init__(self):
        super().__init__('gimbal_controller')

        # 订阅 /target_red_dot_angle 话题
        self.subscription = self.create_subscription(
            Point,
            '/target_path_point',
            self.angle_callback,
            10)

        # 发布 /gimbal_pose 话题
        self.publisher = self.create_publisher(
            Point,
            '/gimbal_pose',
            10)

        # 串口参数
        self.serial_port = '/dev/ttyS0'
        self.baud_rate = 115200
        self.serial_timeout = 1.0  # 串口超时（秒）

        # 初始化串口
        self.ser = None
        try:
            self.ser = serial.Serial(
                port=self.serial_port,
                baudrate=self.baud_rate,
                timeout=self.serial_timeout
            )
            self.get_logger().info(f"串口 {self.serial_port} 打开成功，波特率 {self.baud_rate}")
        except serial.SerialException as e:
            self.get_logger().error(f"无法打开串口 {self.serial_port}: {e}")
            self.ser = None

        # 启动串口读取线程
        self.running = True
        self.serial_thread = threading.Thread(target=self.read_serial)
        self.serial_thread.daemon = True
        self.serial_thread.start()

    def angle_callback(self, msg):
        """处理 /target_red_dot_angle 话题，发送相对角度到串口"""
        if self.ser is None or not self.ser.is_open:
            self.get_logger().error("串口未打开，无法发送角度")
            return

        yaw = msg.x  # 相对偏航角（弧度）
        pitch = msg.y  # 相对俯仰角（弧度）

        # 格式化串口命令：yaw,pitch\n
        command = f"{yaw:.3f},{pitch:.3f}\n"
        try:
            self.ser.write(command.encode('utf-8'))
            self.get_logger().info(f"发送串口命令: yaw={yaw:.3f}, pitch={pitch:.3f}")
        except serial.SerialException as e:
            self.get_logger().error(f"串口发送失败: {e}")

    def read_serial(self):
        """从串口读取云台角度，发布到 /gimbal_pose"""
        while self.running and rclpy.ok():
            if self.ser is None or not self.ser.is_open:
                self.get_logger().error("串口未打开，无法读取数据")
                time.sleep(1.0)
                continue

            try:
                # 读取一行数据
                line = self.ser.readline().decode('utf-8').strip()
                if line:
                    # 假设格式为 yaw,pitch（弧度）
                    try:
                        yaw, pitch = map(float, line.split(','))
                        point_msg = Point()
                        point_msg.x = yaw
                        point_msg.y = pitch
                        point_msg.z = 0.0
                        self.publisher.publish(point_msg)
                        self.get_logger().info(f"发布云台角度: yaw={yaw:.3f}, pitch={pitch:.3f}")
                    except ValueError as e:
                        self.get_logger().error(f"串口数据格式错误: {line}, {e}")
                else:
                    self.get_logger().warn("串口未收到数据")
            except serial.SerialException as e:
                self.get_logger().error(f"串口读取失败: {e}")
            time.sleep(0.01)  # 避免高 CPU 占用

    def destroy_node(self):
        """销毁节点时关闭串口和线程"""
        self.running = False
        if self.serial_thread.is_alive():
            self.serial_thread.join()
        if self.ser and self.ser.is_open:
            self.ser.close()
            self.get_logger().info("串口已关闭")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = GimbalController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()