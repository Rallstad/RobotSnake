# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "snakebot_visual_data_topic_collector: 2 messages, 0 services")

set(MSG_I_FLAGS "-Isnakebot_visual_data_topic_collector:/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(snakebot_visual_data_topic_collector_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg" NAME_WE)
add_custom_target(_snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_visual_data_topic_collector" "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg" "geometry_msgs/Pose2D"
)

get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg" NAME_WE)
add_custom_target(_snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_visual_data_topic_collector" "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg" "geometry_msgs/Pose2D"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(snakebot_visual_data_topic_collector
  "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_visual_data_topic_collector
)
_generate_msg_cpp(snakebot_visual_data_topic_collector
  "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_visual_data_topic_collector
)

### Generating Services

### Generating Module File
_generate_module_cpp(snakebot_visual_data_topic_collector
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_visual_data_topic_collector
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(snakebot_visual_data_topic_collector_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages snakebot_visual_data_topic_collector_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg" NAME_WE)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages_cpp _snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg" NAME_WE)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages_cpp _snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_visual_data_topic_collector_gencpp)
add_dependencies(snakebot_visual_data_topic_collector_gencpp snakebot_visual_data_topic_collector_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_visual_data_topic_collector_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(snakebot_visual_data_topic_collector
  "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_visual_data_topic_collector
)
_generate_msg_lisp(snakebot_visual_data_topic_collector
  "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_visual_data_topic_collector
)

### Generating Services

### Generating Module File
_generate_module_lisp(snakebot_visual_data_topic_collector
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_visual_data_topic_collector
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(snakebot_visual_data_topic_collector_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages snakebot_visual_data_topic_collector_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg" NAME_WE)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages_lisp _snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg" NAME_WE)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages_lisp _snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_visual_data_topic_collector_genlisp)
add_dependencies(snakebot_visual_data_topic_collector_genlisp snakebot_visual_data_topic_collector_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_visual_data_topic_collector_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(snakebot_visual_data_topic_collector
  "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_visual_data_topic_collector
)
_generate_msg_py(snakebot_visual_data_topic_collector
  "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_visual_data_topic_collector
)

### Generating Services

### Generating Module File
_generate_module_py(snakebot_visual_data_topic_collector
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_visual_data_topic_collector
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(snakebot_visual_data_topic_collector_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages snakebot_visual_data_topic_collector_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/jointposes.msg" NAME_WE)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages_py _snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg/obstacles.msg" NAME_WE)
add_dependencies(snakebot_visual_data_topic_collector_generate_messages_py _snakebot_visual_data_topic_collector_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_visual_data_topic_collector_genpy)
add_dependencies(snakebot_visual_data_topic_collector_genpy snakebot_visual_data_topic_collector_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_visual_data_topic_collector_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_visual_data_topic_collector)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_visual_data_topic_collector
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(snakebot_visual_data_topic_collector_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(snakebot_visual_data_topic_collector_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_visual_data_topic_collector)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_visual_data_topic_collector
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(snakebot_visual_data_topic_collector_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(snakebot_visual_data_topic_collector_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_visual_data_topic_collector)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_visual_data_topic_collector\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_visual_data_topic_collector
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(snakebot_visual_data_topic_collector_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(snakebot_visual_data_topic_collector_generate_messages_py geometry_msgs_generate_messages_py)
endif()
