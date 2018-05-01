#include "matlab_communication.h"

Snake::Snake(ros::NodeHandle n){

	SGDataJointSub = n.subscribe("from_matlab/SG", 10, &Snake::SGDataJointCallback, this);
	SnakePoseSub = n.subscribe("/snakebot/real_snake_pose", 10, &Snake::SnakePoseCallback, this);
	obstacleSub = n.subscribe("/snakebot/obstaclePosition", 100, &Snake::obstacleCallback, this);
	//SGPub = n.advertise()
	//CollisionPub = n.advertise...
	/*SGDataJoint2Sub = n.subscribe("from_matlab/SG_joint2", 100, &Snake::SGDataJoint2Callback, this);
	SGDataJoint3Sub = n.subscribe("from_matlab/SG_joint3", 100, &Snake::SGDataJoint3Callback, this);
	SGDataJoint4Sub = n.subscribe("from_matlab/SG_joint4", 100, &Snake::SGDataJoint4Callback, this);
	SGDataJoint5Sub = n.subscribe("from_matlab/SG_joint5", 100, &Snake::SGDataJoint5Callback, this);
	SGDataJoint6Sub = n.subscribe("from_matlab/SG_joint6", 100, &Snake::SGDataJoint6Callback, this);
	SGDataJoint7Sub = n.subscribe("from_matlab/SG_joint7", 100, &Snake::SGDataJoint7Callback, this);
	SGDataJoint8Sub = n.subscribe("from_matlab/SG_joint8", 100, &Snake::SGDataJoint8Callback, this);
	SGDataJoint9Sub = n.subscribe("from_matlab/SG_joint9", 100, &Snake::SGDataJoint9Callback, this);
	SGDataJoint10Sub = n.subscribe("from_matlab/SG_joint10", 100, &Snake::SGDataJoint10Callback, this);
	SGDataJoint11Sub = n.subscribe("from_matlab/SG_joint11", 100, &Snake::SGDataJoint11Callback, this);
	SGDataJoint12Sub = n.subscribe("from_matlab/SG_joint12", 100, &Snake::SGDataJoint12Callback, this);
	SGDataJoint13Sub = n.subscribe("from_matlab/SG_joint13", 100, &Snake::SGDataJoint13Callback, this);*/
	CollisionListPub = n.advertise<snakebot_matlab_communication::collisionList>("/snakebot/collisionsFromMatlab",13);
	pushpointCandidatesPub = n.advertise<snakebot_matlab_communication::pushpointCandidates>("/snakebot/pushpointCandidates",10);

	
}

Snake::~Snake(){}

void Snake::SGDataJointCallback(const std_msgs::Float32MultiArray::ConstPtr &msg){
	for(int jointNum = msg->data.size()-1;jointNum >= 0; jointNum--){
		this->SGData[jointNum] = msg->data[jointNum];
	}
}

void Snake::SnakePoseCallback(const snakebot_kinematics::kinematics::ConstPtr& msg){
	for(int jointNum = 0;jointNum<msg->pose.size();jointNum++){
		this->jointPoses[jointNum].x = msg->pose[jointNum].x;
		this->jointPoses[jointNum].y = msg->pose[jointNum].y;
		this->jointPoses[jointNum].theta = msg->pose[jointNum].theta;
	}
}

void Snake::publishCollisions(){
	//Because of how the pushpointextractor finds pushpoints, the order of the joints has to be reversed
	
	snakebot_matlab_communication::collisionList list;
	int tempJoint = 0;
	for(int jointNum = 0; jointNum <=12; jointNum++){

		snakebot_matlab_communication::collision msg;
		msg.link = jointNum;

		geometry_msgs::Vector3 normal_vector = getContactNormal(getContactSide(jointNum),jointPoses[jointNum].theta);
		string side = getContactSide(tempJoint);
		string tempSide = getContactSide(tempJoint + 1);
		if(side == tempSide){
			tempJoint ++;
		}
		else{
			msg.contact_sides.push_back(side);
			if(sqrt(normal_vector.x*normal_vector.x + normal_vector.y*normal_vector.y + normal_vector.z*normal_vector.z)>0){
			msg.contact_normals.push_back(getContactNormal(getContactSide(jointNum),jointPoses[jointNum].theta));	
		}
			tempJoint ++;
		}
		
		
		//msg.contact_normals.push_back(getContactNormal(getContactSide(jointNum),jointPoses[jointNum].theta));
		msg.contact_tangents.push_back(getContactTangent(getContactSide(jointNum), jointPoses[jointNum].theta));
		msg.contact_positions.push_back(getContactPosition(getContactSide(jointNum), jointPoses[jointNum]));
		list.link.push_back(msg);
	}
	CollisionListPub.publish(list);
	//CollisionPub.pub(msg);
}

