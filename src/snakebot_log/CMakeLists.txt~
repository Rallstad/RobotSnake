cmake_minimum_required(VERSION 2.8.3)
project(snakebot_log)

# add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_executable(log_node 
	src/main.cpp
)

add_library(logger_class
	src/logger.cpp
)

add_dependencies(log_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(logger_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(log_node
	logger_class
	${catkin_LIBRARIES}
)


