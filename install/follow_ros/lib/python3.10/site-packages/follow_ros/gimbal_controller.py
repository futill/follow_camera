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

        self.reset_server = self.create_service(
            Empty,
            '/stop_gimbal',
            self.stop_execute_callback
        )

        self.reset_server = self.create_service(
            Empty,
            '/reset_tracker',
            self.reset_tracker_callback
        )

        # 声明模式选择参数
        self.declare_parameter('mode', 0x00)  # 默认模式为 0x00
        self.mode = self.get_parameter('mode').get_parameter_value().integer_value
        self.get_logger().info(f'串口节点已启动，模式: {hex(self.mode)}')

        # 串口配置
        self.serial_port = '/dev/ttyS0'  # 可根据实际设备修改
        self.baud_rate = 115200
        self.angle_limit = 60  # 角度限幅，单位：度数，范围[-180, 180]
        try:
            self.ser = serial.Serial(self.serial_port, self.baud_rate, timeout=1)
            #self.get_logger().info(f'串口 {self.serial_port} 打开成功，波特率 {self.baud_rate}')
        except serial.SerialException as e:
            self.get_logger().error(f'打开串口失败: {str(e)}')
            self.ser = None


    def reset_tracker_callback(self, request, response):
        """处理/reset_tracker服务调用"""
        self.get_logger().info('接收到重置请求')
        self.send_laser_power_RETRUN()
        return response
    
    def stop_execute_callback(self, request, response):
        """处理/stop_gimbal服务调用"""
        self.get_logger().info('接收到停止请求')
        self.send_laser_power_OFF()
        return response
    
    def cmd_vel_callback(self, msg):
        """处理cmd_vel话题消息"""
        try:
            # 获取yaw和pitch角度（度数）
            yaw_angle = msg.angular.z  # 偏航角（度数）
            pitch_angle = msg.angular.y  # 仰角（度数）
            mode = msg.angular.x
            if mode == 1.0:
                self.send_serial_packet(yaw_angle, pitch_angle)
            elif mode == 2.0:
                self.send_laser_power_ON()
            elif mode == 3.0:
                self.send_laser_power_OFF()
            elif mode == 4.0:
                self.send_laser_power_RETRUN()
        except Exception as e:
            self.get_logger().error(f'处理角度消息出错: {str(e)}')

    def send_laser_power_ON(self):
        """构建并发送串口数据包（角度）"""
        if self.ser is None or not self.ser.is_open:
            self.get_logger().error('串口未打开，跳过发送')
            return

        try:
            # 构建协议数据
            packet = [
                0xC7,0xC8,  # 起始字节
                0x00, 0x00,    # yaw角度高低字节
                0x5D
            ]
            # 发送串口数据
            self.ser.write(bytes(packet))
            time.sleep(0.02)  # 确保数据发送完成
            #self.get_logger().info(f'发送串口数据: {packet}')

        except serial.SerialException as e:
            self.get_logger().error(f'串口发送失败: {str(e)}')

    def send_laser_power_OFF(self):
        """构建并发送串口数据包（角度）"""
        if self.ser is None or not self.ser.is_open:
            self.get_logger().error('串口未打开，跳过发送')
            return

        try:
            # 构建协议数据
            packet = [
                0xC7,0xC8,  # 起始字节
                0x00, 0x01,    # yaw角度高低字节
                0x5D
            ]
            # 发送串口数据
            self.ser.write(bytes(packet))
            time.sleep(0.02)  # 确保数据发送完成
            #self.get_logger().info(f'发送串口数据: {packet}')

        except serial.SerialException as e:
            self.get_logger().error(f'串口发送失败: {str(e)}')

    def send_laser_power_RETRUN(self):
        """构建并发送串口数据包（角度）"""
        if self.ser is None or not self.ser.is_open:
            self.get_logger().error('串口未打开，跳过发送')
            return

        try:
            # 构建协议数据
            packet = [
                0xC5,0xC6,  # 起始字节
                0x00, 0x02,    # yaw角度高低字节
                0x4D
            ]
            # 发送串口数据
            self.ser.write(bytes(packet))
            time.sleep(0.02)  # 确保数据发送完成
            #self.get_logger().info(f'发送串口数据: {packet}')

        except serial.SerialException as e:
            self.get_logger().error(f'串口发送失败: {str(e)}')


    def send_serial_packet(self, yaw_angle, pitch_angle):
        """构建并发送串口数据包（角度）"""
        if self.ser is None or not self.ser.is_open:
            self.get_logger().error('串口未打开，跳过发送')
            return

        try:
            # 确定方向和绝对角度
            yaw_direction = 0x01 if yaw_angle >= 0 else 0x00
            pitch_direction = 0x01 if pitch_angle >= 0 else 0x00
            yaw_abs_angle = int(abs(yaw_angle))  # 取绝对值并转换为整数
            pitch_abs_angle = int(abs(pitch_angle))

            # 限制角度范围
            yaw_abs_angle = max(0, min(self.angle_limit, yaw_abs_angle))
            pitch_abs_angle = max(0, min(self.angle_limit, pitch_abs_angle))

            # 分解为高低字节
            yaw_high = (yaw_abs_angle >> 8) & 0xFF
            yaw_low = yaw_abs_angle & 0xFF
            pitch_high = (pitch_abs_angle >> 8) & 0xFF
            pitch_low = pitch_abs_angle & 0xFF

            # 构建协议数据
            packet = [
                0xA5,0xA6,  # 起始字节
                yaw_direction,   # yaw方向
                pitch_direction, # pitch方向
                yaw_high, yaw_low,    # yaw角度高低字节
                pitch_high, pitch_low,  # pitch角度高低字节
                0x6B, 0x5B  # 结束字节
            ]

            # 发送串口数据
            self.ser.write(bytes(packet))
            time.sleep(0.02)  # 确保数据发送完成
            self.get_logger().info(f'发送串口数据: {packet}')

        except serial.SerialException as e:
            self.get_logger().error(f'串口发送失败: {str(e)}')

    def set_mode(self, mode):
        """接口：设置模式选择字节"""
        if 0 <= mode <= 255:
            self.mode = mode
            self.get_logger().info(f'模式更新为: {hex(self.mode)}')
        else:
            self.get_logger().error(f'无效模式值: {mode}，必须在 [0, 255] 范围内')

    def destroy_node(self):
        """节点销毁时关闭串口"""
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