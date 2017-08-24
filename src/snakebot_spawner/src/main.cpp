#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
#include <ros/ros.h>
#include <ros/package.h>
#include <gazebo_msgs/ModelState.h>

#define _printf(__s__,__a__...) { \
	printf( "[spawner] " ); \
	printf( __s__, ##__a__ ); \
}

#define OBSR  0.1						//radius of an obstacle
#define OBSH	0.2						//heigth of an obstacle

#define LLINK_2 0.13
#define WLINK   0.1

#define OBSO    (WLINK/2.+(double)OBSR)

int main(int argc, char **argv)
{	
    char sIn[128] = "";
    int iErr;
    int nLinks, nJoints;
    double* pJoint = NULL;
    double* pTheta = NULL;
    double *pX = NULL, *pY = NULL;
    int piObs[3] = {0,0,0};
    int piSide[3] = {0,0,0};
    double pObsX[3], pObsY[3];
    double overlap;
    
    string sPath = ros::package::getPath("snakebot_spawner");
    sPath.erase( sPath.rfind( "/src/" ) );
    sprintf( sIn, "%s/obstacles.txt", sPath.c_str() );
	
/* ************************************************************************** *
 * INPUT                                                                      *
 * ************************************************************************** */

		/*if ( argc > 1 ) {
        strcpy( sIn, argv[1] );
    }*/

    FILE* pIn = fopen( sIn, "r" );
    if ( !pIn ) {
        _printf( "ERROR : couldn't open the input file\n" );
        _printf( "\tmake sure the file \"obstacle.txt\" exists in \"%s\"\n", sPath.c_str() );
        return -1;
    }

    iErr = fscanf( pIn, "%d", &nLinks );
    if ( iErr == EOF ) {
        _printf( "ERROR : can't read the amount of links\n" );
        return -1;
    }
    nJoints = nLinks-1;

    pJoint = (double*)malloc( nJoints*sizeof(double) );
    if ( !pJoint ) {
        _printf( "ERROR : couldn't malloc pJoint\n" );
        return -1;
    }
    for ( int i=0; i<nJoints; i++ ) {
        iErr = fscanf( pIn, "%lf", &pJoint[i] );
        if ( iErr == EOF ) {
            _printf( "ERROR : can't read the joint angle %d out of %d\n", i+1, nJoints );
            return -1;
        }
    }

    for ( int i=0; i<3; i++ ) {
        iErr = fscanf( pIn, "%d", &piObs[i] );
        if ( iErr == EOF ) {
            _printf( "ERROR : can't read the obstacle position %d out of 3\n", i+1 );
            return -1;
        }
    }
    
    for ( int i=0; i<3; i++ ) {
        iErr = fscanf( pIn, "%d", &piSide[i] );
        if ( iErr == EOF ) {
            _printf( "ERROR : can't read the obstacle side %d out of 3\n", i+1 );
            return -1;
        }
    }
    
    iErr = fscanf( pIn, "%lf", &overlap );
    if ( iErr == EOF ) {
        _printf( "NOTE : can't read the snake/obstacles overlap. Set to default value (0.01)\n" );
        overlap = 0.01;
    }

    _printf( "SUCCESS : reading input :\n" );
    _printf( "\t%d links (%d joints)\n", nLinks, nJoints );
    for ( int i=0; i<nJoints; i++ )
        _printf( "\tangle[%d] : %f\n", i+1, pJoint[i] );
    for ( int i=0; i<3; i++ )
        _printf( "\tobs link[%d] : %d\n", i+1, piObs[i] );
    for ( int i=0; i<3; i++ )
        _printf( "\tobs side[%d] : %d\n", i+1, piSide[i] );

    fclose( pIn );
	
/* ************************************************************************** *
 * COMPUTE                                                                    *
 * ************************************************************************** */

    pTheta = (double*)malloc( nLinks*sizeof(double) );
    pX = (double*)malloc( nLinks*sizeof(double) );
    pY = (double*)malloc( nLinks*sizeof(double) );
    if ( !pJoint || !pX || !pY ) {
        _printf( "ERROR : couldn't malloc pJoint, pX and/or pY\n" );
        return -1;
    }

    pTheta[0] = 0;
    for ( int i=1; i<nLinks; i++ ) {
        pTheta[i] = pTheta[i-1]+pJoint[i-1];
        _printf( "theta[%d] = %f\n", i, pTheta[i] );
    }

    pX[0] = 0;
    pY[0] = 0;
    for ( int i=1; i<nLinks; i++ ) {
        pX[i] = pX[i-1] + LLINK_2*cos(pTheta[i-1]) + LLINK_2*cos(pTheta[i]);
        pY[i] = pY[i-1] + LLINK_2*sin(pTheta[i-1]) + LLINK_2*sin(pTheta[i]);
        _printf( "x[%d] = %f\ny[%d] = %f\n", i, pX[i], i, pY[i] );
    }

    for ( int i=0; i<3; i++ ){
        pObsX[i] = pX[piObs[i]-1] - (piSide[i]?1:-1)*OBSO*sin(pTheta[piObs[i]-1]);
        pObsY[i] = pY[piObs[i]-1] + (piSide[i]?1:-1)*OBSO*cos(pTheta[piObs[i]-1]);
        _printf( "x[%d] = %f\ny[%d] = %f\n", i, pObsX[i], i, pObsY[i] );
    }
    
/* ************************************************************************** *
 * SPAWN                                                                      *
 * ************************************************************************** */
 
  ros::init(argc, argv, "snake_spawner");
	ros::NodeHandle	zNode;
  ros::Rate zRate(100);
	
	ros::Publisher zPubSpawn = zNode.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 8 );
  gazebo_msgs::ModelState	pzMsgState[3];
  for ( int i=0; i<3; i++ ) {
  	char sBuf[128];
  	sprintf( sBuf, "cylinder_%d", i+1 );
  	pzMsgState[i].model_name = sBuf;
  	pzMsgState[i].reference_frame = "world";
  	pzMsgState[i].pose.position.x = pObsX[i];
  	pzMsgState[i].pose.position.y = pObsY[i];
  	pzMsgState[i].pose.position.z = 0;
  	pzMsgState[i].pose.orientation.w = 1;
  }
  
  for ( int i=0; i<200; i++ ) {
  //while ( true ) {
  	for ( int j=0; j<3; j++ ) {
			pzMsgState[j].pose.position.x += (piSide[j]?1:-1)*(overlap/200.)*sin(pTheta[piObs[j]-1]);
			pzMsgState[j].pose.position.y -= (piSide[j]?1:-1)*(overlap/200.)*cos(pTheta[piObs[j]-1]);
  		zPubSpawn.publish( pzMsgState[j] );
  	}
  	
    ros::spinOnce();
    zRate.sleep();
  }
  
  _printf( "FINISHED : obstacles spawned\n" );

  return 0;
}
