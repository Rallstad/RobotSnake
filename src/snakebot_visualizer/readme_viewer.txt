ROS package "snakebot_visualizer"

launch :
roslaunch snakebot_visualize snakebot_visualizer.launch

The launch file opens an RViz window and runs the snakebot_visualizer node.
The plugin gets data from other nodes and draws arrows in RViz.

This plugins are expected to be launched before :
	snakebot_gazebo
	snakebot_effort_control

How to see the objects in RVIZ :
- launch RVIZ
- In the left panel : set the "Global Options" > "Fixed Frame" to "dummy_link"
- Using the "Add" button on the bottom left :
	> add By display type > RobotModel
	> add By topic > visualization_marker > marker
- In the left panel : choose the objects (not) to display in "namespaces"
