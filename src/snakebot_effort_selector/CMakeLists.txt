cmake_minimum_required(VERSION 2.8.3)
project(snakebot_effort_selector)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  snakebot_propulsion_control
  snakebot_position_control
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(effort_selector 
	src/main.cpp
)
add_library(effort_selector_class
	src/effortselector.cpp
)

add_dependencies(effort_selector ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(effort_selector_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(effort_selector
	effort_selector_class
	${catkin_LIBRARIES}
)

