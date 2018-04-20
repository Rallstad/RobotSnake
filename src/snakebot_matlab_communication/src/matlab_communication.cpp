#include "matlab_communication.h"

Snake::Snake(ros::NodeHandle n){

	SGDataJointSub = n.subscribe("from_matlab/SG", 10, &Snake::SGDataJointCallback, this);
	SnakePoseSub = n.subscribe("/snakebot/real_snake_pose", 10, &Snake::SnakePoseCallback, this);
	//SGPub = n.advertise()
	//CollisionPub = n.advertise...
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
	CollisionListPub = n.advertise<snakebot_matlab_communication::collisionList>("/snakebot/collisionsFromMatlab",10);

	
}

Snake::~Snake(){}

void Snake::SGDataJointCallback(const std_msgs::Float32MultiArray::ConstPtr &msg){
	for(int jointNum = 0;jointNum<msg->data.size();jointNum++){
		this->SGData[jointNum] = msg->data[jointNum];
	}
}

void Snake::SnakePoseCallback(const snakebot_kinematics::kinematics::ConstPtr& msg){
	for(int jointNum = 0;jointNum<msg->pose.size();jointNum++){
		this->jointPoses[jointNum].x = msg->pose[jointNum].x;
		this->jointPoses[jointNum].y = msg->pose[jointNum].y;
		this->jointPoses[jointNum].theta = msg->pose[jointNum].theta;
	}
}

void Snake::publishCollisions(){
	//Because of how the pushpointextractor finds pushpoints, the order of the joints has to be reversed
	snakebot_matlab_communication::collision msg;
	snakebot_matlab_communication::collisionList list;
	for(int jointNum = 0; jointNum <12; jointNum++){
		
		msg.link = jointNum;
		msg.contact_sides.push_back(getContactSide(SGData[jointNum]));
		msg.contact_normals.push_back(getContactNormal(getContactSide(SGData[jointNum]),jointPoses[jointNum].theta));
		msg.contact_tangents.push_back(getContactTangent(getContactSide(SGData[jointNum]), jointPoses[jointNum].theta));
		msg.contact_positions.push_back(getContactPosition(getContactSide(SGData[jointNum]), jointPoses[jointNum]));
		list.link.push_back(msg);
	}
	CollisionListPub.publish(list);
	//CollisionPub.pub(msg);
}

string Snake::getContactSide(float contactForce){
	if(contactForce > 0.5){
		return "left";
	}
	else if(contactForce < -0.5){
		return "right";
	}
	else{
		return "none";
	}
}

geometry_msgs::Vector3 Snake::getContactNormal(string contactSide, float jointAngle){
	geometry_msgs::Vector3 normal;
	if(contactSide == "left"){
		normal.x = cos((jointAngle*M_PI/180)-M_PI/2);
		normal.y = sin((jointAngle*M_PI/180)-M_PI/2);
		normal.z = 0.0;
	}
	else if(contactSide == "right"){
		normal.x = cos((jointAngle*M_PI/180)+M_PI/2);
		normal.y = sin((jointAngle*M_PI/180)+M_PI/2);
		normal.z = 0.0;
	}
	else if(contactSide == "none"){
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
	}
	return normal;
}

geometry_msgs::Vector3 Snake::getContactTangent(string contactSide, float jointAngle){
	geometry_msgs::Vector3 tangent;

	if(contactSide == "none"){
		tangent.x = 0;
		tangent.y = 0;
		tangent.z = 0;
	}
	else{
		tangent.x = cos(jointAngle*M_PI/180);
		tangent.y = sin(jointAngle*M_PI/180);
		tangent.z = 0;
	}
	return tangent;
}

geometry_msgs::Point Snake::getContactPosition(string contactSide, geometry_msgs::Pose2D jointPose){
	geometry_msgs::Point contactpos;

	if(contactSide == "left"){
		contactpos.x = jointPose.x-(0.5*linkWidth*sin(jointPose.theta));
		contactpos.y = jointPose.y+(0.5*linkWidth*cos(jointPose.theta));
		contactpos.z = 0.0;
	}
	else if(contactSide == "right"){
		contactpos.x = jointPose.x+(0.5*linkWidth*sin(jointPose.theta));
		contactpos.y = jointPose.y-(0.5*linkWidth*cos(jointPose.theta));
		contactpos.z = 0.0;
	}
	else if(contactSide == "none"){
		contactpos.x = 0.0;
		contactpos.y = 0.0;
		contactpos.z = 0.0;	
	}
	return contactpos;
}
