cmake_minimum_required(VERSION 2.8.3)
project(snakebot_pushpoints)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
  snakebot_collisions
)


add_message_files(
 FILES
 Pushpoints.msg
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


add_executable(pushpoints
	src/main.cpp
)
add_library(pushpoint_extractor
	src/pushpointextractor.cpp
)

add_dependencies(pushpoints snakebot_pushpoints_generate_messages_cpp ${catkin_EXPORTED_TARGETS})

target_link_libraries(pushpoints
	pushpoint_extractor
	${catkin_LIBRARIES}
)

