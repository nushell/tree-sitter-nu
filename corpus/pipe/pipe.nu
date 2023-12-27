=====
pipe-001-normal-pipe
=====

echo this | str split "i"

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)))))

=====
pipe-002-across-the-line
=====

echo this
| split row "i"
| str join

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
pipe-003-crossing-too-much-lines
=====

echo this
| split row "i"
|
|
|
| str join
| print $in

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable)))))

=====
pipe-004-end-of-line
=====

echo this
| split row "i" |
  str join

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
pipe-005-unquoted-1-character
=====

'nushell' | str contains n

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)))))

=====
pipe-006-terminated-by-newline
=====

ls | each {|x| echo $x}
let x = 42

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (parameter_pipes
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_variable
                  (identifier)))))))))
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))
