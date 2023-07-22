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


=====
let-004-with-type
=====

let x: string = 'tree-sitter'

-----

(nu_script
  (stmt_let
    (identifier)
    (param_type
      (flat_type))
    (pipeline
      (pipe_element
        (val_string)))))

=====
let-005-with-complex-type
=====

let x: record<name: string> = { name: 'tree-sitter' }

-----

(nu_script
  (stmt_let
    (identifier)
    (param_type
      (collection_type
        (identifier)
        (flat_type)))
    (pipeline
      (pipe_element
        (val_record
          (record_entry
            (identifier)
            (val_string)))))))
