#include "logger.h"

int main(int argc, char **argv)
{
    int freq = 100;
    ros::init(argc, argv, "position");
    ros::NodeHandle n;
    ros::Rate loop_rate(freq);
    Logger logger(n);

    while (ros::ok())
    {

        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}
