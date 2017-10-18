#include "positioncontroller.h"

#include <sstream>





bool followRealSnakeMode = false;





int main(int argc, char **argv)
{
    int const numJoints = 10;
    int freq = 1000;
    ros::init(argc, argv, "position_controller");
    ros::NodeHandle n;

    //PID parameters
    // Proporsional gain:
    //double array[] = {60, 70, 80, 90, 100, 100, 90, 80, 70, 60};
    double array[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    //double array[] = {50, 50, 50, 50, 100, 100, 200, 200, 200, 200};
    //double array[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
    //double array[] = {10, 20, 30, 40, 50, 50, 40, 30, 20, 10};
    //double array[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
    std::vector<double> kp(array, array+10); //(numJoints, 50);
    // Derivative gain: negative value for absolute rotation speed, positive for error - preError
     std::vector<double> kd(numJoints, 0.3); //somewhat ok, but still sucks
    //std::vector<double> kd(numJoints, 0.0);
    // Integral gain
    //std::vector<double> ki(numJoints, 0.0);
	std::vector<double> ki(numJoints, 10.0);

    double effortLimit = 50; // Saturation for the control input
    PositionController controller(n, 1.0/freq, kp, kd, ki, effortLimit);
    ros::Rate loop_rate(freq);

    while (ros::ok())
    {
        //controller.calculateAndPublishEffort();
        //cout << ros::Time::now().toNSec() << endl;
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}

