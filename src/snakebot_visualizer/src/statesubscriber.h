#pragma once
#include <ros/ros.h>
#include "snakebot_propulsion_control/PropulsionEffort.h"
#include "snakebot_input_interface/Ctrl.h"
#include "snakebot_collisions/SnakeContacts.h"
#include "snakebot_kinematics/kinematics.h"
#include "datatypes.h"
#include "snakebot_robot_pose/Pose.h"


using std::cout;
using std::endl;

class StateSubscriber{
private:
    ros::NodeHandle rosNode;
    ros::Subscriber	contactsSub;
    ros::Subscriber robotPoseSub;
    ros::Subscriber	ctrlSub;
    ros::Subscriber effortSub;
    ros::Subscriber propulsionJointSub;
    ros::Subscriber realSnakePoseSub;

    void ctrlCallback(const snakebot_input_interface::Ctrl::ConstPtr& msg);
    void robotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr& msg);
    void contactCallback(const snakebot_collisions::SnakeContacts::ConstPtr& msg);
    void effortCallback(const snakebot_propulsion_control::PropulsionEffort::ConstPtr& msg);
    void jointPoseCallback(const snakebot_kinematics::kinematics::ConstPtr &msg);
    void rotateContacts( ContactData& contacts, double da);
    void translateContactPositions( ContactData& contacts, double dx, double dy, double dz );

    int                     numberOfLinks;
    Pose2d					snakePose;
    Pose2d                  jointPose;
    ContactData				contacts;
    double					ctrlA, ctrlV;
    unsigned int            propulsionJoint;
    double					effort;

public:
    StateSubscriber(ros::NodeHandle rosNode, int numberOfLinks);

    Pose2d getSnakePose();
    Pose2d getJointPose();
    ContactData getContacts();
    std::vector<Vector3d> getAllForces();
    std::vector<Vector3d> getResultantForce();
    double getCtrlA();
    double getCtrlV();
    unsigned int getPropulsionJoint();
    double getEffort();


};


