

#include "virtualsnake.h"

#include <sstream>



int main(int argc, char **argv)
{

    int freq = 50;
    ros::init(argc, argv, "virtual_snake");
    ros::NodeHandle n;
    VirtualSnake snake(n);
    ros::Rate loop_rate(freq);

    while (ros::ok())
    {
        snake.findDesiredJointAngles();
        snake.publishSetPoints();
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}

