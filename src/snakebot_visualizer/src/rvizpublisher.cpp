#include "rvizpublisher.h"
#include <math.h>
RVizPublisher::RVizPublisher(ros::NodeHandle rosNodeHandle, int numberOfLinks): rosNode(rosNodeHandle), numberOfLinks(numberOfLinks){

    obstacleSub = rosNode.subscribe("/snakebot/obstaclePosition",100, &RVizPublisher::obstaclesCallback, this);
    visualJointPoseSub = rosNode.subscribe("/snakebot/visualSnakeJointPose",100, &RVizPublisher::visualJointsCallback, this);
    sgDataSub = rosNode.subscribe("/from_matlab/SG_unfiltered",100, &RVizPublisher::sgDataCallback, this);
    kinematicsJointPoseSub = rosNode.subscribe("/snakebot/real_snake_pose",100, &RVizPublisher::kinematicsJointsCallback, this);
    jointCandidateSub = rosNode.subscribe("/snakebot/pushpointCandidates", 100, &RVizPublisher::jointCandidateCallback, this);

    rvizPub = rosNode.advertise<visualization_msgs::Marker>("visualization_marker", 100);
    rvizVisualJointPub = rosNode.advertise<visualization_msgs::MarkerArray>("/snakebot/visualSnakeJointPoseToRviz",100);
    rvizKinematicsJointPub = rosNode.advertise<visualization_msgs::MarkerArray>("/snakebot/kinematicsSnakeJointPoseToRviz",100);
    rvizObstaclePub = rosNode.advertise<visualization_msgs::MarkerArray>("/snakebot/obstacleToRviz", 100);
    rvizNormalForcePub = rosNode.advertise<visualization_msgs::MarkerArray>("/snakebot/NormalForceToRviz", 100);
    rvizTangentForcePub = rosNode.advertise<visualization_msgs::MarkerArray>("/snakebot/TangentForceToRviz", 100);

    normalsMarker.header.frame_id =
        resultantNormalsMarker.header.frame_id =
            tangentsMarker.header.frame_id =
                forcesMarker.header.frame_id =
                    allForcesMarker.header.frame_id =
                        resultantForceMarker.header.frame_id =
                            ctrlMarker.header.frame_id =
                                effortMarker.header.frame_id = "/world";
    normalsMarker.ns = "normals";
    resultantNormalsMarker.ns = "sum of normals";
    tangentsMarker.ns = "tangents";
    forcesMarker.ns = "forces";
    allForcesMarker.ns = "all forces";
        resultantForceMarker.ns = "total forces";
    ctrlMarker.ns = "control";
    effortMarker.ns = "effort";
    normalsMarker.action =
        resultantNormalsMarker.action =
            tangentsMarker.action =
                forcesMarker.action =
                    allForcesMarker.action =
                        resultantForceMarker.action =
                            ctrlMarker.action =
                                effortMarker.action = visualization_msgs::Marker::ADD;
    normalsMarker.pose.orientation.w =
        resultantNormalsMarker.pose.orientation.w =
            tangentsMarker.pose.orientation.w =
                forcesMarker.pose.orientation.w =
                    allForcesMarker.pose.orientation.w =
                        resultantForceMarker.pose.orientation.w =
                            ctrlMarker.pose.orientation.w =
                                effortMarker.pose.orientation.w = 1.0;
    normalsMarker.scale.x =
        resultantNormalsMarker.scale.x =
            tangentsMarker.scale.x =
                forcesMarker.scale.x =
                    allForcesMarker.scale.x = 0.01;
    resultantForceMarker.scale.x =
        ctrlMarker.scale.x =
            effortMarker.scale.x = 0.05;
    resultantForceMarker.scale.y =
        ctrlMarker.scale.y =
            effortMarker.scale.y = 0.10;
    normalsMarker.type =
        tangentsMarker.type =
            forcesMarker.type = visualization_msgs::Marker::LINE_LIST;
    resultantNormalsMarker.type = visualization_msgs::Marker::ARROW;
    allForcesMarker.type = visualization_msgs::Marker::LINE_STRIP;
    resultantForceMarker.type = visualization_msgs::Marker::ARROW;
    ctrlMarker.type = visualization_msgs::Marker::ARROW;
    effortMarker.type = visualization_msgs::Marker::ARROW;

    normalsMarker.id = 0;
    resultantNormalsMarker.id = 1;
    tangentsMarker.id = 2;
    forcesMarker.id = 3;
    allForcesMarker.id = 4;
    resultantForceMarker.id = 5;
    ctrlMarker.id = 6;
    effortMarker.id = 7;

    normalsMarker.color.g = 1.0;
    normalsMarker.color.a = 1.0;
    resultantNormalsMarker.color.r = 1.0;
    resultantNormalsMarker.color.g = 1.0;
    resultantNormalsMarker.color.b = 1.0;
    resultantNormalsMarker.color.a = 1.0;
    tangentsMarker.color.b = 1.0;
    tangentsMarker.color.a = 1.0;
    forcesMarker.color.b = 1.0;
    forcesMarker.color.a = 1.0;
    forcesMarker.color.r = 1.0;
    forcesMarker.color.g = 1.0;
    allForcesMarker.color.r = 1.0;
    allForcesMarker.color.a = 1.0;
    resultantForceMarker.color.r = 1.0;
    resultantForceMarker.color.g = 1.0;
    resultantForceMarker.color.b = 1.0;
    resultantForceMarker.color.a = 1.0;
    ctrlMarker.color.r = 1.0;
    ctrlMarker.color.g = 1.0;
    ctrlMarker.color.b = 1.0;
    ctrlMarker.color.a = 1.0;
    effortMarker.color.r = 1.0;
    effortMarker.color.g = 1.0;
    effortMarker.color.a = 1.0;

    foundMidPoint = false;
    ros::Duration(5).sleep();

}
RVizPublisher::~RVizPublisher(){}

