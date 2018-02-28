#include "visual_data_topic_collector.h"

Topic_collector::Topic_collector(ros::NodeHandle n){
	joint12Sub = n.subscribe("joint_12/ground_pose",100, &Topic_collector::joint12Callback, this);
	joint8Sub = n.subscribe("joint_8/ground_pose",100, &Topic_collector::joint8Callback, this);
	joint4Sub = n.subscribe("joint_4/ground_pose",100, &Topic_collector::joint4Callback, this);
	joint0Sub = n.subscribe("joint_0/ground_pose",100, &Topic_collector::joint0Callback, this);

	//jointPosePub = n.advertise<snakebot_visual_data_topic_collector::visual_data_topic_collector>("/test",10);
	jointPosePub = n.advertise<snakebot_visual_data_topic_collector::visual_data_topic_collector>("/snakebot/snakeJointPose",100);
}

Topic_collector::~Topic_collector(){}

void Topic_collector::joint12Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[0].x = msg->x;
	jointPoses[0].y = msg->y;
	jointPoses[0].theta = msg->theta;
}

void Topic_collector::joint8Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[1].x = msg->x;
	jointPoses[1].y = msg->y;
	jointPoses[1].theta = msg->theta;
}

void Topic_collector::joint4Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[2].x = msg->x;
	jointPoses[2].y = msg->y;
	jointPoses[2].theta = msg->theta;
}

void Topic_collector::joint0Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[3].x = msg->x;
	jointPoses[3].y = msg->y;
	jointPoses[3].theta = msg->theta;
}

/*geometry_msgs::Pose2D Topic_collector::getJoint12Pose(){
	return jointPoses[0];
}*/



void Topic_collector::publishJointPose(){
	geometry_msgs::Pose2D pose2d;
	snakebot_visual_data_topic_collector::visual_data_topic_collector msg;
	for(int i=3;i>=0;i--){
		pose2d.x = jointPoses[i].x;
		pose2d.y = jointPoses[i].y;
		pose2d.theta = jointPoses[i].theta;		
		msg.jointposes.push_back(pose2d);
	}
	jointPosePub.publish(msg);
}