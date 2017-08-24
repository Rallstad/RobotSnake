#include "inputinterface.h"


void JoystickInterface::joystickCallback(const sensor_msgs::Joy::ConstPtr& msg){
    snakebot_input_interface::Ctrl ctrlMsg;

    ctrlMsg.velocity = msg->axes[1];
    ctrlMsg.direction = -msg->axes[2];
    ctrlPub.publish(ctrlMsg);
}

JoystickInterface::JoystickInterface(ros::NodeHandle rosNode): rosNode(rosNode){
    ros::Subscriber joystickSub = rosNode.subscribe("joy", 1, &JoystickInterface::joystickCallback, this);
    ros::Publisher ctrlPub = rosNode.advertise<snakebot_input_interface::Ctrl>("/snakebot/ctrl", 1);

}
