
(cl:in-package :asdf)

(defsystem "snakebot_matlab_communication-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "collisionList" :depends-on ("_package_collisionList"))
    (:file "_package_collisionList" :depends-on ("_package"))
    (:file "closestJoints" :depends-on ("_package_closestJoints"))
    (:file "_package_closestJoints" :depends-on ("_package"))
    (:file "pushpointsvisual" :depends-on ("_package_pushpointsvisual"))
    (:file "_package_pushpointsvisual" :depends-on ("_package"))
    (:file "collision" :depends-on ("_package_collision"))
    (:file "_package_collision" :depends-on ("_package"))
  ))