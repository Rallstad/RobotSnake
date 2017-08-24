#pragma once
#include "ros/ros.h"
#include "ros/time.h"
#include <vector>
#include "sensor_msgs/JointState.h"
#include "snakebot_labview_communication/Float64Array.h"
#include "std_msgs/Float64MultiArray.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class Logger{
private:
    ofstream rosMeasJointsFile;
    ofstream rosRefJointsFile;
    ofstream labviewMeasJointsFile;
    ofstream labviewRefJointsFile;

    int numberOfLinks;
    ros::NodeHandle n;

    ros::Subscriber LabVIEWMeasuredAnglesSub;
    ros::Subscriber ROSMeasuredAnglesSub;
    ros::Subscriber LabVIEWReferenceAnglesSub;
    ros::Subscriber ROSReferenceAnglesSub;

    void LabVIEWMeasuredAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& msg);
    void ROSMeasuredAnglesCallback(const sensor_msgs::JointState::ConstPtr& msg);
    void LabVIEWReferenceAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& msg);
    void ROSReferenceAnglesCallback(const std_msgs::Float64MultiArray::ConstPtr& msg);


public:
    Logger(ros::NodeHandle nodeHandle);
    ~Logger();

};
