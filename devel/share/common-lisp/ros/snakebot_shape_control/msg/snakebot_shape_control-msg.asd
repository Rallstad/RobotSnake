
(cl:in-package :asdf)

(defsystem "snakebot_shape_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "ShapeCurve" :depends-on ("_package_ShapeCurve"))
    (:file "_package_ShapeCurve" :depends-on ("_package"))
  ))