#pragma once
#include <cmath>
#include <vector>


/* ************************************************************************* *
 * BASIC OBJECTS                                                             *
 * ************************************************************************* */

class Vector3d {
//DATA
private :
    double x, y, z;
    double angle, length;
//METHODS
public :
    Vector3d( double xPos, double yPos, double zPos ):x(xPos),y(yPos),z(zPos),angle(atan2(yPos,xPos)),length(sqrt(xPos*xPos+yPos*yPos+zPos*zPos)){}
    Vector3d():x(0),y(0),z(0),angle(0),length(0){}
	//access
    double getX()const{ return x; }
    double getY()const{ return y; }
    double getZ()const{ return z; }
    double getAngle()const{ return angle; }
    double getLength()const{ return length; }
	//modify
	void normalize();
	void half( double a );
	void project( double a );
	//operators
    Vector3d operator*( const Vector3d& v )const;
    Vector3d& operator+=( const Vector3d& v);
    Vector3d& operator*=( double f );
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

struct ContactData {
    std::vector<Position3d> position;
    std::vector<Vector3d> forceVector;
    std::vector<Vector3d> normalVector;
};




