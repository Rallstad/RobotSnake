#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>

#include "ros/ros.h"
#include "std_msgs/UInt16MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include <snakebot_kinematics/kinematics.h>
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"
#include <snakebot_matlab_communication/collision.h>
#include <snakebot_matlab_communication/collisionList.h>



using std::cout;
using std::endl;

using namespace std;

class Snake{
private:
	geometry_msgs::Pose2D jointPoses [13];
	float SGData [13];
	float linkWidth = 0.07;

	ros::Subscriber SGDataJointSub;
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

	ros::Subscriber SnakePoseSub;
	
	ros::Publisher SGPub;
	ros::Publisher CollisionListPub;
	

public:
	Snake(ros::NodeHandle n);
	~Snake();


	void SGDataJointCallback(const std_msgs::Float32MultiArray::ConstPtr &msg);
	void SGDataJoint2Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint3Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint4Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint5Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint6Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint7Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint8Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint9Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint10Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint11Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint12Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint13Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);

	
	void SnakePoseCallback(const snakebot_kinematics::kinematics::ConstPtr& msg);

	void publishCollisions();

	string getContactSide(float contactForce);
	geometry_msgs::Vector3 getContactNormal(string contactSide, float jointAngle);
	geometry_msgs::Vector3 getContactTangent(string contactSide, float jointAngle);
	geometry_msgs::Point getContactPosition(string contactSide, geometry_msgs::Pose2D jointPose);
};