void RVizPublisher::publishToRViz(){
    //cout << "publishToRviz" << endl;
    updateMarkers();
    //cout << "updated markers" << endl;
    rvizPub.publish(normalsMarker);
    //rvizPub.publish(resultantNormalsMarker);
    rvizPub.publish(tangentsMarker);
    rvizPub.publish(forcesMarker);
    rvizPub.publish(allForcesMarker);
    rvizPub.publish(resultantForceMarker);
    rvizPub.publish(ctrlMarker);
    rvizPub.publish(effortMarker);
}

void RVizPublisher::updateMarkers(){
    //cout << "updateMarkers" << endl;
    clearMarkerPointData();
    //cout << "maker point data cleared" << endl;
    normalsMarker.header.stamp =
        resultantNormalsMarker.header.stamp =
            tangentsMarker.header.stamp =
                forcesMarker.header.stamp =
                    allForcesMarker.header.stamp =
                        resultantForceMarker.header.stamp =
                            ctrlMarker.header.stamp =
                                effortMarker.header.stamp = ros::Time::now();

    allForcesMarker.points.push_back(Vector3d(0,0,0).toPointMsg());
    resultantForceMarker.points.push_back(Vector3d(0,0,0).toPointMsg());
    resultantNormalsMarker.points.push_back(Vector3d(-0.0,-1,0).toPointMsg());

    Vector3d sumNormals(0,0,0);

    for ( int i=0; i<contacts.position.size(); i++ ) {
        normalsMarker.points.push_back(contacts.position[i].toPointMsg());
        normalsMarker.points.push_back((contacts.position[i] + scaleVector(contacts.normal[i],0.3)).toPointMsg());
        sumNormals += contacts.normal[i];
        tangentsMarker.points.push_back(contacts.position[i].toPointMsg());
        tangentsMarker.points.push_back((contacts.position[i] + scaleVector(contacts.tangent[i],0.3)).toPointMsg());
        forcesMarker.points.push_back(contacts.position[i].toPointMsg());
        forcesMarker.points.push_back((contacts.position[i] + scaleVector(contacts.force[i], 0.05)).toPointMsg());
        allForcesMarker.points.push_back((Vector3d(allForcesMarker.points[i]) + scaleVector(contacts.force[i],0.05)).toPointMsg()); // This one ends up wrong I think
    }

    resultantNormalsMarker.points.push_back((Vector3d(-0.5,-0.5,0) + scaleVector(sumNormals, 1)).toPointMsg());
    resultantForceMarker.points.push_back(allForcesMarker.points[allForcesMarker.points.size()-1]);

    geometry_msgs::Point p;

    p.x = p.y = 2;
    p.z = 0;
    ctrlMarker.points.push_back(p);
    p.x += ctrlV*cos(ctrlA);
    p.y += ctrlV*sin(ctrlA);
    ctrlMarker.points.push_back(p);

    p.x = p.z = 0;
    p.y = 2;
    effortMarker.points.push_back(p);
    p.z += effort/10.;
    effortMarker.points.push_back(p);
}

void RVizPublisher::clearMarkerPointData(){
    normalsMarker.points.clear();
    resultantNormalsMarker.points.clear();
    tangentsMarker.points.clear();
    forcesMarker.points.clear();
    allForcesMarker.points.clear();
    resultantForceMarker.points.clear();
    ctrlMarker.points.clear();
    effortMarker.points.clear();

}

