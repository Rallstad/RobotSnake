#include "kinematics.h"

Snake::Snake(ros::NodeHandle n){
	link_length = 0.177; //m
	measuredJointAnglesSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles",100,&Snake::anglesCallback,this);
	headGroundPoseSub = n.subscribe("snake_head/ground_pose", 100, &Snake::headGroundPoseCallback, this);
	snakeConfigurationPub = n.advertise<snakebot_kinematics::kinematics>("/snakebot/real_snake_pose",10);
}

Snake::~Snake(){}

void Snake::anglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg){
	
	for(int joint_num = 0; joint_num < msg->data.size();joint_num++){
		jointAnglesBody[joint_num] = msg->data[joint_num];
	}
}

void Snake::headGroundPoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg){
	headGroundPose.x=msg->x;
	headGroundPose.y=msg->y;
	headGroundPose.theta=msg->theta;
}

void Snake::publishSnakeConfiguration(){
	snakebot_kinematics::kinematics pose;
	snakeConfigurationPub.publish(pose);
}

geometry_msgs::Pose2D Snake::getHeadGroundPose(){
	return headGroundPose;
}

void Snake::calculateJointAnglesWorld(){

}

void Snake::calculateJointPosition(){
	geometry_msgs::Pose2D headGroundPose = getHeadGroundPose();
	float theta_sum = 0;
	for(int joint_num = 0; joint_num<6;joint_num++){
		if(joint_num == 0){
			theta_sum = headGroundPose.theta;
			jointPositions[joint_num].x = headGroundPose.x -link_length*cos(theta_sum*M_PI/180);
			jointPositions[joint_num].y = headGroundPose.y -link_length*sin(theta_sum*M_PI/180);
		}
		else if(joint_num > 0){
			theta_sum-=jointAnglesBody[(joint_num*2)-1];
			jointPositions[joint_num].x = jointPositions[joint_num-1].x -link_length*cos(theta_sum*M_PI/180);
			jointPositions[joint_num].y = jointPositions[joint_num-1].y -link_length*sin(theta_sum*M_PI/180);
		}
		jointAnglesWorld[joint_num] = theta_sum;
		//cout << "Joint: " <<joint_num << "Theta: " << jointAnglesWorld[(joint_num-1)/2] <<endl;
		cout << "Theta_sum: " << theta_sum <<"\n"<<endl;
		cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		//cout<<"\n";
	}
	cout<<"\n";
}