#pragma once

#include <vector>
#include <sstream>
#include "ros/ros.h"
#include "ros/time.h"
#include "snakebot_collisions/SnakeContacts.h"
#include "snakebot_pushpoints/Pushpoints.h"
#include "std_msgs/Float32MultiArray.h"
#include "snakebot_matlab_communication/collisionList.h"

using std::cout;
using std::endl;


class PushpointExtractor{
private:
    ros::NodeHandle n;
    ros::Subscriber snakeContactsSub;
    ros::Subscriber SGSub;
    ros::Subscriber snakeContactsMatlabSub;
    ros::Publisher pushPointPub;

    ros::Publisher LabVIEW_PushPointsPub;

    void snakeContactsCallback(const snakebot_matlab_communication::collisionList::ConstPtr& contactMsg);
    snakebot_pushpoints::Pushpoints extractPushpoints(const snakebot_matlab_communication::collisionList::ConstPtr& contactMsg);
    void mambaExtractPushPoints(const std_msgs::Float32MultiArray::ConstPtr& sgMsg);
    void publishPushPoints(snakebot_pushpoints::Pushpoints pushPointMsg);

    int numberOfLinks;
    bool threePushPointsFound;

public:
    PushpointExtractor(ros::NodeHandle n, int numberOfLinks);

};
