from setuptools import find_packages, setup

package_name = 'follow_ros'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/tracker_system.launch.py'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='futill',
    maintainer_email='358181022@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'camer_node = follow_ros.camer_node:main',
            'imu_msg = follow_ros.imu_msg:main',
            'reset_controller = follow_ros.reset_controller:main',
            'red_dot_tracker = follow_ros.red_dot_tracker:main',
            'tape_tracker = follow_ros.tape_tracker:main',
            'gimbal_controller = follow_ros.gimbal_controller:main',
        ],
    },
)
