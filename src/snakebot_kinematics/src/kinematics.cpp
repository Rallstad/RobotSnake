#include "kinematics.h"
#include <iostream>
#include <fstream>
using namespace std;

Snake::Snake(ros::NodeHandle n){
	link_length = 0.0885; //m
	measuredJointAnglesSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles",100,&Snake::anglesCallback,this);
	//headGroundPoseSub = n.subscribe("snake_tail/ground_pose", 100, &Snake::headGroundPoseCallback, this);
	jointPoseSub = n.subscribe("/snakebot/visualSnakeJointPose/",100, &Snake::jointPoseCallback,this);
	matlabTestSub = n.subscribe("/SG_data", 100, &Snake::matlabCallback,this);
	obstacleSub = n.subscribe("/snakebot/obstaclePosition",100, &Snake::obstacleCallback,this);

	snakeConfigurationPub = n.advertise<snakebot_kinematics::kinematics>("/snakebot/real_snake_pose",10);
	snakeObstaclePub = n.advertise<snakebot_kinematics::snake_obstacles>("snakebot/snake_obstacles",10);

	//snakeJointPosePub = n.advertise<visualization_msgs::MarkerArray>("/snakebot/real_snake_joint_pose",10);
}

Snake::~Snake(){}

void Snake::matlabCallback(const geometry_msgs::Point::ConstPtr &msg){
	//cout<< "X: " <<msg->x<<endl;
}

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

void Snake::jointPoseCallback(const snakebot_visual_data_topic_collector::jointposes::ConstPtr &msg){
	for(int i=0;i<=3;i++){
		jointPoses[i*4].x = msg->jointposes[i*4].x;
		jointPoses[i*4].y = msg->jointposes[i*4].y;
		jointPoses[i*4].theta = msg->jointposes[i*4].theta;
		//cout<<i<< ": x: " <<jointPoses[i*4].x<<" y: "<<jointPoses[i*4].y<<" theta: "<<jointPoses[i].theta<<endl;
	}
	for(int i=11;i>=0;i--){
		jointPoses[i].theta = jointPoses[i+1].theta + jointAnglesBody[i];
	}
}

void Snake::obstacleCallback(const snakebot_visual_data_topic_collector::obstacles::ConstPtr& msg){
	for(int i =0;i<msg->obstacles.size();i++){
		obstaclePoses[i].x = msg->obstacles[i].x;
		obstaclePoses[i].y = msg->obstacles[i].y;
		obstacleNumber[i] = i+1;
	}
}


void Snake::publishSnakeConfiguration(){
	//snakebot_kinematics::kinematics pose;
	geometry_msgs::Pose2D pose2d;
	snakebot_kinematics::kinematics positions;
	for(int joint_num = 12;joint_num >= 0;joint_num--){
		positions.number.push_back(joint_num);
		pose2d.x = jointPoses[joint_num].x;
		pose2d.y = jointPoses[joint_num].y;
		pose2d.theta = jointPoses[joint_num].theta;
		positions.pose.push_back(pose2d);
		//cout<<joint_num<< ": x: " <<pose2d.x<<" y: "<<pose2d.y<<" theta: "<<pose2d.theta<<endl;
	} 
	snakeConfigurationPub.publish(positions);
}

void Snake::publishSnakeObstaclePose(){
	geometry_msgs::Pose2D pose2d;
	snakebot_kinematics::kinematics positions;
	snakebot_kinematics::obstacles Obstacles;
	
	for(int joint_num = 12;joint_num >= 0;joint_num--){
		positions.number.push_back(joint_num);
		pose2d.x = jointPoses[joint_num].x;
		pose2d.y = jointPoses[joint_num].y;
		pose2d.theta = jointPoses[joint_num].theta;
		positions.pose.push_back(pose2d);
	}

	for(int i=0;i<5;i++){
        Obstacles.number.push_back(i+1);
        geometry_msgs::Pose2D pose;
        pose.x = obstaclePoses[i].x;
        pose.y = obstaclePoses[i].y;
        Obstacles.pose.push_back(pose);
	}
	
	snakebot_kinematics::snake_obstacles Snake_Obstacles;
	Snake_Obstacles.obstaclePose = Obstacles;
	Snake_Obstacles.snakePose = positions;
	snakeObstaclePub.publish(Snake_Obstacles);
}





