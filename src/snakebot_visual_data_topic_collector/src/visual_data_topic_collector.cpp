#include "visual_data_topic_collector.h"
using namespace std;

Topic_collector::Topic_collector(ros::NodeHandle n){
	joint12Sub = n.subscribe("joint_12/ground_pose",100, &Topic_collector::joint12Callback, this);
	joint11Sub = n.subscribe("joint_11/ground_pose",100, &Topic_collector::joint11Callback, this);
	joint10Sub = n.subscribe("joint_10/ground_pose",100, &Topic_collector::joint10Callback, this);
	joint9Sub = n.subscribe("joint_9/ground_pose",100, &Topic_collector::joint9Callback, this);
	joint8Sub = n.subscribe("joint_8/ground_pose",100, &Topic_collector::joint8Callback, this);
	joint7Sub = n.subscribe("joint_7/ground_pose",100, &Topic_collector::joint7Callback, this);
	joint6Sub = n.subscribe("joint_6/ground_pose",100, &Topic_collector::joint6Callback, this);
	joint5Sub = n.subscribe("joint_5/ground_pose",100, &Topic_collector::joint5Callback, this);
	joint4Sub = n.subscribe("joint_4/ground_pose",100, &Topic_collector::joint4Callback, this);
	joint3Sub = n.subscribe("joint_3/ground_pose",100, &Topic_collector::joint3Callback, this);
	joint2Sub = n.subscribe("joint_2/ground_pose",100, &Topic_collector::joint2Callback, this);
	joint1Sub = n.subscribe("joint_1/ground_pose",100, &Topic_collector::joint1Callback, this);
	joint0Sub = n.subscribe("joint_0/ground_pose",100, &Topic_collector::joint0Callback, this);
	obstacle1Sub = n.subscribe("obstacle_1/ground_pose", 100, &Topic_collector::obstacle1Callback, this);
	obstacle2Sub = n.subscribe("obstacle_2/ground_pose", 100, &Topic_collector::obstacle2Callback, this);
	obstacle3Sub = n.subscribe("obstacle_3/ground_pose", 100, &Topic_collector::obstacle3Callback, this);


	//jointPosePub = n.advertise<snakebot_visual_data_topic_collector::visual_data_topic_collector>("/test",10);
	jointPosePub = n.advertise<snakebot_visual_data_topic_collector::jointposes>("/snakebot/visualSnakeJointPose",100);
	obstaclePub = n.advertise<snakebot_visual_data_topic_collector::obstacles>("/snakebot/obstaclePosition",100);




	jointPose1Init = false;
	jointPose2Init = false;
	jointPose3Init = false;
	jointPose4Init = false;
	jointPose5Init = false;
	jointPose6Init = false;
	jointPose7Init = false;
	jointPose8Init = false;
	jointPose9Init = false;
	jointPose10Init = false;
	jointPose11Init = false;
	jointPose12Init = false;
	jointPose13Init = false;

}

Topic_collector::~Topic_collector(){}


void Topic_collector::joint12Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[12].x = msg->x;
	jointPoses[12].y = msg->y;
	jointPosesPrev[12].theta = msg->theta;
	if((!(abs(jointPosesPrev[12].theta - jointPoses[12].theta) > 30)) || jointPose12Init == false){
		jointPoses[12].theta = msg->theta;
		jointPose12Init = true;
	}

	cout << "jointPoses[12]: " << jointPoses[12] << "jointPosesPrev[12]: " << jointPosesPrev[12] << endl;

}

void Topic_collector::joint11Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[11].x = msg->x;
	jointPoses[11].y = msg->y;
	jointPosesPrev[11].theta = msg->theta;
	if((!(abs(jointPosesPrev[11].theta - jointPoses[11].theta) > 30)) || jointPose11Init == false){
		jointPoses[11].theta = msg->theta;
		jointPose11Init = true;
	}
	cout << "jointPoses[11]: " << jointPoses[11] << "jointPosesPrev[11]: " << jointPosesPrev[11] << endl;

}


void Topic_collector::joint10Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[10].x = msg->x;
	jointPoses[10].y = msg->y;
	jointPosesPrev[10].theta = msg->theta;
	if((!(abs(jointPosesPrev[10].theta - jointPoses[10].theta) > 30)) || jointPose10Init == false){
		jointPoses[10].theta = msg->theta;
		jointPose10Init = true;
	}
	cout << "jointPoses[10]: " << jointPoses[10] << "jointPosesPrev[10]: " << jointPosesPrev[10] << endl;

}

void Topic_collector::joint9Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[9].x = msg->x;
	jointPoses[9].y = msg->y;
	jointPosesPrev[9].theta = msg->theta;
	if((!(abs(jointPosesPrev[9].theta - jointPoses[9].theta) > 30)) || jointPose9Init == false){
		jointPoses[9].theta = msg->theta;
		jointPose9Init = true;
	}
	cout << "jointPoses[9]: " << jointPoses[9] << "jointPosesPrev[9]: " << jointPosesPrev[9] << endl;

}

void Topic_collector::joint8Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[8].x = msg->x;
	jointPoses[8].y = msg->y;
	jointPosesPrev[8].theta = msg->theta;
	if((!(abs(jointPosesPrev[8].theta - jointPoses[8].theta) > 30)) || jointPose8Init == false){
		jointPoses[8].theta = msg->theta;
		jointPose8Init = true;
	}
	cout << "jointPoses[8]: " << jointPoses[8] << "jointPosesPrev[8]: " << jointPosesPrev[8] << endl;
}

