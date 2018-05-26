; Auto-generated. Do not edit!


(cl:in-package snakebot_kinematics-msg)


;//! \htmlinclude obstacles.msg.html

(cl:defclass <obstacles> (roslisp-msg-protocol:ros-message)
  ((number
    :reader number
    :initarg :number
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (pose
    :reader pose
    :initarg :pose
    :type (cl:vector geometry_msgs-msg:Pose2D)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Pose2D :initial-element (cl:make-instance 'geometry_msgs-msg:Pose2D))))
)

(cl:defclass obstacles (<obstacles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <obstacles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'obstacles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_kinematics-msg:<obstacles> is deprecated: use snakebot_kinematics-msg:obstacles instead.")))

(cl:ensure-generic-function 'number-val :lambda-list '(m))
(cl:defmethod number-val ((m <obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_kinematics-msg:number-val is deprecated.  Use snakebot_kinematics-msg:number instead.")
  (number m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_kinematics-msg:pose-val is deprecated.  Use snakebot_kinematics-msg:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <obstacles>) ostream)
  "Serializes a message object of type '<obstacles>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'number))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'number))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pose))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'pose))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <obstacles>) istream)
  "Deserializes a message object of type '<obstacles>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'number) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'number)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pose) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pose)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Pose2D))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<obstacles>)))
  "Returns string type for a message object of type '<obstacles>"
  "snakebot_kinematics/obstacles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'obstacles)))
  "Returns string type for a message object of type 'obstacles"
  "snakebot_kinematics/obstacles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<obstacles>)))
  "Returns md5sum for a message object of type '<obstacles>"
  "65957b924e9e5ac01b02eafee4ee892a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'obstacles)))
  "Returns md5sum for a message object of type 'obstacles"
  "65957b924e9e5ac01b02eafee4ee892a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<obstacles>)))
  "Returns full string definition for message of type '<obstacles>"
  (cl:format cl:nil "int32[] number				  # obstacle numbers~%geometry_msgs/Pose2D[] pose~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'obstacles)))
  "Returns full string definition for message of type 'obstacles"
  (cl:format cl:nil "int32[] number				  # obstacle numbers~%geometry_msgs/Pose2D[] pose~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <obstacles>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'number) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pose) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <obstacles>))
  "Converts a ROS message object to a list"
  (cl:list 'obstacles
    (cl:cons ':number (number msg))
    (cl:cons ':pose (pose msg))
))
