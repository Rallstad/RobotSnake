
(cl:in-package :asdf)

(defsystem "snakebot_kinematics-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "kinematics" :depends-on ("_package_kinematics"))
    (:file "_package_kinematics" :depends-on ("_package"))
  ))