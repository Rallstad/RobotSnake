#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "ros/ros.h"


using std::cout;
using std::endl;


struct Joint{
	std::vector<double> SGData;
	jointID;
	Joint(std::vector<double> SG, int ID):SGData = SG,jointID(ID){}
}

class Snake{
private:
	std::vector<Joint> snakeJoints;

	ros::Subscriber SGDataJoint1Sub;
	ros::Subscriber SGDataJoint2Sub;
	ros::Subscriber SGDataJoint3Sub;
	ros::Subscriber SGDataJoint4Sub;
	ros::Subscriber SGDataJoint5Sub;
	ros::Subscriber SGDataJoint6Sub;
	ros::Subscriber SGDataJoint7Sub;
	ros::Subscriber SGDataJoint8Sub;
	ros::Subscriber SGDataJoint9Sub;
	ros::Subscriber SGDataJoint10Sub;
	ros::Subscriber SGDataJoint11Sub;
	ros::Subscriber SGDataJoint12Sub;
	ros::Subscriber SGDataJoint13Sub;
public:
	Snake(ros::NodeHandle n);
	~Snake();

	bool jointAddedToSnake(int jointNum);

	void SGDataJoint1Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint2Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint3Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint4Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint5Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint6Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint7Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint8Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint9Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint10Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint11Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint12Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);
	void SGDataJoint13Callback(const std_msgs::UInt16MultiArray ConstPtr &msg);

}