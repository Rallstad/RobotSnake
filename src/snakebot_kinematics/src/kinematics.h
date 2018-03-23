#pragma once

#include <vector>
#include <math.h>
#include "std_msgs/Float64MultiArray.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Point.h"
#include "snakebot_kinematics/kinematics.h"
#include "snakebot_labview_communication/Float64Array.h"
#include "snakebot_labview_communication/Int32Array.h"
#include "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/src/visual_data_topic_collector.h"
#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

using std::cout;
using std::endl;

class Snake{
private:
	float link_length;
	float jointAnglesBody[13];
	float jointAnglesWorld[13];

	geometry_msgs::Pose2D jointPoses[13];
	ros::Subscriber measuredJointAnglesSub;
	ros::Subscriber headGroundPoseSub;
	ros::Subscriber jointPoseSub;

	ros::Subscriber matlabTestSub;

	ros::Publisher snakeConfigurationPub;

	void anglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg);
	void headGroundPoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void jointPoseCallback(const snakebot_visual_data_topic_collector::visual_data_topic_collector::ConstPtr &msg);
	void matlabCallback(const geometry_msgs::Point::ConstPtr &msg);

public:
	void calculateJointAnglesWorld();
	void calculateJointPosition();
	void publishSnakeConfiguration();
	void writeJointPosesToFile();
	//geometry_msgs::Pose2D getHeadGroundPose();
	geometry_msgs::Pose2D getjointPose(int joint_num);
	Snake(ros::NodeHandle n);
	~Snake();
};