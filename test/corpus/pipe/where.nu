=====
where-001-basic
=====

ls | where size > 10kb

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))
    (pipe_element
      (where_command
        (val_string)
        (val_filesize
          (val_number)
          (filesize_unit))))))

=====
where-002-parenthesized
=====

['foo', 'bar'] | where ($it | str starts-with 'bar')

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))
    (pipe_element
      (where_command
        (expr_parenthesized
          (pipeline
            (pipe_element
              (val_variable
                (identifier)))
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)
                (val_string)))))))))

=====
where-003-closure
=====

ls | where {|x| $x.size > 10kb }

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))
    (pipe_element
      (where_command
        (val_closure
          (parameter_pipes
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (expr_binary
                (val_variable
                  (identifier)
                  (cell_path
                    (path)))
                (val_filesize
                  (val_number)
                  (filesize_unit))))))))))
