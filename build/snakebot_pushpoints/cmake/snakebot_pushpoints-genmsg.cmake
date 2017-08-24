# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "snakebot_pushpoints: 1 messages, 0 services")

set(MSG_I_FLAGS "-Isnakebot_pushpoints:/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(snakebot_pushpoints_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg" NAME_WE)
add_custom_target(_snakebot_pushpoints_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "snakebot_pushpoints" "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg" "geometry_msgs/Vector3:std_msgs/Header:geometry_msgs/Point"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(snakebot_pushpoints
  "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_pushpoints
)

### Generating Services

### Generating Module File
_generate_module_cpp(snakebot_pushpoints
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_pushpoints
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(snakebot_pushpoints_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(snakebot_pushpoints_generate_messages snakebot_pushpoints_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg" NAME_WE)
add_dependencies(snakebot_pushpoints_generate_messages_cpp _snakebot_pushpoints_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_pushpoints_gencpp)
add_dependencies(snakebot_pushpoints_gencpp snakebot_pushpoints_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_pushpoints_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(snakebot_pushpoints
  "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_pushpoints
)

### Generating Services

### Generating Module File
_generate_module_lisp(snakebot_pushpoints
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_pushpoints
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(snakebot_pushpoints_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(snakebot_pushpoints_generate_messages snakebot_pushpoints_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg" NAME_WE)
add_dependencies(snakebot_pushpoints_generate_messages_lisp _snakebot_pushpoints_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_pushpoints_genlisp)
add_dependencies(snakebot_pushpoints_genlisp snakebot_pushpoints_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_pushpoints_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(snakebot_pushpoints
  "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_pushpoints
)

### Generating Services

### Generating Module File
_generate_module_py(snakebot_pushpoints
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_pushpoints
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(snakebot_pushpoints_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(snakebot_pushpoints_generate_messages snakebot_pushpoints_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/snake/Documents/catkin_ws/src/snakebot_pushpoints/msg/Pushpoints.msg" NAME_WE)
add_dependencies(snakebot_pushpoints_generate_messages_py _snakebot_pushpoints_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(snakebot_pushpoints_genpy)
add_dependencies(snakebot_pushpoints_genpy snakebot_pushpoints_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS snakebot_pushpoints_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_pushpoints)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/snakebot_pushpoints
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(snakebot_pushpoints_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(snakebot_pushpoints_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_pushpoints)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/snakebot_pushpoints
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(snakebot_pushpoints_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(snakebot_pushpoints_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_pushpoints)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_pushpoints\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/snakebot_pushpoints
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(snakebot_pushpoints_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(snakebot_pushpoints_generate_messages_py geometry_msgs_generate_messages_py)
endif()
