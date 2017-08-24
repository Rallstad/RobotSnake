#pragma once

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "statesubscriber.h"
#include "datatypes.h"

using std::cout;
using std::endl;

class RVizPublisher{
private:
    ros::NodeHandle rosNode;

    ros::Publisher 	rvizPub;

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
    ContactData				contacts;
    double					ctrlA, ctrlV;
    unsigned int            propulsionJoint;
    double					effort;

    void clearMarkerPointData();
    void updateMarkers();

public:
    RVizPublisher(ros::NodeHandle rosNodeHandle, int numberOfLinks);
    void publishToRViz();
    void getData(StateSubscriber stateSub);
};
