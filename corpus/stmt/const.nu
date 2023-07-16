=====
const-001-smoke-test
=====

const x = 42

----

(nu_script
  (stmt_const
    (identifier)
    (val_number)))

=====
const-002-semicolon
=====

const x = 42;

-----

(nu_script
  (stmt_const
    (identifier)
    (val_number)))

=====
const-003-assignment-to-a-pipeline
=====

const x = 42 | math sin


-----

(nu_script
  (stmt_const
    (identifier)
    (val_number))
  (ERROR
    (identifier)))
