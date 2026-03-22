import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class CommandListener(Node):
    def __init__(self):
        super().__init__('command_listener')
        self.subscription = self.create_subscription(
            String, '/rover_command', self.listener_callback, 10)

    def listener_callback(self, msg):
        self.get_logger().info(f'Received command: {msg.data} | Rover wheels moving...')

def main(args=None):
    rclpy.init(args=args)
    node = CommandListener()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()