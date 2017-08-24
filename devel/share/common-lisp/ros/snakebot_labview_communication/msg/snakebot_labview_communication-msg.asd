
(cl:in-package :asdf)

(defsystem "snakebot_labview_communication-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Float64Array" :depends-on ("_package_Float64Array"))
    (:file "_package_Float64Array" :depends-on ("_package"))
    (:file "LinkPoses" :depends-on ("_package_LinkPoses"))
    (:file "_package_LinkPoses" :depends-on ("_package"))
    (:file "Collisions" :depends-on ("_package_Collisions"))
    (:file "_package_Collisions" :depends-on ("_package"))
    (:file "Int32Array" :depends-on ("_package_Int32Array"))
    (:file "_package_Int32Array" :depends-on ("_package"))
  ))