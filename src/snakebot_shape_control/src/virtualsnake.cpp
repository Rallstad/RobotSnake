#include "virtualsnake.h"

VirtualSnake::VirtualSnake(ros::NodeHandle n){
    numberOfLinks = 11;
    linkLength = 0.2 + 0.03*2;
    linkWidth = 0.1;
    obstacleDataSub = n.subscribe("/snakebot/pushpoints", 10, &VirtualSnake::obstacleDataCallback, this);
    robotPoseSub = n.subscribe( "/snakebot/robot_pose", 10, &VirtualSnake::robotPoseCallback, this );
    desiredPositionPub = n.advertise<std_msgs::Float64MultiArray>("/snakebot/desired_joint_positions", 1);
}

void VirtualSnake::obstacleDataCallback(const snakebot_pushpoints::Pushpoints::ConstPtr& msg){
    c1 = Point2d(msg->contact_positions[0].x, msg->contact_positions[0].y);
    c2 = Point2d(msg->contact_positions[1].x, msg->contact_positions[1].y);
    c3 = Point2d(msg->contact_positions[2].x, msg->contact_positions[2].y);
    contactLinkNumber.clear();
    contactLinkNumber.push_back(msg->link_numbers[0]);
    contactLinkNumber.push_back(msg->link_numbers[1]);
    contactLinkNumber.push_back(msg->link_numbers[2]);
    if (contactLinkNumber.size() != 3){
        obstacleDataReady = false;
    }
    else {
        obstacleDataReady = true;
        obstacleDataReceiveTime = ros::Time::now();
    }
}


void VirtualSnake::robotPoseCallback(const snakebot_robot_pose::Pose::ConstPtr &msg){
    contactLinkPosition.clear();
    contactLinkOrientation.clear();
    linkPosition.clear();
    linkOrientation.clear();
    obstaclePosition.clear();
    for (int i = 0; i < msg->snakePose.name.size(); i++){
        for (int j = 0; j < contactLinkNumber.size(); j++){
            int link = contactLinkNumber[j];
            if (msg->snakePose.number[i] == link){
                contactLinkPosition.push_back(Point2d(msg->snakePose.pose[i].x, msg->snakePose.pose[i].y));
                contactLinkOrientation.push_back(msg->snakePose.pose[i].theta);
            }

        }
        linkPosition.push_back(Point2d(msg->snakePose.pose[i].x, msg->snakePose.pose[i].y));
        linkOrientation.push_back(msg->snakePose.pose[i].theta);

    }
    if ((contactLinkPosition.size() != 3) || (contactLinkOrientation.size() != 3) || (linkPosition.size() != numberOfLinks) || (linkOrientation.size() != numberOfLinks)){
        robotPoseReady = false;
    }
    else {
        robotPoseReady = true;
    }
    for (int i = 0; i < msg->obstaclePose.name.size(); i++){
        obstaclePosition.push_back(Point2d(msg->obstaclePose.pose[i].x, msg->obstaclePose.pose[i].y));
    }
}

void VirtualSnake::shapeCurveCallback(const snakebot_shape_control::ShapeCurve::ConstPtr &msg){
    shapeCurve.clear();
    for (int i = 0; i < msg->shapeCurve.size(); i++){
        shapeCurve.push_back(Point2d(msg->shapeCurve[i].x, msg->shapeCurve[i].y));
    }
}



void VirtualSnake::interpolate(Point2d p1, Point2d p2){
    Vector2d v(p2.x- p1.x, p2.y - p1.y);
    double d = vectorNorm(v);
    int N = (100*d);
    if (p2.x - p1.x == 0.0){
        double stepLen = (p2.y - p1.y)/N;
        Point2d newPoint;
        newPoint.x = p1.x;
        double y = p1.y;
        for (int i = 0 ; i < N; i++){
            newPoint.y = y;
            shapeCurve.push_back(newPoint);
            y+= stepLen;
        }
    }
    else {
        double stepLen = (p2.x - p1.x)/N;
        double m = (p2.y - p1.y)/(p2.x - p1.x);
        double y;
        Point2d newPoint;
        if (p1.x < p2.x){
            for (double x = p1.x; x < p2.x; x+=stepLen){
                y = m*x + (p1.y - m*p1.x);
                newPoint.x = x;
                newPoint.y = y;
                shapeCurve.push_back(newPoint);
            }
        }
        else{
            for (double x = p1.x; x > p2.x; x+=stepLen){
                y = m*x + (p1.y - m*p1.x);
                newPoint.x = x;
                newPoint.y = y;
                shapeCurve.push_back(newPoint);
            }
        }

    }
}

