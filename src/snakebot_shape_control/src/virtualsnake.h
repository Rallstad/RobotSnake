#pragma once

#include <vector>
#include <math.h>
#include "std_msgs/Float64MultiArray.h"
#include <snakebot_pushpoints/Pushpoints.h>
#include "ros/ros.h"
#include "snakebot_robot_pose/Pose.h"
#include "snakebot_shape_control/ShapeCurve.h"
#include "spline.h"
#include "snakebot_kinematics/snake_obstacles.h"

using std::cout;
using std::endl;



struct Vector2d{
    double x, y;
    Vector2d():x(0), y(0){}
    Vector2d(double x, double y):x(x), y(y){}

    double norm(){return sqrt(x*x + y*y);}
};

struct Point2d{
    double x, y;
    Point2d():x(0), y(0){}
    Point2d(double x, double y):x(x), y(y){}
    Vector2d operator-( const Point2d& v ) const;
};

Vector2d Point2d::operator-( const Point2d& v ) const
{
    return Vector2d(this->x - v.x, this->y - v.y);
}

class VirtualSnake{
private:
    double linkLength;
    double linkWidth;
    int numberOfLinks;
    std::vector<Point2d> jointPositions;
    std::vector<Point2d> shapeCurve;
    std::vector<double> jointSetPoint;
    std::vector<double> linkAngles;
    Point2d c1;
    Point2d c2;
    Point2d c3;
    std::vector<Point2d> contactLinkPosition;
    std::vector<double> contactLinkOrientation;
    std::vector<int> contactLinkNumber;
    std::vector<Point2d> linkPosition;
    std::vector<double> linkOrientation;
    std::vector<Point2d> obstaclePosition;

    bool obstacleDataReady;
    bool robotPoseReady;
    ros::Time obstacleDataReceiveTime;

    ros::Publisher desiredPositionPub;
    ros::Subscriber obstacleDataSub;
    ros::Subscriber robotPoseSub;
    ros::Subscriber shapeCurveSub;

    void robotPoseCallback(const snakebot_kinematics::snake_obstacles::ConstPtr &msg);
    void obstacleDataCallback(const snakebot_pushpoints::Pushpoints::ConstPtr& msg);
    void shapeCurveCallback(const snakebot_shape_control::ShapeCurve::ConstPtr& msg);

    void interpolate(Point2d p1, Point2d p2);
    void cosint(std::vector<double> x,std::vector<double> y,std::vector<double> xi, std::vector<double> &yi);
    void generateShapeCurve(); // temporary function for making a shape curve

    void zeroPadJointSetPoints();
    double vectorNorm(Vector2d v);
    double constrainAngle(double x);

    int findStartJoint();
    int findStartLinkAngle();

    void findDesiredJointPositions();
    Point2d findDesiredTailPosition();

public:
    VirtualSnake(ros::NodeHandle n);
    void findDesiredJointAngles();
    void calculateJointSetPoints();
    void publishSetPoints();

};