void RVizPublisher::getData(StateSubscriber stateSub){
    //cout << "GETTING DATA" << endl;
   //snakePose = stateSub.getSnakePose();
    jointPose = stateSub.getJointPose();
    contacts = stateSub.getContacts();
//    for (int i = 0; i < contacts.normal.size(); i++){
//        cout << "normals:" << endl;
//        cout << contacts.normal[i].getX() << endl;
//    }
    ctrlA = stateSub.getCtrlA();
    ctrlV = stateSub.getCtrlV();
    propulsionJoint = stateSub.getPropulsionJoint();
    effort = stateSub.getEffort();
}


void RVizPublisher::obstaclesCallback(const snakebot_visual_data_topic_collector::obstacles::ConstPtr &msg){
    for(int i = 0; i <= 2; i++){
        obstaclePositions[i] = msg->obstacles[i];
    }
}

void RVizPublisher::visualJointsCallback(const snakebot_visual_data_topic_collector::jointposes::ConstPtr &msg){
    for(int joint_num = 0; joint_num <= 12;joint_num++){
        visualJointPoses[joint_num].x = msg->jointposes[joint_num].x;
        visualJointPoses[joint_num].y = msg->jointposes[joint_num].y;
        visualJointPoses[joint_num].theta = msg->jointposes[joint_num].theta;   
    }
}

void RVizPublisher::kinematicsJointsCallback(const snakebot_kinematics::kinematics::ConstPtr &msg){
    for(int joint_num = 0; joint_num <= 12;joint_num++){
        kinematicsJointPoses[joint_num].x = msg->pose[joint_num].x;
        kinematicsJointPoses[joint_num].y = msg->pose[joint_num].y;
        kinematicsJointPoses[joint_num].theta = msg->pose[joint_num].theta;   
    }
}

void RVizPublisher::sgDataCallback(const std_msgs::Float32MultiArray::ConstPtr &msg){
    for(int joint_num = msg->data.size()-1; joint_num >= 0; joint_num--){
        sgData[joint_num] = msg->data[joint_num];
        //cout << "msg->data.size(): "<<msg->data.size()<<endl;
    }
    if(foundMidPoint == false){
        for(int joint_num = 0; joint_num <= 12; joint_num++){
            forceMidpoint[joint_num] = sgData[joint_num];
            cout<<"force midppoint: "<<forceMidpoint[joint_num]<<endl;
        }
        foundMidPoint = true;
    }
}

void RVizPublisher::jointCandidateCallback(const snakebot_pushpoints::pushpointCandidates::ConstPtr &msg){
    for(int candidate = 0; candidate < 3; candidate++){
        pushpointCandidates[candidate] = msg->pushpointcandidates[candidate];
    }
}


void RVizPublisher::publishVisualSnakeJointPose(){
    visualization_msgs::MarkerArray markerarray;
    visualization_msgs::Marker marker;
    for(int joint_num = 0; joint_num <= 3; joint_num++){
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time();
        marker.ns = "visual_joints";
        marker.id = joint_num * 4 +1;
        marker.type = visualization_msgs::Marker::CUBE;
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = visualJointPoses[joint_num*4].x;
        marker.pose.position.y = visualJointPoses[joint_num*4].y;
        marker.pose.position.z = 0.035;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = sin((visualJointPoses[joint_num-1].theta/2)*(M_PI/180));
        marker.pose.orientation.w = cos((visualJointPoses[joint_num-1].theta/2)*(M_PI/180));
        marker.scale.x = 0.01;
        marker.scale.y = 0.01;
        marker.scale.z = 0.01;
        marker.color.a = 1.0; // Don't forget to set the alpha!
        marker.color.r = 1.0;
        marker.color.g = 1.0;
        marker.color.b = 1.0;
        markerarray.markers.push_back(marker);

    }

    //only if using a MESH_RESOURCE marker type:
        rvizVisualJointPub.publish( markerarray );
} 

