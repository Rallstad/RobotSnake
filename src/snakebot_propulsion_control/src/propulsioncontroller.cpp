#include "propulsioncontroller.h"


PropulsionController::PropulsionController(ros::NodeHandle handle)
{
	n = handle;
    obstacleDataSub = n.subscribe("/snakebot/pushpoints", 1000, &PropulsionController::obstacleDataCallback, this);
    propForceSub = n.subscribe("/snakebot/propulsion_force", 1000, &PropulsionController::propulsionForceCallback, this);
    robotPoseSub = n.subscribe("snakebot/robot_pose", 1000, &PropulsionController::snakePoseCallback,this);
    propulsionEffortPub = n.advertise<snakebot_propulsion_control::PropulsionEffort>("/snakebot/propulsion_effort", 1000);
    obstacleDataInitialized = false;
    positionDataInitialized = false;
    propForceReceived = false;

    //Set length of vectors
}
PropulsionController::~PropulsionController()
{
}

void PropulsionController::setPhysicalSpec(double totalMass, double linkLength, double linkWidth, double linkHeight, double linkToJointLength){
    this->totalMass = totalMass;
    this->linkLength = linkLength;
    this->linkWidth = linkWidth;
    this->linkHeight = linkHeight;
    this->linkToJointLength = linkToJointLength;
}


// CALLBACK FUNCTIONS //////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////
void PropulsionController::obstacleDataCallback(const snakebot_pushpoints::Pushpoints::ConstPtr& msg){

    this->n1 = Vector3d(reduceForceResolution(msg->contact_normals[0].x),reduceForceResolution(msg->contact_normals[0].y),reduceForceResolution(msg->contact_normals[0].z));
    this->n2 = Vector3d(reduceForceResolution(msg->contact_normals[1].x),reduceForceResolution(msg->contact_normals[1].y),reduceForceResolution(msg->contact_normals[1].z));
    this->n3 = Vector3d(reduceForceResolution(msg->contact_normals[2].x),reduceForceResolution(msg->contact_normals[2].y),reduceForceResolution(msg->contact_normals[2].z));
    this->t1 = Vector3d(reduceForceResolution(msg->contact_tangents[0].x),reduceForceResolution(msg->contact_tangents[0].y),reduceForceResolution(msg->contact_tangents[0].z));
    this->t2 = Vector3d(reduceForceResolution(msg->contact_tangents[1].x),reduceForceResolution(msg->contact_tangents[1].y),reduceForceResolution(msg->contact_tangents[1].z));
    this->t3 = Vector3d(-reduceForceResolution(msg->contact_tangents[2].x),-reduceForceResolution(msg->contact_tangents[2].y),-reduceForceResolution(msg->contact_tangents[2].z));
/*
    this->n1 = Vector3d(msg->contact_normals[0].x, msg->contact_normals[0].y, msg->contact_normals[0].z);
    this->n2 = Vector3d(msg->contact_normals[1].x, msg->contact_normals[1].y, msg->contact_normals[1].z);
    this->n3 = Vector3d(msg->contact_normals[2].x, msg->contact_normals[2].y, msg->contact_normals[2].z);
    this->t1 = Vector3d(msg->contact_tangents[0].x, msg->contact_tangents[0].y, msg->contact_tangents[0].z);
    this->t2 = Vector3d(msg->contact_tangents[1].x, msg->contact_tangents[1].y, msg->contact_tangents[1].z);
    this->t3 = Vector3d(-msg->contact_tangents[2].x, -msg->contact_tangents[2].y, -msg->contact_tangents[2].z); // Defined opposite direction, see the pdf*/

    this->c1 = Position3d(reduceContactPositionResolution(msg->contact_sides[0],msg->link_numbers[0],true,false,0),reduceContactPositionResolution(msg->contact_sides[0],msg->link_numbers[0],false,true,0),0.1);
    this->c2 = Position3d(reduceContactPositionResolution(msg->contact_sides[1],msg->link_numbers[1],true,false,1),reduceContactPositionResolution(msg->contact_sides[1],msg->link_numbers[1],false,true,1),0.1);
    this->c3 = Position3d(reduceContactPositionResolution(msg->contact_sides[2],msg->link_numbers[2],true,false,2),reduceContactPositionResolution(msg->contact_sides[2],msg->link_numbers[2],false,true,2),0.1);
    /*this->c1 = Position3d(msg->contact_positions[0].x, msg->contact_positions[0].y, msg->contact_positions[0].z);
    this->c2 = Position3d(msg->contact_positions[1].x, msg->contact_positions[1].y, msg->contact_positions[1].z);
    this->c3 = Position3d(msg->contact_positions[2].x, msg->contact_positions[2].y, msg->contact_positions[2].z);*/
    this->c3Side = msg->contact_sides[2];
    this->r = Vector3d(c3.x - c2.x, c3.y - c2.y, c3.z - c2.z);
    iPropLink = msg->centerContactLink;
    obstacleDataInitialized = true;
    contactsCallbackTime = ros::Time::now();
    contactsMsgDataTime = msg->header.stamp;
}

