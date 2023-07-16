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