void VirtualSnake::generateShapeCurve(){ // With cosint method the snake must go in positive x-direction
    shapeCurve.clear();
    Point2d preC1;
    Point2d postC3;
    std::vector<Point2d> obst;
    if (obstaclePosition.size() >= 5){
        preC1 = obstaclePosition[3];
        postC3 = obstaclePosition[4];
        obst.push_back(preC1);obst.push_back(c1);obst.push_back(c2);obst.push_back(c3);obst.push_back(postC3);
    }
    else {
        obst.push_back(c1);obst.push_back(c2);obst.push_back(c3);
    }

    std::vector<double> xi;
    std::vector<double> yi;
    std::vector<double> x;
    std::vector<double> y;

    for (int i = 0; i < obst.size() ; i++){
        x.push_back(obst[i].x);
        y.push_back(obst[i].y);
    }

    tk::spline shapeSpline;
    shapeSpline.set_points(x,y);

    if (linkPosition.size() == numberOfLinks){
        for (double xx = -1; xx < 4; xx += 0.001){
            xi.push_back(xx);
        }
        //yi.resize(xi.size(),0);
        //cosint(x,y, xi, yi);
    }
//    for (int i = 0; i < xi.size(); i++){
//        shapeCurve.push_back(Point2d(xi[i], yi[i]));
//    }

    for (int i = 0; i < xi.size(); i++){
        yi.push_back(shapeSpline(xi[i]));
        shapeCurve.push_back(Point2d(xi[i], yi[i]));
    }

    cout << "curveX = [";
    for (int i = 0; i < shapeCurve.size(); i++){
        cout << shapeCurve[i].x << " ";
    }
    cout << "];" << endl;
    cout << "curveY = [";
    for (int i = 0; i < shapeCurve.size(); i++){
        cout << shapeCurve[i].y << " ";
    }
    cout << "];" << endl;
    cout << "x and y for points for interpolation: " << endl;
    cout << "intX = [";
    for (int i = 0; i < obst.size(); i++){
        cout << obst[i].x << " ";
    }
    cout << "];" << endl;
    cout << "intY = [";
    for (int i = 0; i < obst.size(); i++){
        cout << obst[i].y << " ";
    }
    cout << "];" << endl;

}

int VirtualSnake::findStartJoint(){
    if ((contactLinkPosition.size() < 1) || (contactLinkOrientation.size() < 1 )){
        cout << "start joint not found" << endl;
        return -1;
    }
    jointPositions.clear();
    double x = linkLength/2 * cos(contactLinkOrientation[0]) + contactLinkPosition[0].x;
    double y = linkLength/2 * sin(contactLinkOrientation[0]) + contactLinkPosition[0].y;
    Point2d firstJoint(x,y);
    jointPositions.push_back(firstJoint);
    return 0;
}

int VirtualSnake::findStartLinkAngle(){
    if ((contactLinkPosition.size() < 1) || (contactLinkOrientation.size() < 1 ) || (jointPositions.size() < 1)){
        cout << "start link angle not found" << endl;
        return -1;
    }
    double x = - linkLength/2 * cos(contactLinkOrientation[0]) + contactLinkPosition[0].x;
    double y = - linkLength/2 * sin(contactLinkOrientation[0]) + contactLinkPosition[0].y;
    Point2d firstFirstJoint(x,y);
    Vector2d jointToJoint(jointPositions[0].x - firstFirstJoint.x,jointPositions[0].y - firstFirstJoint.y);
    linkAngles.push_back(constrainAngle(atan2(jointToJoint.y, jointToJoint.x)));
    cout << "start link angle= " << linkAngles[0] << endl;
    return 0;
}

