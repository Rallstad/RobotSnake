; Auto-generated. Do not edit!


(cl:in-package snakebot_kinematics-msg)


;//! \htmlinclude snake_obstacles.msg.html

(cl:defclass <snake_obstacles> (roslisp-msg-protocol:ros-message)
  ((obstaclePose
    :reader obstaclePose
    :initarg :obstaclePose
    :type snakebot_kinematics-msg:obstacles
    :initform (cl:make-instance 'snakebot_kinematics-msg:obstacles))
   (snakePose
    :reader snakePose
    :initarg :snakePose
    :type snakebot_kinematics-msg:kinematics
    :initform (cl:make-instance 'snakebot_kinematics-msg:kinematics)))
)

(cl:defclass snake_obstacles (<snake_obstacles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <snake_obstacles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'snake_obstacles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_kinematics-msg:<snake_obstacles> is deprecated: use snakebot_kinematics-msg:snake_obstacles instead.")))

(cl:ensure-generic-function 'obstaclePose-val :lambda-list '(m))
(cl:defmethod obstaclePose-val ((m <snake_obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_kinematics-msg:obstaclePose-val is deprecated.  Use snakebot_kinematics-msg:obstaclePose instead.")
  (obstaclePose m))

(cl:ensure-generic-function 'snakePose-val :lambda-list '(m))
(cl:defmethod snakePose-val ((m <snake_obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_kinematics-msg:snakePose-val is deprecated.  Use snakebot_kinematics-msg:snakePose instead.")
  (snakePose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <snake_obstacles>) ostream)
  "Serializes a message object of type '<snake_obstacles>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePose) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'snakePose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <snake_obstacles>) istream)
  "Deserializes a message object of type '<snake_obstacles>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePose) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'snakePose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<snake_obstacles>)))
  "Returns string type for a message object of type '<snake_obstacles>"
  "snakebot_kinematics/snake_obstacles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'snake_obstacles)))
  "Returns string type for a message object of type 'snake_obstacles"
  "snakebot_kinematics/snake_obstacles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<snake_obstacles>)))
  "Returns md5sum for a message object of type '<snake_obstacles>"
  "b58eaeba4fdc2fe74e0b3582ba64166f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'snake_obstacles)))
  "Returns md5sum for a message object of type 'snake_obstacles"
  "b58eaeba4fdc2fe74e0b3582ba64166f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<snake_obstacles>)))
  "Returns full string definition for message of type '<snake_obstacles>"
  (cl:format cl:nil "obstacles obstaclePose~%kinematics snakePose~%~%================================================================================~%MSG: snakebot_kinematics/obstacles~%int32[] number				  # obstacle numbers~%geometry_msgs/Pose2D[] pose~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%================================================================================~%MSG: snakebot_kinematics/kinematics~%int32[] number	# link numbers~%geometry_msgs/Pose2D[] pose~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'snake_obstacles)))
  "Returns full string definition for message of type 'snake_obstacles"
  (cl:format cl:nil "obstacles obstaclePose~%kinematics snakePose~%~%================================================================================~%MSG: snakebot_kinematics/obstacles~%int32[] number				  # obstacle numbers~%geometry_msgs/Pose2D[] pose~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%================================================================================~%MSG: snakebot_kinematics/kinematics~%int32[] number	# link numbers~%geometry_msgs/Pose2D[] pose~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <snake_obstacles>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePose))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'snakePose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <snake_obstacles>))
  "Converts a ROS message object to a list"
  (cl:list 'snake_obstacles
    (cl:cons ':obstaclePose (obstaclePose msg))
    (cl:cons ':snakePose (snakePose msg))
))