void PropulsionController::snakePoseCallback(const snakebot_robot_pose::Pose::ConstPtr& msg){
    for(int i=0;i<14;i++){
        snakePose[i] = msg->snakePose.pose[i];
        //cout<<i<<" "<<snakePose[i]<<endl;
    }
}

float PropulsionController::reduceForceResolution(float force){
    if(force >= -1.0 && force <= -0.5){
        //return -0.75;
        return -0.80;
    }
    else if(force > -0.5 && force <= 0.0){
        //return -0.25;
        return -0.20;
    }
    else if(force > 0.0 && force <= 0.5){
        //return 0.25;
        return 0.30;
    }
    else if(force > 0.5 && force <= 1.0){
        //return 0.75;
        return 0.70;
    }
    else{
        cout<<"Error: Force greater than 1, equal to "<<force <<endl;
        return -5.0;
    }    
}

float PropulsionController::reduceContactPositionResolution(std::string side, int link_number, bool x,bool y, int pushpoint){
    if(x){
        if(side == "left"){
            return snakePose[link_number-1].x-(0.5*linkWidth*sin(snakePose[pushpoint-1].theta));
        }
        else if(side == "right"){
            return snakePose[link_number-1].x+(0.5*linkWidth*sin(snakePose[pushpoint-1].theta));
        }
    }
    if(y){
        if(side == "left"){
            return snakePose[link_number-1].y+(0.5*linkWidth*cos(snakePose[pushpoint-1].theta));
        }
        else if(side == "right"){
            return snakePose[link_number-1].y-(0.5*linkWidth*cos(snakePose[pushpoint-1].theta));
        }
    }
}

void PropulsionController::propulsionForceCallback(const std_msgs::Float64::ConstPtr &msg){
    fs = msg->data;
    propForceReceived = true;
    propulsionForceCallbackTime = ros::Time::now();
}

// /////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////


// Main equation solver
// Calculates the force f3 from given fs
void PropulsionController::f3Fromfs()
{
    // The equation:
    // A*fs + B*f3 = 0 --> f3 = -A/B * fs
    //

    double A = det(c1, n1) * (t1.x/n1.x) -
        det(c1, t1) + (det(c2, n2) -
        det(c1, n1)*(n2.x/n1.x))*((t1.y - (n1.y/n1.x)*t1.x)/(n2.y - (n1.y/n1.x)*n2.x));

    double B = -det(c1, n1) * (n3.x/n1.x) + det(c3, n3) +
    (det(c2, n2)-det(c1, n1)*(n2.x/n1.x))*  (((n1.y/n1.x)*n3.x - n3.y)/(n2.y - (n1.y/n1.x)*n2.x));

    cout << "c1 == " << c1.x << ", " << c1.y << ", "<<c1.z<<endl;
    cout << "c2 == " << c2.x << ", " << c2.y << ", "<<c2.z<< endl;
    cout << "c3 == " << c3.x << ", " << c3.y << ", "<<c3.z<< endl;
    cout << "n1 == " << n1.x << ", " << n1.y << endl;
    cout << "n2 == " << n2.x << ", " << n2.y << endl;
    cout << "n3 == " << n3.x << ", " << n3.y << endl;
    cout << "t1 == " << t1.x << ", " << t1.y << endl;
    cout << "t2 == " << t2.x << ", " << t2.y << endl;
    cout << "t3 == " << t3.x << ", " << t3.y << endl;
    cout<<"A: "<<A<<endl;
    cout<<"B: " <<B<<endl;
	if(isinf(A)){
        cout<<"hiemataholehe";
    }
    f3 = -fs*(A/B);
    //f3 = fs*(A/B);
    cout << "f3 == " << f3 << endl;
    cout<<"1 "<<det(c1, n1)<<endl;
    cout<<"2 "<<(t1.x/n1.x)<<endl;
    cout<<"3 "<<(n2.x/n1.x)<<endl;
    cout<<"4 "<<(t1.y - (n1.y/n1.x)*t1.x)<<endl;
    cout<<"5 "<<(n2.y - (n1.y/n1.x)*n2.x)<<endl;
}

// Uses the calculated f3 to calculate propulsion torque
void PropulsionController::desiredTorqueFromf3()
{
    setTorqueJoint();
    float temp = t3.y*(r.x * r.x + r.y * r.y);
    cout<<"torqueDenominator: "<<temp<<endl;
    desiredTorque.z = (f3 * n3.x * (r.x * t3.x + r.y * t3.y))/(t3.y*(r.x * r.x + r.y * r.y));
}

