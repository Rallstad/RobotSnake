cmake_minimum_required(VERSION 2.8.3)
project(snakebot_propulsion_control)


find_package(catkin REQUIRED
	roscpp
	rospy
	std_msgs
	geometry_msgs
	message_generation
	snakebot_pushpoints
)


add_message_files(
  FILES
  PropulsionEffort.msg
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

include_directories(include 
${catkin_INCLUDE_DIRS}
)

add_executable(propulsion_control
	src/main.cpp
)
add_library(snakeControlLib 
	src/propulsioncontroller.cpp
)

add_dependencies(snakeControlLib ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_dependencies(propulsion_control ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(snakeControlLib 
	${catkin_LIBRARIES}
)
target_link_libraries(propulsion_control
	${catkin_LIBRARIES}
snakeControlLib
)







