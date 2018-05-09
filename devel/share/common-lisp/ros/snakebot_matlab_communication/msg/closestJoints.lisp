; Auto-generated. Do not edit!


(cl:in-package snakebot_matlab_communication-msg)


;//! \htmlinclude closestJoints.msg.html

(cl:defclass <closestJoints> (roslisp-msg-protocol:ros-message)
  ((closestjoints
    :reader closestjoints
    :initarg :closestjoints
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass closestJoints (<closestJoints>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <closestJoints>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'closestJoints)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_matlab_communication-msg:<closestJoints> is deprecated: use snakebot_matlab_communication-msg:closestJoints instead.")))

(cl:ensure-generic-function 'closestjoints-val :lambda-list '(m))
(cl:defmethod closestjoints-val ((m <closestJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_matlab_communication-msg:closestjoints-val is deprecated.  Use snakebot_matlab_communication-msg:closestjoints instead.")
  (closestjoints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <closestJoints>) ostream)
  "Serializes a message object of type '<closestJoints>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'closestjoints))))
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
   (cl:slot-value msg 'closestjoints))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <closestJoints>) istream)
  "Deserializes a message object of type '<closestJoints>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'closestjoints) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'closestjoints)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<closestJoints>)))
  "Returns string type for a message object of type '<closestJoints>"
  "snakebot_matlab_communication/closestJoints")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'closestJoints)))
  "Returns string type for a message object of type 'closestJoints"
  "snakebot_matlab_communication/closestJoints")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<closestJoints>)))
  "Returns md5sum for a message object of type '<closestJoints>"
  "e42bda731c775f6815ae82d3e34de264")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'closestJoints)))
  "Returns md5sum for a message object of type 'closestJoints"
  "e42bda731c775f6815ae82d3e34de264")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<closestJoints>)))
  "Returns full string definition for message of type '<closestJoints>"
  (cl:format cl:nil "int32[] closestjoints~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'closestJoints)))
  "Returns full string definition for message of type 'closestJoints"
  (cl:format cl:nil "int32[] closestjoints~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <closestJoints>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'closestjoints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <closestJoints>))
  "Converts a ROS message object to a list"
  (cl:list 'closestJoints
    (cl:cons ':closestjoints (closestjoints msg))
))
