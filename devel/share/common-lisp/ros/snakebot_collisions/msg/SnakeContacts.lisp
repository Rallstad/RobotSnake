; Auto-generated. Do not edit!


(cl:in-package snakebot_collisions-msg)


;//! \htmlinclude SnakeContacts.msg.html

(cl:defclass <SnakeContacts> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (link
    :reader link
    :initarg :link
    :type (cl:vector snakebot_collisions-msg:LinkContacts)
   :initform (cl:make-array 0 :element-type 'snakebot_collisions-msg:LinkContacts :initial-element (cl:make-instance 'snakebot_collisions-msg:LinkContacts))))
)

(cl:defclass SnakeContacts (<SnakeContacts>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SnakeContacts>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SnakeContacts)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_collisions-msg:<SnakeContacts> is deprecated: use snakebot_collisions-msg:SnakeContacts instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SnakeContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:header-val is deprecated.  Use snakebot_collisions-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'link-val :lambda-list '(m))
(cl:defmethod link-val ((m <SnakeContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:link-val is deprecated.  Use snakebot_collisions-msg:link instead.")
  (link m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SnakeContacts>) ostream)
  "Serializes a message object of type '<SnakeContacts>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'link))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'link))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SnakeContacts>) istream)
  "Deserializes a message object of type '<SnakeContacts>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'link) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'link)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'snakebot_collisions-msg:LinkContacts))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SnakeContacts>)))
  "Returns string type for a message object of type '<SnakeContacts>"
  "snakebot_collisions/SnakeContacts")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SnakeContacts)))
  "Returns string type for a message object of type 'SnakeContacts"
  "snakebot_collisions/SnakeContacts")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SnakeContacts>)))
  "Returns md5sum for a message object of type '<SnakeContacts>"
  "f85c5970fbed266205d8542dac34552d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SnakeContacts)))
  "Returns md5sum for a message object of type 'SnakeContacts"
  "f85c5970fbed266205d8542dac34552d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SnakeContacts>)))
  "Returns full string definition for message of type '<SnakeContacts>"
  (cl:format cl:nil "Header header~%~%snakebot_collisions/LinkContacts[] link~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: snakebot_collisions/LinkContacts~%Header header~%~%#link number~%int32 link~%~%#contact side (left or right)~%string[] contact_sides~%~%#normals~%geometry_msgs/Vector3[] contact_normals~%~%#tangents~%geometry_msgs/Vector3[] contact_tangents~%~%#forces~%geometry_msgs/Vector3[] contact_forces~%~%#positions~%geometry_msgs/Point[] contact_positions~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SnakeContacts)))
  "Returns full string definition for message of type 'SnakeContacts"
  (cl:format cl:nil "Header header~%~%snakebot_collisions/LinkContacts[] link~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: snakebot_collisions/LinkContacts~%Header header~%~%#link number~%int32 link~%~%#contact side (left or right)~%string[] contact_sides~%~%#normals~%geometry_msgs/Vector3[] contact_normals~%~%#tangents~%geometry_msgs/Vector3[] contact_tangents~%~%#forces~%geometry_msgs/Vector3[] contact_forces~%~%#positions~%geometry_msgs/Point[] contact_positions~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SnakeContacts>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'link) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SnakeContacts>))
  "Converts a ROS message object to a list"
  (cl:list 'SnakeContacts
    (cl:cons ':header (header msg))
    (cl:cons ':link (link msg))
))
