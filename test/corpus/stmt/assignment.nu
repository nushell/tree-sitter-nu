=====
assignment-001-smoke-test
=====

$var = 42

-----

(nu_script
  (pipeline
    (pipe_element
      (assignment
        (val_variable
          (identifier))
        (pipeline
          (pipe_element
            (val_number)))))))

=====
assignment-002-semicolon
=====

$var += 69;

-----

(nu_script
  (pipeline
    (pipe_element
      (assignment
        (val_variable
          (identifier))
        (pipeline
          (pipe_element
            (val_number)))))))

=====
assignment-003-assignment-to-a-pipeline
=====

$x += 1 | $in + 10
$x ++= [1 2 3]
| each {|x|
  $x + 8
}
($a /= 1) | default 0

-----

(nu_script
  (pipeline
    (pipe_element
      (assignment
        (val_variable
          (identifier))
        (pipeline
          (pipe_element
            (val_number))
          (pipe_element
            (expr_binary
              (val_variable)
              (val_number)))))))
  (pipeline
    (pipe_element
      (assignment
        (val_variable
          (identifier))
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
                (parameter_pipes
                  (parameter
                    (identifier)))
                (pipeline
                  (pipe_element
                    (expr_binary
                      (val_variable
                        (identifier))
                      (val_number)))))))))))
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (assignment
              (val_variable
                (identifier))
              (pipeline
                (pipe_element
                  (val_number))))))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_number)))))

=====
assignment-004-assignment-after-pipe
=====

"foo" | $bar ++= $in

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (string_content)))
    (pipe_element
      (assignment
        (val_variable
          (identifier))
        (pipeline
          (pipe_element
            (val_variable)))))))
