=====
cmd-001-head
=====

cmd

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))

======
cmd-002-head-sub
======

cmd sub

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
cmd-003-external-cmd
=====

^cmd 42

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_number)))))

=====
cmd-004-command-in-different-line
=====

print this
print this
print this
if $a == true {
    print this
    print this
}

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (ctrl_if
    (expr_binary
      (val_variable
        (identifier))
      (val_bool))
    (block
      (pipeline
        (pipe_element
          (command
            (cmd_identifier)
            (val_string))))
      (pipeline
        (pipe_element
          (command
            (cmd_identifier)
            (val_string)))))))

=====
cmd-005-command-with-semicolon
=====

print $a; print $b; echo $c | print $in

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable)))))

=====
cmd-006-so-many-arguments
=====

foo this is only for testing

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))
