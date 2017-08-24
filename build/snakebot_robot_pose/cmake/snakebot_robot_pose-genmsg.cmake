# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "snakebot_robot_pose: 3 messages, 0 services")

set(MSG_I_FLAGS "-Isnakebot_robot_pose:/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(snakebot_robot_pose_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg" NAME_WE)
add_custom_target(_snakebot_robot_pose_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_robot_pose" "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg" "geometry_msgs/Pose2D"
)

get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg" NAME_WE)
add_custom_target(_snakebot_robot_pose_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_robot_pose" "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg" "snakebot_robot_pose/SnakePose:snakebot_robot_pose/ObstaclePose:geometry_msgs/Pose2D"
)

get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg" NAME_WE)
add_custom_target(_snakebot_robot_pose_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_robot_pose" "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg" "geometry_msgs/Pose2D"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_robot_pose
)
_generate_msg_cpp(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg;/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_robot_pose
)
_generate_msg_cpp(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_robot_pose
)

### Generating Services

### Generating Module File
_generate_module_cpp(snakebot_robot_pose
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_robot_pose
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(snakebot_robot_pose_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(snakebot_robot_pose_generate_messages snakebot_robot_pose_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_cpp _snakebot_robot_pose_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_cpp _snakebot_robot_pose_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_cpp _snakebot_robot_pose_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_robot_pose_gencpp)
add_dependencies(snakebot_robot_pose_gencpp snakebot_robot_pose_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_robot_pose_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_robot_pose
)
_generate_msg_lisp(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg;/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_robot_pose
)
_generate_msg_lisp(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_robot_pose
)

### Generating Services

### Generating Module File
_generate_module_lisp(snakebot_robot_pose
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_robot_pose
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(snakebot_robot_pose_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(snakebot_robot_pose_generate_messages snakebot_robot_pose_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_lisp _snakebot_robot_pose_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_lisp _snakebot_robot_pose_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_lisp _snakebot_robot_pose_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_robot_pose_genlisp)
add_dependencies(snakebot_robot_pose_genlisp snakebot_robot_pose_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_robot_pose_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose
)
_generate_msg_py(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg;/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose
)
_generate_msg_py(snakebot_robot_pose
  "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose2D.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose
)

### Generating Services

### Generating Module File
_generate_module_py(snakebot_robot_pose
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(snakebot_robot_pose_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(snakebot_robot_pose_generate_messages snakebot_robot_pose_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/ObstaclePose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_py _snakebot_robot_pose_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/Pose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_py _snakebot_robot_pose_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_robot_pose/msg/SnakePose.msg" NAME_WE)
add_dependencies(snakebot_robot_pose_generate_messages_py _snakebot_robot_pose_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_robot_pose_genpy)
add_dependencies(snakebot_robot_pose_genpy snakebot_robot_pose_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_robot_pose_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_robot_pose)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_robot_pose
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(snakebot_robot_pose_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(snakebot_robot_pose_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_robot_pose)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_robot_pose
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(snakebot_robot_pose_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(snakebot_robot_pose_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_robot_pose
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(snakebot_robot_pose_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(snakebot_robot_pose_generate_messages_py geometry_msgs_generate_messages_py)
endif()
