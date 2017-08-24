; Auto-generated. Do not edit!


(cl:in-package snakebot_input_interface-msg)


;//! \htmlinclude Ctrl.msg.html

(cl:defclass <Ctrl> (roslisp-msg-protocol:ros-message)
  ((velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0)
   (direction
    :reader direction
    :initarg :direction
    :type cl:float
    :initform 0.0))
)

(cl:defclass Ctrl (<Ctrl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Ctrl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Ctrl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_input_interface-msg:<Ctrl> is deprecated: use snakebot_input_interface-msg:Ctrl instead.")))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <Ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_input_interface-msg:velocity-val is deprecated.  Use snakebot_input_interface-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <Ctrl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_input_interface-msg:direction-val is deprecated.  Use snakebot_input_interface-msg:direction instead.")
  (direction m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Ctrl>) ostream)
  "Serializes a message object of type '<Ctrl>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'direction))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Ctrl>) istream)
  "Deserializes a message object of type '<Ctrl>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'direction) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Ctrl>)))
  "Returns string type for a message object of type '<Ctrl>"
  "snakebot_input_interface/Ctrl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Ctrl)))
  "Returns string type for a message object of type 'Ctrl"
  "snakebot_input_interface/Ctrl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Ctrl>)))
  "Returns md5sum for a message object of type '<Ctrl>"
  "3ee460f2bd60d02ac4ab00befc73f100")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Ctrl)))
  "Returns md5sum for a message object of type 'Ctrl"
  "3ee460f2bd60d02ac4ab00befc73f100")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Ctrl>)))
  "Returns full string definition for message of type '<Ctrl>"
  (cl:format cl:nil "#desired velocity~%float64 velocity~%#desired direction~%float64 direction~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Ctrl)))
  "Returns full string definition for message of type 'Ctrl"
  (cl:format cl:nil "#desired velocity~%float64 velocity~%#desired direction~%float64 direction~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Ctrl>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Ctrl>))
  "Converts a ROS message object to a list"
  (cl:list 'Ctrl
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':direction (direction msg))
))
