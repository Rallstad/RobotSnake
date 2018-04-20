#include "visual_data_topic_collector.h"
using namespace std;
int main(int argc, char **argv){

	int freq = 1000;
    ros::init(argc, argv, "visual_data_topic_collector");
    ros::NodeHandle n;
    Topic_collector topic_collector(n);
    ros::Rate loop_rate(freq);

    while(ros::ok()){
        
        topic_collector.publishJointPose();
        topic_collector.publishObstacles();
    	ros::spinOnce();
    	loop_rate.sleep();


       
    }

	return 0;
}