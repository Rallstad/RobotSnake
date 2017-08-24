; Auto-generated. Do not edit!


(cl:in-package snakebot_shape_control-msg)


;//! \htmlinclude ShapeCurve.msg.html

(cl:defclass <ShapeCurve> (roslisp-msg-protocol:ros-message)
  ((shapeCurve
    :reader shapeCurve
    :initarg :shapeCurve
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point))))
)

(cl:defclass ShapeCurve (<ShapeCurve>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ShapeCurve>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ShapeCurve)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snakebot_shape_control-msg:<ShapeCurve> is deprecated: use snakebot_shape_control-msg:ShapeCurve instead.")))

(cl:ensure-generic-function 'shapeCurve-val :lambda-list '(m))
(cl:defmethod shapeCurve-val ((m <ShapeCurve>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snakebot_shape_control-msg:shapeCurve-val is deprecated.  Use snakebot_shape_control-msg:shapeCurve instead.")
  (shapeCurve m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ShapeCurve>) ostream)
  "Serializes a message object of type '<ShapeCurve>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'shapeCurve))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'shapeCurve))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ShapeCurve>) istream)
  "Deserializes a message object of type '<ShapeCurve>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'shapeCurve) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'shapeCurve)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ShapeCurve>)))
  "Returns string type for a message object of type '<ShapeCurve>"
  "snakebot_shape_control/ShapeCurve")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ShapeCurve)))
  "Returns string type for a message object of type 'ShapeCurve"
  "snakebot_shape_control/ShapeCurve")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ShapeCurve>)))
  "Returns md5sum for a message object of type '<ShapeCurve>"
  "43c13542a7907ce8fee400a3e84d9eef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ShapeCurve)))
  "Returns md5sum for a message object of type 'ShapeCurve"
  "43c13542a7907ce8fee400a3e84d9eef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ShapeCurve>)))
  "Returns full string definition for message of type '<ShapeCurve>"
  (cl:format cl:nil "geometry_msgs/Point[] shapeCurve	#Curve defining desired shape of robot~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ShapeCurve)))
  "Returns full string definition for message of type 'ShapeCurve"
  (cl:format cl:nil "geometry_msgs/Point[] shapeCurve	#Curve defining desired shape of robot~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ShapeCurve>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'shapeCurve) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ShapeCurve>))
  "Converts a ROS message object to a list"
  (cl:list 'ShapeCurve
    (cl:cons ':shapeCurve (shapeCurve msg))
))
