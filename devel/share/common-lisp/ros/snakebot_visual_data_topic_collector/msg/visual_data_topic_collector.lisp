; Auto-generated. Do not edit!


(cl:in-package snakebot_visual_data_topic_collector-msg)


;//! \htmlinclude visual_data_topic_collector.msg.html

(cl:defclass <visual_data_topic_collector> (roslisp-msg-protocol:ros-message)
  ((jointposes
    :reader jointposes
    :initarg :jointposes
    :type (cl:vector geometry_msgs-msg:Pose2D)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Pose2D :initial-element (cl:make-instance 'geometry_msgs-msg:Pose2D))))
)

(cl:defclass visual_data_topic_collector (<visual_data_topic_collector>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <visual_data_topic_collector>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'visual_data_topic_collector)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_visual_data_topic_collector-msg:<visual_data_topic_collector> is deprecated: use snakebot_visual_data_topic_collector-msg:visual_data_topic_collector instead.")))

(cl:ensure-generic-function 'jointposes-val :lambda-list '(m))
(cl:defmethod jointposes-val ((m <visual_data_topic_collector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_visual_data_topic_collector-msg:jointposes-val is deprecated.  Use snakebot_visual_data_topic_collector-msg:jointposes instead.")
  (jointposes m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <visual_data_topic_collector>) ostream)
  "Serializes a message object of type '<visual_data_topic_collector>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'jointposes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'jointposes))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <visual_data_topic_collector>) istream)
  "Deserializes a message object of type '<visual_data_topic_collector>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'jointposes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'jointposes)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Pose2D))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<visual_data_topic_collector>)))
  "Returns string type for a message object of type '<visual_data_topic_collector>"
  "snakebot_visual_data_topic_collector/visual_data_topic_collector")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'visual_data_topic_collector)))
  "Returns string type for a message object of type 'visual_data_topic_collector"
  "snakebot_visual_data_topic_collector/visual_data_topic_collector")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<visual_data_topic_collector>)))
  "Returns md5sum for a message object of type '<visual_data_topic_collector>"
  "0c6f0598a6c1c5c4f41cb8ce0c396bdf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'visual_data_topic_collector)))
  "Returns md5sum for a message object of type 'visual_data_topic_collector"
  "0c6f0598a6c1c5c4f41cb8ce0c396bdf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<visual_data_topic_collector>)))
  "Returns full string definition for message of type '<visual_data_topic_collector>"
  (cl:format cl:nil "geometry_msgs/Pose2D[] jointposes~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'visual_data_topic_collector)))
  "Returns full string definition for message of type 'visual_data_topic_collector"
  (cl:format cl:nil "geometry_msgs/Pose2D[] jointposes~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <visual_data_topic_collector>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'jointposes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <visual_data_topic_collector>))
  "Converts a ROS message object to a list"
  (cl:list 'visual_data_topic_collector
    (cl:cons ':jointposes (jointposes msg))
))
