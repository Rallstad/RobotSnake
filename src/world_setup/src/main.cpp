//#include "world_setup.h"
#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"
#include <fstream>
#include <iostream>
#include <string>
#include <tinyxml.h>
#include "sstream"
#include "snakebot_labview_communication/Float64Array.h"
#include "snakebot_labview_communication/Int32Array.h"
//#include "stdafx.h"

using namespace std;


class world_setup{
private:
	geometry_msgs::Pose2D obstaclePoses[3];
	geometry_msgs::Pose2D snakeHead;
	float jointStates[13];
	bool obstacle1PoseAcquired = false;
	bool obstacle2PoseAcquired = false;
	bool obstacle3PoseAcquired = false;
	bool snakeHeadPoseAcquired = false;

	ros::NodeHandle n;
	ros::Subscriber obstacle1Sub;
	ros::Subscriber obstacle2Sub;
	ros::Subscriber obstacle3Sub;
	ros::Subscriber snakeHeadSub;
	ros::Subscriber snakeJointPositionSub;

	void Obstacle1PoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void Obstacle2PoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void Obstacle3PoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void joint_0Callback(const geometry_msgs::Pose2D::ConstPtr &msg);
	void jointStateCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg);

public:
	world_setup(ros::NodeHandle nodeHandle);
	void writeObstacleFile();
	bool getPoseAcquired(int obstacle_num);
	void simulateSnake();

};


world_setup::world_setup(ros::NodeHandle nodeHandle){
	n = nodeHandle;
	obstacle1Sub = n.subscribe("/obstacle_1/ground_pose", 10, &world_setup::Obstacle1PoseCallback, this);
	obstacle2Sub = n.subscribe("/obstacle_2/ground_pose", 10, &world_setup::Obstacle2PoseCallback, this);
	obstacle3Sub = n.subscribe("/obstacle_3/ground_pose", 10, &world_setup::Obstacle3PoseCallback, this);
	snakeHeadSub = n.subscribe("/joint_12/ground_pose", 10, &world_setup::joint_0Callback, this);
	snakeJointPositionSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles", 20, &world_setup::jointStateCallback, this);
}

void world_setup::Obstacle1PoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg){
	obstaclePoses[0] = *msg;
	if(obstaclePoses[0].x != 0 && obstaclePoses[0].y != 0){
		obstacle1PoseAcquired = true;
	}
}

void world_setup::Obstacle2PoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg){
	obstaclePoses[1] = *msg;
	if(obstaclePoses[1].x != 0 && obstaclePoses[1].y != 0){
		obstacle2PoseAcquired = true;
	}

}
void world_setup::Obstacle3PoseCallback(const geometry_msgs::Pose2D::ConstPtr &msg){
	obstaclePoses[2] = *msg;
	if(obstaclePoses[2].x != 0 && obstaclePoses[2].y != 0){
		obstacle3PoseAcquired = true;
	}

}


void world_setup::joint_0Callback(const geometry_msgs::Pose2D::ConstPtr &msg){
	snakeHead = *msg;
	if(snakeHead.x != 0 && snakeHead.y != 0){
		snakeHeadPoseAcquired = true;
	}
}

void world_setup::jointStateCallback(const snakebot_labview_communication::Float64Array::ConstPtr &msg){
	for(int joint_num = 0; joint_num < msg->data.size();joint_num++){
		if(joint_num == 9 || joint_num == 11){
			jointStates[joint_num] = -msg->data[joint_num];
		}
		else{
			jointStates[joint_num] = msg->data[joint_num];
		}

	}

}


bool world_setup::getPoseAcquired(int obstacle_num){
	switch(obstacle_num){
		case 1:
			return obstacle1PoseAcquired;
		case 2:
			return obstacle2PoseAcquired;
		case 3:
			return obstacle3PoseAcquired;
		case 4:
			return snakeHeadPoseAcquired;
		default:
			return 0;

	}
}


