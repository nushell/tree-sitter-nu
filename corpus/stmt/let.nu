=====
let-001-smoke-test
=====

let x = 42

----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
let-002-semicolon
=====

let x = 42;

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
let-003-assignment-to-a-pipeline
=====

let x = 42 | math sin


-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number))
      (pipe_element
        (command
          (cmd_identifier)
          (val_string))))))
