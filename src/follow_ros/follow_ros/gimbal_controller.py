import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import serial
from std_srvs.srv import Empty
import time

class SerialVelocityNode(Node):
    def __init__(self):
        super().__init__('serial_velocity_node')

        self.subscription = self.create_subscription(
            Twist,
            'cmd_vel',
            self.cmd_vel_callback,
            10)

        self.stop_service = self.create_service(
            Empty,
            '/stop_gimbal',
            self.reset_execute_callback
        )

        self.reset_service = self.create_service(
            Empty,
            '/reset_tracker',
            self.reset_tracker_callback
        )

        # 声明模式选择参数
        self.declare_parameter('mode', 0x00)
        self.mode = self.get_parameter('mode').get_parameter_value().integer_value
        self.get_logger().info(f'串口节点已启动，模式: {hex(self.mode)}')

        # 串口配置
        self.serial_port = '/dev/ttyS0'  # 视你的设备而定
        self.baud_rate = 115200
        self.angle_limit = 36 * 5  # 180度 × 5
        self.address = 0x01  # 假设设备地址为 0x01，可修改

        try:
            self.ser = serial.Serial(self.serial_port, self.baud_rate, timeout=1)
            self.get_logger().info(f'串口 {self.serial_port} 打开成功，波特率 {self.baud_rate}')
        except serial.SerialException as e:
            self.get_logger().error(f'打开串口失败: {str(e)}')
            self.ser = None

    def reset_tracker_callback(self, request, response):
        self.get_logger().info('接收到重置请求')
        self.mode = 0x01
        self.send_serial_packet(0, 0)
        return response

    def reset_execute_callback(self, request, response):
        self.get_logger().info('接收到停止请求')
        self.mode = 0x03
        self.send_serial_packet(0, 0)
        return response

    def cmd_vel_callback(self, msg):
        try:
            yaw_angle = msg.angular.z
            pitch_angle = msg.angular.y
            self.mode = 0x03
            self.send_serial_packet(yaw_angle, pitch_angle)
        except Exception as e:
            self.get_logger().error(f'处理角度消息出错: {str(e)}')

    def send_serial_packet(self, yaw_angle, pitch_angle):
        if self.ser is None:
            self.get_logger().warning('串口未初始化，无法发送数据')
            return

        # 方向判断：0x00 = CW, 0x01 = CCW
        yaw_dir = 0x01 if yaw_angle >= 0 else 0x00
        pitch_dir = 0x01 if pitch_angle >= 0 else 0x00
        

        # 将角度转换为“速度值”，乘以比例系数
        yaw_speed = int(min(max(abs(yaw_angle * 5), 0), self.angle_limit))
        pitch_speed = int(min(max(abs(pitch_angle * 5), 0), self.angle_limit))

        # 分别发送 yaw 和 pitch 命令（可按实际协议合并）
        self.send_speed_command(2, yaw_dir, yaw_speed)
        time.sleep(0.02)
        self.send_speed_command(1, pitch_dir, pitch_speed)
        time.sleep(0.02)

    def send_speed_command(self, address: int, direction: int, speed_rpm: int):
        speed_high = (speed_rpm >> 8) & 0xFF
        speed_low = speed_rpm & 0xFF

        cmd = [
            address & 0xFF,
            0xF6,
            direction & 0x01,
            speed_high,
            speed_low,
            0x00,  # 加速度档位
            0x00,  # 同步位
            0x6B   # 校验或结束标志，需根据协议替换
        ]

        try:
            self.ser.write(bytes(cmd))
            # self.get_logger().info(f'发送命令: {cmd}')
        except serial.SerialException as e:
            self.get_logger().error(f'串口写入失败: {str(e)}')

    def set_mode(self, mode):
        if 0 <= mode <= 255:
            self.mode = mode
            self.get_logger().info(f'模式更新为: {hex(self.mode)}')
        else:
            self.get_logger().error(f'无效模式值: {mode}，必须在 [0, 255] 范围内')

    def destroy_node(self):
        if self.ser and self.ser.is_open:
            self.ser.close()
            self.get_logger().info('串口已关闭')
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = SerialVelocityNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
