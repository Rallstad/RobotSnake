#include "communication.h"

int main(int argc, char **argv)
{
    int freq = 100;
    ros::init(argc, argv, "LabVIEW_ROS_Communication");
    ros::NodeHandle n;
    ros::Rate loop_rate(freq);
    Communication communication(n);


    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}
