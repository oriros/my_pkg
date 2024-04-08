#include "rclcpp/rclcpp.hpp"
// #include "my_msgs/msg/num.hpp"
class RobotNode : public rclcpp::Node
{
public:
    RobotNode() : Node("robot_node")
    {
        RCLCPP_INFO(this->get_logger(), "robot_node 기본 생성자");
        timer_=this->create_wall_timer(std::chrono::milliseconds(200), 
        std::bind(&RobotNode::timerCallback,this));
    }
private:
    void timerCallback()
    {
        RCLCPP_INFO(this->get_logger(),"안녕 콜백!");
    }
    rclcpp::TimerBase::SharedPtr timer_; 
};

int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<RobotNode>();//이 때 기본생성자 실행
    rclcpp::spin(node);//타이머가 돌려면 노드가 돌아야 된다.  
    rclcpp::shutdown();
    return 0;
}
//참조 : https://roboticsbackend.com/write-minimal-ros2-cpp-node/