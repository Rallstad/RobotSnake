#pragma once

#include <vector>
#include <sstream>
#include <cmath>
#include <string>
#include <math.h>
#include "ros/ros.h"
#include "ros/time.h"
#include "geometry_msgs/Pose2D.h"
#include "snakebot_collisions/SnakeContacts.h"
#include "snakebot_pushpoints/Pushpoints.h"
#include "std_msgs/Float32MultiArray.h"
#include "snakebot_matlab_communication/collisionList.h"
#include "snakebot_kinematics/kinematics.h"
#include "snakebot_visual_data_topic_collector/obstacles.h"
using std::cout;
using std::endl;


class PushpointExtractor{
private:

    int numberOfLinks;
    bool threePushPointsFound;
    int jointCandidates[3];
    geometry_msgs::Pose2D jointPoses[13];
    geometry_msgs::Pose2D obstacles[3];
    std::vector<std::string> contactSides;

    ros::NodeHandle n;
    ros::Subscriber snakeContactsSub;
    ros::Subscriber snakeConfigurationSub;
    ros::Subscriber SGSub;
    ros::Subscriber snakeContactsMatlabSub;

    ros::Publisher pushPointPub;
    ros::Publisher pushpointCandidatesPub;
    ros::Publisher LabVIEW_PushPointsPub;

    void snakeContactsCallback(const snakebot_matlab_communication::collisionList::ConstPtr& contactMsg);

public:
    PushpointExtractor(ros::NodeHandle n, int numberOfLinks);

    snakebot_pushpoints::Pushpoints extractPushpoints(const snakebot_matlab_communication::collisionList::ConstPtr& contactMsg);
    void mambaExtractPushPoints(const std_msgs::Float32MultiArray::ConstPtr& sgMsg);
    void publishPushPoints(snakebot_pushpoints::Pushpoints pushPointMsg);



};

