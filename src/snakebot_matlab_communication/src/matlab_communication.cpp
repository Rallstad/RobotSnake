#include "matlab_communication.h"

Snake::Snake(ros::NodeHandle n){

	SGDataJoint1Sub = n.subscribe("from_matlab/SG", 10, &Snake::SGDataJoint1Callback, this);
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

void Snake::SGDataJoint1Callback(const std_msgs::Float32MultiArray::ConstPtr &msg){

	int SGdata;
	vector<int> SG;
	if(jointAddedToSnake(1)){
		this->snakeJoints.erase(this->snakeJoints.begin(),this->snakeJoints.end());
	}
	for(int i=0;i<msg->data.size();i++){
		cout<<"joint: "<< i<<" "<<msg->data[i]<<endl;
		SGdata = msg->data[i];
		this->snakeJoints[1].push_back(SGdata);
	}
	cout<<endl;
}

bool Snake::jointAddedToSnake(int jointNum){
	std::map<int,vector<int>>::iterator it;
	it = this->snakeJoints.find(jointNum);
	if(it!=this->snakeJoints.end()){
		/*cout<<"jada"<<endl;
		cout<<it->second[0]<<endl;
		cout<<it->second[1]<<endl;
		cout<<it->second[2]<<endl;
		cout<<it->second[3]<<endl;
		cout<<it->second[4]<<endl;
		cout<<it->second[5]<<endl;*/
		
		return true;
	}
	
	return false;
}