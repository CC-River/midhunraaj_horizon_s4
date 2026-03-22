import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, String

class DecisionNode(Node):
    def __init__(self):
        super().__init__('decision_node')
        self.subscription = self.create_subscription(
            Float32, '/distance', self.listener_callback, 10)
        self.publisher_ = self.create_publisher(String, '/rover_command', 10)

    def listener_callback(self, msg):
        distance = msg.data
        command = String()
        if distance < 30.0:
            command.data = 'STOP'
        else:
            command.data = 'MOVE_FORWARD'
        self.publisher_.publish(command)
        self.get_logger().info(f'Distance received: {distance} cm | Command published: {command.data}')

def main(args=None):
    rclpy.init(args=args)
    node = DecisionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()