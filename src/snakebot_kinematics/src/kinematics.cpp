#include "kinematics.h"
#include <iostream>
#include <fstream>
using namespace std;

Snake::Snake(ros::NodeHandle n){
	link_length = 0.0885; //m
	measuredJointAnglesSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles",100,&Snake::anglesCallback,this);
	//headGroundPoseSub = n.subscribe("snake_tail/ground_pose", 100, &Snake::headGroundPoseCallback, this);
	jointPoseSub = n.subscribe("/snakebot/snakeJointPose/",100, &Snake::jointPoseCallback,this);
	matlabTestSub = n.subscribe("/SG_data", 100, &Snake::matlabCallback,this);
	snakeConfigurationPub = n.advertise<snakebot_kinematics::kinematics>("/snakebot/real_snake_pose",10);
	snakeJointPosePub = n.advertise<visualization_msgs::MarkerArray>("/snakebot/real_snake_joint_pose",10);
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

void Snake::jointPoseCallback(const snakebot_visual_data_topic_collector::visual_data_topic_collector::ConstPtr &msg){
	for(int i=0;i<4;i++){
		jointPoses[i*4].x = msg->jointposes[i*4].x;
		jointPoses[i*4].y = msg->jointposes[i*4].y;
		jointPoses[i*4].theta = msg->jointposes[i*4].theta;
	}
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
	for(int joint_num = 1;joint_num <= 13;joint_num++){
		positions.number.push_back(joint_num);
		pose2d.x = jointPoses[joint_num-1].x;
		pose2d.y = jointPoses[joint_num-1].y;
		positions.pose.push_back(pose2d);
	} 
	snakeConfigurationPub.publish(positions);
}

void Snake::publishKinematicsSnakeJointPose(){
	visualization_msgs::MarkerArray markerarray;
	visualization_msgs::Marker marker;
	for(int joint_num = 1; joint_num <= 13; joint_num++){
		marker.header.frame_id = "dummy_link";
	    marker.header.stamp = ros::Time();
	    marker.ns = "my_namespace";
	    marker.id = joint_num;
	    marker.type = visualization_msgs::Marker::CUBE;
	    marker.action = visualization_msgs::Marker::ADD;
	    marker.pose.position.x = jointPoses[joint_num-1].x;
	    marker.pose.position.y = jointPoses[joint_num-1].y;
	    marker.pose.position.z = 0;
	    marker.pose.orientation.x = 0.0;
	    marker.pose.orientation.y = 0.0;
	    marker.pose.orientation.z = 0.0;
	    marker.pose.orientation.w = 1.0;
	    marker.scale.x = 0.0885;
	    marker.scale.y = 0.07;
	    marker.scale.z = 0.07;
	    marker.color.a = 1.0; // Don't forget to set the alpha!
	    marker.color.r = 0.0;
	    marker.color.g = 1.0;
	    marker.color.b = 0.0;
	    markerarray.markers.push_back(marker);



	}
    //only if using a MESH_RESOURCE marker type:
        snakeJointPosePub.publish( markerarray );
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

void Snake::calculateJointAnglesWorld(){

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
			jointPoses[joint_num-1].theta = theta_sum;

			theta_sum += jointAnglesBody[joint_num-1];
			//cout <<"theta 1: "<<theta_sum<<endl;
			//Calculate position of joint 10, will be compared with result from joint 8
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num-2].theta = theta_sum;
			//cout<< "Joint: " <<joint_num << " X: " << jointPoses[joint_num].x << " Y: "<< jointPoses[joint_num].y <<endl;
		}

		else if (joint_num == 8){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			
			theta_sum = jointPose.theta - jointAnglesBody[joint_num];

			//Calculate position of joint 9
			//cout << theta_sum <<endl;
			jointPoses[joint_num+1].x = jointPose.x - link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y - link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num+1].theta = theta_sum;

			theta_sum -= jointAnglesBody[joint_num+1];
			//cout <<"theta 2: "<<theta_sum<<endl;
			// Calculate mean of mid joint 10
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x - link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y - link_length*sin(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].theta = theta_sum;

			theta_sum = jointPose.theta;
			//cout <<"theta 3: "<<theta_sum<<endl;
			// Calculate position of joint 7
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num-1].theta = theta_sum;

			theta_sum += jointAnglesBody[joint_num-1];
			//cout <<"theta 4: "<<theta_sum<<endl;
			//Calculate position of joint 6, will be compared with result from joint 4
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num-2].theta = theta_sum;

			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}

		else if (joint_num == 4){

			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			theta_sum = jointPose.theta - jointAnglesBody[joint_num];

			//Calculate position of joint 5
			jointPoses[joint_num+1].x = jointPose.x - link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y - link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num+1].theta = theta_sum;

			theta_sum -= jointAnglesBody[joint_num+1];
			//cout <<"theta 5: "<<theta_sum<<endl;
			// Calculate mean of mid joint 6
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x - link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y - link_length*sin(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].theta = theta_sum;

			theta_sum = jointPose.theta;
			//cout <<"theta 6: "<<theta_sum<<endl;
			// Calculate position of joint 3
			jointPoses[joint_num-1].x = jointPose.x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-1].y = jointPose.y + link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num-1].theta = theta_sum;

			theta_sum += jointAnglesBody[joint_num-1];
			//cout <<"theta 7: "<<theta_sum<<endl;
			//Calculate position of joint 2, will be compared with result from joint 0
			jointPoses[joint_num-2].x = jointPoses[joint_num-1].x + link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num-2].y = jointPoses[joint_num-1].y + link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num-2].theta = theta_sum;

			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}

		else if (joint_num == 0){
			geometry_msgs::Pose2D jointPose = getjointPose(joint_num); 
			//cout<<"jointpose.theta = "<<jointPose.theta<<endl;
			theta_sum = jointPose.theta - jointAnglesBody[joint_num+1];
			//cout<<"theta_sum 0: "<< theta_sum<<endl;
			jointPoses[joint_num+1].x = jointPose.x - link_length*cos(theta_sum*M_PI/180);
			jointPoses[joint_num+1].y = jointPose.y - link_length*sin(theta_sum*M_PI/180);
			jointPoses[joint_num+1].theta = theta_sum;

			theta_sum -= jointAnglesBody[joint_num+2];
			//cout <<"theta 8: "<<theta_sum<<endl;

			// Calculate mean of mid joint 2
			jointPoses[joint_num+2].x = (jointPoses[joint_num+2].x + jointPoses[joint_num+1].x - link_length*cos(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].y = (jointPoses[joint_num+2].y + jointPoses[joint_num+1].y - link_length*sin(theta_sum*M_PI/180))/2;
			jointPoses[joint_num+2].theta = theta_sum;



			//cout<< "Joint: " <<joint_num << " X: " << jointPositions[joint_num].x << " Y: "<< jointPositions[joint_num].y <<endl;
		}
		//cout<< "Joint: " <<joint_num << " X: " << jointPoses[joint_num].x << " Y: "<< jointPoses[joint_num].y <<endl;
	}
	//cout<<"\n";
}