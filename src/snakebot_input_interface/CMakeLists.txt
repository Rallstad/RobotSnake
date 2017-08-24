cmake_minimum_required(VERSION 2.8.3)
project(snakebot_input_interface)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)


add_message_files(
  FILES
	Ctrl.msg
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


add_executable(input_interface
	src/main.cpp
)
add_library(input_interface_class
	src/inputinterface.cpp
)

add_dependencies(input_interface ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(input_interface_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(input_interface
	input_interface_class
	${catkin_LIBRARIES}
)


