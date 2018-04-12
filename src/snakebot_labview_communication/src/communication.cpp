#include "communication.h"


Communication::Communication(ros::NodeHandle n)
{
    // Publishes data to the ROS side:
    ROS_RefAnglesPub = n.advertise<std_msgs::Float64MultiArray>("LabVIEW_ROS/to_ROS_reference_angles", 1);
    ROS_MeasuredAnglesPub = n.advertise<std_msgs::Float64MultiArray>("LabVIEW_ROS/to_ROS_measured_angles", 1);
    ROS_CollisionsPub = n.advertise<snakebot_collisions::SnakeContacts>("LabVIEW_ROS/to_ROS_collisions", 1);
    ROS_RobotPosePub = n.advertise<snakebot_robot_pose::SnakePose>("LabVIEW_ROS/to_ROS_robot_pose", 1);

    // Subcribes to data from the ROS side:
    ROS_RefAnglesSub = n.subscribe("LabVIEW_ROS/from_ROS_reference_angles", 10, &Communication::ROS_RefAnglesCallback, this);
    ROS_MeasuredAnglesSub = n.subscribe("/snakebot/joint_states", 10, &Communication::ROS_MeasuredAnglesCallback, this);
    ROS_CollisionsSub = n.subscribe("LabVIEW_ROS/from_ROS_collisions", 10, &Communication::ROS_CollisionsCallback, this);
    ROS_PushPointsSub = n.subscribe("LabVIEW_ROS/from_ROS_push_points", 10, &Communication::ROS_PushPointsCallback, this);
    ROS_RobotPoseSub = n.subscribe("LabVIEW_ROS/from_ROS_robot_pose", 10, &Communication::ROS_RobotPoseCallback, this);

    // Publishes data to the LabVIEW side:
    LabVIEW_RefAnglesPub = n.advertise<snakebot_labview_communication::Float64Array>("LabVIEW_ROS/to_LabVIEW_reference_angles", 1);
    LabVIEW_MeasuredAnglesPub = n.advertise<snakebot_labview_communication::Float64Array>("LabVIEW_ROS/to_LabVIEW_measured_angles", 1);
    LabVIEW_CollisionsPub = n.advertise<snakebot_labview_communication::Collisions>("LabVIEW_ROS/to_LabVIEW_collisions", 1);
    LabVIEW_PushPointsPub = n.advertise<snakebot_labview_communication::Collisions>("LabVIEW_ROS/to_LabVIEW_push_points", 1);
    LabVIEW_RobotPosePub = n.advertise<snakebot_labview_communication::LinkPoses>("LabVIEW_ROS/to_LabVIEW_robot_pose", 1);

    // Subcribes to data from the LabVIEW side:
    LabVIEW_pushPointSub = n.subscribe("LabVIEW_ROS/from_LabVIEW_push_points", 10, &Communication::LabVIEW_CollisionsCallback, this);
    LabVIEW_RobotPoseSub = n.subscribe( "LabVIEW_ROS/from_LabVIEW_robot_link_poses", 10, &Communication::LabVIEW_RobotPoseCallback, this );
    LabVIEW_RefAnglesSub = n.subscribe("LabVIEW_ROS/from_LabVIEW_reference_angles", 10, &Communication::LabVIEW_RefAnglesCallback, this);
    LabVIEW_MeasuredAnglesSub = n.subscribe("LabVIEW_ROS/from_LabVIEW_measured_angles", 10, &Communication::LabVIEW_MeasuredAnglesCallback, this);
}


void Communication::ROS_RefAnglesCallback(const std_msgs::Float64MultiArray::ConstPtr& inMsg){
    snakebot_labview_communication::Float64Array outMsg;
    outMsg.data = inMsg->data;
    LabVIEW_RefAnglesPub.publish(outMsg);
}

void Communication::ROS_MeasuredAnglesCallback(const sensor_msgs::JointState::ConstPtr& inMsg){
    snakebot_labview_communication::Float64Array outMsg;
    outMsg.data = inMsg->position;

    LabVIEW_MeasuredAnglesPub.publish(outMsg);
}

void Communication::ROS_CollisionsCallback(const snakebot_collisions::SnakeContacts::ConstPtr& inMsg){
    snakebot_labview_communication::Collisions outMsg;
    for (int i = 0; i < inMsg->link.size(); i++){
        for (int j = 0; j < inMsg->link[i].contact_normals.size(); j ++){
            outMsg.position_x.push_back(inMsg->link[i].contact_positions[j].x);
            outMsg.position_y.push_back(inMsg->link[i].contact_positions[j].y);
            outMsg.position_z.push_back(inMsg->link[i].contact_positions[j].z);

            outMsg.normal_x.push_back(inMsg->link[i].contact_normals[j].x);
            outMsg.normal_y.push_back(inMsg->link[i].contact_normals[j].y);
            outMsg.normal_z.push_back(inMsg->link[i].contact_normals[j].z);

            outMsg.tangent_x.push_back(inMsg->link[i].contact_tangents[j].x);
            outMsg.tangent_y.push_back(inMsg->link[i].contact_tangents[j].y);
            outMsg.tangent_z.push_back(inMsg->link[i].contact_tangents[j].z);

            outMsg.force_x.push_back(inMsg->link[i].contact_forces[j].x);
            outMsg.force_y.push_back(inMsg->link[i].contact_forces[j].y);
            outMsg.force_z.push_back(inMsg->link[i].contact_forces[j].z);

            outMsg.link_numbers.push_back(inMsg->link[i].link);
            outMsg.contact_sides.push_back(inMsg->link[i].contact_sides[j]);
        }
    }
    LabVIEW_CollisionsPub.publish(outMsg);
}

