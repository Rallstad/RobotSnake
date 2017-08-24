cmake_minimum_required(VERSION 2.8.3)
project(snakebot_robot_pose)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)

add_message_files(
  FILES
  SnakePose.msg
  ObstaclePose.msg
  Pose.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime roscpp rospy std_msgs
)

include_directories( ${catkin_INCLUDE_DIRS})



add_executable(robot_pose
	src/main.cpp
)

add_dependencies(robot_pose ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(robot_pose
	${catkin_LIBRARIES}
)
