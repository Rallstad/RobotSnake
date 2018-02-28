#include "kinematics.h"
#include <iostream>
#include <fstream>
using namespace std;

Snake::Snake(ros::NodeHandle n){
	link_length = 0.0885; //m
	measuredJointAnglesSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles",100,&Snake::anglesCallback,this);
	//headGroundPoseSub = n.subscribe("snake_tail/ground_pose", 100, &Snake::headGroundPoseCallback, this);
	jointPoseSub = n.subscribe("/snakebot/snakeJointPose/",100, &Snake::jointPoseCallback,this);
	snakeConfigurationPub = n.advertise<snakebot_kinematics::kinematics>("/snakebot/real_snake_pose",10);
}

Snake::~Snake(){}

void Snake::anglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg){
	
	for(int joint_num = 0; joint_num < msg->data.size();joint_num++){
		if(joint_num == 9 || joint_num == 11){
			jointAnglesBody[joint_num] = -msg->data[joint_num];
		}
		else{
			jointAnglesBody[joint_num] = msg->data[joint_num];
		}
	}

}

void Snake::jointPoseCallback(const snakebot_visual_data_topic_collector::visual_data_topic_collector::ConstPtr &msg){
	for(int i=0;i<4;i++){
		jointPoses[i*4].x = msg->jointposes[i].x;
		jointPoses[i*4].y = msg->jointposes[i].y;
		//jointPoses[i*4].theta = msg->jointposes[i].theta;
	}
	jointPoses[0].theta = -90;
	jointPoses[4].theta = 0;
	jointPoses[8].theta = -90;
	jointPoses[12].theta = 90;

}

/*void Snake::headGroundPoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointGroundPose[].x=msg->x;
	jointGroundPose.y=msg->y;
	jointGroundPose.theta=msg->theta;
}*/

void Snake::publishSnakeConfiguration(){
	//snakebot_kinematics::kinematics pose;
	geometry_msgs::Pose2D pose2d;
	snakebot_kinematics::kinematics positions;
	for(int joint_num = 1;joint_num<14;joint_num++){
		positions.number.push_back(joint_num);
		pose2d.x = jointPoses[joint_num-1].x;
		pose2d.y = jointPoses[joint_num-1].y;
		positions.pose.push_back(pose2d);
	}
	snakeConfigurationPub.publish(positions);


}

//geometry_msgs::Pose2D Snake::getHeadGroundPose(){
//	return headGroundPose;
//}

void Snake::writeJointPosesToFile(){

	ofstream jointWrite;
	jointWrite.open ("/home/snake/Documents/catkin_ws/data/jointPoses.csv",ios::app);
	for(int i=0;i<13;i++){

		jointWrite << jointPoses[i];
		cout<<"joint: "<<i<<jointPoses[i]<<endl;
	}
	jointWrite.close();

}




geometry_msgs::Pose2D Snake::getjointPose(int joint_num){
	return jointPoses[joint_num];
}

void Snake::calculateJointAnglesWorld(){

}

void Snake::calculateJointPosition(){
	float theta_sum = 0;

	for(int joint_num = 12; joint_num >= 0;joint_num--){
		if(joint_num == 12){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num);
			//cout<< "Joint: " <<joint_num << " X: " << headGroundPose.x << " Y: "<< headGroundPose.y <<endl;

			theta_sum = jointPose.theta;

			//Set head position, read from headGroundPose
			//Update theta_sum value, read from jointAngelsBody
			//theta_sum -= jointAnglesBody[joint_num];
			
			//cout << "Head: " << " X: " << jointPositions[joint_num-1].x << " Y: " << jointPositions[joint_num-1].y <<endl;
			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;

			//Calculate position of joint 11
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num-1];
			//Calculate position of joint 10, will be compared with result from joint 8
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);
			/*joint12List[1] == theta_sum;
			theta_sum += jointAnglesBody[joint_num-2];
			joint12List[0] == theta_sum;*/
		}

		else if (joint_num == 8){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			theta_sum = jointPose.theta + jointAnglesBody[joint_num];

			//Calculate position of joint 9
			jointPoses[joint_num+1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num+1];

			// Calculate mean of mid joint 10
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x + link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y + link_length*sin(theta_sum*M_PI/180))/2;

			theta_sum = jointPose.theta + jointAnglesBody[joint_num];

			// Calculate position of joint 7
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num-1];
			//Calculate position of joint 6, will be compared with result from joint 4
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);

			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}

		else if (joint_num == 4){

			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			theta_sum = jointPose.theta + jointAnglesBody[joint_num];

			//Calculate position of joint 5
			jointPoses[joint_num+1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num+1];

			// Calculate mean of mid joint 6
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x + link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y + link_length*sin(theta_sum*M_PI/180))/2;

			theta_sum = jointPose.theta + jointAnglesBody[joint_num];

			// Calculate position of joint 3
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num-1];
			//Calculate position of joint 2, will be compared with result from joint 0
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);

			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}

		else if (joint_num == 0){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			theta_sum = jointPose.theta + jointAnglesBody[joint_num+1];

			jointPoses[joint_num+1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num+2];

			// Calculate mean of mid joint 2
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x + link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y + link_length*sin(theta_sum*M_PI/180))/2;



			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}
	}
	cout<<"\n";
}