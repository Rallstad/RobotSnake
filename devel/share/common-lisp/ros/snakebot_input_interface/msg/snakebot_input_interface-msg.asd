
(cl:in-package :asdf)

(defsystem "snakebot_input_interface-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Ctrl" :depends-on ("_package_Ctrl"))
    (:file "_package_Ctrl" :depends-on ("_package"))
  ))