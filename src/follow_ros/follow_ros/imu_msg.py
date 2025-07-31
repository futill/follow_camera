#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, MagneticField
from geometry_msgs.msg import Vector3
import serial
import struct
import platform
import serial.tools.list_ports
import math

class ImuNode(Node):
    def __init__(self):
        super().__init__('imu_node')
        # 初始化发布器
        self.imu_pub = self.create_publisher(Imu, 'imu/data', 10)
        self.mag_pub = self.create_publisher(MagneticField, 'imu/mag', 10)
        # 定时器，每 0.01 秒检查串口数据
        self.timer = self.create_timer(0.01, self.timer_callback)
        
        # 全局变量
        self.buff = {}
        self.key = 0
        self.angularVelocity = [0.0, 0.0, 0.0]
        self.acceleration = [0.0, 0.0, 0.0]
        self.magnetometer = [0.0, 0.0, 0.0]
        self.angle_degree = [0.0, 0.0, 0.0]
        self.python_version = platform.python_version()[0]

        # 查找串口
        self.find_ttyUSB()
        # 根据操作系统选择串口
        if platform.system().find("Linux") >= 0:
            port = "/dev/ttyS4"
        else:
            port = "COM3"
        baudrate = 9600

        # 初始化串口
        try:
            self.wt_imu = serial.Serial(port=port, baudrate=baudrate, timeout=0.5)
            if self.wt_imu.is_open:
                self.get_logger().info("\033[32m串口打开成功...\033[0m")
            else:
                self.wt_imu.open()
                self.get_logger().info("\033[32m打开串口成功...\033[0m")
        except Exception as e:
            self.get_logger().error(f"串口打开失败: {str(e)}")
            rclpy.shutdown()
            exit(0)

    def find_ttyUSB(self):
        self.get_logger().info('IMU 默认串口为 /dev/ttyUSB0，若识别多个串口设备，请在参数中修改 IMU 对应的串口')
        ports = [port.device for port in serial.tools.list_ports.comports() if 'USB' in port.device]
        self.get_logger().info(f"当前电脑所连接的 USB 串口设备共 {len(ports)} 个: {ports}")

    def checkSum(self, list_data, check_data):
        return sum(list_data) & 0xff == check_data

    def hex_to_short(self, raw_data):
        return list(struct.unpack("hhhh", bytearray(raw_data)))

    def handleSerialData(self, raw_data):
        angle_flag = False
        if self.python_version == '2':
            self.buff[self.key] = ord(raw_data)
        if self.python_version == '3':
            self.buff[self.key] = raw_data

        self.key += 1
        if self.buff.get(0) != 0x55:
            self.key = 0
            return
        if self.key < 11:
            return

        data_buff = list(self.buff.values())
        if self.buff[1] == 0x51:
            if self.checkSum(data_buff[0:10], data_buff[10]):
                self.acceleration = [self.hex_to_short(data_buff[2:10])[i] / 32768.0 * 16 * 9.8 for i in range(0, 3)]
            else:
                self.get_logger().warn('0x51 校验失败')
        elif self.buff[1] == 0x52:
            if self.checkSum(data_buff[0:10], data_buff[10]):
                self.angularVelocity = [self.hex_to_short(data_buff[2:10])[i] / 32768.0 * 2000 * math.pi / 180 for i in range(0, 3)]
            else:
                self.get_logger().warn('0x52 校验失败')
        elif self.buff[1] == 0x53:
            if self.checkSum(data_buff[0:10], data_buff[10]):
                self.angle_degree = [self.hex_to_short(data_buff[2:10])[i] / 32768.0 * 180 for i in range(0, 3)]
                angle_flag = True
            else:
                self.get_logger().warn('0x53 校验失败')
        elif self.buff[1] == 0x54:
            if self.checkSum(data_buff[0:10], data_buff[10]):
                self.magnetometer = [float(x) for x in self.hex_to_short(data_buff[2:10])]
            else:
                self.get_logger().warn('0x54 校验失败')
        else:
            self.get_logger().warn(f"该数据处理类没有提供 {self.buff[1]} 的解析或数据错误")
        
        self.buff = {}
        self.key = 0

        if angle_flag:
            # 发布 IMU 数据
            imu_msg = Imu()
            imu_msg.header.stamp = self.get_clock().now().to_msg()
            imu_msg.header.frame_id = 'imu_link'
            imu_msg.linear_acceleration = Vector3(x=self.acceleration[0], y=self.acceleration[1], z=self.acceleration[2])
            imu_msg.angular_velocity = Vector3(x=self.angularVelocity[0], y=self.angularVelocity[1], z=self.angularVelocity[2])
            # 欧拉角不直接填入，需要转换为四元数（此处省略，需额外实现）
            self.imu_pub.publish(imu_msg)

            # 发布磁场数据
            mag_msg = MagneticField()
            mag_msg.header.stamp = self.get_clock().now().to_msg()
            mag_msg.header.frame_id = 'imu_link'
            mag_msg.magnetic_field = Vector3(x=self.magnetometer[0], y=self.magnetometer[1], z=self.magnetometer[2])
            self.mag_pub.publish(mag_msg)

            # 打印数据
            self.get_logger().info(
                f'''
                加速度(m/s²)：
                    x轴：{self.acceleration[0]:.2f}
                    y轴：{self.acceleration[1]:.2f}
                    z轴：{self.acceleration[2]:.2f}

                角速度(rad/s)：
                    x轴：{self.angularVelocity[0]:.2f}
                    y轴：{self.angularVelocity[1]:.2f}
                    z轴：{self.angularVelocity[2]:.2f}

                欧拉角(°)：
                    x轴：{self.angle_degree[0]:.2f}
                    y轴：{self.angle_degree[1]:.2f}
                    z轴：{self.angle_degree[2]:.2f}

                磁场：
                    x轴：{self.magnetometer[0]:.2f}
                    y轴：{self.magnetometer[1]:.2f}
                    z轴：{self.magnetometer[2]:.2f}
                '''
            )

    def timer_callback(self):
        try:
            buff_count = self.wt_imu.in_waiting
        except Exception as e:
            self.get_logger().error(f"异常: {str(e)}")
            self.get_logger().error("IMU 失去连接，接触不良，或断线")
            rclpy.shutdown()
            exit(0)
        else:
            if buff_count > 0:
                buff_data = self.wt_imu.read(buff_count)
                for i in range(0, buff_count):
                    self.handleSerialData(buff_data[i])

def main(args=None):
    rclpy.init(args=args)
    imu_node = ImuNode()
    try:
        rclpy.spin(imu_node)
    except KeyboardInterrupt:
        imu_node.get_logger().info("节点被用户终止")
    finally:
        if hasattr(imu_node, 'wt_imu') and imu_node.wt_imu.is_open:
            imu_node.wt_imu.close()
        imu_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()