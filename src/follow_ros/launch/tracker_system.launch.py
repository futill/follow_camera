import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # 启动 gimbal_controller 节点

        Node(
            package='follow_ros',
            executable='camer_node',
            name='camer_node',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'log_level': 'info'}
            ]
        ),

        Node(
            package='follow_ros',
            executable='gimbal_controller',
            name='gimbal_controller',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'log_level': 'info'}
            ]
        ),

        # 启动 red_dot_tracker 节点
        Node(
            package='follow_ros',
            executable='red_dot_tracker',
            name='red_dot_tracker',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'log_level': 'info'}
            ]
        ),

        # 启动 tape_tracker 节点
        Node(
            package='follow_ros',
            executable='tape_tracker',
            name='tape_tracker',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'log_level': 'info'}
            ]
        ),

        # 启动 reset_controller 节点
        Node(
            package='follow_ros',
            executable='reset_controller',
            name='reset_controller',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'log_level': 'info'}
            ]
        ),
    ])