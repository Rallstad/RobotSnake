
(cl:in-package :asdf)

(defsystem "snakebot_collisions-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "LinkContacts" :depends-on ("_package_LinkContacts"))
    (:file "_package_LinkContacts" :depends-on ("_package"))
    (:file "SnakeContacts" :depends-on ("_package_SnakeContacts"))
    (:file "_package_SnakeContacts" :depends-on ("_package"))
  ))