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

=====
where-004-binary-predicate
=====

ls | where size > 10kb and size < 100kb

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
          (filesize_unit))
        (val_string)
        (val_filesize
          (val_number)
          (filesize_unit))))))

=====
where-005-parenthesized-binary-predicate
=====

(ls |
where
  size > 10kb # comment
  and # comment
  size < 100kb # comment
  or
  name == 'foo'
  )

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)))
          (pipe_element
            (where_command
              (val_string)
              (val_filesize
                (val_number)
                (filesize_unit))
              (comment)
              (comment)
              (val_string)
              (val_filesize
                (val_number)
                (filesize_unit))
              (comment)
              (val_string)
              (val_string))))))))

=====
where-006-binary-predicate-with-expression
=====

ls | where (size > 10kb) and true

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))
    (pipe_element
      (where_command
        (expr_parenthesized
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)
                (val_filesize
                  (val_number)
                  (filesize_unit))))))
        (val_bool)))))

=====
where-007-unary
=====

where false
where not ($in)
(
where
false
and
name !~ foo
)

-----

(nu_script
  (pipeline
    (pipe_element
      (where_command
        (val_bool))))
  (pipeline
    (pipe_element
      (where_command
        (expr_unary
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_variable))))))))
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (where_command
              (val_bool)
              (val_string)
              (val_string))))))))
