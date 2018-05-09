; Auto-generated. Do not edit!


(cl:in-package snakebot_matlab_communication-msg)


;//! \htmlinclude pushPoints.msg.html

(cl:defclass <pushPoints> (roslisp-msg-protocol:ros-message)
  ((pushpoints
    :reader pushpoints
    :initarg :pushpoints
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass pushPoints (<pushPoints>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pushPoints>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pushPoints)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_matlab_communication-msg:<pushPoints> is deprecated: use snakebot_matlab_communication-msg:pushPoints instead.")))

(cl:ensure-generic-function 'pushpoints-val :lambda-list '(m))
(cl:defmethod pushpoints-val ((m <pushPoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_matlab_communication-msg:pushpoints-val is deprecated.  Use snakebot_matlab_communication-msg:pushpoints instead.")
  (pushpoints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pushPoints>) ostream)
  "Serializes a message object of type '<pushPoints>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pushPoints>) istream)
  "Deserializes a message object of type '<pushPoints>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pushPoints>)))
  "Returns string type for a message object of type '<pushPoints>"
  "snakebot_matlab_communication/pushPoints")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pushPoints)))
  "Returns string type for a message object of type 'pushPoints"
  "snakebot_matlab_communication/pushPoints")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pushPoints>)))
  "Returns md5sum for a message object of type '<pushPoints>"
  "f4e69e5e9ff0b2d3198591521dc8cf47")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pushPoints)))
  "Returns md5sum for a message object of type 'pushPoints"
  "f4e69e5e9ff0b2d3198591521dc8cf47")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pushPoints>)))
  "Returns full string definition for message of type '<pushPoints>"
  (cl:format cl:nil "int32[] pushpoints~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pushPoints)))
  "Returns full string definition for message of type 'pushPoints"
  (cl:format cl:nil "int32[] pushpoints~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pushPoints>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pushpoints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pushPoints>))
  "Converts a ROS message object to a list"
  (cl:list 'pushPoints
    (cl:cons ':pushpoints (pushpoints msg))
))
