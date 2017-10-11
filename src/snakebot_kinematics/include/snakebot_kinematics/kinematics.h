#pragma once

#include <vector>
#include <math.h>
#include "std_msgs/Float64MultiArray.h"
#include "geometry_msgs/Pose2D.h"
#include "snakebot_labview_communication/Float64Array.h"
#include "snakebot_labview_communication/Int32Array.h"
#include "ros/ros.h"

using std::cout;
using std::endl;

class Snake{
private:
	float link_length;



	void anglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg);
public:
	Snake(ros::NodeHandle n);

};