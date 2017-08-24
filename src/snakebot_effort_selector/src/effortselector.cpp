#include "effortselector.h"

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR
EffortSelector::EffortSelector(ros::NodeHandle handle)
{
    positionControlOnly = false;

    n = handle;

    propulsionEffortSub = n.subscribe("/snakebot/propulsion_effort", 1, &EffortSelector::propulsionEffortCallback, this);
    positionControlEffortSub = n.subscribe("/snakebot/position_controller_effort", 1, &EffortSelector::positionControlEffortCallback, this);

    joint1TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_01_effort_controller/command", 1);
    joint2TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_02_effort_controller/command", 1);
    joint3TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_03_effort_controller/command", 1);
    joint4TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_04_effort_controller/command", 1);
    joint5TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_05_effort_controller/command", 1);
    joint6TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_06_effort_controller/command", 1);
    joint7TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_07_effort_controller/command", 1);
    joint8TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_08_effort_controller/command", 1);
    joint9TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_09_effort_controller/command", 1);
    joint10TorquePub = n.advertise<std_msgs::Float64>("/snakebot/joint_10_effort_controller/command", 1);

    positionControlEffort.resize(numJoints);
    combinedEffort.resize(numJoints);


    propulsionEffortReady = false;
    positionControlEffortReady = false;
    propulsionStarted = false;

}
// DESTRUCTOR
EffortSelector::~EffortSelector()
{
}
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// updates the effort vector sent to the ROS effort controller
void EffortSelector::updateEffort(){
    //publishDesiredPosition();

    if (positionControlOnly){
        combinedEffort = positionControlEffort;
    }
    else if (!(propulsionEffortReady && positionControlEffortReady)){
        if (positionControlEffortReady){
            cout << "Only position control available. " << endl;
            combinedEffort = positionControlEffort;
        }
        else{
            //cout << "Hybrid controller is waiting for data. " << endl;
            return;
        }
    }
    else{
        cout << "All data available" << endl;
        propulsionStarted = true;
        combineEfforts();
    }
    publishEffort();
    ros::Time timeNow = ros::Time::now();
    if (((timeNow - timeOfReceivedPropulsionEffort).toNSec()/1000000) > 100){
        //cout << "delay is by " << ((timeNow - timeOfReceivedPropulsionEffort).toNSec()/1000000) << " ms" << endl;
        propulsionEffortReady = false;
    }
}

// publishes the effort vector to ROS effort controller - 7/12-2016: Hardcoded for number of joints
void EffortSelector::publishEffort(){
    std_msgs::Float64 msg1;
    std_msgs::Float64 msg2;
    std_msgs::Float64 msg3;
    std_msgs::Float64 msg4;
    std_msgs::Float64 msg5;
    std_msgs::Float64 msg6;
    std_msgs::Float64 msg7;
    std_msgs::Float64 msg8;
    std_msgs::Float64 msg9;
    std_msgs::Float64 msg10;

    msg1.data = combinedEffort[0];
    msg2.data = combinedEffort[1];
    msg3.data = combinedEffort[2];
    msg4.data = combinedEffort[3];
    msg5.data = combinedEffort[4];
    msg6.data = combinedEffort[5];
    msg7.data = combinedEffort[6];
    msg8.data = combinedEffort[7];
    msg9.data = combinedEffort[8];
    msg10.data = combinedEffort[9];

    joint1TorquePub.publish(msg1);
    joint2TorquePub.publish(msg2);
    joint3TorquePub.publish(msg3);
    joint4TorquePub.publish(msg4);
    joint5TorquePub.publish(msg5);
    joint6TorquePub.publish(msg6);
    joint7TorquePub.publish(msg7);
    joint8TorquePub.publish(msg8);
    joint9TorquePub.publish(msg9);
    joint10TorquePub.publish(msg10);
}

// combines effort from the position controller and propulsion controller
void EffortSelector::combineEfforts(){
    combinedEffort = positionControlEffort;
    combinedEffort[propulsionJointNum - 1] = propulsionEffort;
}

void EffortSelector::runPositionControlOnly(){
    positionControlOnly = true;
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// // CALLBACK FUNCTIONS - FOR RECEIVING DATA ///////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////


// store received vector of desired efforts
void EffortSelector::propulsionEffortCallback(const snakebot_propulsion_control::PropulsionEffort::ConstPtr &msg){
    cout << "propulsionEffortCallback" << endl;
    propulsionEffort = msg->effort;
    propulsionJointNum = msg->jointNum;
    timeOfReceivedPropulsionEffort = ros::Time::now();
    propulsionEffortReady = true;
}

void EffortSelector::positionControlEffortCallback(const snakebot_position_control::PositionControlEffort::ConstPtr &msg){
    if (msg->arraySize != numJoints){
        cout << "ERROR: effort vector size not equal to number of joints!" << endl;
        cout << "Cannot publish effort to ros_control" << endl;
        return;
    }
    positionControlEffort = msg->effort;
    positionControlEffortReady = true;
    //cout << "Current time: " << ros::Time::now().toNSec() << endl;
    //cout << "Time on received message: " << msg->pubTime.toNSec() << endl;
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////
