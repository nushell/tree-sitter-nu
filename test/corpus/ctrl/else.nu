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
          head: (val_string))))))

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
          head: (expr_parenthesized
            (pipeline
              (pipe_element
                (val_string)))))))))

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

=====
else-007-parenthesized
=====

(
if

# comment
false
  # comment
  { 1 }

  else

  2
  # comment
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (ctrl_if
              (comment)
              (val_bool)
              (comment)
              (block
                (pipeline
                  (pipe_element
                    (val_number))))
              (val_number))))
        (comment)))))