void world_setup::writeObstacleFile(){
	char obstacle1[32];
	char obstacle2[32];
	char obstacle3[32];
	sprintf(obstacle1, "%f %f %d %d %d %d", obstaclePoses[0].x, obstaclePoses[0].y, 0,0,0,0);
	sprintf(obstacle2, "%f %f %d %d %d %d", obstaclePoses[1].x, obstaclePoses[1].y, 0,0,0,0);
	sprintf(obstacle3, "%f %f %d %d %d %d", obstaclePoses[2].x, obstaclePoses[2].y, 0,0,0,0);

	const char* demoStart = 
		"<?xml version=\"1.0\"?>"
		"<sdf version=\"1.4\">" 
		"<world name=\"myworld\">" 
		"<include>" 
		"<uri>model://sun</uri>" 
		"</include>" 
		"<include>" 
    	"<uri>model://ground_plane</uri>" 
  		"</include>" 
  		"<model name ='cylinder_1'>" 
  		"<pose></pose>" 
   		"<link name ='cyl'>" 
       	"<pose>0 0 0.1 0 0 0</pose>" 
      	"<collision name ='collision'>" 
        "<geometry>" 
        "<cylinder><radius>0.1</radius><length>0.2</length></cylinder>" 
        "</geometry>" 
       	"</collision>" 
       	"<visual name ='visual'>" 
        "<geometry>" 
        "<cylinder><radius>0.1</radius><length>0.2</length></cylinder>" 
        "</geometry>" 
       	"</visual>" 
   		"</link>" 
   		"<static>1</static>" 
		"</model>" 
		"<model name ='cylinder_2'>" 
   		"<pose></pose>" 
   		"<link name ='cyl'>" 
       	"<pose>0 0 0.1 0 0 0</pose>" 
       	"<collision name ='collision'>" 
        "<geometry>" 
        "<cylinder><radius>0.1</radius><length>0.2</length></cylinder>" 
        "</geometry>" 
       	"</collision>" 
       	"<visual name ='visual'>" 
        "<geometry>" 
        "<cylinder><radius>0.1</radius><length>0.2</length></cylinder>" 
        "</geometry>" 
       	"</visual>" 
   		"</link>" 
  		"<static>1</static>" 
		"</model>" 
		"<model name ='cylinder_3'>" 
   		"<pose></pose>" 
   		"<link name ='cyl'>" 
       	"<pose>0 0 0.1 0 0 0</pose>" 
       	"<collision name ='collision'>" 
        "<geometry>" 
        "<cylinder><radius>0.1</radius><length>0.2</length></cylinder>" 
        "</geometry>" 
       	"</collision>" 
       	"<visual name ='visual'>" 
        "<geometry>" 
        "<cylinder><radius>0.1</radius><length>0.2</length></cylinder>" 
        "</geometry>" 
       	"</visual>" 
   		"</link>" 
   		"<static>1</static>" 
		"</model>" 
		"</world>" 
		"</sdf>" ;
		
	{

	TiXmlDocument doc( "/home/snake/Documents/catkin_ws/src/snakebot_gazebo/worlds/snakebot.world" );

		doc.Parse( demoStart );

		if ( doc.Error() )
		{
			printf( "Error in %s: %s\n", doc.Value(), doc.ErrorDesc() );
			exit( 1 );
		}
		doc.SaveFile();
	}

	TiXmlDocument doc( "/home/snake/Documents/catkin_ws/src/snakebot_gazebo/worlds/snakebot.world" );
		bool loadOkay = doc.LoadFile();

		if ( !loadOkay )
		{
			printf( "Could not load test file '/home/snake/Documents/catkin_ws/src/snakebot_gazebo/worlds/snakebot_custom.world'. Error='%s'. Exiting.\n", doc.ErrorDesc() );
			exit( 1 );
		}

	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemElement = 0;
	node = doc.FirstChild( "sdf" )->FirstChild("world")->FirstChild("model")->FirstChild("pose")->ToElement();
	assert(node);

	char buf[256];
	snprintf(buf, sizeof(buf), "%s", obstacle1);
	TiXmlText * text = new TiXmlText(buf);
	itemElement = node->ToElement();//->FirstChild()->ToElement();
	assert( itemElement  );
	itemElement->LinkEndChild(text);

	node = doc.FirstChild( "sdf" )->FirstChild("world")->FirstChild("model")->NextSibling()->FirstChild("pose")->ToElement();
	itemElement = node->ToElement();
	assert(itemElement);
	char abuf[256];
	snprintf(abuf, sizeof(buf), "%s", obstacle2);
	TiXmlText * atext = new TiXmlText(abuf);
	itemElement->LinkEndChild(atext);

	node = doc.FirstChild( "sdf" )->FirstChild("world")->FirstChild("model")->NextSibling()->NextSibling()->FirstChild("pose")->ToElement();
	itemElement = node->ToElement();
	assert(itemElement);
	char bbuf[256];
	snprintf(bbuf, sizeof(buf), "%s", obstacle3);
	TiXmlText * btext = new TiXmlText(bbuf);
	itemElement->LinkEndChild(btext);

	doc.SaveFile();
	
}