Point2d VirtualSnake::findDesiredTailPosition(){
    double theta = contactLinkOrientation[0];
    Vector2d r =  c1 - contactLinkPosition[0];
    double rLen = r.norm();
    double offset = sqrt(rLen*rLen + (0.5*linkWidth)*(0.5*linkWidth));
    Vector2d rRotated(cos(-theta)*r.x - sin(-theta)*r.y, sin(-theta)*r.x + cos(-theta)*r.y);
    if (rRotated.x > 0.0){
        offset = -offset;
    }
    cout << "contactLinkPosition[0]= " << contactLinkPosition[0].x << " " << contactLinkPosition[0].y << endl;
    cout << "c1= " << c1.x << " " << c1.y << endl;
    cout << "r= " << r.x << " " << r.y << endl;
    cout << "rRotated= " << rRotated.x << " " << rRotated.y << endl;
    int startIndex = -1;
    for (int i = 0; i < shapeCurve.size(); i++){
        if ((shapeCurve[i] - c1).norm() < 0.01){
            startIndex = i;
            break;
        }
    }
    if (startIndex == -1){
        cout << "error (findDesiredTailPosition): could not find start index" << endl;
    }
    Point2d tail;
    Point2d joint;
    int jointCount = 0;
    //cout << "shapcurve0x = " << shapeCurve[0].x << endl;
    for (int i = startIndex; i > 0; i--){
        if (jointCount == 0){
            if (((shapeCurve[i] - c1).norm() < linkLength - offset + 0.01) && ((shapeCurve[i] - c1).norm() > linkLength - offset - 0.01)){
                if (contactLinkNumber[0] == 1){
                    tail = shapeCurve[i];
                    cout << "found tail at " << tail.x << " " << tail.y << endl;
                    return tail;
                }
                else{
                    joint = shapeCurve[i];
                    jointCount++;
                }
            }
        }
        else{
            if (((shapeCurve[i] - joint).norm() < linkLength + 0.01) && ((shapeCurve[i] - joint).norm() > linkLength - 0.01)){
                cout << "condition true " << endl;
                if (contactLinkNumber[0] - jointCount == 1){
                    tail = shapeCurve[i];
                    cout << "found tail at " << tail.x << " " << tail.y << endl;
                    return tail;
                }
                else{
                    joint = shapeCurve[i];
                    jointCount++;
                }
            }
        }
    }
    return (Point2d(-999, -999));
}

void VirtualSnake::findDesiredJointPositions(){
    Point2d tail = findDesiredTailPosition();
    int startIndex = -1;
    for (int i = 0; i < shapeCurve.size(); i++){
        if ((shapeCurve[i] - tail).norm() < 0.01){
            startIndex = i;
            break;
        }
    }
    if (startIndex == -1){
        cout << "error (findDesiredJointPositions): could not find start index" << endl;
        return;
    }
    jointPositions.push_back(tail);
    for (int i = startIndex; i < shapeCurve.size(); i++){
        if (jointPositions.size() > numberOfLinks){
            cout << "count enough joints" << endl;
            break;
        }
        else{
//            if (jointPositions.size() > 9){
//                cout << "distance: " << (shapeCurve[i] - jointPositions[jointPositions.size()-1]).norm() << endl;
//            }
            if (((shapeCurve[i] - jointPositions[jointPositions.size()-1]).norm() < linkLength + 0.01) && ((shapeCurve[i] - jointPositions[jointPositions.size()-1]).norm() > linkLength - 0.01)){

                jointPositions.push_back(shapeCurve[i]);
            }
        }
    }
}

