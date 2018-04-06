#pragma once

//#include <vector>
#include "geometry_msgs/Pose2D.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "snakebot_visual_data_topic_collector/visual_data_topic_collector.h"
#include "ros/ros.h"



class Topic_collector{
private:
	geometry_msgs::Pose2D jointPoses[13];
	geometry_msgs::Pose2D jointPosesPrev[13];
	visualization_msgs::MarkerArray jointPose;

	bool jointPosesInit = true;

	ros::Subscriber joint12Sub;
	ros::Subscriber joint11Sub;
	ros::Subscriber joint10Sub;
	ros::Subscriber joint9Sub;
	ros::Subscriber joint8Sub;
	ros::Subscriber joint7Sub;
	ros::Subscriber joint6Sub;
	ros::Subscriber joint5Sub;
	ros::Subscriber joint4Sub;
	ros::Subscriber joint3Sub;
	ros::Subscriber joint2Sub;
	ros::Subscriber joint1Sub;
	ros::Subscriber joint0Sub;

	ros::Publisher jointPosePub;
	ros:: Publisher RvizPub;

	void joint12Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint11Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint10Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint9Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint8Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint7Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint6Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint5Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint4Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint3Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint2Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint1Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint0Callback(const geometry_msgs::Pose2D::ConstPtr &msg);


public:
	void publishJointPose();
	void publishVisualSnakeJointPose();

	Topic_collector(ros::NodeHandle n);
	~Topic_collector();
};