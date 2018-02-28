
(cl:in-package :asdf)

(defsystem "snakebot_visual_data_topic_collector-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "visual_data_topic_collector" :depends-on ("_package_visual_data_topic_collector"))
    (:file "_package_visual_data_topic_collector" :depends-on ("_package"))
  ))