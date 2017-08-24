
(cl:in-package :asdf)

(defsystem "snakebot_position_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "PositionControlEffort" :depends-on ("_package_PositionControlEffort"))
    (:file "_package_PositionControlEffort" :depends-on ("_package"))
  ))