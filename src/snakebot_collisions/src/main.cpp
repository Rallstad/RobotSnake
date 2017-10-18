#include "collisions.h"

int main(int argc, char **argv)
{
    int freq = 100;
    ros::init(argc, argv, "collisions");
    ros::NodeHandle n;
    int numberOfLinks = 5;

    Collisions collisions(n, numberOfLinks);
    ros::Rate loop_rate(freq);

    while (ros::ok())
    {
        collisions.sendContacts();
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}

