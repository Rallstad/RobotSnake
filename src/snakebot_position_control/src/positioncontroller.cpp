#include "positioncontroller.h"

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR
PositionController::PositionController(ros::NodeHandle handle, double stepLength, std::vector<double> kp, std::vector<double> kd, std::vector<double> ki, double effortLimit)
{
    n = handle;
    this->dt = stepLength;
    this->kp = kp;
    this->kd = kd;
    this->ki = ki;
    this->effortLimit = effortLimit;

    //setMappingMatrix();

    desiredPositionSub = n.subscribe("/snakebot/desired_joint_positions", 100, &PositionController::desiredPositionCallback, this);
    labviewPositionSub = n.subscribe("/LabVIEW_ROS/from_LabVIEW_measured_angles", 100, &PositionController::labviewPositionCallback, this);
    //jointStateSub = n.subscribe("/snakebot/joint_states", 1, &PositionController::jointStateCallback, this);
    desiredPositionPub = n.advertise<std_msgs::Float64MultiArray>("/snakebot/desired_joint_positions", 1);
    effortPub = n.advertise<snakebot_position_control::PositionControlEffort>("/snakebot/position_controller_effort", 1);
    LabViewDesiredPositionPub = n.advertise<std_msgs::Float64MultiArray>("/LabVIEW_ROS/from_ROS_reference_angles",1);
    desiredPosition.resize(numJoints);
    currentPosition.resize(numJoints);
    currentVelocity.resize(numJoints,0.1);
    velocityAverage.resize(numJoints, 0.0);
    error.resize(numJoints, 0.0);
    errorPrev.resize(numJoints, 0.0);
    errorDerivative.resize(numJoints, 0.0);
    errorIntegral.resize(numJoints, 0.0);
    cout <<"numJoints: "<< numJoints<<endl;

    desiredPositionReady = false;
    currentPositionReady = false;
    firstRun = true;


}
// DESTRUCTOR
PositionController::~PositionController()
{
}
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// //////////////////////////////////////////////////////////////////////////////////////////////
// // CALLBACK FUNCTIONS - FOR RECEIVING DATA ///////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////

// store received vector of desired positions
void PositionController::desiredPositionCallback(const std_msgs::Float64MultiArray::ConstPtr &msg){
    desiredPosition = msg->data;
    desiredPositionReady = true;
    std_msgs::Float64MultiArray LabViewDesiredPosition;
    for(int i=0;i<msg->data.size();i++){
        LabViewDesiredPosition.data = desiredPosition;//msg->data[i];
    }
    LabViewDesiredPositionPub.publish(LabViewDesiredPosition);
   // cout<<"desiredmsgsize "<<msg->data.size()<<endl;
   // cout<<"desiredPositionReady: " << desiredPositionReady;
    //cout<<"currentPositionReady: " <<currentPositionReady;
}

void PositionController::labviewPositionCallback(const snakebot_labview_communication::Float64Array::ConstPtr &inMsg){
    std::vector<double> PositionMsg;
    for(int i=0;i<=12;i++){
        PositionMsg.push_back(inMsg->data[i]*3.1415/180);
        cout<<"hei"<<endl;
    }
    currentPosition = PositionMsg;
    calculateAndPublishEffort();    
}



// get vector of measured positions of real snake robot and use as desired position
/*void PositionController::labviewPositionCallback(const std_msgs::Float64MultiArray::ConstPtr &inMsg){
    if (followRealSnakeMode){
        std::vector<double> mappedJoints = map6to10(inMsg->data);
        std_msgs::Float64MultiArray outMsg;
        outMsg.data = mappedJoints;
        desiredPositionPub.publish(outMsg);
    }
}*/

// store received vector of current positions
void PositionController::jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg){
    currentPosition = msg->position;
    //currentVelocity = msg->velocity;
    currentPositionReady = true;
    calculateAndPublishEffort();
}

// //////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////


