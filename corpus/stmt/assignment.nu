=====
assignment-001-smoke-test
=====

$var = 42

-----

(nu_script
  (assignment
    (val_variable
      (identifier))
    (pipeline
      (pipe_element
        (val_number)))))

=====
assignment-002-semicolon
=====

$var += 69;

-----

(nu_script
  (assignment
    (val_variable
      (identifier))
    (pipeline
      (pipe_element
        (val_number)))))

=====
assignment-003-assignment-to-a-pipeline
=====

$x ++= [1 2 3] | each {|x| $x + 8}

-----

(nu_script
  (assignment
    (val_variable
      (identifier))
    (pipeline
      (pipe_element
        (val_list
          (val_number)
          (val_number)
          (val_number)))
      (pipe_element
        (command
          (cmd_identifier)
          (val_closure
            (parameter_pipes
              (parameter
                (identifier)))
            (ERROR
              (expr_binary
                (val_variable
                  (identifier))
                (val_number)))))))))
