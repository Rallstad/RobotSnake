#include "matlab_communication.h"

void Snake::Snake(NodeHandle n){

	SGDataJoint1Sub = n.subscribe("from_matlab/SG_joint1", 100, &Snake::SGDataJoint1Callback, this);
	SGDataJoint2Sub = n.subscribe("from_matlab/SG_joint2", 100, &Snake::SGDataJoint2Callback, this);
	SGDataJoint3Sub = n.subscribe("from_matlab/SG_joint3", 100, &Snake::SGDataJoint3Callback, this);
	SGDataJoint4Sub = n.subscribe("from_matlab/SG_joint4", 100, &Snake::SGDataJoint4Callback, this);
	SGDataJoint5Sub = n.subscribe("from_matlab/SG_joint5", 100, &Snake::SGDataJoint5Callback, this);
	SGDataJoint6Sub = n.subscribe("from_matlab/SG_joint6", 100, &Snake::SGDataJoint6Callback, this);
	SGDataJoint7Sub = n.subscribe("from_matlab/SG_joint7", 100, &Snake::SGDataJoint7Callback, this);
	SGDataJoint8Sub = n.subscribe("from_matlab/SG_joint8", 100, &Snake::SGDataJoint8Callback, this);
	SGDataJoint9Sub = n.subscribe("from_matlab/SG_joint9", 100, &Snake::SGDataJoint9Callback, this);
	SGDataJoint10Sub = n.subscribe("from_matlab/SG_joint10", 100, &Snake::SGDataJoint10Callback, this);
	SGDataJoint11Sub = n.subscribe("from_matlab/SG_joint11", 100, &Snake::SGDataJoint11Callback, this);
	SGDataJoint12Sub = n.subscribe("from_matlab/SG_joint12", 100, &Snake::SGDataJoint12Callback, this);
	SGDataJoint13Sub = n.subscribe("from_matlab/SG_joint13", 100, &Snake::SGDataJoint13Callback, this);

}

void Snake::SGDataJoint1Callback(const std_msgs::UInt16MultiArray ConstPtr &msg){
	Joint(msg.Data,1) joint;
	snakeJoints.push_back(joint);
	//if()
}

bool snake::jointAddedToSnake(int jointNum){
	if(std::find(this->snakeJoints.begin(),this->snakeJoints.end(),jointNum)){
		cout<<"joint present"<<endl;
		return true;
	}
	cout<<"joint not present"<<endl;
	return false;
}