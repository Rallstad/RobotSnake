#include "inputinterface.h"


int main(int argc, char **argv)
{
    int freq = 100;
    ros::init(argc, argv, "input_interface");
    ros::NodeHandle n;
    int numberOfLinks = 11;

    JoystickInterface joyInterface(n);
    ros::Rate loop_rate(freq);

    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}

