cmake_minimum_required(VERSION 2.8.3)
project(snakebot_labview_communication)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)

add_message_files(
 	FILES
 	Collisions.msg
 	LinkPoses.msg
	Float64Array.msg
	Int32Array.msg
)

generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime roscpp rospy std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_executable(labview_communication 
	src/main.cpp
)

add_library(communication_class
	src/communication.cpp
)

add_dependencies(labview_communication ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(communication_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(labview_communication
	communication_class
	${catkin_LIBRARIES}
)


