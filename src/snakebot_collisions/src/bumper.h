#pragma once

#include "geometry.h"
#include "ros/ros.h"
#include "ros/time.h"
#include "gazebo_msgs/ContactsState.h"
#include "snakebot_collisions/LinkContacts.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

class Bumper{
private:
    ros::Subscriber bumperSub;
    void bumperCallback(const gazebo_msgs::ContactsState::ConstPtr& msg);
    ros::NodeHandle n;

    //ContactData contacts;
    int link;

    snakebot_collisions::LinkContacts contacts;

    std::string linkName;
    std::string collisionName;
    Pose2d pose;

    int messageSequenceId;
    ros::Time messageTime;

    //ContactData newContactData(int state, int contact);
    void addContactData(int state, int contact, const gazebo_msgs::ContactsState::ConstPtr &msg);
    void clearContactData();
public:
    //void bumperCallback(const gazebo_msgs::ContactsState::ConstPtr& msg);
    Bumper(int link, ros::NodeHandle n);
    Bumper(const Bumper &obj);
    Bumper();
    //~Bumper();
    snakebot_collisions::LinkContacts getContacts();
    void setMessageHeader();

    void printOutputMessage();
    Pose2d getPose();
    void setPose(Pose2d pose);
    std::string getLinkName();
};
