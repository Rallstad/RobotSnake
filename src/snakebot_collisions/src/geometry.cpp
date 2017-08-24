#include "geometry.h"


void Vector3d::normalize()
{
    x /= length;
    y /= length;
    z /= length;
}

// I do not understand this function - Stian Danielsen 10/02-2017
void Vector3d::half( double a )
{
	while ( a > M_PI )
		a -= 2*M_PI;
	while ( a < -M_PI )
		a += 2*M_PI;
		
    double da = fabs(a-angle);
	if ( da > M_PI )
		da = 2*M_PI-da;
		
	if ( M_PI_2 < da )
		*this *= -1;
}

// I do not understand this function - Stian Danielsen 10/02-2017
void Vector3d::project( double a )
{
	while ( a > M_PI )
		a -= 2*M_PI;
	while ( a < -M_PI )
		a += 2*M_PI;
		
    x = length*cos( angle - a )*cos( a );
    y = length*cos( angle - a )*sin( a );
    z = 0;
    length = sqrt(x*x+y*y+z*z);
    angle = atan2(y,x);
}

Vector3d Vector3d::operator*( const Vector3d& v ) const
{
    return Vector3d(
        y*v.z - z*v.y,
        z*v.x - x*v.z,
        x*v.y - y*v.x
	);
}

Vector3d& Vector3d::operator+=( const Vector3d& v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    length = sqrt(x*x+y*y+z*z);
    angle = atan2(y,x);
	
	return *this;
}

Vector3d& Vector3d::operator*=( double f )
{
    x *= f;
    y *= f;
    z *= f;
    length = sqrt(x*x+y*y+z*z);
    angle = atan2(y,x);
	
	return *this;
}
