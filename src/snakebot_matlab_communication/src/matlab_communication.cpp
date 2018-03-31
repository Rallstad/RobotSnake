#include "matlab_communication.h"

Snake::Snake(ros::NodeHandle n){

	SGDataJoint1Sub = n.subscribe("from_matlab/SG_joint1", 10, &Snake::SGDataJoint1Callback, this);
	/*SGDataJoint2Sub = n.subscribe("from_matlab/SG_joint2", 100, &Snake::SGDataJoint2Callback, this);
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
	SGDataJoint13Sub = n.subscribe("from_matlab/SG_joint13", 100, &Snake::SGDataJoint13Callback, this);*/

}

Snake::~Snake(){}

void Snake::SGDataJoint1Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg){
	int fx, fy, fz, tx, ty, tz;
	fx = msg->data[0];
	fy = msg->data[1];
	fz = msg->data[2];
	tx = msg->data[3];
	ty = msg->data[4];
	tz = msg->data[5];
	int SGData [6] = {fx, fy, fz, tx, ty, tz};
	vector<int> SG;
	for(int i=0;i<6;i++){
		SG.push_back(SGData[i]);
	}
	Joint joint(SG,1);
	if(jointAddedToSnake(1)){
		for(int i = 0;i<6;i++){
			this->snakeJoints[1] = SG;
		}
	}
	else{
		std::map<int,Joint>::iterator it = this->snakeJoints.begin();
		
		//this->snakeJoints.insert(std::pair<int,Joint>(1,Joint(SG,1)));
	}
	//cout<<"message received";
	//cout<<msg->data[0];

}

bool Snake::jointAddedToSnake(int jointNum){
	std::map<int,Joint>::iterator it;
	it = this->snakeJoints.find(jointNum);
	if(it!=this->snakeJoints.end()){
		cout<<"jada";
			return true;
	}
	
	return false;
}