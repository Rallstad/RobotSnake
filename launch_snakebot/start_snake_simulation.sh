#!/bin/bash


gnome-terminal --tab -e ~/Documents/catkin_ws/launch_snakebot/gazebo.sh &
sleep 3
gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/matlab_communication.sh &
gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/labview_communication.sh &

sleep 1
gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/mocap_optitrack.sh &

sleep 1
gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/world_setup.sh &



gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/effort_selector.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/position_control.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/collisions.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/pushpoints.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/propulsion_control.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/visualizer.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/robot_pose.sh &


gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/virtual_snake.sh &
gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/shape_control.sh &


gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/kinematics.sh &

gnome-terminal -e ~/Documents/catkin_ws/launch_snakebot/visual_data_topic_collector.sh &