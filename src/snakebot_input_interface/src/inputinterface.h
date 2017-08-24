#pragma once

#include "snakebot_input_interface/Ctrl.h"
#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

class JoystickInterface{
private:
    ros::NodeHandle rosNode;
    ros::Subscriber joystickSub;
    ros::Publisher ctrlPub;
    void joystickCallback(const sensor_msgs::Joy::ConstPtr& msg);

public:
    JoystickInterface(ros::NodeHandle rosNode);

};
