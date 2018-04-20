; Auto-generated. Do not edit!


(cl:in-package snakebot_visual_data_topic_collector-msg)


;//! \htmlinclude jointposes.msg.html

(cl:defclass <jointposes> (roslisp-msg-protocol:ros-message)
  ((jointposes
    :reader jointposes
    :initarg :jointposes
    :type (cl:vector geometry_msgs-msg:Pose2D)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Pose2D :initial-element (cl:make-instance 'geometry_msgs-msg:Pose2D))))
)

(cl:defclass jointposes (<jointposes>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jointposes>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jointposes)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_visual_data_topic_collector-msg:<jointposes> is deprecated: use snakebot_visual_data_topic_collector-msg:jointposes instead.")))

(cl:ensure-generic-function 'jointposes-val :lambda-list '(m))
(cl:defmethod jointposes-val ((m <jointposes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_visual_data_topic_collector-msg:jointposes-val is deprecated.  Use snakebot_visual_data_topic_collector-msg:jointposes instead.")
  (jointposes m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jointposes>) ostream)
  "Serializes a message object of type '<jointposes>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'jointposes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'jointposes))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jointposes>) istream)
  "Deserializes a message object of type '<jointposes>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jointposes>)))
  "Returns string type for a message object of type '<jointposes>"
  "snakebot_visual_data_topic_collector/jointposes")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jointposes)))
  "Returns string type for a message object of type 'jointposes"
  "snakebot_visual_data_topic_collector/jointposes")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jointposes>)))
  "Returns md5sum for a message object of type '<jointposes>"
  "0c6f0598a6c1c5c4f41cb8ce0c396bdf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jointposes)))
  "Returns md5sum for a message object of type 'jointposes"
  "0c6f0598a6c1c5c4f41cb8ce0c396bdf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jointposes>)))
  "Returns full string definition for message of type '<jointposes>"
  (cl:format cl:nil "geometry_msgs/Pose2D[] jointposes~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jointposes)))
  "Returns full string definition for message of type 'jointposes"
  (cl:format cl:nil "geometry_msgs/Pose2D[] jointposes~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jointposes>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'jointposes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jointposes>))
  "Converts a ROS message object to a list"
  (cl:list 'jointposes
    (cl:cons ':jointposes (jointposes msg))
))
