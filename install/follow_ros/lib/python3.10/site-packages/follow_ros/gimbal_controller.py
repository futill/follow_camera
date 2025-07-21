import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Point
from follow_msg.action import TrackRedDot
import serial
import struct
import threading
import time
import re
import math
from std_srvs.srv import Empty

class TrackRedDotServer(Node):
    def __init__(self):
        super().__init__('gimbal_controller')
        self.action_server = ActionServer(
            self,
            TrackRedDot,
            '/track_red_dot',
            self.execute_callback,
        )
        self.stop_service = self.create_service(
            Empty,
            '/stop_gimbal',
            self.stop_gimbal_callback
        )
        
        # 串口配置
        self.serial_port = serial.Serial(
            port='/dev/ttyS0',
            baudrate=115200,
            timeout=1.0
        )
        self.current_angle = Point(x=0.0, y=0.0, z=0.0)
        self.serial_lock = threading.Lock()
        self.running = True
        self.slop = False
        
        # 启动串口读取线程
        self.serial_thread = threading.Thread(target=self.read_serial)
        self.serial_thread.daemon = True
        self.serial_thread.start()
        
        self.get_logger().info('TrackRedDot 动作服务器已启动')

    def goal_callback(self, goal_request):
        """接受或拒绝动作目标"""
        self.get_logger().info('收到动作目标')
        return rclpy.action.GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        """处理取消请求"""
        self.get_logger().info(f'收到取消请求，目标 ID: {goal_handle.goal_id}')
        return rclpy.action.CancelResponse.ACCEPT

    def read_serial(self):
        """从串口读取 yaw 和 pitch 反馈，格式为 'ID: 1 Angle: X deg' 和 'ID: 2 Angle: Y deg'"""
        buffer = ""
        while self.running:
            if self.serial_port.in_waiting > 0:
                with self.serial_lock:
                    buffer += self.serial_port.read(self.serial_port.in_waiting).decode('utf-8', errors='ignore')
                
                lines = buffer.split('\n')
                buffer = lines[-1]
                for line in lines[:-1]:
                    match = re.match(r'ID:\s*(\d+)\s*Angle:\s*([-]?\d+\.\d+)\s*deg', line.strip())
                    if match:
                        id_val = int(match.group(1))
                        angle = float(match.group(2))
                        if id_val == 1:
                            self.current_angle.x = math.radians(angle)
                            self.get_logger().info(f'收到 yaw 反馈: {angle:.3f} deg ({self.current_angle.x:.3f} rad)')
                        elif id_val == 2:
                            self.current_angle.y = math.radians(angle)
                            self.get_logger().info(f'收到 pitch 反馈: {angle:.3f} deg ({self.current_angle.y:.3f} rad)')
            time.sleep(0.01)

    def float_to_bytes(self, value):
        """将浮点数转换为 32 位浮点字节，保留 3 位小数"""
        value = round(value, 3)*1000
        return struct.pack('>f', value)

    def send_command(self, yaw, pitch, is_relative):
        """发送 yaw 和 pitch 控制命令"""
        frame_head = 0xBD if is_relative else 0xAD
        
        yaw_direction = 0x01 if yaw < 0 else 0x00
        yaw_bytes = self.float_to_bytes(abs(yaw))
        yaw_command = bytearray([0x01, frame_head, yaw_direction]) + yaw_bytes + bytearray([0x6B])
        
        pitch_direction = 0x01 if pitch < 0 else 0x00
        pitch_bytes = self.float_to_bytes(abs(pitch))
        pitch_command = bytearray([0x02, frame_head, pitch_direction]) + pitch_bytes + bytearray([0x6B])
        
        with self.serial_lock:
            self.serial_port.write(yaw_command)
            self.get_logger().info(f'发送 yaw 命令: frame=0x01, control={hex(frame_head)}, yaw={yaw:.3f}')
            time.sleep(0.001)
            self.serial_port.write(pitch_command)
            self.get_logger().info(f'发送 pitch 命令: frame=0x02, control={hex(frame_head)}, pitch={pitch:.3f}')

    def stop_gimbal_callback(self, request, response):
        """处理停止服务请求，立即取消动作并发送停止命令"""
        start_time = self.get_clock().now()
        self.get_logger().info("收到停止云台请求")
        
        # 取消所有活跃动作
        self.get_logger().info("尝试取消所有动作目标")
        self.slop = False
        
        # 发送停止命令
        stop_yaw_command = bytearray([0x01, 0xCD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6B])
        stop_pitch_command = bytearray([0x02, 0xCD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6B])
        self.serial_port.write(stop_yaw_command)
        self.get_logger().info("发送 yaw 停止命令: 01 CD 00 00 00 00 00 6B")
        time.sleep(0.001)
        self.serial_port.write(stop_pitch_command)
        self.get_logger().info("发送 pitch 停止命令: 02 CD 00 00 00 00 00 6B")
        
        elapsed = (self.get_clock().now() - start_time).nanoseconds / 1e9
        self.get_logger().info(f"云台已停止，当前角度: yaw={self.current_angle.x:.3f} rad, pitch={self.current_angle.y:.3f} rad, 处理耗时: {elapsed:.6f} 秒")
        self.get_logger().info("动作服务器准备接受新目标")
        return response

    def execute_callback(self, goal_handle: ServerGoalHandle):
        """处理动作目标，依次发送所有路径点，仅检查最终路径点"""
        self.get_logger().info(f"执行动作目标: {goal_handle.goal_id}, {len(goal_handle.request.target_angles)} 个路径点, relative={goal_handle.request.is_relative}")
        
        goal = goal_handle.request
        is_relative = goal.is_relative
        
        for i, target in enumerate(goal.target_angles):
            target_yaw = target.x
            target_pitch = target.y
            self.get_logger().info(f'发送路径点 {i+1}: yaw={target_yaw:.3f}, pitch={target_pitch:.3f}')
            self.send_command(target_yaw, target_pitch, is_relative)

        if not goal.target_angles:
            self.get_logger().error('目标路径点为空')
            result = TrackRedDot.Result()
            result.success = False
            result.message = '目标路径点为空'
            goal_handle.abort()
            return result

        final_target = goal.target_angles[-1]
        target_yaw = final_target.x
        target_pitch = final_target.y
        
        start_time = self.get_clock().now()
        timeout = 3.0
        while rclpy.ok() and goal_handle.is_active:
            if self.slop:
                result = TrackRedDot.Result()
                result.success = True
                result.message = f'动作被取消，当前角度: yaw={self.current_angle.x:.3f} rad, pitch={self.current_angle.y:.3f} rad'
                goal_handle.canceled()
                self.slop = False
                return result
            self.get_logger().debug(f"目标 {goal_handle.goal_id} 活跃状态: {goal_handle.is_active}")
            yaw_error = abs(self.current_angle.x - (target_yaw if not is_relative else self.current_angle.x + target_yaw))
            pitch_error = abs(self.current_angle.y - (target_pitch if not is_relative else self.current_angle.y + target_pitch))
            if yaw_error < 0.1 and pitch_error < 0.1:
                self.get_logger().info('最终路径点目标角度已达到')
                result = TrackRedDot.Result()
                result.success = True
                result.message = f'所有路径点已完成，当前角度: yaw={self.current_angle.x:.3f} rad, pitch={self.current_angle.y:.3f} rad'
                goal_handle.succeed()
                return result
            if (self.get_clock().now() - start_time).nanoseconds / 1e9 > timeout:
                self.get_logger().error(f'最终路径点执行超时，目标: yaw={target_yaw:.3f}, pitch={target_pitch:.3f}, 当前: yaw={self.current_angle.x:.3f}, pitch={self.current_angle.y:.3f}')
                result = TrackRedDot.Result()
                result.success = False
                result.message = f'最终路径点执行超时，目标: yaw={target_yaw:.3f} rad, pitch={target_pitch:.3f} rad, 当前: yaw={self.current_angle.x:.3f} rad, pitch={self.current_angle.y:.3f} rad'
                goal_handle.abort()
                return result

    def destroy_node(self):
        """清理资源"""
        self.running = False
        self.serial_thread.join(timeout=1.0)
        self.serial_port.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = TrackRedDotServer()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()