#pragma once

//#include <vector>
#include "geometry_msgs/Pose2D.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "snakebot_visual_data_topic_collector/jointposes.h"
#include "snakebot_visual_data_topic_collector/obstacles.h"
#include "std_msgs/Float32MultiArray.h"
#include "ros/ros.h"



class Topic_collector{
private:
	geometry_msgs::Pose2D jointPoses[13];
	geometry_msgs::Pose2D jointPosesPrev[13];
	geometry_msgs::Pose2D obstacles[3];

	visualization_msgs::MarkerArray jointPose;
	visualization_msgs::MarkerArray obstacle;

	bool jointPose0Init;
	bool jointPose1Init;
	bool jointPose2Init;
	bool jointPose3Init;
	bool jointPose4Init;
	bool jointPose5Init;
	bool jointPose6Init;
	bool jointPose7Init;
	bool jointPose8Init;
	bool jointPose9Init;
	bool jointPose10Init;
	bool jointPose11Init;
	bool jointPose12Init;
	bool jointPose13Init;


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
	ros::Subscriber obstacle1Sub;
	ros::Subscriber obstacle2Sub;
	ros::Subscriber obstacle3Sub;

	ros::Publisher jointPosePub;
	ros::Publisher obstaclePub;

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
	void obstacle1Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void obstacle2Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void obstacle3Callback(const geometry_msgs::Pose2D::ConstPtr &msg);



public:
	void publishJointPose();
	void publishObstacles();


	Topic_collector(ros::NodeHandle n);
	~Topic_collector();
};