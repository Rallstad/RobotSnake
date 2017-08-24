cmake_minimum_required(VERSION 2.8.3)
project(snakebot_shape_control)

# add_definitions(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
  snakebot_pushpoints
  snakebot_robot_pose
)

add_message_files(
  FILES
  ShapeCurve.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)


catkin_package(
  CATKIN_DEPENDS message_runtime roscpp rospy std_msgs geometry_msgs
)


include_directories(include 
	${catkin_INCLUDE_DIRS}
)

add_executable(shape_control
	src/main.cpp
)
add_library(virtual_snake_class 
	src/virtualsnake.cpp
)
add_library(spline_interpolation_lib
	src/spline.h
)

set_target_properties(spline_interpolation_lib PROPERTIES LINKER_LANGUAGE CXX)

add_dependencies(shape_control ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(virtual_snake_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(shape_control
	virtual_snake_class
	spline_interpolation_lib
	${catkin_LIBRARIES}
)

