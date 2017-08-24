#pragma once

#include <vector>
#include <sstream>
#include "ros/ros.h"
#include "ros/time.h"
#include "gazebo_msgs/ContactsState.h"
#include "snakebot_collisions/SnakeContacts.h"
#include "snakebot_robot_pose/Pose.h"
#include "bumper.h"

using std::cout;
using std::endl;



class Collisions{
private:
    ros::NodeHandle n;
    std::vector<Bumper> bumpers;
    ros::Publisher obstacleContactsPub;

    ros::Publisher LabVIEW_CollisionsPub;

    ros::Subscriber robotPoseSub;
    void robotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr& msg);

    int numberOfLinks;

    std::string linkName;
    std::string collisionName;

public:
    Collisions(ros::NodeHandle nodeHandle, int numLinks);

    void sendContacts();
};


