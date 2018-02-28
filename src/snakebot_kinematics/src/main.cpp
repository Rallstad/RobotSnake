#include "kinematics.h"

int main(int argc, char **argv){

	int freq = 1000;
    ros::init(argc, argv, "kinematics");
    ros::NodeHandle n;
    Snake snake(n);
    ros::Rate loop_rate(freq);

    while(ros::ok()){
    	
        snake.calculateJointPosition();
        snake.publishSnakeConfiguration();
        snake.writeJointPosesToFile();

        //snake.readJointPosesFromBag();
    	ros::spinOnce();
    	loop_rate.sleep();
    }

	return 0;
}