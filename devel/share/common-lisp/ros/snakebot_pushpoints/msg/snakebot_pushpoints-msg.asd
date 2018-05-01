
(cl:in-package :asdf)

(defsystem "snakebot_pushpoints-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "pushpointCandidates" :depends-on ("_package_pushpointCandidates"))
    (:file "_package_pushpointCandidates" :depends-on ("_package"))
    (:file "Pushpoints" :depends-on ("_package_Pushpoints"))
    (:file "_package_Pushpoints" :depends-on ("_package"))
  ))