=====
else-001-block
=====

if true {} else {}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        condition: (val_bool)
        then_branch: (block)
        else_block: (block)))))

=====
else-002-command
=====

if true {} else ls

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        condition: (val_bool)
        then_branch: (block)
        else_block: (command
          head: (cmd_identifier))))))

=====
else-003-command
=====

if true {} else ^ls

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        condition: (val_bool)
        then_branch: (block)
        else_block: (command
          head: (cmd_identifier))))))

=====
else-004-command
=====

if true {} else ^'ls'

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        condition: (val_bool)
        then_branch: (block)
        else_block: (command
          head: (cmd_identifier))))))

=====
else-005-command
=====

if true {} else ^('ls')

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        condition: (val_bool)
        then_branch: (block)
        else_block: (command
          head: (cmd_identifier))))))

=====
else-006-expression
=====

if true {} else $expression

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        condition: (val_bool)
        then_branch: (block)
        else_block: (val_variable
          name: (identifier))))))
