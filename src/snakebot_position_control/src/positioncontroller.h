#pragma once

#include "vectoroperators.h"
#include "ros/ros.h"
#include "ros/time.h"
#include <vector>
#include <iostream>
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"
#include "snakebot_position_control/PositionControlEffort.h"

using std::cout;
using std::endl;


extern bool followRealSnakeMode;


class PositionController
{
private:
    static const int numJoints = 10;

    //ROS specific
    ros::NodeHandle n;

    double dt;
    std::vector<double> kp;
    std::vector<double> kd;
    std::vector<double> ki;

    std::vector<double> error;
    std::vector<double> errorPrev;
    std::vector<double> errorDerivative;
    std::vector<double> errorIntegral;

    void desiredPositionCallback(const std_msgs::Float64MultiArray::ConstPtr& msg);
    void labviewPositionCallback(const std_msgs::Float64MultiArray::ConstPtr& msg);
    void jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg);
    ros::Subscriber desiredPositionSub;
    ros::Subscriber labviewPositionSub;
    ros::Subscriber jointStateSub;
    ros::Publisher desiredPositionPub;
    ros::Publisher effortPub;

    std::vector<std::vector<double>> jointMappingMatrix;
    void setMappingMatrix();
    std::vector<double> map6to10(std::vector<double> vector6);

    bool desiredPositionReady;
    bool currentPositionReady;
    bool firstRun;

    std::vector<double> desiredPosition;
    std::vector<double> currentPosition;
    std::vector<double> currentVelocity;
    std::vector<double> velocityAverage;

    double effortLimit;
    std::vector<double> effort;

    ros::Time lastStateDataTime;

    std::vector<double> saturate(double upperLimit, double lowerLimit, std::vector<double> v);
    std::vector<double> movingAverage(std::vector<double> currentData, std::vector<double> prevAverage, double smoothingFactor);

public:
    //Constructor and destructor
    PositionController(ros::NodeHandle handle, double stepLength, std::vector<double> kp, std::vector<double> kd, std::vector<double> ki, double effortLimit);
    ~PositionController();

    void calculateAndPublishEffort();
};

