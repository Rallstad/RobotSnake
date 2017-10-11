#include "kinematics.h"

Snake::Snake(ros::NodeHandle n){
	link_length = 0.09; //m
	measuredJointAnglesSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles",100,&Snake::anglesCallback,this);
	snakeConfigurationPub = n.advertise<snakebot_kinematics::kinematics>("/snakebot/real_snake_pose",10);
}

Snake::~Snake(){}

void Snake::anglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg){
	
	for(int joint_num = 0; joint_num < msg->data.size();joint_num++){
		joints[joint_num] = msg->data[joint_num];
		cout<<joints[joint_num]<<endl;
	}
}

void Snake::publishSnakeConfiguration(){
	snakebot_kinematics::kinematics pose;
	//pose.number.push_back(1);
	snakeConfigurationPub.publish(pose);
}