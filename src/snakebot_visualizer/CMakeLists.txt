cmake_minimum_required(VERSION 2.8.3)

add_definitions(-std=c++11)

project(snakebot_visualizer)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
  snakebot_propulsion_control
  snakebot_robot_pose
  snakebot_collisions
)

catkin_package(
  CATKIN_DEPENDS roscpp visualization_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")


add_executable(visualizer
	src/main.cpp
)
add_library(rviz_publisher
	src/rvizpublisher.cpp
)
add_library(state_subscriber
	src/statesubscriber.cpp
)
add_library(data_types
	src/datatypes.cpp
	)
	
add_dependencies(visualizer ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(rviz_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(state_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

	
target_link_libraries(visualizer
	rviz_publisher
	state_subscriber
	data_types
${catkin_LIBRARIES}
)
