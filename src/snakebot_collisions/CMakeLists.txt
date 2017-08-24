cmake_minimum_required(VERSION 2.8.3)
project(snakebot_collisions)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
  snakebot_robot_pose
)


add_message_files(
  FILES
	LinkContacts.msg
	SnakeContacts.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime roscpp rospy std_msgs
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)



add_executable(collisions
	src/main.cpp
)
add_library(collisions_class
	src/collisions.cpp
)
add_library(bumper_class
	src/bumper.cpp
)
add_library(geometry_lib
	src/geometry.cpp
)

add_dependencies(collisions ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(collisions_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(bumper_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(collisions
	collisions_class
	bumper_class
	geometry_lib
	${catkin_LIBRARIES}
)