//geometry_msgs::Pose2D Snake::getHeadGroundPose(){
//	return headGroundPose;
//}

void Snake::writeJointPosesToFile(){
	if(jointPoses[1].x !=-0.0885 && jointPoses[2].x != 0 && jointPoses[6].x!=0){
		ofstream jointWrite;
		jointWrite.open ("/home/snake/Documents/catkin_ws/data/jointPoses.csv",ios::app);
		for(int i=0;i<13;i++){

			jointWrite << jointPoses[0].x<<",";
			jointWrite << jointPoses[0].y <<"\n";
			
		}
		jointWrite.close();
	}

}



geometry_msgs::Pose2D Snake::getjointPose(int joint_num){
	return jointPoses[joint_num];
}


void Snake::calculateJointPosition(){
	float theta_sum = 0;

	for(int joint_num = 12; joint_num >= 0;joint_num--){
		if(joint_num == 12){

			geometry_msgs::Pose2D jointPose = getjointPose(joint_num);
			//cout<< "Joint: " <<joint_num << " X: " << headGroundPose.x << " Y: "<< headGroundPose.y <<endl;

			theta_sum = jointPose.theta;		
			//cout << "Head: " << " X: " << jointPositions[joint_num-1].x << " Y: " << jointPositions[joint_num-1].y <<endl;
			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;

			//Calculate position of joint 11
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num-1];
			//cout <<"theta 1: "<<theta_sum<<endl;
			//Calculate position of joint 10, will be compared with result from joint 8
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);
			//cout<< "Joint: " <<joint_num << " X: " << jointPoses[joint_num].x << " Y: "<< jointPoses[joint_num].y <<endl;
		}

		else if (joint_num == 8){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			
			theta_sum = jointPose.theta - jointAnglesBody[joint_num];

			//Calculate position of joint 9
			//cout << theta_sum <<endl;
			jointPoses[joint_num+1].x = jointPose.x - link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y - link_length*sin(theta_sum*M_PI/180);

			theta_sum -= jointAnglesBody[joint_num+1];

			//cout <<"theta 2: "<<theta_sum<<endl;
			// Calculate mean of mid joint 10
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x - link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y - link_length*sin(theta_sum*M_PI/180))/2;

			theta_sum = jointPose.theta;
			//cout <<"theta 3: "<<theta_sum<<endl;
			// Calculate position of joint 7
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);

			theta_sum += jointAnglesBody[joint_num-1];
			//cout <<"theta 4: "<<theta_sum<<endl;
			//Calculate position of joint 6, will be compared with result from joint 4
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);

			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}

		else if (joint_num == 4){

			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			theta_sum = jointPose.theta - jointAnglesBody[joint_num];

			//Calculate position of joint 5
			jointPoses[joint_num+1].x = jointPose.x - link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y - link_length*sin(theta_sum*M_PI/180);

			theta_sum -= jointAnglesBody[joint_num+1];
			//cout <<"theta 5: "<<theta_sum<<endl;
			// Calculate mean of mid joint 6
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x - link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y - link_length*sin(theta_sum*M_PI/180))/2;

			theta_sum = jointPose.theta;
			//cout <<"theta 6: "<<theta_sum<<endl;
			// Calculate position of joint 3
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);
			theta_sum += jointAnglesBody[joint_num-1];
			//cout <<"theta 7: "<<theta_sum<<endl;
			//Calculate position of joint 2, will be compared with result from joint 0
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);
			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}

		else if (joint_num == 0){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			//cout<<"jointpose.theta = "<<jointPose.theta<<endl;
			theta_sum = jointPose.theta - jointAnglesBody[joint_num];
			//cout<<"theta_sum 0: "<< theta_sum<<endl;
			jointPoses[joint_num+1].x = jointPose.x - link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y - link_length*sin(theta_sum*M_PI/180);

			theta_sum -= jointAnglesBody[joint_num+1];
			//cout <<"theta 8: "<<theta_sum<<endl;

			// Calculate mean of mid joint 2
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x - link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y - link_length*sin(theta_sum*M_PI/180))/2;

			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}
		//cout<< "Joint: " <<joint_num << " X: " << jointPoses[joint_num].x << " Y: "<< jointPoses[joint_num].y <<endl;
	}
	//cout<<"\n";
}