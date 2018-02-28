#pragma once

//#include <vector>
#include "geometry_msgs/Pose2D.h"
#include "snakebot_visual_data_topic_collector/visual_data_topic_collector.h"
#include "ros/ros.h"



class Topic_collector{
private:
	geometry_msgs::Pose2D jointPoses[4];

	ros::Subscriber joint12Sub;
	ros::Subscriber joint8Sub;
	ros::Subscriber joint4Sub;
	ros::Subscriber joint0Sub;
	ros::Publisher jointPosePub;
	void joint12Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint8Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint4Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint0Callback(const geometry_msgs::Pose2D::ConstPtr &msg);

public:
	void publishJointPose();

	Topic_collector(ros::NodeHandle n);
	~Topic_collector();
};