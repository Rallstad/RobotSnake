; Auto-generated. Do not edit!


(cl:in-package snakebot_robot_pose-msg)


;//! \htmlinclude Pose.msg.html

(cl:defclass <Pose> (roslisp-msg-protocol:ros-message)
  ((obstaclePose
    :reader obstaclePose
    :initarg :obstaclePose
    :type snakebot_robot_pose-msg:ObstaclePose
    :initform (cl:make-instance 'snakebot_robot_pose-msg:ObstaclePose))
   (snakePose
    :reader snakePose
    :initarg :snakePose
    :type snakebot_robot_pose-msg:SnakePose
    :initform (cl:make-instance 'snakebot_robot_pose-msg:SnakePose)))
)

(cl:defclass Pose (<Pose>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Pose>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Pose)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_robot_pose-msg:<Pose> is deprecated: use snakebot_robot_pose-msg:Pose instead.")))

(cl:ensure-generic-function 'obstaclePose-val :lambda-list '(m))
(cl:defmethod obstaclePose-val ((m <Pose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_robot_pose-msg:obstaclePose-val is deprecated.  Use snakebot_robot_pose-msg:obstaclePose instead.")
  (obstaclePose m))

(cl:ensure-generic-function 'snakePose-val :lambda-list '(m))
(cl:defmethod snakePose-val ((m <Pose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_robot_pose-msg:snakePose-val is deprecated.  Use snakebot_robot_pose-msg:snakePose instead.")
  (snakePose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Pose>) ostream)
  "Serializes a message object of type '<Pose>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePose) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'snakePose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Pose>) istream)
  "Deserializes a message object of type '<Pose>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePose) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'snakePose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Pose>)))
  "Returns string type for a message object of type '<Pose>"
  "snakebot_robot_pose/Pose")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Pose)))
  "Returns string type for a message object of type 'Pose"
  "snakebot_robot_pose/Pose")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Pose>)))
  "Returns md5sum for a message object of type '<Pose>"
  "aff8fe2814f3bc61ee63b10f4685f479")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Pose)))
  "Returns md5sum for a message object of type 'Pose"
  "aff8fe2814f3bc61ee63b10f4685f479")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Pose>)))
  "Returns full string definition for message of type '<Pose>"
  (cl:format cl:nil "ObstaclePose obstaclePose~%SnakePose snakePose~%~%================================================================================~%MSG: snakebot_robot_pose/ObstaclePose~%string[] name                 # obstacle names~%int32[] number								# obstacle numbers~%geometry_msgs/Pose2D[] pose~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%================================================================================~%MSG: snakebot_robot_pose/SnakePose~%string[] name                 # link names~%int32[] number								# link numbers~%geometry_msgs/Pose2D[] pose~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Pose)))
  "Returns full string definition for message of type 'Pose"
  (cl:format cl:nil "ObstaclePose obstaclePose~%SnakePose snakePose~%~%================================================================================~%MSG: snakebot_robot_pose/ObstaclePose~%string[] name                 # obstacle names~%int32[] number								# obstacle numbers~%geometry_msgs/Pose2D[] pose~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%================================================================================~%MSG: snakebot_robot_pose/SnakePose~%string[] name                 # link names~%int32[] number								# link numbers~%geometry_msgs/Pose2D[] pose~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Pose>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePose))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'snakePose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Pose>))
  "Converts a ROS message object to a list"
  (cl:list 'Pose
    (cl:cons ':obstaclePose (obstaclePose msg))
    (cl:cons ':snakePose (snakePose msg))
))
