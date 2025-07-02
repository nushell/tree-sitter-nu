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
        (val_string
          (string_content))))))

=====
let-005-with-complex-type
=====

let x: record<foo-bar: string> = { foo-bar: 'tree-sitter' }
let y: oneof<int, list<record>> = 1

-----

(nu_script
  (stmt_let
    var_name: (identifier)
    type: (param_type
      type: (collection_type
        key: (identifier)
        type: (flat_type)))
    value: (pipeline
      (pipe_element
        (val_record
          (record_body
            entry: (record_entry
              key: (identifier)
              value: (val_string
                (string_content))))))))
  (stmt_let
    var_name: (identifier)
    type: (param_type
      type: (composite_type
        type: (flat_type)
        type: (list_type
          type: (flat_type))))
    value: (pipeline
      (pipe_element
        (val_number)))))
