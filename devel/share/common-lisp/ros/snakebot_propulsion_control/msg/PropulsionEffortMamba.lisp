; Auto-generated. Do not edit!


(cl:in-package snakebot_propulsion_control-msg)


;//! \htmlinclude PropulsionEffortMamba.msg.html

(cl:defclass <PropulsionEffortMamba> (roslisp-msg-protocol:ros-message)
  ((jointnum
    :reader jointnum
    :initarg :jointnum
    :type cl:integer
    :initform 0)
   (desiredtorque
    :reader desiredtorque
    :initarg :desiredtorque
    :type cl:float
    :initform 0.0))
)

(cl:defclass PropulsionEffortMamba (<PropulsionEffortMamba>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PropulsionEffortMamba>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PropulsionEffortMamba)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_propulsion_control-msg:<PropulsionEffortMamba> is deprecated: use snakebot_propulsion_control-msg:PropulsionEffortMamba instead.")))

(cl:ensure-generic-function 'jointnum-val :lambda-list '(m))
(cl:defmethod jointnum-val ((m <PropulsionEffortMamba>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_propulsion_control-msg:jointnum-val is deprecated.  Use snakebot_propulsion_control-msg:jointnum instead.")
  (jointnum m))

(cl:ensure-generic-function 'desiredtorque-val :lambda-list '(m))
(cl:defmethod desiredtorque-val ((m <PropulsionEffortMamba>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_propulsion_control-msg:desiredtorque-val is deprecated.  Use snakebot_propulsion_control-msg:desiredtorque instead.")
  (desiredtorque m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PropulsionEffortMamba>) ostream)
  "Serializes a message object of type '<PropulsionEffortMamba>"
  (cl:let* ((signed (cl:slot-value msg 'jointnum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'desiredtorque))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PropulsionEffortMamba>) istream)
  "Deserializes a message object of type '<PropulsionEffortMamba>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'jointnum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'desiredtorque) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PropulsionEffortMamba>)))
  "Returns string type for a message object of type '<PropulsionEffortMamba>"
  "snakebot_propulsion_control/PropulsionEffortMamba")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PropulsionEffortMamba)))
  "Returns string type for a message object of type 'PropulsionEffortMamba"
  "snakebot_propulsion_control/PropulsionEffortMamba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PropulsionEffortMamba>)))
  "Returns md5sum for a message object of type '<PropulsionEffortMamba>"
  "4a8b56678dbbea5f95218ac247cce854")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PropulsionEffortMamba)))
  "Returns md5sum for a message object of type 'PropulsionEffortMamba"
  "4a8b56678dbbea5f95218ac247cce854")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PropulsionEffortMamba>)))
  "Returns full string definition for message of type '<PropulsionEffortMamba>"
  (cl:format cl:nil "~%int32 jointnum~%float64 desiredtorque~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PropulsionEffortMamba)))
  "Returns full string definition for message of type 'PropulsionEffortMamba"
  (cl:format cl:nil "~%int32 jointnum~%float64 desiredtorque~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PropulsionEffortMamba>))
  (cl:+ 0
     4
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PropulsionEffortMamba>))
  "Converts a ROS message object to a list"
  (cl:list 'PropulsionEffortMamba
    (cl:cons ':jointnum (jointnum msg))
    (cl:cons ':desiredtorque (desiredtorque msg))
))
