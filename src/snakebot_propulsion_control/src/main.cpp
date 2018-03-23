#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"
#include <math.h> 
#include <vector>
#include "propulsioncontroller.h"

#include <sstream>



int main(int argc, char **argv)
{
    //Initialization
    double totalMass = 1*14; //Hardcoded for 1kg times 11 links. Inaccurate
    double linkLength = 0.2;
    double linkWidth = 0.1;
    double linkHeight = 0.1;
    double jointOffset = 0.03;
    double linkToJointLength = (linkLength/2) + jointOffset;
    int freq = 100;
	ros::init(argc, argv, "position_torque_controller");
    ros::NodeHandle n;
    PropulsionController controller(n);
    controller.setPhysicalSpec(totalMass, linkLength, linkWidth, linkHeight, linkToJointLength);
	ros::Rate loop_rate(freq);	
    //

    while (ros::ok())
    {
        // This functions gets data from the snakebot_interface package,
        // then calculates and publishes the propulsion torque
        controller.updateTorqueOutput();


        ros::spinOnce();
        loop_rate.sleep();
	}

  return 0;
}

