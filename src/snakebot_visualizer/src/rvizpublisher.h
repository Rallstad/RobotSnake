#pragma once

#include <ros/ros.h>
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Point.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "snakebot_labview_communication/Float64Array.h"
#include "snakebot_labview_communication/Int32Array.h"
#include "snakebot_pushpoints/pushpointCandidates.h"
#include "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/src/visual_data_topic_collector.h"
#include "/home/snake/Documents/catkin_ws/src/snakebot_kinematics/src/kinematics.h"
#include "/home/snake/Documents/catkin_ws/src/snakebot_visualizer/src/rvizpublisher.h"
#include "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/src/pushpointextractor.h"
#include "statesubscriber.h"
#include "datatypes.h"
//#include "tf/Quaternion.h"


using std::cout;
using std::endl;

class RVizPublisher{
private:
    visualization_msgs::MarkerArray visualJointPose;
    visualization_msgs::MarkerArray kinematicsJointPose;
    visualization_msgs::MarkerArray obstaclePosition;

    geometry_msgs::Pose2D kinematicsJointPoses[13];
    geometry_msgs::Pose2D visualJointPoses[13];
    geometry_msgs::Pose2D obstaclePositions[3];
    float sgData[13];
    float forceMidpoint[13];
    int pushpointCandidates[3];
    bool foundMidPoint;



    ros::NodeHandle rosNode;

    ros::Subscriber obstacleSub;
    ros::Subscriber visualJointPoseSub;
    ros::Subscriber kinematicsJointPoseSub;
    ros::Subscriber sgDataSub;
    ros::Subscriber jointCandidateSub;

    ros::Publisher rvizPub;
    ros::Publisher rvizVisualJointPub;
    ros::Publisher rvizKinematicsJointPub;
    ros::Publisher rvizObstaclePub;
    ros::Publisher rvizNormalForcePub;
    ros::Publisher rvizTangentForcePub;

    visualization_msgs::Marker normalsMarker;
    visualization_msgs::Marker resultantNormalsMarker;
    visualization_msgs::Marker tangentsMarker;
    visualization_msgs::Marker forcesMarker;
    visualization_msgs::Marker allForcesMarker;
    visualization_msgs::Marker resultantForceMarker;
    visualization_msgs::Marker ctrlMarker;
    visualization_msgs::Marker effortMarker;

    int                     numberOfLinks;

    Pose2d					snakePose;
    Pose2d                  jointPose;
    ContactData				contacts;
    double					ctrlA, ctrlV;
    unsigned int            propulsionJoint;
    double					effort;

    void clearMarkerPointData();
    void updateMarkers();

    void obstaclesCallback(const snakebot_visual_data_topic_collector::obstacles::ConstPtr &msg);
    void visualJointsCallback(const snakebot_visual_data_topic_collector::jointposes::ConstPtr &msg);
    void kinematicsJointsCallback(const snakebot_kinematics::kinematics::ConstPtr &msg);
    void sgDataCallback(const std_msgs::Float32MultiArray::ConstPtr &msg);
    void jointCandidateCallback(const snakebot_pushpoints::pushpointCandidates::ConstPtr &msg);


public:
    RVizPublisher(ros::NodeHandle rosNodeHandle, int numberOfLinks);
    ~RVizPublisher();
    void publishToRViz();
    void getData(StateSubscriber stateSub);
    void publishVisualObstacle();
    void publishVisualTangentForce();
    void publishVisualNormalForce();
    void publishVisualSnakeJointPose();
    void publishKinematicsSnakeJointPose();
};