void VirtualSnake::findDesiredJointAngles(){
    if (!(obstacleDataReady && robotPoseReady)){
        cout << "obstacle or link data not available" << endl;
        return;
    }
    if (contactLinkNumber.size() == 0){
        cout << "could not identify contact links" << endl;
        return;
    }
    jointSetPoint.clear();
    linkAngles.clear();
    jointPositions.clear();
    generateShapeCurve();
    findDesiredJointPositions();
    Vector2d r;
    for (int i = 0; i < int(jointPositions.size()) - 1; i++){
        r = jointPositions[i+1] - jointPositions[i];
        double angle = atan2(r.y,r.x);
        linkAngles.push_back(angle);
        cout << angle << " ";
    }
    cout << endl;
    cout << "jointX= [";
    for (int i = 0; i < jointPositions.size(); i++){
        cout << jointPositions[i].x << " ";
    }
    cout << "];" << endl;
    cout << "jointY= [";
    for (int i = 0; i < jointPositions.size(); i++){
        cout << jointPositions[i].y << " ";
    }
    cout << "];" << endl;
    cout << "linkX= [";
    for (int i = 0; i < linkPosition.size(); i++){
        cout << linkPosition[i].x << " ";
    }
    cout << "];" << endl;
    cout << "linkY= [";
    for (int i = 0; i < linkPosition.size(); i++){
        cout << linkPosition[i].y << " ";
    }
    cout << "];" << endl;
    for (int i = 0; i < int(linkAngles.size()) - 1; i++){
        jointSetPoint.push_back(linkAngles[i+1] - linkAngles[i]);
    }
}



void VirtualSnake::zeroPadJointSetPoints(){
    //cout << "zero padded ";
    int zeroPadCount = 0;   
    for (int i = jointSetPoint.size(); i < numberOfLinks-1; i++){
        jointSetPoint.push_back(0.0);
        zeroPadCount++;
    }
    //cout << zeroPadCount << " joints" << endl;
}

void VirtualSnake::publishSetPoints(){
    zeroPadJointSetPoints();
    if (jointSetPoint.size() < numberOfLinks-1){
        cout << "ERROR: set point size does not equal number of joints" << endl;
        return;
    }

    std_msgs::Float64MultiArray msg;
    for (int i = 0; i < jointSetPoint.size(); i++){
        msg.data.push_back(jointSetPoint[i]);
    }
    cout << "jointSetPoint.size()= " << jointSetPoint.size() << endl;
    cout << "linkAngles.size()= " << linkAngles.size() << endl;
    cout << "jointPositions.size()= " << jointPositions.size() << endl;
    desiredPositionPub.publish(msg);
    cout << "[";
    for (int i = 0; i < jointSetPoint.size(); i++){
        cout << jointSetPoint[i] << " ";
    }
    cout << "]" << endl;
    zeroPadJointSetPoints();
}

double VirtualSnake::vectorNorm(Vector2d v){
    return sqrt(v.x*v.x + v.y*v.y);
}

double VirtualSnake::constrainAngle(double x){
    x = fmod(x + M_PI,2*M_PI);
    if (x < 0)
        x += 2*M_PI;
    return x - M_PI;
}




void VirtualSnake::cosint(std::vector<double> x, std::vector<double> y, std::vector<double> xi, std::vector<double> &yi){
//    % COSINT 1-D piecewise cosine interpolation
//    %    COSINT(X,Y,XI) interpolates to find YI, the values of the
//    %    underlying function Y at the points in the array XI, using
//    %    piecewise cosine interpolation.  X and Y must be vectors
//    %    of length N.

//    % Joe Henning - Fall 2011

    int n = x.size();

    for (int i = 0; i < xi.size(); i++){
       //% Find the right place in the table by means of a bisection.
       int klo = 0;
       int khi = n - 1;
       while (khi-klo > 1){
          int k = trunc((khi+klo)/2.0);
          if (x[k] > xi[i]){
             khi = k;
          }
          else{
             klo = k;
          }
       }

       double h = x[khi] - x[klo];
       if (h == 0.0){
          cout << "??? Bad x input to cosint ==> x values must be distinct\n";
          yi[i] = 99999;
          continue;
       }

       //% Evaluate cosine function
       double cfact = (1 - cos(M_PI*(xi[i]-x[klo])/h))/2.0;
       yi[i] = y[klo] + cfact*(y[khi]-y[klo]);
    }
}




