ROS plugin "snakebot_spawner"

launch :
rosrun snakebot_spawner spawner

This plugin places three obstacles according to the scenario.

How it does it :
- definition of the obstacles
	snakebot_gazebo/snakebot.world contains the default definition of the cylinders
	cylinder_1, cylinder_2 and cylinder_3 MUST be defined
- the spawner place them arround the snake according to the scenario
- it moves it toward the snake for a short time in order to improve the contact

It needs to be launched for :
	snakebot_interface
	snakebot_control_plugin

Customization :
The file "obstacle.txt" allows to set the positions of the obstacles
obstacle.txt should go at the root of the catkin workspace (next to the src & devel folders)
#content of the file :
line 1 : (int) amount of links of the snake
line 2 : (list of double) list of the joints initial positions
line 3 : (3 int) the three links you want obstacle againts
line 4 : (3 bool) the side of contact : 1 for left, 0 for right
#optional :
line 5 : (double) the overlap distance between the snake and the obstacles
