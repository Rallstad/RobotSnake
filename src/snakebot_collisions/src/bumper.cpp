#include "bumper.h"

Bumper::Bumper(){
}

Bumper::Bumper(int link, ros::NodeHandle n)
    : link(link), n(n), messageSequenceId(-1), messageTime(ros::Time::now()){

    char buffer[512];
    if (link == 1){
        linkName = "snakebot::dummy_link";
        collisionName = "snakebot::dummy_link::dummy_link_collision_body_01";
        //cout << "Created bumper 1" << endl;
    }
    else{
        sprintf(buffer, "snakebot::body_%02d", link );
        linkName = std::string(buffer);
        sprintf(buffer, "snakebot::body_%02d::body_%02d_collision", link, link );
        collisionName = std::string(buffer);// = buffer;
        //cout << "Created bumper " << link << endl;
    }
    sprintf(buffer, "/bumper_%02d", link );
    bumperSub = n.subscribe(buffer, 1, &Bumper::bumperCallback, this);



    contacts.link = link;
}

Bumper::Bumper(const Bumper &obj){
    this->link = obj.link;
    this->n = n;
    this->linkName = obj.linkName;
    this->collisionName = obj.collisionName;
    this->contacts = obj.contacts;

    char buffer[512];
    sprintf(buffer, "/bumper_%02d", link );
    this->bumperSub = n.subscribe(buffer, 1, &Bumper::bumperCallback, this);
}


Pose2d Bumper::getPose(){
    return pose;
}

void Bumper::setPose(Pose2d pose){
    this->pose = pose;
}

std::string Bumper::getLinkName(){
    return linkName;
}


void Bumper::addContactData(int state, int contact, const gazebo_msgs::ContactsState::ConstPtr &msg){
    geometry_msgs::Point position;
    position.x = msg->states[state].contact_positions[contact].x;
    position.y = msg->states[state].contact_positions[contact].y;
    position.z = msg->states[state].contact_positions[contact].z;
    geometry_msgs::Vector3 force;
    force.x = msg->states[state].wrenches[contact].force.x;
    force.y = msg->states[state].wrenches[contact].force.y;
    force.z = msg->states[state].wrenches[contact].force.z;
    geometry_msgs::Vector3 normal; // change direction according to propulsion theory
    normal.x = - msg->states[state].contact_normals[contact].x;
    normal.y = - msg->states[state].contact_normals[contact].y;
    normal.z = - msg->states[state].contact_normals[contact].z;
    //cout << "addContactData" << endl;
    geometry_msgs::Vector3 tangent;
    Vector3d normalVector(normal.x, normal.y, normal.z);
    Vector3d zVector(0,0,1);
    Vector3d testTangent(normalVector * zVector);
    //cout << "testTangent angle: " << testTangent.getAngle() << ", pose.orientation: " << pose.orientation << endl;
    if (abs(testTangent.getAngle() - pose.orientation) < M_PI/2){
        tangent.x = testTangent.getX();
        tangent.y = testTangent.getY();
        tangent.z = testTangent.getZ();
        contacts.contact_sides.push_back("right");
    }
    else{
        tangent.x = -testTangent.getX();
        tangent.y = -testTangent.getY();
        tangent.z = -testTangent.getZ();
        contacts.contact_sides.push_back("left");
    }

    contacts.contact_positions.push_back(position);
    contacts.contact_forces.push_back(force);
    contacts.contact_normals.push_back(normal);
    contacts.contact_tangents.push_back(tangent);

}

void Bumper::setMessageHeader(){
    messageSequenceId += 1;
    contacts.header.seq = messageSequenceId;
    messageTime = ros::Time::now();
    contacts.header.stamp = messageTime;
    contacts.header.frame_id = linkName;
}

snakebot_collisions::LinkContacts Bumper::getContacts(){
    return contacts;
}

void Bumper::clearContactData(){
    contacts.contact_sides.clear();
    contacts.contact_normals.clear();
    contacts.contact_tangents.clear();
    contacts.contact_positions.clear();
    contacts.contact_forces.clear();
}

void Bumper::printOutputMessage(){
    cout << "link = " << contacts.link << endl;
    for (int i = 0 ; i < contacts.contact_forces.size() ; i++){
        cout << "force = [" << contacts.contact_forces[i].x << " " << contacts.contact_forces[i].y << " " << contacts.contact_forces[i].z << "]" << endl;
        cout << "normal = [" << contacts.contact_normals[i].x << " " << contacts.contact_normals[i].y << " " << contacts.contact_normals[i].z << "]" << endl;
        cout << "position = [" << contacts.contact_positions[i].x << " " << contacts.contact_positions[i].y << " " << contacts.contact_positions[i].z << "]" << endl;
    }
}

void Bumper::bumperCallback(const gazebo_msgs::ContactsState::ConstPtr &msg){
    if ( msg->states.size() == 0 ){
        return;
    }
    clearContactData();
    //make sure that the received message is sent to the right bumper
    for (int i=0; i < msg->states.size(); i++) {
        if (msg->states[i].collision1_name != collisionName
            &&	msg->states[i].collision2_name != collisionName){
                cout << "Wrong contact message received" << endl;
            }
    }
    messageTime = msg->header.stamp;

    std::vector<std::string> registeredObstacles;
    for ( int i=0; i<msg->states.size(); i++ ) {

        if (msg->states[i].collision1_name == collisionName){
            if (std::find(registeredObstacles.begin(), registeredObstacles.end(), msg->states[i].collision2_name) != registeredObstacles.end()){
                    return;
            }
            else{
                registeredObstacles.push_back(msg->states[i].collision2_name);
            }
        }
        if (msg->states[i].collision2_name == collisionName){
            if (std::find(registeredObstacles.begin(), registeredObstacles.end(), msg->states[i].collision1_name) != registeredObstacles.end()){
                    return;
            }
            else{
                registeredObstacles.push_back(msg->states[i].collision1_name);
            }
        }

        for ( int j=0; j<msg->states[i].contact_positions.size(); j++ ) {
            //filter away contact with ground plane
            if ( !(msg->states[i].collision1_name == "ground_plane::link::collision")
                 && !(msg->states[i].collision2_name == "ground_plane::link::collision")) {


                //the contacts vector is empty
                if (contacts.contact_normals.size() == 0) {
                    addContactData(i,j, msg);
                }
                //the contacts vector is not empty
                else {
                    bool duplicate = false;
                    //check if the new contact is at the same 2d position as a previous one
                    for (int k=0; k<contacts.contact_normals.size(); k++){
                        if ((abs(msg->states[i].contact_positions[j].x-contacts.contact_positions[k].x) < 0.01)
                        &&	(abs(msg->states[i].contact_positions[j].y-contacts.contact_positions[k].y) < 0.01)) {
                            duplicate = true;
                            contacts.contact_forces[k].x += msg->states[i].wrenches[j].force.x;
                            contacts.contact_forces[k].y += msg->states[i].wrenches[j].force.y;
                            contacts.contact_forces[k].z += msg->states[i].wrenches[j].force.z;
                            break;
                        }
                    }
                    if (duplicate == false){
                        addContactData(i,j, msg);
                    }
                }
            }
        }
    }
}

