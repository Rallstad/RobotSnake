#include "datatypes.h"

Vector3d::Vector3d(double xPos, double yPos, double zPos):
    x(xPos),y(yPos),z(zPos),angleX(atan2(zPos,yPos)),angleY(atan2(xPos,zPos)),angleZ(atan2(yPos,xPos)),lengthTotal(sqrt(xPos*xPos+yPos*yPos+zPos*zPos))
{}

Vector3d::Vector3d(const geometry_msgs::Vector3& v): Vector3d(v.x, v.y, v.z)
{}

Vector3d::Vector3d(const geometry_msgs::Point& p): Vector3d(p.x, p.y, p.z)
{}

Vector3d::Vector3d():
    x(0),y(0),z(0),angleX(0),angleY(0),angleZ(0),lengthTotal(0)
{}

void Vector3d::rotateZ(double rotationAngle){
    double lengthXY= sqrt(x*x+y*y);
    angleZ += rotationAngle;
    x = lengthXY*cos(angleZ);
    y = lengthXY*sin(angleZ);
}

Vector3d Vector3d::operator+( const Vector3d& v )
{
    Vector3d vector;
    vector.x = x + v.x;
    vector.y = y + v.y;
    vector.z = z + v.z;
    vector.lengthTotal = sqrt(vector.x*vector.x+vector.y*vector.y+vector.z*vector.z);
    vector.angleX = atan2(vector.z,vector.y);
    vector.angleY = atan2(vector.x,vector.z);
    vector.angleZ = atan2(vector.y,vector.x);
    return vector;
}

Vector3d& Vector3d::operator+=( const Vector3d& v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    lengthTotal = sqrt(x*x+y*y+z*z);
    angleX = atan2(z,y);
    angleY = atan2(x,z);
    angleZ = atan2(y,x);
    return *this;
}

Vector3d& Vector3d::operator=( const Vector3d& v )
{
    x = v.x;
    y = v.y;
    z = v.z;
    lengthTotal = sqrt(x*x+y*y+z*z);
    angleX = atan2(z,y);
    angleY = atan2(x,z);
    angleZ = atan2(y,x);
    return *this;
}

geometry_msgs::Point Vector3d::toPointMsg(){
    geometry_msgs::Point p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

Point3d::Point3d(double xPos, double yPos, double zPos): Vector3d(xPos, yPos, zPos)
{}

Point3d::Point3d(const geometry_msgs::Point &p): Vector3d(p.x, p.y, p.z)
{}

Point3d::Point3d(): Vector3d()
{}

void Point3d::translateXY(double translationX, double translationY){
    x += translationX;
    y += translationY;
    lengthTotal = sqrt(x*x + y*y + z*z);
    angleZ = atan2(y,x);
}

void ContactData::translatePositionsXY(double translationX, double translationY){
    for (int i = 0; i < position.size(); i++){
        position[i].translateXY(translationX, translationY);
        //cout << "translate" << i << endl;
    }
}

void ContactData::rotateVectorsZ(double rotationAngle) {
    for (int i = 0; i < normal.size(); i++){
        position[i].rotateZ(rotationAngle);
        force[i].rotateZ(rotationAngle);
        normal[i].rotateZ(rotationAngle);
        tangent[i].rotateZ(rotationAngle);
    }
}

Vector3d scaleVector(Vector3d v, double scale){
    Vector3d vec;
    vec.x = v.x*scale;
    vec.y = v.y*scale;
    vec.z = v.z*scale;
    return vec;
}
