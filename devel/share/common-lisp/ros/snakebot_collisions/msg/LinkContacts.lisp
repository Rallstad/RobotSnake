; Auto-generated. Do not edit!


(cl:in-package snakebot_collisions-msg)


;//! \htmlinclude LinkContacts.msg.html

(cl:defclass <LinkContacts> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (link
    :reader link
    :initarg :link
    :type cl:integer
    :initform 0)
   (contact_sides
    :reader contact_sides
    :initarg :contact_sides
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (contact_normals
    :reader contact_normals
    :initarg :contact_normals
    :type (cl:vector geometry_msgs-msg:Vector3)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Vector3 :initial-element (cl:make-instance 'geometry_msgs-msg:Vector3)))
   (contact_tangents
    :reader contact_tangents
    :initarg :contact_tangents
    :type (cl:vector geometry_msgs-msg:Vector3)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Vector3 :initial-element (cl:make-instance 'geometry_msgs-msg:Vector3)))
   (contact_forces
    :reader contact_forces
    :initarg :contact_forces
    :type (cl:vector geometry_msgs-msg:Vector3)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Vector3 :initial-element (cl:make-instance 'geometry_msgs-msg:Vector3)))
   (contact_positions
    :reader contact_positions
    :initarg :contact_positions
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point))))
)

(cl:defclass LinkContacts (<LinkContacts>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LinkContacts>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LinkContacts)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_collisions-msg:<LinkContacts> is deprecated: use snakebot_collisions-msg:LinkContacts instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:header-val is deprecated.  Use snakebot_collisions-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'link-val :lambda-list '(m))
(cl:defmethod link-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:link-val is deprecated.  Use snakebot_collisions-msg:link instead.")
  (link m))

(cl:ensure-generic-function 'contact_sides-val :lambda-list '(m))
(cl:defmethod contact_sides-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:contact_sides-val is deprecated.  Use snakebot_collisions-msg:contact_sides instead.")
  (contact_sides m))

(cl:ensure-generic-function 'contact_normals-val :lambda-list '(m))
(cl:defmethod contact_normals-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:contact_normals-val is deprecated.  Use snakebot_collisions-msg:contact_normals instead.")
  (contact_normals m))

(cl:ensure-generic-function 'contact_tangents-val :lambda-list '(m))
(cl:defmethod contact_tangents-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:contact_tangents-val is deprecated.  Use snakebot_collisions-msg:contact_tangents instead.")
  (contact_tangents m))

(cl:ensure-generic-function 'contact_forces-val :lambda-list '(m))
(cl:defmethod contact_forces-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:contact_forces-val is deprecated.  Use snakebot_collisions-msg:contact_forces instead.")
  (contact_forces m))

(cl:ensure-generic-function 'contact_positions-val :lambda-list '(m))
(cl:defmethod contact_positions-val ((m <LinkContacts>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_collisions-msg:contact_positions-val is deprecated.  Use snakebot_collisions-msg:contact_positions instead.")
  (contact_positions m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LinkContacts>) ostream)
  "Serializes a message object of type '<LinkContacts>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'link)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'contact_sides))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'contact_sides))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'contact_normals))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'contact_normals))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'contact_tangents))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'contact_tangents))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'contact_forces))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'contact_forces))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'contact_positions))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'contact_positions))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LinkContacts>) istream)
  "Deserializes a message object of type '<LinkContacts>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'link) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'contact_sides) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'contact_sides)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'contact_normals) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'contact_normals)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Vector3))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'contact_tangents) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'contact_tangents)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Vector3))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'contact_forces) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'contact_forces)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Vector3))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'contact_positions) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'contact_positions)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LinkContacts>)))
  "Returns string type for a message object of type '<LinkContacts>"
  "snakebot_collisions/LinkContacts")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LinkContacts)))
  "Returns string type for a message object of type 'LinkContacts"
  "snakebot_collisions/LinkContacts")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LinkContacts>)))
  "Returns md5sum for a message object of type '<LinkContacts>"
  "7fbb92d1b381927a81c6388ea406cd64")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LinkContacts)))
  "Returns md5sum for a message object of type 'LinkContacts"
  "7fbb92d1b381927a81c6388ea406cd64")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LinkContacts>)))
  "Returns full string definition for message of type '<LinkContacts>"
  (cl:format cl:nil "Header header~%~%#link number~%int32 link~%~%#contact side (left or right)~%string[] contact_sides~%~%#normals~%geometry_msgs/Vector3[] contact_normals~%~%#tangents~%geometry_msgs/Vector3[] contact_tangents~%~%#forces~%geometry_msgs/Vector3[] contact_forces~%~%#positions~%geometry_msgs/Point[] contact_positions~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LinkContacts)))
  "Returns full string definition for message of type 'LinkContacts"
  (cl:format cl:nil "Header header~%~%#link number~%int32 link~%~%#contact side (left or right)~%string[] contact_sides~%~%#normals~%geometry_msgs/Vector3[] contact_normals~%~%#tangents~%geometry_msgs/Vector3[] contact_tangents~%~%#forces~%geometry_msgs/Vector3[] contact_forces~%~%#positions~%geometry_msgs/Point[] contact_positions~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LinkContacts>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'contact_sides) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'contact_normals) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'contact_tangents) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'contact_forces) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'contact_positions) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LinkContacts>))
  "Converts a ROS message object to a list"
  (cl:list 'LinkContacts
    (cl:cons ':header (header msg))
    (cl:cons ':link (link msg))
    (cl:cons ':contact_sides (contact_sides msg))
    (cl:cons ':contact_normals (contact_normals msg))
    (cl:cons ':contact_tangents (contact_tangents msg))
    (cl:cons ':contact_forces (contact_forces msg))
    (cl:cons ':contact_positions (contact_positions msg))
))
