# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "snakebot_link_pose_interface: 3 messages, 0 services")

set(MSG_I_FLAGS "-Isnakebot_link_pose_interface:/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(snakebot_link_pose_interface_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg" NAME_WE)
add_custom_target(_snakebot_link_pose_interface_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_link_pose_interface" "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg" "snakebot_link_pose_interface/ObstaclePose:snakebot_link_pose_interface/SnakePose:geometry_msgs/Pose2D"
)

get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg" NAME_WE)
add_custom_target(_snakebot_link_pose_interface_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_link_pose_interface" "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg" "geometry_msgs/Pose2D"
)

get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg" NAME_WE)
add_custom_target(_snakebot_link_pose_interface_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_link_pose_interface" "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg" "geometry_msgs/Pose2D"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg;/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_link_pose_interface
)
_generate_msg_cpp(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_link_pose_interface
)
_generate_msg_cpp(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_link_pose_interface
)

### Generating Services

### Generating Module File
_generate_module_cpp(snakebot_link_pose_interface
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_link_pose_interface
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(snakebot_link_pose_interface_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(snakebot_link_pose_interface_generate_messages snakebot_link_pose_interface_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_cpp _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_cpp _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_cpp _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_link_pose_interface_gencpp)
add_dependencies(snakebot_link_pose_interface_gencpp snakebot_link_pose_interface_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_link_pose_interface_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg;/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_link_pose_interface
)
_generate_msg_lisp(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_link_pose_interface
)
_generate_msg_lisp(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_link_pose_interface
)

### Generating Services

### Generating Module File
_generate_module_lisp(snakebot_link_pose_interface
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_link_pose_interface
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(snakebot_link_pose_interface_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(snakebot_link_pose_interface_generate_messages snakebot_link_pose_interface_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_lisp _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_lisp _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_lisp _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_link_pose_interface_genlisp)
add_dependencies(snakebot_link_pose_interface_genlisp snakebot_link_pose_interface_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_link_pose_interface_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg;/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface
)
_generate_msg_py(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface
)
_generate_msg_py(snakebot_link_pose_interface
  "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface
)

### Generating Services

### Generating Module File
_generate_module_py(snakebot_link_pose_interface
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(snakebot_link_pose_interface_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(snakebot_link_pose_interface_generate_messages snakebot_link_pose_interface_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/Pose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_py _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/ObstaclePose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_py _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/archived packages/snakebot_link_pose_interface/msg/SnakePose.msg" NAME_WE)
add_dependencies(snakebot_link_pose_interface_generate_messages_py _snakebot_link_pose_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_link_pose_interface_genpy)
add_dependencies(snakebot_link_pose_interface_genpy snakebot_link_pose_interface_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_link_pose_interface_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_link_pose_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_link_pose_interface
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(snakebot_link_pose_interface_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(snakebot_link_pose_interface_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_link_pose_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_link_pose_interface
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(snakebot_link_pose_interface_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(snakebot_link_pose_interface_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_link_pose_interface
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(snakebot_link_pose_interface_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(snakebot_link_pose_interface_generate_messages_py geometry_msgs_generate_messages_py)
endif()
