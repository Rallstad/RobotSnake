
(cl:in-package :asdf)

(defsystem "snakebot_visual_data_topic_collector-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "obstacles" :depends-on ("_package_obstacles"))
    (:file "_package_obstacles" :depends-on ("_package"))
    (:file "jointposes" :depends-on ("_package_jointposes"))
    (:file "_package_jointposes" :depends-on ("_package"))
  ))