#include "pushpointextractor.h"

PushpointExtractor::PushpointExtractor(ros::NodeHandle n, int numberOfLinks): n(n), numberOfLinks(numberOfLinks), threePushPointsFound(false){
   // snakeContactsSub = n.subscribe("/snakebot/collisions", 1, &PushpointExtractor::snakeContactsCallback, this);
    snakeContactsMatlabSub = n.subscribe("/snakebot/collisionsFromMatlab", 1, &PushpointExtractor::snakeContactsCallback,this);
    //snakeConfigurationSub = n.subscribe("/snakebot/real_snake_pose", 100, &PushpointExtractor::snakePoseCallback,this);
    

    //SGSub = n.subscribe("from_matlab/SG", 1, &PushpointExtractor::mambaExtractPushPoints, this);
    pushPointPub = n.advertise<snakebot_pushpoints::Pushpoints>("/snakebot/pushpoints", 1);
    
    LabVIEW_PushPointsPub = n.advertise<snakebot_pushpoints::Pushpoints>("LabVIEW_ROS/from_ROS_push_points", 1);

}

//parameter changed from snakebot_pushpoints
void PushpointExtractor::snakeContactsCallback(const snakebot_matlab_communication::collisionList::ConstPtr &contactMsg){
    snakebot_pushpoints::Pushpoints pushPointMsg;

    pushPointMsg = extractPushpoints(contactMsg);
    if (threePushPointsFound == true){
        publishPushPoints(pushPointMsg);
    }
}

void PushpointExtractor::publishPushPoints(snakebot_pushpoints::Pushpoints pushPointMsg){
    pushPointPub.publish(pushPointMsg);

    //LabVIEW_PushPointsPub.publish(pushPointMsg);
}
//parameter changed from snakebot_pushpoints
snakebot_pushpoints::Pushpoints PushpointExtractor::extractPushpoints(const snakebot_matlab_communication::collisionList::ConstPtr& contactMsg){
    snakebot_pushpoints::Pushpoints pushPointMsg;
    std::string obstacleSide = "empty";
    int pushPointsAdded = 0;
    for (int i = 0 ; (i < contactMsg->link.size()) && (pushPointsAdded < 3) ; i++){
        if (pushPointsAdded == 2){
            pushPointMsg.centerContactLink = pushPointMsg.link_numbers[1];
        }
        for (int j = 0 ; j < contactMsg->link[i].contact_normals.size() ; j++){
            if (obstacleSide == "empty"){
                pushPointMsg.contact_normals.push_back(contactMsg->link[i].contact_normals[j]);
                pushPointMsg.contact_tangents.push_back(contactMsg->link[i].contact_tangents[j]);
                pushPointMsg.contact_positions.push_back(contactMsg->link[i].contact_positions[j]);
                pushPointMsg.link_numbers.push_back(contactMsg->link[i].link);
                obstacleSide = contactMsg->link[i].contact_sides[j];
                //cout<<"contactmsg_contactside: "<<contactMsg->link[i].contact_sides[j];
                cout<<"Obstacleside: "<<obstacleSide<<endl;
                pushPointMsg.contact_sides.push_back(obstacleSide);
                pushPointsAdded++;
                break;
            }
            if (obstacleSide == "left"){
                if (contactMsg->link[i].contact_sides[j] == "left"){
                    continue;
                }
                else if (contactMsg->link[i].contact_sides[j] == "right"){
                    pushPointMsg.contact_normals.push_back(contactMsg->link[i].contact_normals[j]);
                    pushPointMsg.contact_tangents.push_back(contactMsg->link[i].contact_tangents[j]);
                    pushPointMsg.contact_positions.push_back(contactMsg->link[i].contact_positions[j]);
                    pushPointMsg.link_numbers.push_back(contactMsg->link[i].link);
                    obstacleSide = contactMsg->link[i].contact_sides[j];
                    cout<<"Obstacleside: "<<obstacleSide<<endl;
                    pushPointMsg.contact_sides.push_back(obstacleSide);
                    pushPointsAdded++;
                    break;
                }
            }
            if (obstacleSide == "right"){
                if (contactMsg->link[i].contact_sides[j] == "right"){
                    continue;
                }
                else if (contactMsg->link[i].contact_sides[j] == "left"){
                    pushPointMsg.contact_normals.push_back(contactMsg->link[i].contact_normals[j]);
                    pushPointMsg.contact_tangents.push_back(contactMsg->link[i].contact_tangents[j]);
                    pushPointMsg.contact_positions.push_back(contactMsg->link[i].contact_positions[j]);
                    pushPointMsg.link_numbers.push_back(contactMsg->link[i].link);
                    obstacleSide = contactMsg->link[i].contact_sides[j];
                    cout<<"Obstacleside: "<<obstacleSide<<endl;
                    pushPointMsg.contact_sides.push_back(obstacleSide);
                    pushPointsAdded++;
                    break;
                }
            }
        }

    }
    cout<<"pushpoints: "<<pushPointsAdded<<endl;
    if (pushPointsAdded == 3){
        threePushPointsFound = true;
    }
    else{
        threePushPointsFound = false;
    }
    return pushPointMsg;

}

void PushpointExtractor::mambaExtractPushPoints(const std_msgs::Float32MultiArray::ConstPtr& sgMsg){
    bool firstPushpoint = true;
    std::string contactside;
    std::vector<std::string> pushpointsside;
    std::vector<int> pushpointsjoint;    
    for(int i=sgMsg->data.size();i>0;i-=1){
        //cout<<i<<endl;
        if(firstPushpoint){
            if(sgMsg->data[i-1]< -0.5){
                pushpointsside.push_back("right");
                pushpointsjoint.push_back(i-1);
                contactside = "right";
            }
            else if(sgMsg->data[i-1] > 0.5){
                pushpointsside.push_back("left");
                pushpointsjoint.push_back(i-1);
                contactside = "left";
            }
            firstPushpoint = false;
        }
        if(!firstPushpoint && contactside =="left"){
            if(sgMsg->data[i-1]< -0.5){
                pushpointsside.push_back("right");
                pushpointsjoint.push_back(i-1);
                contactside = "right";
            }
        }
        if(!firstPushpoint && contactside == "right"){
            if(sgMsg->data[i-1]> 0.5){
                pushpointsside.push_back("left");
                pushpointsjoint.push_back(i-1);
                contactside = "left";
            }
        }
    }
    if(pushpointsjoint.size()>= 3){
        cout<<pushpointsjoint.size()<<" pushpoints found"<<endl;
        for(int i=0;i<pushpointsjoint.size(); i++){
            cout<<"Pushpoints: "<<pushpointsjoint[i]<<endl;
            cout<<pushpointsside[i]<<endl;
        }
    }
    else if(pushpointsjoint.size()<3){
        cout<<pushpointsjoint.size()<<" pushpoints found"<<endl;
        for(int i=0;i<pushpointsjoint.size();i++){
            cout<<"Pushpoints: "<<pushpointsjoint[i]<<endl;
            cout<<pushpointsside[i]<<endl;
            cout<<"too few"<<endl;
        }
    }
}