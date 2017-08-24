; Auto-generated. Do not edit!


(cl:in-package snakebot_position_control-msg)


;//! \htmlinclude PositionControlEffort.msg.html

(cl:defclass <PositionControlEffort> (roslisp-msg-protocol:ros-message)
  ((pubTime
    :reader pubTime
    :initarg :pubTime
    :type cl:real
    :initform 0)
   (arraySize
    :reader arraySize
    :initarg :arraySize
    :type cl:integer
    :initform 0)
   (effort
    :reader effort
    :initarg :effort
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass PositionControlEffort (<PositionControlEffort>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PositionControlEffort>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PositionControlEffort)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_position_control-msg:<PositionControlEffort> is deprecated: use snakebot_position_control-msg:PositionControlEffort instead.")))

(cl:ensure-generic-function 'pubTime-val :lambda-list '(m))
(cl:defmethod pubTime-val ((m <PositionControlEffort>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_position_control-msg:pubTime-val is deprecated.  Use snakebot_position_control-msg:pubTime instead.")
  (pubTime m))

(cl:ensure-generic-function 'arraySize-val :lambda-list '(m))
(cl:defmethod arraySize-val ((m <PositionControlEffort>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_position_control-msg:arraySize-val is deprecated.  Use snakebot_position_control-msg:arraySize instead.")
  (arraySize m))

(cl:ensure-generic-function 'effort-val :lambda-list '(m))
(cl:defmethod effort-val ((m <PositionControlEffort>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_position_control-msg:effort-val is deprecated.  Use snakebot_position_control-msg:effort instead.")
  (effort m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PositionControlEffort>) ostream)
  "Serializes a message object of type '<PositionControlEffort>"
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
  (cl:let* ((signed (cl:slot-value msg 'arraySize)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'effort))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'effort))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PositionControlEffort>) istream)
  "Deserializes a message object of type '<PositionControlEffort>"
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
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arraySize) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'effort) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'effort)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PositionControlEffort>)))
  "Returns string type for a message object of type '<PositionControlEffort>"
  "snakebot_position_control/PositionControlEffort")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PositionControlEffort)))
  "Returns string type for a message object of type 'PositionControlEffort"
  "snakebot_position_control/PositionControlEffort")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PositionControlEffort>)))
  "Returns md5sum for a message object of type '<PositionControlEffort>"
  "ca9559c8310a9ed8cb203d8a67e1f66e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PositionControlEffort)))
  "Returns md5sum for a message object of type 'PositionControlEffort"
  "ca9559c8310a9ed8cb203d8a67e1f66e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PositionControlEffort>)))
  "Returns full string definition for message of type '<PositionControlEffort>"
  (cl:format cl:nil "time pubTime~%int32 arraySize~%float64[] effort~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PositionControlEffort)))
  "Returns full string definition for message of type 'PositionControlEffort"
  (cl:format cl:nil "time pubTime~%int32 arraySize~%float64[] effort~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PositionControlEffort>))
  (cl:+ 0
     8
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'effort) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PositionControlEffort>))
  "Converts a ROS message object to a list"
  (cl:list 'PositionControlEffort
    (cl:cons ':pubTime (pubTime msg))
    (cl:cons ':arraySize (arraySize msg))
    (cl:cons ':effort (effort msg))
))
