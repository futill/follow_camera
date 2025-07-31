import rclpy
from rclpy.node import Node
from geometry_msgs.msg import bool
import serial
from std_srvs.srv import Empty
import time

class SerialVelocityNode(Node):
    def __init__(self):
        super().__init__('serial_velocity_node')

        self.subscription = self.create_subscription(
            bool,
            'laser_power',
            self.laser_power_callback,
            10)

        self.stop_service = self.create_service(
            Empty,
            '/stop_gimbal',
            self.reset_execute_callback
        )

        # 声明模式选择参数
        self.declare_parameter('mode', 0x00)
        self.mode = self.get_parameter('mode').get_parameter_value().integer_value
        self.get_logger().info(f'串口节点已启动，模式: {hex(self.mode)}')

        # 串口配置
        self.serial_port = '/dev/ttyS4'  # 视你的设备而定
        self.baud_rate = 115200

        try:
            self.ser = serial.Serial(self.serial_port, self.baud_rate, timeout=1)
            self.get_logger().info(f'串口 {self.serial_port} 打开成功，波特率 {self.baud_rate}')
        except serial.SerialException as e:
            self.get_logger().error(f'打开串口失败: {str(e)}')
            self.ser = None


    def reset_execute_callback(self, request, response):
        self.get_logger().info('接收到停止请求')
        self.mode = 0x03
        self.send_serial_packet(0, 0)
        return response

    def cmd_vel_callback(self, msg):
        try:
            power = msg.bool
            self.send_serial_packet(power)
        except Exception as e:
            self.get_logger().error(f'处理角度消息出错: {str(e)}')

    def send_serial_packet(self, power):
        
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
