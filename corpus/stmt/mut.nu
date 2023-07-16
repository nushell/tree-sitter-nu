=====
mut-001-smoke-test
=====

mut x = 42

----

(nu_script
  (stmt_mut
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
mut-002-semicolon
=====

mut x = 42;

-----

(nu_script
  (stmt_mut
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
mut-003-assignment-to-a-pipeline
=====

mut x = 42 | math sin


-----

(nu_script
  (stmt_mut
    (identifier)
    (pipeline
      (pipe_element
        (val_number))
      (pipe_element
        (command
          (cmd_identifier)
          (val_string))))))
