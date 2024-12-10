=====
const-001-smoke-test
=====

const x = 42

----

(nu_script
  (stmt_const
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
const-002-semicolon
=====

const x = 42;

-----

(nu_script
  (stmt_const
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
const-003-assignment-to-a-pipeline
=====

const x = 42 | math sin


-----

(nu_script
  (stmt_const
    (identifier)
    (pipeline
      (pipe_element
        (val_number))
      (pipe_element
        (command
          (cmd_identifier))))))

=====
const-004-exported
=====

export const x = 42

----

(nu_script
  (stmt_const
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
const-005-exported-multiple
=====

export const GAMMA = 0.5772156649015329
export const E = 2.718281828459045

----

(nu_script
  (stmt_const
    (identifier)
    (pipeline
      (pipe_element
        (val_number))))
  (stmt_const
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))
