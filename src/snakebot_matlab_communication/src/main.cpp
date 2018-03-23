#include "matlab_communication.h"

int main(int argc, char **argv){

	int freq = 1000;
    ros::init(argc, argv, "matlab_communication");
    ros::NodeHandle n;
    Snake snake(n);
    ros::Rate loop_rate(freq);

    while(ros::ok()){
    	ros::spinOnce();
    	loop_rate.sleep();
    }

	return 0;
}