from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='grasp_publisher',
            namespace='mani_gpt',
            executable='gpt',
            name='gpt'
        ),
        Node(
            package='franka_grasp',
            namespace='mani_gpt',
            executable='grasp',
            name='grasp'
        )
    ])