void Communication::ROS_PushPointsCallback(const snakebot_pushpoints::Pushpoints::ConstPtr& inMsg){
    snakebot_labview_communication::Collisions outMsg;
    for (int i = 0; i < inMsg->contact_normals.size(); i++){
        outMsg.position_x.push_back(inMsg->contact_positions[i].x);
        outMsg.position_y.push_back(inMsg->contact_positions[i].y);
        outMsg.position_z.push_back(inMsg->contact_positions[i].z);

        outMsg.normal_x.push_back(inMsg->contact_normals[i].x);
        outMsg.normal_y.push_back(inMsg->contact_normals[i].y);
        outMsg.normal_z.push_back(inMsg->contact_normals[i].z);

        outMsg.tangent_x.push_back(inMsg->contact_tangents[i].x);
        outMsg.tangent_y.push_back(inMsg->contact_tangents[i].y);
        outMsg.tangent_z.push_back(inMsg->contact_tangents[i].z);

        outMsg.link_numbers.push_back(inMsg->link_numbers[i]);
        outMsg.contact_sides.push_back(inMsg->contact_sides[i]);
    }
    LabVIEW_PushPointsPub.publish(outMsg);
}

void Communication::ROS_RobotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr& inMsg){
    snakebot_labview_communication::LinkPoses outMsg;
    snakebot_robot_pose::SnakePose pose = inMsg->snakePose;
    for (int i = 0; i < pose.name.size(); i++){
        outMsg.x.push_back(pose.pose[i].x);
        outMsg.y.push_back(pose.pose[i].y);
        outMsg.theta.push_back(pose.pose[i].theta);
    }

    LabVIEW_RobotPosePub.publish(outMsg);
}

void Communication::LabVIEW_CollisionsCallback(const snakebot_labview_communication::Collisions::ConstPtr& inMsg){
    if (inMsg->link_numbers.size() == 0){
        cout << "Receiving empty collision messages" << endl;
        return;
    }

    snakebot_collisions::SnakeContacts outMsg;
    int numberOfLinks = inMsg->link_numbers[inMsg->link_numbers.size()-1];
    int index = 0;
    for (int i = 1; i <= numberOfLinks; i++){
        snakebot_collisions::LinkContacts linkContact;
        linkContact.link = i;
        for (int j = index; j < inMsg->link_numbers.size(); j++){
            if (inMsg->link_numbers[j] == i){
                geometry_msgs::Point position;
                position.x = inMsg->position_x[j];
                position.y = inMsg->position_y[j];
                position.z = inMsg->position_z[j];
                linkContact.contact_positions.push_back(position);

                geometry_msgs::Vector3 normal;
                normal.x = inMsg->normal_x[j];
                normal.y = inMsg->normal_y[j];
                normal.z = inMsg->normal_z[j];
                linkContact.contact_normals.push_back(normal);

                geometry_msgs::Vector3 tangent;
                tangent.x = inMsg->tangent_x[j];
                tangent.y = inMsg->tangent_y[j];
                tangent.z = inMsg->tangent_z[j];
                linkContact.contact_tangents.push_back(tangent);

                geometry_msgs::Vector3 force;
                force.x = inMsg->force_x[j];
                force.y = inMsg->force_y[j];
                force.z = inMsg->force_z[j];
                linkContact.contact_forces.push_back(force);

                linkContact.contact_sides.push_back(inMsg->contact_sides[j]);
            }
            else{
                index = j;
                break;
            }
        }
        outMsg.link.push_back(linkContact);
    }
    ROS_CollisionsPub.publish(outMsg);
}

void Communication::LabVIEW_RobotPoseCallback(const snakebot_labview_communication::LinkPoses::ConstPtr& inMsg){
    snakebot_robot_pose::SnakePose outMsg;
    geometry_msgs::Pose2D pose;
    for (int i = 0; i < inMsg->x.size(); i++){
        pose.x = inMsg->x[i];
        pose.y = inMsg->y[i];
        pose.theta = inMsg->theta[i];
        outMsg.pose.push_back(pose);
        outMsg.number.push_back(i+1);
    }
    ROS_RobotPosePub.publish(outMsg);
}

void Communication::LabVIEW_RefAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& inMsg){
    std_msgs::Float64MultiArray outMsg;
    outMsg.data = deg2rad(inMsg->data);
    std::reverse(outMsg.data.begin(),outMsg.data.end());
    ROS_RefAnglesPub.publish(outMsg);
}
void Communication::LabVIEW_MeasuredAnglesCallback(const snakebot_labview_communication::Float64Array::ConstPtr& inMsg){
    std_msgs::Float64MultiArray outMsg;
    std::vector<double> yawJoints = {inMsg->data[1], inMsg->data[3], inMsg->data[5], inMsg->data[7], inMsg->data[9], inMsg->data[11]};
    yawJoints = deg2rad(yawJoints);
    std::reverse(yawJoints.begin(),yawJoints.end());
    outMsg.data = yawJoints;
    ROS_MeasuredAnglesPub.publish(outMsg);
}


std::vector<double> Communication::deg2rad(const std::vector<double>& data){
    std::vector<double> radData;
    for (int i = 0; i < data.size(); i++){
        radData.push_back(data[i] * M_PI /180);
    }
    return radData;
}
