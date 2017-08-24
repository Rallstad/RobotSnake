#pragma once

#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"
#include <vector>

using std::cout;
using std::endl;

class Vector3d {
//DATA
protected :
    double x, y, z;
    double angleX, angleY, angleZ, lengthTotal;
//METHODS
public :
    Vector3d( double xPos, double yPos, double zPos );
    Vector3d(const geometry_msgs::Vector3& msgVector3);
    Vector3d(const geometry_msgs::Point& msgPoint);
    Vector3d();
    //access
    double getX()const{ return x; }
    double getY()const{ return y; }
    double getZ()const{ return z; }
    double getAngleX()const{ return angleX; }
    double getAngleY()const{ return angleY; }
    double getAngleZ()const{ return angleZ; }
    double getLengthTotal()const{ return lengthTotal; }
    //modify
    void rotateZ(double rotationAngle);
    Vector3d operator+(const Vector3d&v);
    Vector3d& operator+=( const Vector3d& v);
    Vector3d& operator=( const Vector3d& v);
    geometry_msgs::Point toPointMsg();
    friend Vector3d scaleVector(Vector3d v, double scale);
};

class Point3d: public Vector3d {
public :
    Point3d( double xPos, double yPos, double zPos );
    Point3d(const geometry_msgs::Point& msgPoint);
    Point3d();
    void translateXY(double translationX, double translationY);
};

class ContactData {
public:
    std::vector<Point3d> position;
    std::vector<Vector3d> force;
    std::vector<Vector3d> normal;
    std::vector<Vector3d> tangent;

    void translatePositionsXY(double translationX, double translationY);
    void rotateVectorsZ(double rotationAngle);
};

struct Pose2d {
    double x, y, orientation;
    Pose2d(double xPos,double yPos,double angle):x(xPos),y(yPos),orientation(angle){}
    Pose2d():x(0),y(0),orientation(0){}
};

struct Position3d{
    double x, y, z;
    Position3d():x(0), y(0), z(0){}
    Position3d(double xPos, double yPos, double zPos):x(xPos), y(yPos), z(zPos){}
};

