
(cl:in-package :asdf)

(defsystem "snakebot_robot_pose-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "Pose" :depends-on ("_package_Pose"))
    (:file "_package_Pose" :depends-on ("_package"))
    (:file "SnakePose" :depends-on ("_package_SnakePose"))
    (:file "_package_SnakePose" :depends-on ("_package"))
    (:file "ObstaclePose" :depends-on ("_package_ObstaclePose"))
    (:file "_package_ObstaclePose" :depends-on ("_package"))
  ))