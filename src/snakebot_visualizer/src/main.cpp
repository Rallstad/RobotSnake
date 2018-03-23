#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <snakebot_collisions/SnakeContacts.h>
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Int8.h"
#include "rvizpublisher.h"

#define SCALE	5000.

using std::cout;
using std::endl;

int main( int argc, char** argv )
{
    //cout << "main has started" << endl;
    int numberOfLinks = 14;
    int freq = 30;
    ros::init(argc, argv, "viewer");
    ros::NodeHandle rosNode;
    ros::Rate       loopRate(freq);

    //cout << "node created" << endl;
    RVizPublisher rvizPublisher(rosNode, numberOfLinks);
    StateSubscriber stateSubscriber(rosNode, numberOfLinks);

    cout << "publisher and subscriber created" << endl;
    while (ros::ok()){
        //cout << "in while loop" << endl;
        rvizPublisher.getData(stateSubscriber);
        //cout << "successfull getData" << endl;
        rvizPublisher.publishToRViz();
        //cout << "done publishing data " << endl;

        ros::spinOnce();
        //cout << "sleep" <<endl;
        loopRate.sleep();
  }
}
