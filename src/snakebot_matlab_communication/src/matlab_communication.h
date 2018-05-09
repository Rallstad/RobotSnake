#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>

#include "ros/ros.h"
#include "std_msgs/UInt16MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"
#include <snakebot_matlab_communication/closestJoints.h>
#include <snakebot_kinematics/kinematics.h>
#include <snakebot_visual_data_topic_collector/obstacles.h>
#include <snakebot_matlab_communication/collision.h>
#include <snakebot_matlab_communication/collisionList.h>



using std::cout;
using std::endl;

using namespace std;

class Snake{
private:

	int closestJoints[3];
    std::vector<std::string> contactSides;
	geometry_msgs::Pose2D jointPoses [13];
    geometry_msgs::Pose2D obstacles[3];

    std::vector<int>  obstacle1;
    std::vector<int>  obstacle2;
    std::vector<int>  obstacle3;

    bool initialSGRead;
    int SGZeroForceY [13];
	int SGDataForceY [13];
	float linkWidth = 0.07;

	ros::Subscriber SGDataJointSub;
	ros::Subscriber SGDataJoint2Sub;
	ros::Subscriber SGDataJoint3Sub;
	ros::Subscriber SGDataJoint4Sub;
	ros::Subscriber SGDataJoint5Sub;
	ros::Subscriber SGDataJoint6Sub;
	ros::Subscriber SGDataJoint7Sub;
	ros::Subscriber SGDataJoint8Sub;
	ros::Subscriber SGDataJoint9Sub;
	ros::Subscriber SGDataJoint10Sub;
	ros::Subscriber SGDataJoint11Sub;
	ros::Subscriber SGDataJoint12Sub;
	ros::Subscriber SGDataJoint13Sub;
	ros::Subscriber obstacleSub;

	ros::Subscriber SnakePoseSub;
	ros::Subscriber propulsionSub;
	
	ros::Publisher SGPub;
	ros::Publisher CollisionListPub;
	ros::Publisher closestJointsPub;
	ros::Publisher propulsionPub;
	

public:
	Snake(ros::NodeHandle n);
	~Snake();


	void SGDataJointCallback(const std_msgs::Float32MultiArray::ConstPtr &msg);
	void SGDataJoint2Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint3Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint4Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint5Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint6Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint7Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint8Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint9Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint10Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint11Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint12Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);
	void SGDataJoint13Callback(const std_msgs::UInt16MultiArray::ConstPtr &msg);

	
	void SnakePoseCallback(const snakebot_kinematics::kinematics::ConstPtr& msg);
	void propulsionCallback(const std_msgs::Float64MultiArray::ConstPtr& msg);

	void publishCollisions();
	void publishJointCandidates();
	void getClosestJoint();
	float getJointDistance2Obstacle(int joint, int obstacle);
	void obstacleCallback(const snakebot_visual_data_topic_collector::obstacles::ConstPtr& msg);
	void findPossibleCollisions();
	bool bestCollisionCandidate(int jointNum, int obstacle_num);

	string getContactSide(int jointNum);
	geometry_msgs::Vector3 getContactNormal(string contactSide, float jointAngle);
	geometry_msgs::Vector3 getContactTangent(string contactSide, float jointAngle);
	geometry_msgs::Point getContactPosition(string contactSide, geometry_msgs::Pose2D jointPose);
};