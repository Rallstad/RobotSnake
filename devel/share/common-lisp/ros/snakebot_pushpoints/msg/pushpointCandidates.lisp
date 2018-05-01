; Auto-generated. Do not edit!


(cl:in-package snakebot_pushpoints-msg)


;//! \htmlinclude pushpointCandidates.msg.html

(cl:defclass <pushpointCandidates> (roslisp-msg-protocol:ros-message)
  ((pushpointcandidates
    :reader pushpointcandidates
    :initarg :pushpointcandidates
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass pushpointCandidates (<pushpointCandidates>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pushpointCandidates>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pushpointCandidates)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_pushpoints-msg:<pushpointCandidates> is deprecated: use snakebot_pushpoints-msg:pushpointCandidates instead.")))

(cl:ensure-generic-function 'pushpointcandidates-val :lambda-list '(m))
(cl:defmethod pushpointcandidates-val ((m <pushpointCandidates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_pushpoints-msg:pushpointcandidates-val is deprecated.  Use snakebot_pushpoints-msg:pushpointcandidates instead.")
  (pushpointcandidates m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pushpointCandidates>) ostream)
  "Serializes a message object of type '<pushpointCandidates>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pushpointcandidates))))
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
   (cl:slot-value msg 'pushpointcandidates))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pushpointCandidates>) istream)
  "Deserializes a message object of type '<pushpointCandidates>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pushpointcandidates) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pushpointcandidates)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pushpointCandidates>)))
  "Returns string type for a message object of type '<pushpointCandidates>"
  "snakebot_pushpoints/pushpointCandidates")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pushpointCandidates)))
  "Returns string type for a message object of type 'pushpointCandidates"
  "snakebot_pushpoints/pushpointCandidates")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pushpointCandidates>)))
  "Returns md5sum for a message object of type '<pushpointCandidates>"
  "aa77bb8159d3c15726311f4e2879eb10")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pushpointCandidates)))
  "Returns md5sum for a message object of type 'pushpointCandidates"
  "aa77bb8159d3c15726311f4e2879eb10")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pushpointCandidates>)))
  "Returns full string definition for message of type '<pushpointCandidates>"
  (cl:format cl:nil "int32[] pushpointcandidates~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pushpointCandidates)))
  "Returns full string definition for message of type 'pushpointCandidates"
  (cl:format cl:nil "int32[] pushpointcandidates~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pushpointCandidates>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pushpointcandidates) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pushpointCandidates>))
  "Converts a ROS message object to a list"
  (cl:list 'pushpointCandidates
    (cl:cons ':pushpointcandidates (pushpointcandidates msg))
))
