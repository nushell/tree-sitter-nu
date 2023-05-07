=====
cmd-001-head
=====

cmd

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_head
          (cmd_identifier))))))

======
cmd-002-head-sub
======

cmd sub

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_head_sub
          (cmd_identifier)
          (cmd_identifier))))))

=====
cmd-003-external-cmd
=====

^cmd 42

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_head
          (cmd_identifier)
          (val_number))))))
