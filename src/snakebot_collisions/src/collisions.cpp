#include "collisions.h"


Collisions::Collisions(ros::NodeHandle nodeHandle, int numLinks){
    n = nodeHandle;
    numberOfLinks = numLinks;

    obstacleContactsPub = n.advertise<snakebot_collisions::SnakeContacts>("/snakebot/collisions", 1);
    robotPoseSub = n.subscribe("/snakebot/robot_pose", 10, &Collisions::robotPoseCallback, this );

    LabVIEW_CollisionsPub = n.advertise<snakebot_collisions::SnakeContacts>("LabVIEW_ROS/from_ROS_collisions", 1);

    //generate bumper objects
    for ( int i=0; i<numberOfLinks; i++ ){
        bumpers.push_back(Bumper(i+1,n));
    }
}


void Collisions::robotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr& msg){
    for ( int i=0; i < msg->snakePose.name.size(); i++ ) {
        for ( int j=0; j < numberOfLinks; j++ ) {
            if ( msg->snakePose.name[i] == bumpers[j].getLinkName() ) {
                bumpers[j].setPose(Pose2d(msg->snakePose.pose[i].x, msg->snakePose.pose[i].y, msg->snakePose.pose[i].theta));
                break;
            }
        }
    }
}

void Collisions::sendContacts(){
    snakebot_collisions::SnakeContacts msg;
    for (int i = 0; i < bumpers.size(); i++){
        bumpers[i].setMessageHeader();
        msg.link.push_back(bumpers[i].getContacts());
    }
    obstacleContactsPub.publish(msg);

    LabVIEW_CollisionsPub.publish(msg);
}
