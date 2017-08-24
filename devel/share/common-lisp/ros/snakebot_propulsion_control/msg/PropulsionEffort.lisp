; Auto-generated. Do not edit!


(cl:in-package snakebot_propulsion_control-msg)


;//! \htmlinclude PropulsionEffort.msg.html

(cl:defclass <PropulsionEffort> (roslisp-msg-protocol:ros-message)
  ((pubTime
    :reader pubTime
    :initarg :pubTime
    :type cl:real
    :initform 0)
   (effort
    :reader effort
    :initarg :effort
    :type cl:float
    :initform 0.0)
   (jointNum
    :reader jointNum
    :initarg :jointNum
    :type cl:integer
    :initform 0))
)

(cl:defclass PropulsionEffort (<PropulsionEffort>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PropulsionEffort>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PropulsionEffort)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_propulsion_control-msg:<PropulsionEffort> is deprecated: use snakebot_propulsion_control-msg:PropulsionEffort instead.")))

(cl:ensure-generic-function 'pubTime-val :lambda-list '(m))
(cl:defmethod pubTime-val ((m <PropulsionEffort>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_propulsion_control-msg:pubTime-val is deprecated.  Use snakebot_propulsion_control-msg:pubTime instead.")
  (pubTime m))

(cl:ensure-generic-function 'effort-val :lambda-list '(m))
(cl:defmethod effort-val ((m <PropulsionEffort>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_propulsion_control-msg:effort-val is deprecated.  Use snakebot_propulsion_control-msg:effort instead.")
  (effort m))

(cl:ensure-generic-function 'jointNum-val :lambda-list '(m))
(cl:defmethod jointNum-val ((m <PropulsionEffort>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_propulsion_control-msg:jointNum-val is deprecated.  Use snakebot_propulsion_control-msg:jointNum instead.")
  (jointNum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PropulsionEffort>) ostream)
  "Serializes a message object of type '<PropulsionEffort>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'pubTime)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'pubTime) (cl:floor (cl:slot-value msg 'pubTime)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'effort))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'jointNum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PropulsionEffort>) istream)
  "Deserializes a message object of type '<PropulsionEffort>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pubTime) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'effort) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'jointNum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PropulsionEffort>)))
  "Returns string type for a message object of type '<PropulsionEffort>"
  "snakebot_propulsion_control/PropulsionEffort")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PropulsionEffort)))
  "Returns string type for a message object of type 'PropulsionEffort"
  "snakebot_propulsion_control/PropulsionEffort")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PropulsionEffort>)))
  "Returns md5sum for a message object of type '<PropulsionEffort>"
  "3445f8426e3fc7aaf9a644a7c0e2c955")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PropulsionEffort)))
  "Returns md5sum for a message object of type 'PropulsionEffort"
  "3445f8426e3fc7aaf9a644a7c0e2c955")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PropulsionEffort>)))
  "Returns full string definition for message of type '<PropulsionEffort>"
  (cl:format cl:nil "time pubTime~%~%float64 effort~%int32 jointNum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PropulsionEffort)))
  "Returns full string definition for message of type 'PropulsionEffort"
  (cl:format cl:nil "time pubTime~%~%float64 effort~%int32 jointNum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PropulsionEffort>))
  (cl:+ 0
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PropulsionEffort>))
  "Converts a ROS message object to a list"
  (cl:list 'PropulsionEffort
    (cl:cons ':pubTime (pubTime msg))
    (cl:cons ':effort (effort msg))
    (cl:cons ':jointNum (jointNum msg))
))