string Snake::getContactSide(int joint_num){
	float distance = 1000;
	int closest_obstacle = 10;
	for(int obstacle_num = 0;obstacle_num<3;obstacle_num++){
		if(getJointDistance2Obstacle(joint_num,obstacle_num) < distance){
			distance = getJointDistance2Obstacle(joint_num,obstacle_num);
			closest_obstacle = obstacle_num;
		}
	}
	float x = obstacles[closest_obstacle].x - jointPoses[joint_num].x;
    float y = obstacles[closest_obstacle].y - jointPoses[joint_num].y;
    float angle = atan2(y,x);
    if(distance < 0.20){
		if(angle >= 0){
	    	return "left";
	    }
	    else{
			return "right";
	    }
	}
	else{
		return "none";
	}
	/*if(contactForce > 0.0){
		return "left";
	}
	else if(contactForce < -0.0){
		return "right";
	}
	else{
		return "none";
	}*/
}

geometry_msgs::Vector3 Snake::getContactNormal(string contactSide, float jointAngle){
	geometry_msgs::Vector3 normal;
	if(contactSide == "left"){
		normal.x = cos((jointAngle*M_PI/180)-M_PI/2);
		normal.y = sin((jointAngle*M_PI/180)-M_PI/2);
		normal.z = 0.0;
	}
	else if(contactSide == "right"){
		normal.x = cos((jointAngle*M_PI/180)+M_PI/2);
		normal.y = sin((jointAngle*M_PI/180)+M_PI/2);
		normal.z = 0.0;
	}
	else if(contactSide == "none"){
		normal.x = 0;
		normal.y = 0;
		normal.z = 0;
	}
	return normal;
}

geometry_msgs::Vector3 Snake::getContactTangent(string contactSide, float jointAngle){
	geometry_msgs::Vector3 tangent;

	if(contactSide == "none"){
		tangent.x = 0;
		tangent.y = 0;
		tangent.z = 0;
	}
	else{
		tangent.x = cos(jointAngle*M_PI/180);
		tangent.y = sin(jointAngle*M_PI/180);
		tangent.z = 0;
	}
	return tangent;
}

geometry_msgs::Point Snake::getContactPosition(string contactSide, geometry_msgs::Pose2D jointPose){
	geometry_msgs::Point contactpos;

	if(contactSide == "left"){
		contactpos.x = jointPose.x-(0.5*linkWidth*sin(jointPose.theta));
		contactpos.y = jointPose.y+(0.5*linkWidth*cos(jointPose.theta));
		contactpos.z = 0.0;
	}
	else if(contactSide == "right"){
		contactpos.x = jointPose.x+(0.5*linkWidth*sin(jointPose.theta));
		contactpos.y = jointPose.y-(0.5*linkWidth*cos(jointPose.theta));
		contactpos.z = 0.0;
	}
	else if(contactSide == "none"){
		contactpos.x = 0.0;
		contactpos.y = 0.0;
		contactpos.z = 0.0;	
	}
	return contactpos;
}


void Snake::obstacleCallback(const snakebot_visual_data_topic_collector::obstacles::ConstPtr& msg){
    for(int obstacle_num = 0; obstacle_num < 3; obstacle_num++){
        obstacles[obstacle_num].x = msg->obstacles[obstacle_num].x;
        obstacles[obstacle_num].y = msg->obstacles[obstacle_num].y;
    }
}

float Snake::getJointDistance2Obstacle(int joint, int obstacle){
    float distance = sqrt(pow((jointPoses[joint].x - obstacles[obstacle].x),2) + pow((jointPoses[joint].y - obstacles[obstacle].y),2));
    return distance;
}

void Snake::getJointCandidate(){
    int jointCandidate;
    std::string side = "none";
    std::string prevSide = "none";
    for(int obstacle_num = 0; obstacle_num < 3; obstacle_num++){
        float shortestDistance = 1000;
        for(int joint_num = 0; joint_num < 13; joint_num++){
            float distance = getJointDistance2Obstacle(joint_num, obstacle_num);
            float x = obstacles[obstacle_num].x - jointPoses[joint_num].x;
            float y = obstacles[obstacle_num].y - jointPoses[joint_num].y;
            float angle = atan2(y,x);
            //cout << "obstacle_num: " << obstacle_num<< " angle: "<< angle<<endl;

            if(distance < shortestDistance && distance < 0.20){
                shortestDistance = distance;
                jointCandidate = joint_num;

                if(angle >= 0){
                    side = "left";
                }
                else{
                    side = "right";
                }
            }


        }        
        contactSides.push_back(side);
             //cout<<"side: "<<side<<endl;
        if(prevSide != side){
            prevSide = side;
            for(int joint_candidate = 0; joint_candidate < sizeof(jointCandidates)/sizeof(jointCandidates[0]); joint_candidate++){
                if(jointCandidates[joint_candidate] != jointCandidate){
                    jointCandidates[obstacle_num] = jointCandidate;
                    
                   
                }
            }
        }
        else{
            prevSide = side;
            jointCandidates[obstacle_num] = -1;
        }     
    }
    cout << "-----------------------------------"<<endl;
   // cout << "jointCandidates: "<< jointCandidates[0]<< jointCandidates[1]<< jointCandidates[2]<<endl;
    //cout << "numberOfCandidates: " << sizeof(jointCandidates)/sizeof(jointCandidates[0]) << endl;
}

void Snake::publishJointCandidates(){
    snakebot_matlab_communication::pushpointCandidates candidate;
    for(int i = 0; i <= 2; i++){
        candidate.pushpointcandidates.push_back(jointCandidates[i]);
    }
    pushpointCandidatesPub.publish(candidate);
}