void RVizPublisher::publishKinematicsSnakeJointPose(){
    visualization_msgs::MarkerArray markerarray;
    visualization_msgs::Marker marker;
    for(int joint_num = 1; joint_num <= 13; joint_num++){
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time();
        marker.ns = "kinematics_joints";
        marker.id = joint_num;
        marker.type = visualization_msgs::Marker::CUBE;
        marker.action = visualization_msgs::Marker::ADD;

         //cout<<"joint_num: "<<joint_num <<" "<<kinematicsJointPoses[joint_num-1].theta<<endl;

        marker.pose.position.x = kinematicsJointPoses[joint_num-1].x;
        marker.pose.position.y = kinematicsJointPoses[joint_num-1].y;
        marker.pose.position.z = 0.035;

        /*tf::Quaternion Q = tf::createQuaternionFromRPY(0,0,(kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        marker.pose.orientation.x = Q.x;
        marker.pose.orientation.y = Q.y;
        marker.pose.orientation.z = Q.z;
        marker.pose.orientation.w = Q.w;*/


        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = sin((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        marker.pose.orientation.w = cos((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        marker.scale.x = 0.01;
        marker.scale.y = 0.01;
        marker.scale.z = 0.01;
        marker.color.a = 1.0; // Don't forget to set the alpha!

        marker.color.r = 0.0;
        marker.color.g = 1.0;
        marker.color.b = 0.0;    

        for(int i = 0; i < sizeof(pushpointCandidates)/sizeof(pushpointCandidates[0]); i++){  
            if((joint_num-1) == pushpointCandidates[i]){     
                marker.color.r = 0.0;
                marker.color.g = 0.0;
                marker.color.b = 1.0;
                break;
            }
        }
        markerarray.markers.push_back(marker);
    }
    //only if using a MESH_RESOURCE marker type:
    rvizKinematicsJointPub.publish( markerarray );
} 

void RVizPublisher::publishVisualObstacle(){
    visualization_msgs::MarkerArray markerarray;
    visualization_msgs::Marker marker;
    for(int obstacle_num = 14; obstacle_num <= 16; obstacle_num++){
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time();
        marker.ns = "obstacles";
        marker.id = obstacle_num;
        marker.type = visualization_msgs::Marker::CYLINDER;
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = obstaclePositions[obstacle_num-14].x;
        marker.pose.position.y = obstaclePositions[obstacle_num-14].y;
        marker.pose.position.z = 0.05;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;
        marker.scale.x = 0.1;
        marker.scale.y = 0.1;
        marker.scale.z = 0.1;

        marker.color.a = 1.0; // Don't forget to set the alpha!
        marker.color.r = 1.0;
        marker.color.g = 1.0;
        marker.color.b = 1.0;
        markerarray.markers.push_back(marker);

    }

    //only if using a MESH_RESOURCE marker type:
    rvizObstaclePub.publish( markerarray );

}



void RVizPublisher::publishVisualNormalForce(){

    visualization_msgs::MarkerArray markerarray;
    visualization_msgs::Marker marker;
    for(int joint_num = 1; joint_num <= 13; joint_num++){
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time();
        marker.ns = "normal_forces";
        marker.id = joint_num;
        marker.type = visualization_msgs::Marker::ARROW;
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = kinematicsJointPoses[joint_num-1].x;
        marker.pose.position.y = kinematicsJointPoses[joint_num-1].y;
        marker.pose.position.z = 0.035;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
       


        if((sgData[joint_num-1] - forceMidpoint[joint_num-1]) <= 0) {
            marker.pose.orientation.z = sin((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180))-1;
            marker.pose.orientation.w = cos((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        }

        else if((sgData[joint_num-1] - forceMidpoint[joint_num-1]) > 0){
            marker.pose.orientation.z = sin((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180))+1;
            marker.pose.orientation.w = cos((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        }

        marker.scale.x = (sgData[joint_num-1] - forceMidpoint[joint_num-1])/2000;
        marker.scale.y = 0.005;
        marker.scale.z = 0.005;
        marker.color.a = 1.0; // Don't forget to set the alpha!
        marker.color.r = 1.0;
        marker.color.g = 0.0;
        marker.color.b = 0.0;
        markerarray.markers.push_back(marker);

    }

    //only if using a MESH_RESOURCE marker type:
    rvizNormalForcePub.publish( markerarray );
} 


void RVizPublisher::publishVisualTangentForce(){
    visualization_msgs::MarkerArray markerarray;
    visualization_msgs::Marker marker;
    for(int joint_num = 1; joint_num <= 13; joint_num++){
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time();
        marker.ns = "tangent_forces";
        marker.id = joint_num;
        marker.type = visualization_msgs::Marker::ARROW;
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = kinematicsJointPoses[joint_num-1].x;
        marker.pose.position.y = kinematicsJointPoses[joint_num-1].y;
        marker.pose.position.z = 0.035;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = sin((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        marker.pose.orientation.w = cos((kinematicsJointPoses[joint_num-1].theta/2)*(M_PI/180));
        
        marker.scale.x = (sgData[joint_num-1] - forceMidpoint[joint_num-1])/2000;
        marker.scale.y = 0.005;
        marker.scale.z = 0.005;
        marker.color.a = 1.0; // Don't forget to set the alpha!
        marker.color.r = 1.0;
        marker.color.g = 0.0;
        marker.color.b = 1.0;
        markerarray.markers.push_back(marker);

    }

    //only if using a MESH_RESOURCE marker type:
    rvizTangentForcePub.publish( markerarray );
} 



