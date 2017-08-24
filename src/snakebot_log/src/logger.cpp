#include "logger.h"


Logger::Logger(ros::NodeHandle nodeHandle){
    n = nodeHandle;

    ROSMeasuredAnglesSub = n.subscribe("/snakebot/joint_states", 1, &Logger::ROSMeasuredAnglesCallback, this);
    ROSReferenceAnglesSub = n.subscribe("/snakebot/desired_joint_positions", 1, &Logger::ROSReferenceAnglesCallback, this);
    LabVIEWMeasuredAnglesSub = n.subscribe("LabVIEW_ROS/from_LabVIEW_measured_angles", 1, &Logger::LabVIEWMeasuredAnglesCallback, this);
    LabVIEWReferenceAnglesSub = n.subscribe("LabVIEW_ROS/from_LabVIEW_reference_angles", 1, &Logger::LabVIEWReferenceAnglesCallback, this);

    // Opening files for logging
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    stringstream ssTime;
    ssTime << now->tm_year + 1900 << "." << now->tm_mon+1 << "." << now->tm_mday << "." << now->tm_hour << "." << now->tm_min << "." << now->tm_sec << ".";
    string sTime = ssTime.str();
    string folderName = "Documents/catkin_ws/log/";
    stringstream ssFilePath;
    ssFilePath << folderName << sTime << "rosMeasJoints.csv";
    rosMeasJointsFile.open(ssFilePath.str().c_str());
    ssFilePath.str("");
    ssFilePath << folderName << sTime << "rosRefJoints.csv";
    rosRefJointsFile.open(ssFilePath.str().c_str());
    ssFilePath.str("");
    ssFilePath << folderName << sTime << "labviewMeasJoints.csv";
    labviewMeasJointsFile.open(ssFilePath.str().c_str());
    ssFilePath.str("");
    ssFilePath << folderName << sTime << "labviewRefJoints.csv";
    labviewRefJointsFile.open(ssFilePath.str().c_str());
}

Logger::~Logger(){
    rosMeasJointsFile.close();
    rosRefJointsFile.close();
    labviewMeasJointsFile.close();
    labviewRefJointsFile.close();
}


void Logger::LabVIEWMeasuredAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& msg){
    for (int i = 0; i < msg->data.size() ; i++){
        labviewMeasJointsFile << msg->data[i] << ",";
    }
    labviewMeasJointsFile << ros::Time::now().toSec();
    labviewMeasJointsFile << "\n";
}

void Logger::ROSMeasuredAnglesCallback(const sensor_msgs::JointState::ConstPtr& msg){
        for (int i = 0; i < msg->position.size() ; i++){
            rosMeasJointsFile << msg->position[i] << ",";
        }
        rosMeasJointsFile << ros::Time::now().toSec();
        rosMeasJointsFile << "\n";
}

void Logger::LabVIEWReferenceAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& msg){
    for (int i = 0; i < msg->data.size() ; i++){
        labviewRefJointsFile << msg->data[i] << ",";
    }
    labviewRefJointsFile << ros::Time::now().toSec();
    labviewRefJointsFile << "\n";
}

void Logger::ROSReferenceAnglesCallback(const std_msgs::Float64MultiArray::ConstPtr& msg){
    for (int i = 0; i < msg->data .size() ; i++){
        rosRefJointsFile << msg->data[i] << ",";
    }
    rosRefJointsFile << ros::Time::now().toSec();
    rosRefJointsFile << "\n";
}