// //////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////
void PositionController::calculateAndPublishEffort(){
    if (!(desiredPositionReady && currentPositionReady))
        return;
    if (firstRun){
        errorPrev = desiredPosition - currentPosition; // to prevent a jump when the controller first starts
        firstRun = false;
    }
   // for(int i=0;i<desiredPosition.size();i++){
     //  cout<< i<<" : "<< desiredPosition[i]<<endl;
    //}
    //cout<<endl;
    error = desiredPosition - currentPosition;
    //cout << "desiredsize: "<<desiredPosition.size()<<endl;
    //cout << "currentsize: "<<currentPosition.size()<<endl;
    errorDerivative = (error - errorPrev)/dt;
    //errorDerivative = currentVelocity;
    
    velocityAverage = movingAverage(errorDerivative, velocityAverage, 0.5);
    

    errorIntegral = errorIntegral +  dt*(error + errorPrev)/2;
    //effort = elementWiseMult(kp, error) + elementWiseMult(kd, errorDerivative) + elementWiseMult(ki, errorIntegral);
    effort = elementWiseMult(kp, error) + elementWiseMult(kd, velocityAverage) + elementWiseMult(ki, errorIntegral);
    effort = saturate(effortLimit, -effortLimit, effort);
    errorPrev = error;
    snakebot_position_control::PositionControlEffort msg;
    msg.effort = effort;
    msg.arraySize = effort.size();
    msg.pubTime = ros::Time::now();
    effortPub.publish(msg);

}

std::vector<double> PositionController::saturate(double upperLimit, double lowerLimit, std::vector<double> v){
    std::vector<double> result = v;
    for (int i = 0 ; i < v.size() ; i ++){
        if (v[i] > upperLimit){
            result[i] = upperLimit;
        }
        else if (v[i] < lowerLimit){
            result[i] = lowerLimit;
        }
    }
    return result;
}

// Moving average filter to remove high freq noise
std::vector<double> PositionController::movingAverage(std::vector<double> currentData, std::vector<double> prevAverage, double smoothingFactor){
    int len = currentData.size();
    std::vector<double> newAverage;
    double average;
    for (int i = 0 ; i < len ; i++){
        average = currentData[i]*smoothingFactor + (1-smoothingFactor)*prevAverage[i];
        newAverage.push_back(average);
    }
    return newAverage;
}

void PositionController::setMappingMatrix(){
    std::vector<double> row1 = {0.616144188619990, 0.0599899627924312, 0.000148700250849873, 6.75098094424810e-09, 5.61363453726321e-15, 1.18838801012466e-22};
    std::vector<double> row2 = {0.332393832573526, 0.298573687431595, 0.00682789728377575, 2.85985819209077e-06, 2.19393668982840e-11, 4.28489866711360e-18};
    std::vector<double> row3 = {0.0521872915618096, 0.432479644893911, 0.0912438197530575, 0.000352584581299088, 2.49542916992603e-08, 4.49639080445272e-14};
    std::vector<double> row4 = {0.00238461219293927, 0.182314416808579, 0.354863341356149, 0.0126509556963105, 8.26052413745516e-06, 1.37318403929964e-10};
    std::vector<double> row5 = {3.17111478913760e-05, 0.0223675055694115, 0.401661326213925, 0.132106611758174, 0.000795813244151703, 1.22049117545465e-07};
    std::vector<double> row6 = {1.22729048347016e-07, 0.000798647794276672, 0.132312263496938, 0.401482827428717, 0.0223128949770377, 3.15705204354280e-05};
    std::vector<double> row7 = {1.38236895229239e-10, 8.29916195491471e-06, 0.0126847344852304, 0.355099936609772, 0.182071462559513, 0.00237667632265467};
    std::vector<double> row8 = {4.53149782941066e-14, 2.50988824037536e-08, 0.000353918988329448, 0.0914061498708206, 0.432383428877351, 0.0520714341006069};
    std::vector<double> row9 = {4.32315475667268e-18, 2.20910179516322e-11, 2.87387283624730e-06, 0.00684764817657434, 0.298839088039639, 0.332024582077599};
    std::vector<double> row10 = {1.20033090802162e-22, 5.65872090049508e-15, 6.79160519516743e-09, 0.000149296168394899, 0.0601100327229443, 0.616143880547973};

    std::vector<std::vector<double>> matrix = {row1,row2,row3,row4,row5,row6,row7,row8,row9,row10};

    jointMappingMatrix = matrix;
}

std::vector<double> PositionController::map6to10(std::vector<double> vector6){
    std::vector<double> resultVector10;

    double sum = 0;
    for (int i = 0; i < jointMappingMatrix.size(); i++){
        for (int j = 0; j < jointMappingMatrix[i].size(); j++){
            sum += jointMappingMatrix[i][j] * vector6[j];
        }
        resultVector10.push_back(sum);
        sum = 0;
    }
    return resultVector10;
}
