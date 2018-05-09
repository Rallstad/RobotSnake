; Auto-generated. Do not edit!


(cl:in-package snakebot_matlab_communication-msg)


;//! \htmlinclude pushpointsvisual.msg.html

(cl:defclass <pushpointsvisual> (roslisp-msg-protocol:ros-message)
  ((pushpoints
    :reader pushpoints
    :initarg :pushpoints
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass pushpointsvisual (<pushpointsvisual>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pushpointsvisual>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pushpointsvisual)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_matlab_communication-msg:<pushpointsvisual> is deprecated: use snakebot_matlab_communication-msg:pushpointsvisual instead.")))

(cl:ensure-generic-function 'pushpoints-val :lambda-list '(m))
(cl:defmethod pushpoints-val ((m <pushpointsvisual>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_matlab_communication-msg:pushpoints-val is deprecated.  Use snakebot_matlab_communication-msg:pushpoints instead.")
  (pushpoints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pushpointsvisual>) ostream)
  "Serializes a message object of type '<pushpointsvisual>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pushpoints))))
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
   (cl:slot-value msg 'pushpoints))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pushpointsvisual>) istream)
  "Deserializes a message object of type '<pushpointsvisual>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pushpoints) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pushpoints)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pushpointsvisual>)))
  "Returns string type for a message object of type '<pushpointsvisual>"
  "snakebot_matlab_communication/pushpointsvisual")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pushpointsvisual)))
  "Returns string type for a message object of type 'pushpointsvisual"
  "snakebot_matlab_communication/pushpointsvisual")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pushpointsvisual>)))
  "Returns md5sum for a message object of type '<pushpointsvisual>"
  "f4e69e5e9ff0b2d3198591521dc8cf47")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pushpointsvisual)))
  "Returns md5sum for a message object of type 'pushpointsvisual"
  "f4e69e5e9ff0b2d3198591521dc8cf47")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pushpointsvisual>)))
  "Returns full string definition for message of type '<pushpointsvisual>"
  (cl:format cl:nil "int32[] pushpoints~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pushpointsvisual)))
  "Returns full string definition for message of type 'pushpointsvisual"
  (cl:format cl:nil "int32[] pushpoints~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pushpointsvisual>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pushpoints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pushpointsvisual>))
  "Converts a ROS message object to a list"
  (cl:list 'pushpointsvisual
    (cl:cons ':pushpoints (pushpoints msg))
))
