
(cl:in-package :asdf)

(defsystem "snakebot_propulsion_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "PropulsionEffort" :depends-on ("_package_PropulsionEffort"))
    (:file "_package_PropulsionEffort" :depends-on ("_package"))
    (:file "PropulsionEffortMamba" :depends-on ("_package_PropulsionEffortMamba"))
    (:file "_package_PropulsionEffortMamba" :depends-on ("_package"))
  ))