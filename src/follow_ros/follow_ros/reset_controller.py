import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.executors import SingleThreadedExecutor
from follow_msg.action import ResetTracker
from follow_msg.action import ResetTapeTracker
from std_srvs.srv import Empty
import tkinter as tk
import threading

class ResetController(Node):
    def __init__(self, root):
        super().__init__('reset_controller')
        self.root = root

        # 创建动作客户端
        self.reset_tracker_client = self.create_client(Empty, '/reset_tracker')
        self.reset_tape_tracker_client = self.create_client(Empty,'/reset_tape_tracker')
        self.stop_gimbal_client = self.create_client(Empty, '/stop_gimbal')

        # 创建 GUI
        self.create_gui()

        # 启动 ROS 线程
        self.ros_thread = threading.Thread(target=self.spin_node)
        self.ros_thread.daemon = True
        self.ros_thread.start()

    def create_gui(self):
        """创建 Tkinter GUI 界面"""
        self.root.title("Reset Controller")
        self.root.geometry("300x200")

        # Reset Red Dot Tracker 按钮
        btn_reset_red_dot = tk.Button(
            self.root,
            text="Reset Red Dot Tracker",
            command=self.send_reset_tracker,
            font=("Arial", 12),
            width=20
        )
        btn_reset_red_dot.pack(pady=10)

        # Reset Tape Tracker 按钮
        btn_reset_tape = tk.Button(
            self.root,
            text="Reset Tape Tracker",
            command=self.send_reset_tape_tracker,
            font=("Arial", 12),
            width=20
        )
        btn_reset_tape.pack(pady=10)

        # Stop Gimbal 按钮
        btn_stop_gimbal = tk.Button(
            self.root,
            text="Stop Gimbal",
            command=self.send_stop_gimbal,
            font=("Arial", 12),
            width=20
        )
        btn_stop_gimbal.pack(pady=10)

    def spin_node(self):
        """在单独线程中运行 ROS 节点"""
        executor = SingleThreadedExecutor()
        executor.add_node(self)
        try:
            executor.spin()
        except KeyboardInterrupt:
            pass
        finally:
            executor.shutdown()

    def send_reset_tracker(self):
        if not self.reset_tracker_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error("StopGimbal 服务不可用")
            return
        
        request = Empty.Request()
        self.get_logger().info("ResetTapeTracker 动作目标已接受")
        self.reset_tracker_client.call_async(request).add_done_callback(self.reset_tracker_result_callback)

    def reset_tracker_result_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info("ResetTracker 动作执行成功")
        except Exception as e:
            self.get_logger().error(f"ResetTapeTracker 动作执行失败")


    def send_reset_tape_tracker(self):
        if not self.reset_tape_tracker_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error("StopGimbal 服务不可用")
            return
        
        request = Empty.Request()
        self.get_logger().info("ResetTapeTracker 动作目标已接受")
        self.reset_tape_tracker_client.call_async(request).add_done_callback(self.reset_tape_tracker_result_callback)

    def reset_tape_tracker_result_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info("ResetTapeTracker 动作执行成功")
        except Exception as e:
            self.get_logger().error(f"ResetTapeTracker 动作执行失败")

    def send_stop_gimbal(self):
        """调用 /stop_gimbal 服务"""
        if not self.stop_gimbal_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error("StopGimbal 服务不可用")
            return

        request = Empty.Request()
        self.get_logger().info("发送 StopGimbal 服务请求")
        self.stop_gimbal_client.call_async(request).add_done_callback(self.stop_gimbal_response_callback)

    def stop_gimbal_response_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info("StopGimbal 服务调用成功")
        except Exception as e:
            self.get_logger().error(f"StopGimbal 服务调用失败: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    root = tk.Tk()
    node = ResetController(root)
    try:
        root.mainloop()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        root.destroy()

if __name__ == '__main__':
    main()