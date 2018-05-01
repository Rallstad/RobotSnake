#include "gazebo_msgs/LinkStates.h"
#include "snakebot_robot_pose/ObstaclePose.h"
#include "snakebot_robot_pose/SnakePose.h"
#include "snakebot_robot_pose/Pose.h"
#include "geometry_msgs/Pose2D.h"
#include "ros/ros.h"
#include "math.h"

using std::cout;
using std::endl;

/* ************************************************************************* *
 * ORIENTATIONS                                                              *
 * ************************************************************************* */

struct Quaternion
{
    double x, y, z, w;
    Quaternion(double xPos,double yPos,double zPos,double wPos):x(xPos),y(yPos),z(zPos),w(wPos){}
    Quaternion():x(0),y(0),z(0),w(1){}
};

struct Euler
{
    double x, y, z;
    Euler( const Quaternion& q )
    {
        double ysqr = q.y * q.y;
        double t0 = -2.0f * (ysqr + q.z * q.z) + 1.0f;
        double t1 = +2.0f * (q.x * q.y - q.w * q.z);
        double t2 = -2.0f * (q.x * q.z + q.w * q.y);
        double t3 = +2.0f * (q.y * q.z - q.w * q.x);
        double t4 = -2.0f * (q.x * q.x + ysqr) + 1.0f;

        t2 = t2 > 1.0f ? 1.0f : t2;
        t2 = t2 < -1.0f ? -1.0f : t2;

        x = std::atan2(t3, t4);
        y = std::asin(t2);
        z = std::atan2(t1, t0);
    }
};


/* ********************************************************************* */

double thetaFromEuler(geometry_msgs::Pose pose){
    double theta = Euler(
                    Quaternion(
                    pose.orientation.x,
                    pose.orientation.y,
                    -pose.orientation.z,
                    pose.orientation.w
                    )
                    ).z;
    return theta;
}

class RobotPose{
private:
    int numberOfLinks;
    double l;
    ros::NodeHandle n;
    ros::Publisher posePub;
    ros::Subscriber linkStateSub;
    void linkStateCallback(const gazebo_msgs::LinkStates::ConstPtr& msg);

    ros::Publisher LabVIEW_PosePub;

public:
    RobotPose(ros::NodeHandle nodeHandle, int numLinks);

};

RobotPose::RobotPose(ros::NodeHandle nodeHandle, int numLinks){
    n = nodeHandle;
    numberOfLinks = numLinks;
    double linkLength = 0.0885;
    double offset = 0.01;
    l = 0.5*linkLength + offset;

    posePub = n.advertise<snakebot_robot_pose::Pose>("/snakebot/robot_pose", 1);
    linkStateSub = n.subscribe( "gazebo/link_states", 30, &RobotPose::linkStateCallback, this );

    LabVIEW_PosePub = n.advertise<snakebot_robot_pose::Pose>("LabVIEW_ROS/from_ROS_robot_pose", 1);

}

void RobotPose::linkStateCallback(const gazebo_msgs::LinkStates::ConstPtr& msg){
    snakebot_robot_pose::SnakePose snakePose;
    snakebot_robot_pose::ObstaclePose obstaclePose;
    for ( int i=0; i < msg->name.size(); i++ ) {
        for ( int link=1; link < numberOfLinks + 1 ; link++ ) {
            char buffer[512];
            if (link == 1){
                std::string linkName = "snakebot::dummy_link";
                if (msg->name[i] == linkName){
                    snakePose.name.push_back(linkName);
                    snakePose.number.push_back(link);
                    geometry_msgs::Pose2D pose;
                    pose.x = msg->pose[i].position.x;
                    pose.y = msg->pose[i].position.y;
                    pose.theta = thetaFromEuler(msg->pose[i]);
                    snakePose.pose.push_back(pose);
                }
            }
            else{
                sprintf(buffer, "snakebot::body_%02d", link );
                std::string linkName = std::string(buffer);
                if (msg->name[i] == linkName){
                    snakePose.name.push_back(linkName);
                    snakePose.number.push_back(link);
                    geometry_msgs::Pose2D pose;
                    pose.theta = thetaFromEuler(msg->pose[i]);
                    pose.x = msg->pose[i].position.x + l*cos(pose.theta);
                    pose.y = msg->pose[i].position.y + l*sin(pose.theta);
                    cout << "theta = " << pose.theta << endl;
                    cout << "x = " << msg->pose[i].position.x << " x addtion= " << l*cos(pose.theta) << endl;
                    cout << "y = " << msg->pose[i].position.y << " y addtion= " << l*sin(pose.theta) << endl;
                    snakePose.pose.push_back(pose);
                }
            }
        }
        for (int obst = 1; obst < 11; obst++){
            char buffer[512];
                sprintf(buffer, "cylinder_%d::cyl", obst );
                std::string obstName = std::string(buffer);
                if (msg->name[i] == obstName){
                    obstaclePose.name.push_back(obstName);
                    obstaclePose.number.push_back(obst);
                    geometry_msgs::Pose2D pose;
                    pose.x = msg->pose[i].position.x;
                    pose.y = msg->pose[i].position.y;
                    pose.theta = thetaFromEuler(msg->pose[i]);
                    obstaclePose.pose.push_back(pose);
            }
        }
    }



    snakebot_robot_pose::Pose outputMsg;
    outputMsg.snakePose = snakePose;
    outputMsg.obstaclePose = obstaclePose;
    posePub.publish(outputMsg);

    LabVIEW_PosePub.publish(outputMsg);
}

int main(int argc, char **argv)
{
    int numberOfLinks = 14;
    int freq = 100;
    ros::init(argc, argv, "position");
    ros::NodeHandle n;
    ros::Rate loop_rate(freq);
    RobotPose interface(n, numberOfLinks);


    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}










