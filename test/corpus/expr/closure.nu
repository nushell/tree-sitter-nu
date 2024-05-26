=====
closure-001-basic
=====

[1, 2] | each {|x| $x + 1 }

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (parameter_pipes
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (expr_binary
                (val_variable
                  (identifier))
                (val_number)))))))))

=====
closure-002-closure-without-parameter
=====

[1, 2, 3] | each {|| $in + 2 }

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (parameter_pipes)
          (pipeline
            (pipe_element
              (expr_binary
                (val_variable)
                (val_number)))))))))

=====
closure-003-closure-without-parameter-pipes
=====

[1, 2] | each {
  $in * 2
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (pipeline
            (pipe_element
              (expr_binary
                (val_variable)
                (val_number)))))))))

=====
closure-004-cmd-args
=====

custom-cmd {|| 'hello' } { 'world' }

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (parameter_pipes)
          (pipeline
            (pipe_element
              (val_string))))
        (val_closure
          (pipeline
            (pipe_element
              (val_string))))))))

=====
closure-005-let
=====

let cl = {
  'closure'
}

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_closure
          (pipeline
            (pipe_element
              (val_string))))))))

=====
closure-006-let-parameter-pipes
=====

let cl = {|x|
  $x * 3
}

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_closure
          (parameter_pipes
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (expr_binary
                (val_variable
                  (identifier))
                (val_number)))))))))

=====
closure-007-record-value
=====

{
  closure: {|x| $x * 2}
  closure2: { 'closure' }
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_closure
              (parameter_pipes
                (parameter
                  (identifier)))
              (pipeline
                (pipe_element
                  (expr_binary
                    (val_variable
                      (identifier))
                    (val_number))))))
          (record_entry
            (identifier)
            (val_closure
              (pipeline
                (pipe_element
                  (val_string))))))))))
