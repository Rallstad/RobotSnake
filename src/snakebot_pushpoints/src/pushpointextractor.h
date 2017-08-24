#pragma once

#include <vector>
#include <sstream>
#include "ros/ros.h"
#include "ros/time.h"
#include "snakebot_collisions/SnakeContacts.h"
#include "snakebot_pushpoints/Pushpoints.h"

using std::cout;
using std::endl;


class PushpointExtractor{
private:
    ros::NodeHandle n;
    ros::Subscriber snakeContactsSub;
    ros::Publisher pushPointPub;

    ros::Publisher LabVIEW_PushPointsPub;

    void snakeContactsCallback(const snakebot_collisions::SnakeContacts::ConstPtr& contactMsg);
    snakebot_pushpoints::Pushpoints extractPushpoints(const snakebot_collisions::SnakeContacts::ConstPtr& contactMsg);
    void publishPushPoints(snakebot_pushpoints::Pushpoints pushPointMsg);

    int numberOfLinks;
    bool threePushPointsFound;

public:
    PushpointExtractor(ros::NodeHandle n, int numberOfLinks);

};
