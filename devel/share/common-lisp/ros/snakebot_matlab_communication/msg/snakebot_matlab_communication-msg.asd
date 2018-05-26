
(cl:in-package :asdf)

(defsystem "snakebot_matlab_communication-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "collisionList" :depends-on ("_package_collisionList"))
    (:file "_package_collisionList" :depends-on ("_package"))
    (:file "closestJoints" :depends-on ("_package_closestJoints"))
    (:file "_package_closestJoints" :depends-on ("_package"))
    (:file "pushPoints" :depends-on ("_package_pushPoints"))
    (:file "_package_pushPoints" :depends-on ("_package"))
    (:file "pushpointCandidates" :depends-on ("_package_pushpointCandidates"))
    (:file "_package_pushpointCandidates" :depends-on ("_package"))
    (:file "collision" :depends-on ("_package_collision"))
    (:file "_package_collision" :depends-on ("_package"))
  ))