#pragma once

#include <vector>
#include <math.h>
#include <algorithm>
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/String.h"
#include "ros/ros.h"
#include "snakebot_robot_pose/Pose.h"
#include "snakebot_collisions/SnakeContacts.h"
#include "snakebot_collisions/LinkContacts.h"
#include "snakebot_pushpoints/Pushpoints.h"
#include "snakebot_labview_communication/Collisions.h"
#include "snakebot_labview_communication/LinkPoses.h"
#include "snakebot_labview_communication/Float64Array.h"
#include "snakebot_labview_communication/Int32Array.h"
#include "sensor_msgs/JointState.h"

using std::cout;
using std::endl;


class Communication
{
private:

    // COMMUNICATES WITH NODES ON THE ROS AND GAZEBO SIDE:

    // ROS callback functions
    void ROS_RefAnglesCallback(const std_msgs::Float64MultiArray::ConstPtr& inMsg);
    void ROS_MeasuredAnglesCallback(const sensor_msgs::JointState::ConstPtr& msg);
    void ROS_CollisionsCallback(const snakebot_collisions::SnakeContacts::ConstPtr& msg);
    void ROS_PushPointsCallback(const snakebot_pushpoints::Pushpoints::ConstPtr& msg);
    void ROS_RobotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr& msg);

    // ROS subscribers
    ros::Subscriber ROS_RefAnglesSub;
    ros::Subscriber ROS_MeasuredAnglesSub;
    ros::Subscriber ROS_CollisionsSub;
    ros::Subscriber ROS_PushPointsSub;
    ros::Subscriber ROS_RobotPoseSub;

    // ROS publishers
    ros::Publisher ROS_RefAnglesPub;
    ros::Publisher ROS_MeasuredAnglesPub;
    ros::Publisher ROS_CollisionsPub;
    ros::Publisher ROS_RobotPosePub;



    // COMMUNICATES WITH NODES ON THE LabVIEW SIDE:

    // LabVIEW callback functions
    void LabVIEW_RefAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& msg);
    void LabVIEW_MeasuredAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& msg);
    void LabVIEW_RobotPoseCallback(const snakebot_labview_communication::LinkPoses::ConstPtr& msg);
    void LabVIEW_CollisionsCallback(const snakebot_labview_communication::Collisions::ConstPtr& msg);

    // LabVIEW subscribers
    ros::Subscriber LabVIEW_RefAnglesSub;
    ros::Subscriber LabVIEW_MeasuredAnglesSub;
    ros::Subscriber LabVIEW_PushPointSub;
    ros::Subscriber LabVIEW_LinkPoseSub;
    ros::Subscriber LabVIEW_pushPointSub;
    ros::Subscriber LabVIEW_RobotPoseSub;
    // LabVIEW publishers
    ros::Publisher LabVIEW_RefAnglesPub;
    ros::Publisher LabVIEW_MeasuredAnglesPub;
    ros::Publisher LabVIEW_CollisionsPub;
    ros::Publisher LabVIEW_PushPointsPub;
    ros::Publisher LabVIEW_RobotPosePub;


    std::vector<double> deg2rad(const std::vector<double>& data);



public:
    Communication(ros::NodeHandle n);


};
