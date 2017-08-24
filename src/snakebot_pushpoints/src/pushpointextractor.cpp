#include "pushpointextractor.h"

PushpointExtractor::PushpointExtractor(ros::NodeHandle n, int numberOfLinks): n(n), numberOfLinks(numberOfLinks), threePushPointsFound(false){
    snakeContactsSub = n.subscribe("/snakebot/collisions", 1, &PushpointExtractor::snakeContactsCallback, this);
    pushPointPub = n.advertise<snakebot_pushpoints::Pushpoints>("/snakebot/pushpoints", 1);

    LabVIEW_PushPointsPub = n.advertise<snakebot_pushpoints::Pushpoints>("LabVIEW_ROS/from_ROS_push_points", 1);
}


void PushpointExtractor::snakeContactsCallback(const snakebot_collisions::SnakeContacts::ConstPtr &contactMsg){
    snakebot_pushpoints::Pushpoints pushPointMsg;
    pushPointMsg = extractPushpoints(contactMsg);
    if (threePushPointsFound == true){
        publishPushPoints(pushPointMsg);
    }
}

void PushpointExtractor::publishPushPoints(snakebot_pushpoints::Pushpoints pushPointMsg){
    pushPointPub.publish(pushPointMsg);

    LabVIEW_PushPointsPub.publish(pushPointMsg);
}

snakebot_pushpoints::Pushpoints PushpointExtractor::extractPushpoints(const snakebot_collisions::SnakeContacts::ConstPtr& contactMsg){
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
                    pushPointMsg.contact_sides.push_back(obstacleSide);
                    pushPointsAdded++;
                    break;
                }
            }
        }
    }
    if (pushPointsAdded == 3){
        threePushPointsFound = true;
    }
    else{
        threePushPointsFound = false;
    }
    return pushPointMsg;

}
