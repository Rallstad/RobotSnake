#include "statesubscriber.h"

StateSubscriber::StateSubscriber(ros::NodeHandle rosNode, int numberOfLinks): rosNode(rosNode), numberOfLinks(numberOfLinks){
    contactsSub = rosNode.subscribe( "/snakebot/collisions", 100, &StateSubscriber::contactCallback, this);
    robotPoseSub = rosNode.subscribe( "snakebot/robot_pose", 100, &StateSubscriber::robotPoseCallback, this);
    //realSnakePoseSub = rosNode.subscribe("snakebot/real_snake_pose",100, &StateSubscriber::jointPoseCallback, this);
    ctrlSub = rosNode.subscribe( "/snakebot/ctrl", 100, &StateSubscriber::ctrlCallback, this);
    effortSub = rosNode.subscribe( "snakebot/propulsion_effort", 100, &StateSubscriber::effortCallback, this);
}




// Think this function is crap
/*void StateSubscriber::jointPoseCallback(const snakebot_kinematics::kinematics::ConstPtr &msg){
    for ( int i=0; i < msg->pose.size(); i++ ) {
        if(msg->number[i] == 13){
            jointPose = Pose2d(msg->pose[i].x, msg->pose[i].y, msg->pose[i].theta);
            return;
        }
    }
    cout << "ERROR: there is no tail" << endl;
}*/



void StateSubscriber::robotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr& msg){
    for ( int i=0; i < msg->snakePose.name.size(); i++ ) {
        if ( msg->snakePose.name[i] == "snakebot::dummy_link") {
            snakePose = Pose2d(msg->snakePose.pose[i].x, msg->snakePose.pose[i].y, msg->snakePose.pose[i].theta);
            return;
        }
    }
    cout << "ERROR: there is no snakebot::dummy_link" << endl;
}

void StateSubscriber::contactCallback(const snakebot_collisions::SnakeContacts::ConstPtr& msg){
    contacts.normal.resize(0);
    contacts.position.resize(0);
    contacts.tangent.resize(0);
    contacts.force.resize(0);
    contacts.force.resize(0);
    for (int i = 0; i < msg->link.size(); i ++){
        snakebot_collisions::LinkContacts link = msg->link[i];
        for (int j = 0; j < link.contact_normals.size(); j++){
            contacts.normal.push_back(Vector3d(link.contact_normals[j]));
            contacts.force.push_back(Vector3d(link.contact_forces[j]));
            contacts.tangent.push_back(Vector3d(link.contact_tangents[j]));
            contacts.position.push_back(Point3d(link.contact_positions[j]));
        }
    }
    contacts.translatePositionsXY(-snakePose.x, -snakePose.y);
    contacts.rotateVectorsZ(-snakePose.orientation);

}

void StateSubscriber::ctrlCallback(const snakebot_input_interface::Ctrl::ConstPtr& msg){
    //cout << "ctrlCallback" << endl;
    ctrlA = msg->direction;
    ctrlV = msg->velocity;
}

void StateSubscriber::effortCallback(const snakebot_propulsion_control::PropulsionEffort::ConstPtr& msg){
    //cout << "effortCallback" << endl;
    effort = msg->effort;
    //cout << "propulsion effort :"<< msg->effort << endl;
    propulsionJoint = msg->jointNum;
}

Pose2d StateSubscriber::getSnakePose(){
    return snakePose;
}

Pose2d StateSubscriber::getJointPose(){
    return jointPose;
}

ContactData StateSubscriber::getContacts(){
    return contacts;
}

double StateSubscriber::getCtrlA(){
    return ctrlA;
}
double StateSubscriber::getCtrlV(){
    return ctrlV;
}
unsigned int StateSubscriber::getPropulsionJoint(){
    return propulsionJoint;
}
double StateSubscriber::getEffort(){
    return effort;
}