void Topic_collector::joint7Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[7].x = msg->x;
	jointPoses[7].y = msg->y;
	jointPosesPrev[7].theta = msg->theta;
	if((!(abs(jointPosesPrev[7].theta - jointPoses[7].theta) > 30)) || jointPose7Init == false){
		jointPoses[7].theta = msg->theta;
		jointPose7Init = true;
	}
	cout << "jointPoses[7]: " << jointPoses[7] << "jointPosesPrev[7]: " << jointPosesPrev[7] << endl;

}

void Topic_collector::joint6Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[6].x = msg->x;
	jointPoses[6].y = msg->y;
	jointPosesPrev[6].theta = msg->theta;
	if((!(abs(jointPosesPrev[6].theta - jointPoses[6].theta) > 30)) || jointPose6Init == false){
		jointPoses[6].theta = msg->theta;
		jointPose6Init = true;
	}
	cout << "jointPoses[6]: " << jointPoses[6] << "jointPosesPrev[6]: " << jointPosesPrev[6] << endl;

}

void Topic_collector::joint5Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[5].x = msg->x;
	jointPoses[5].y = msg->y;
	jointPosesPrev[5].theta = msg->theta;
	if((!(abs(jointPosesPrev[5].theta - jointPoses[5].theta) > 30)) || jointPose5Init == false){
		jointPoses[5].theta = msg->theta;
		jointPose5Init = true;
	}
	cout << "jointPoses[5]: " << jointPoses[5] << "jointPosesPrev[5]: " << jointPosesPrev[5] << endl;

}

void Topic_collector::joint4Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[4].x = msg->x;
	jointPoses[4].y = msg->y;
	jointPosesPrev[4].theta = msg->theta;
	if((!(abs(jointPosesPrev[4].theta - jointPoses[4].theta) > 30)) || jointPose4Init == false){
		jointPoses[4].theta = msg->theta;
		jointPose4Init = true;
	}
	cout << "jointPoses[4]: " << jointPoses[4] << "jointPosesPrev[4]: " << jointPosesPrev[4] << endl;

}

void Topic_collector::joint3Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[3].x = msg->x;
	jointPoses[3].y = msg->y;
	jointPosesPrev[3].theta = msg->theta;
	if((!(abs(jointPosesPrev[3].theta - jointPoses[3].theta) > 30)) || jointPose3Init == false){
		jointPoses[3].theta = msg->theta;
		jointPose3Init = true;
	}
	cout << "jointPoses[3]: " << jointPoses[3] << "jointPosesPrev[3]: " << jointPosesPrev[3] << endl;

}


void Topic_collector::joint2Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[2].x = msg->x;
	jointPoses[2].y = msg->y;
	jointPosesPrev[2].theta = msg->theta;
	if((!(abs(jointPosesPrev[2].theta - jointPoses[2].theta) > 30)) || jointPose2Init == false){
		jointPoses[2].theta = msg->theta;
		jointPose2Init = true;
	}
	cout << "jointPoses[2]: " << jointPoses[2] << "jointPosesPrev[2]: " << jointPosesPrev[2] << endl;

}

void Topic_collector::joint1Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[1].x = msg->x;
	jointPoses[1].y = msg->y;
	jointPosesPrev[1].theta = msg->theta;
	if((!(abs(jointPosesPrev[1].theta - jointPoses[1].theta) > 30)) || jointPose1Init == false){
		jointPoses[1].theta = msg->theta;
		jointPose1Init = true;
	}
	cout << "jointPoses[1]: " << jointPoses[1] << "jointPosesPrev[1]: " << jointPosesPrev[1] << endl;

}

void Topic_collector::joint0Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	jointPoses[0].x = msg->x;
	jointPoses[0].y = msg->y;
	jointPosesPrev[0].theta = msg->theta;
	if((!(abs(jointPosesPrev[0].theta - jointPoses[0].theta) > 30)) || jointPose0Init == false){
		jointPoses[0].theta = msg->theta;
		jointPose0Init = true;
	}
	cout << "jointPoses[0]: " << jointPoses[0] << "jointPosesPrev[0]: " << jointPosesPrev[0] << endl;

}

void Topic_collector::obstacle1Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	obstacles[0].x = msg->x;
	obstacles[0].y = msg->y;
}

void Topic_collector::obstacle2Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	obstacles[1].x = msg->x;
	obstacles[1].y = msg->y;
}

void Topic_collector::obstacle3Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	obstacles[2].x = msg->x;
	obstacles[2].y = msg->y;
}



void Topic_collector::publishJointPose(){
	geometry_msgs::Pose2D pose2d;
	snakebot_visual_data_topic_collector::jointposes msg;
	for(int i=0;i<=12;i++){
		pose2d.x = jointPoses[i].x;
		pose2d.y = jointPoses[i].y;
		pose2d.theta = jointPoses[i].theta;		
		msg.jointposes.push_back(pose2d);
	}
	jointPosePub.publish(msg);
}


void Topic_collector::publishObstacles(){
	geometry_msgs::Pose2D pose2d;
	snakebot_visual_data_topic_collector::obstacles msg;
	for(int i=0;i<=2;i++){
		pose2d.x = obstacles[i].x;
		pose2d.y = obstacles[i].y;
		msg.obstacles.push_back(pose2d);
	}
	obstaclePub.publish(msg);
}



