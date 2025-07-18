=====
source-001-smoke-test
=====

source file.nu

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
source-002-semicolon
=====

source file.nu;

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
source-003-variable
=====

source $plugin

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier))))))

=====
source-004-string_var
=====

source 'file.nu'

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (string_content))))))

=====
source-005-pipe
=====

source ('file.nu')

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (expr_parenthesized
          (pipeline
            (pipe_element
              (val_string
                (string_content)))))))))

=====
source-006-interpolated
=====

source $"($plugin)"

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_interpolated
          (expr_interpolated
            (pipeline
              (pipe_element
                (val_variable
                  (identifier))))))))))

=====
source-env-001-smoke-test
=====

source-env FOO

----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))
