#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <cmath>
#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Int8.h"
#include <snakebot_pushpoints/Pushpoints.h>
#include "snakebot_propulsion_control/PropulsionEffort.h"
using std::cout;
using std::endl;


struct Pose2D{
    double x;
    double y;
    double theta;
};

struct Vector3d{
    double x, y, z;
    Vector3d():x(0), y(0), z(0){}
    Vector3d(double xPos, double yPos, double zPos):x(xPos), y(yPos), z(zPos){}
};

struct Position3d{
    double x, y, z;
    Position3d():x(0), y(0), z(0){}
    Position3d(double xPos, double yPos, double zPos):x(xPos), y(yPos), z(zPos){}
};


//Subscribes to new data and publishes control input
class PropulsionController
{
private:
    //Flag for received data
    bool propForceReceived;
    bool obstacleDataInitialized;
    bool positionDataInitialized;

	//ROS specific
	ros::NodeHandle n;
    void obstacleDataCallback(const snakebot_pushpoints::Pushpoints::ConstPtr& msg);
//    void positionDataCallback(const snakebot_interface::State::ConstPtr& msg);
    void propulsionForceCallback(const std_msgs::Float64::ConstPtr& msg);
    ros::Subscriber obstacleDataSub;
    ros::Subscriber positionDataSub;
    ros::Subscriber propForceSub;
    ros::Publisher propulsionEffortPub;

    //Map from x,y,z,theta to array index
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;
	//Physical specfications:
	double totalMass;
    double linkLength;
    double linkWidth;
    double linkHeight;
    double linkToJointLength;
    //Number of links
    int numLinks;
    //Pose of links
    std::vector< Pose2D > linkPose2D;
    //Pose of joints
    std::vector< Pose2D > jointPose2D;
    //Index of link closest to propulsion obstacle
    int iPropLink;
	//Normal vectors at contact points:
    Vector3d n1;
    Vector3d n2;
    Vector3d n3;
	//Tangent vectors at contact points:
    Vector3d t1;
    Vector3d t2;
    Vector3d t3;
	//Position vector of contact points:
    Position3d c1;
    Position3d c2;
    Position3d c3;
    // The side the third contact point is on:
    std::string c3Side;
    //Vector from applied torque joint to third obstacle
    Vector3d r;
    //Time data
    ros::Time contactsCallbackTime;
    ros::Time contactsMsgDataTime;
    ros::Time propulsionForceCallbackTime;
    //Joint number (not index!) for torque control
    int torqueJoint;
	//Force magnitudes:
	double f1;
	double f2;
	double f3;
	double fs;
	//Desired velocity:
	std::vector<double> Vd;
	//Joint angles and Torque:
	std::vector<double> desiredJointAngles;
	std::vector<double> actualJointAngles;
    Vector3d desiredTorque;
    Vector3d actualTorque;
	//Subscribers
	ros::Subscriber contactPointDataSub;
    //Calculating force, torque etc.:
    void f3Fromfs();
    void desiredTorqueFromf3();
    void fsFromVd();
    void setTorqueJoint();
    void publishTorque();

//    bool ContactsDataUsable(const snakebot_interface::Contacts::ConstPtr& msg);
//    bool StateDataUsable(const snakebot_interface::State::ConstPtr& msg);

    //Vector algebra:
    double det(Vector3d v1, Vector3d v2);
    double det(Position3d v1, Vector3d v2);
    double determinant(double a, double b, double c, double d);
    Vector3d crossProduct(Vector3d v1, Vector3d v2);
    double dotProduct(Vector3d v1, Vector3d v2);
    Vector3d toUnitVector(const Vector3d &v);

public:
	//Constructor and destructor
    PropulsionController(ros::NodeHandle handle);
    ~PropulsionController();

    //Set physcial specifications on the snake robot
    void setPhysicalSpec(double totalMass, double linkLength, double linkWidth, double linkHeight, double linkToJointLength);

    //Calculates ouput torque and publishes
    void updateTorqueOutput();
    //void testOnly_torqueOutput(double torque);

	//Update data:
	void updateDesiredVelocity(std::vector<double> newDesiredVelocity);
    void updateJointData(std::vector<double> newJointAngles, Vector3d newActualTorque);
};
