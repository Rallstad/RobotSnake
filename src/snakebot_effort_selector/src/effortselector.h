#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Float64.h"
#include "snakebot_propulsion_control/PropulsionEffort.h"
#include "snakebot_position_control/PositionControlEffort.h"
#include <vector>

using std::cout;
using std::endl;


class EffortSelector
{
private:
    static const int numJoints = 10;

    //ROS specific
    ros::NodeHandle n;

    void propulsionEffortCallback(const snakebot_propulsion_control::PropulsionEffort::ConstPtr& msg);
    void positionControlEffortCallback(const snakebot_position_control::PositionControlEffort::ConstPtr& msg);
    ros::Subscriber propulsionEffortSub;
    ros::Subscriber positionControlEffortSub;
    ros::Publisher joint1TorquePub;
    ros::Publisher joint2TorquePub;
    ros::Publisher joint3TorquePub;
    ros::Publisher joint4TorquePub;
    ros::Publisher joint5TorquePub;
    ros::Publisher joint6TorquePub;
    ros::Publisher joint7TorquePub;
    ros::Publisher joint8TorquePub;
    ros::Publisher joint9TorquePub;
    ros::Publisher joint10TorquePub;

    bool propulsionEffortReady;
    bool positionControlEffortReady;
    bool propulsionStarted;
    bool positionControlOnly;
    ros::Time timeOfReceivedPropulsionEffort;
    double propulsionEffort;
    std::vector<double> positionControlEffort;
    std::vector<double> combinedEffort;

    int propulsionJointNum;

    void combineEfforts();
    void publishEffort();

public:
    //Constructor and destructor
    EffortSelector(ros::NodeHandle handle);
    ~EffortSelector();

    void runPositionControlOnly();
    void updateEffort();
};
