#include "effortselector.h"



int main(int argc, char **argv)
{
    int freq = 1000;
    ros::init(argc, argv, "effort_selector");
    ros::NodeHandle n;

    EffortSelector torqueSelector(n);
    ros::Rate loop_rate(freq);

    //torqueSelector.runPositionControlOnly();

    while (ros::ok())
    {
        torqueSelector.updateEffort();
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}

