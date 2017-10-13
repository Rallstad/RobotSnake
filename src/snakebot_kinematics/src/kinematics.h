#pragma once

#include <vector>
#include <math.h>
#include "std_msgs/Float64MultiArray.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Point.h"
#include "snakebot_kinematics/kinematics.h"
#include "snakebot_labview_communication/Float64Array.h"
#include "snakebot_labview_communication/Int32Array.h"
#include "ros/ros.h"

using std::cout;
using std::endl;

class Snake{
private:
	float link_length;
	float jointAnglesBody[13];
	float jointAnglesWorld[6];
	geometry_msgs::Pose2D headGroundPose;
	geometry_msgs::Point jointPositions[6];
	ros::Subscriber measuredJointAnglesSub;
	ros::Subscriber headGroundPoseSub;
	ros::Publisher snakeConfigurationPub;



	void anglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg);
	void headGroundPoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg);

public:
	void calculateJointAnglesWorld();
	void calculateJointPosition();
	void publishSnakeConfiguration();
	geometry_msgs::Pose2D getHeadGroundPose();
	Snake(ros::NodeHandle n);
	~Snake();
};