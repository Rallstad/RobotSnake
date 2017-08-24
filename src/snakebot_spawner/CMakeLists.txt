cmake_minimum_required(VERSION 2.8.3)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(snakebot_spawner)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslib
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")


file(GLOB spawner_SRC "src/*.hpp" "src/*.cpp")

add_executable(spawner ${spawner_SRC})
set_target_properties(spawner PROPERTIES LINK_FLAGS "-Wl,--no-as-needed")
include_directories(include ${catkin_INCLUDE_DIRS})
target_link_libraries(spawner
  ${GAZEBO_LIBRARIES}
  ${Boost_LIBRARIES}
  ${PROTUBUF_LIBRARIES}
)
target_link_libraries(spawner ${catkin_LIBRARIES})