// Sets which joint to apply torque
void PropulsionController::setTorqueJoint(){
    int iRightJoint = iPropLink;
    torqueJoint = iRightJoint;//+1;
//    r.x = c3.x - jointPose2D[torqueJoint].x;
//    r.y = c3.y - jointPose2D[torqueJoint].y;

}

// Publishes the torque and its joint number
void PropulsionController::publishTorque(){
    long int timeLimitMs = 1000; // [ms]
    ros::Time timeNow = ros::Time::now();
    if ((timeNow - contactsCallbackTime).toNSec()/1000000 > timeLimitMs){
        cout << "Sensor data is too old. Publishing 0 torque." << endl;
        desiredTorque.z = 0.0;
        obstacleDataInitialized = false;
    }
    long int propTimeLimitMs = 100; // [ms]
    if ((timeNow - propulsionForceCallbackTime).toNSec()/1000000 > propTimeLimitMs){
        propForceReceived = false;
        return;
    }
    if (c3Side == "left"){
        if (desiredTorque.z < 0.0){
            cout << "Left, desiredTorqueZ = " <<desiredTorque.z << " Calculated torque is in wrong direction, won't publish" <<endl;
            return;
        }
    }
    else if (c3Side == "right"){
        if (desiredTorque.z > 0.0){
            cout << "Right, desiredTorqueZ = " <<desiredTorque.z << " Calculated torque is in wrong direction, won't publish" <<endl;
            return;
        }
    }
    std::stringstream ss;
    ss << "\nfs:" << fs << "\nTorque link: " << iPropLink << "\n" << "Torque at joint "<< torqueJoint << ": " << desiredTorque.z;
    std::string output = ss.str();
    ROS_INFO("%s", output.c_str());

    // Normal mode:
    snakebot_propulsion_control::PropulsionEffort msg;
    msg.jointNum = torqueJoint;
    msg.effort = desiredTorque.z;
    msg.pubTime = ros::Time::now();
    propulsionEffortPub.publish(msg);

}

// Runs the required functions to get torque to publish
void PropulsionController::updateTorqueOutput(){
    //printf("updateTorqueOutput started \n");
    if (!propForceReceived){
        cout << "Waiting for fs" << endl;
        return;
    }
    else if (obstacleDataInitialized){
        f3Fromfs();
        desiredTorqueFromf3();
        publishTorque();
    }
    else{
        printf("Cannot calculate force f3: obstacle data unknown \n");
        cout << "c1 == " << c1.x << ", " << c1.y << endl;
        cout << "c2 == " << c2.x << ", " << c2.y << endl;
        cout << "c3 == " << c3.x << ", " << c3.y << endl;
        cout << "n1 == " << n1.x << ", " << n1.y << endl;
        cout << "n2 == " << n2.x << ", " << n2.y << endl;
        cout << "n3 == " << n3.x << ", " << n3.y << endl;
        cout << "t1 == " << t1.x << ", " << t1.y << endl;
        cout << "t2 == " << t2.x << ", " << t2.y << endl;
        cout << "t3 == " << t3.x << ", " << t3.y << endl;
    }
}

// 15/12 - 2016: Not used
void PropulsionController::updateDesiredVelocity(std::vector<double> newDesiredVelocity)
{
    Vd = newDesiredVelocity;
}

// 15/12 - 2016: Not used
void PropulsionController::updateJointData(std::vector<double> newActualJointAngles, Vector3d newActualTorque)
{
	actualJointAngles = newActualJointAngles;
	actualTorque = newActualTorque;
}



// ////////////////////VECTOR ALGEBRA//////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////
double PropulsionController::det(Vector3d v1, Vector3d v2){
    return v1.x*v2.y - v1.y*v2.x;
}

double PropulsionController::det(Position3d v1, Vector3d v2){
    return v1.x*v2.y - v1.y*v2.x;
}

double PropulsionController::determinant(double a, double b, double c, double d)
{
	return (a*d - b*c);
}

Vector3d PropulsionController::crossProduct(Vector3d v1, Vector3d v2)
{
    double i = determinant(v1.y, v1.z, v2.y, v2.z);
    double j = - determinant(v1.x, v1.z, v2.x, v2.z);
    double k = determinant(v1.x, v1.y, v2.x, v2.y);
    Vector3d ans(i,j,k);
	return ans;
}

double PropulsionController::dotProduct(Vector3d v1, Vector3d v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector3d PropulsionController::toUnitVector(const Vector3d &v){
    double sumSquares = v.x*v.x + v.y*v.y + v.z*v.z;
    double length = sqrt(sumSquares);
    if (length == 0.0){
        cout << "ERROR: Cannot convert zero vector to unit vector" << endl;
        return v;
    }
    Vector3d unitVector(v.x/length, v.y/length, v.z/length);

    return unitVector;
}
