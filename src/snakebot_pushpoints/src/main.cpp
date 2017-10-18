#include "pushpointextractor.h"

int main(int argc, char **argv)
{
    int freq = 100;
    ros::init(argc, argv, "pushpoints");
    ros::NodeHandle n;
    int numberOfLinks = 5;

    PushpointExtractor pushpointObj(n, numberOfLinks);
    ros::Rate loop_rate(freq);

    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}