void world_setup::simulateSnake(){
	const char* demoStart = 
		"<launch>"	  
		"<include file=\"$(find gazebo_ros)/launch/empty_world.launch\">"	    
		"<arg name=\"world_name\" value=\"$(find snakebot_gazebo)/worlds/snakebot.world\"/>"	    
		"<arg name=\"gui\" value=\"true\"/>"	  
		"</include>"
		"<param name=\"robot_description\" command=\"$(find xacro)/xacro.py $(find snakebot_description)/urdf/snakebot.xacro\" />"
		"<node name=\"snakebot_spawn\" pkg=\"gazebo_ros\" type=\"spawn_model\" output=\"screen\""
		"args=\"-urdf -param robot_description -model snakebot -J joint_01 -J joint_02 -J joint_03 -J joint_04 -J joint_05 -J joint_06 -J joint_07 -J joint_08 -J joint_09 -J joint_10 -J joint_11 -J joint_12 -J joint_13 \" />" 
		"</launch>";
	{
		cout<<"jointStates1: "<<jointStates[0]<<endl;
		cout<<"jointStates2: "<<jointStates[1]<<endl;
		cout<<"jointStates3: "<<jointStates[2]<<endl;
		cout<<"jointStates4: "<<jointStates[3]<<endl;
		cout<<"jointStates5: "<<jointStates[4]<<endl;
		cout<<"jointStates6: "<<jointStates[5]<<endl;
		cout<<"jointStates7: "<<jointStates[6]<<endl;
		cout<<"jointStates8: "<<jointStates[7]<<endl;
		cout<<"jointStates9: "<<jointStates[8]<<endl;
		cout<<"jointStates10: "<<jointStates[9]<<endl;
		cout<<"jointStates11: "<<jointStates[10]<<endl;
		cout<<"jointStates12: "<<jointStates[11]<<endl;
		cout<<"jointStates13: "<<jointStates[12]<<endl;



	TiXmlDocument doc( "/home/snake/Documents/catkin_ws/src/snakebot_gazebo/launch/snakebot_world.launch" );

		doc.Parse( demoStart );

		if ( doc.Error() )
		{
			printf( "Error in %s: %s\n", doc.Value(), doc.ErrorDesc() );
			exit( 1 );
		}
		doc.SaveFile();
	}

	TiXmlDocument doc( "/home/snake/Documents/catkin_ws/src/snakebot_gazebo/launch/snakebot_world.launch" );
		bool loadOkay = doc.LoadFile();

		if ( !loadOkay )
		{
			printf( "Could not load test file '/home/snake/Documents/catkin_ws/src/snakebot_gazebo/worlds/snakebot.world'. Error='%s'. Exiting.\n", doc.ErrorDesc() );
			exit( 1 );
		}

	char xyzStr[512]; // This can be done easier I think. Something may be superfluous
	char kisBuf[512];
	sprintf(xyzStr, "%s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f %s %f" ,"-urdf -param robot_description -model snakebot -x" ,snakeHead.x,
		" -y",snakeHead.y, " -z 0 -J joint_01", jointStates[0], "-J joint_02", jointStates[1], " -J joint_03 ", jointStates[2], " -J joint_04 ", jointStates[3], " -J joint_05 ", jointStates[4],
		 " -J joint_06 ", jointStates[5], " -J joint_07 ", jointStates[6], " -J joint_08 ", jointStates[7], " -J joint_09 ", jointStates[8], " -J joint_10 ", jointStates[9],
		  " -J joint_11 ", jointStates[10], " -J joint_12 ", jointStates[11], " -J joint_13 ", jointStates[12]);

	snprintf(kisBuf, sizeof(kisBuf), "%s", xyzStr);

	//cout<<kisBuf<<endl;
	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemElement = 0;
	node = doc.FirstChild( "launch" )->FirstChild("node")->ToElement();
	itemElement = node->ToElement();
	assert(itemElement);
	itemElement->SetAttribute("args", kisBuf);

	doc.SaveFile();
	
}


int main(int argc, char **argv){
	ros::init(argc, argv, "world_setup");
	ros::NodeHandle n;

	world_setup World_setup(n);
	bool fileWritten = 0;
	

	while(!fileWritten){
		ros::spinOnce();
		//build_simple_doc();
		if(World_setup.getPoseAcquired(1) && World_setup.getPoseAcquired(2) && World_setup.getPoseAcquired(3) && World_setup.getPoseAcquired(4)){
			World_setup.simulateSnake();
			World_setup.writeObstacleFile();
			fileWritten = 1;
		}
	}
	return 0;
}