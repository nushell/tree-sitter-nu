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
      (row_condition_command
        (row_condition
          (path)
          (val_filesize
            (val_number)
            (filesize_unit)))))))

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
            (val_string
              (string_content)))
          (val_entry
            (val_string
              (string_content))))))
    (pipe_element
      (row_condition_command
        (row_condition
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_variable
                  (identifier)))
              (pipe_element
                (command
                  (cmd_identifier)
                  (val_string)
                  (val_string
                    (string_content)))))))))))

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
      (row_condition_command
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
      (row_condition_command
        (row_condition
          (row_condition
            (path)
            (val_filesize
              (val_number)
              (filesize_unit)))
          (row_condition
            (path)
            (val_filesize
              (val_number)
              (filesize_unit))))))))

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
            (row_condition_command
              (row_condition
                (row_condition
                  (path)
                  (val_filesize
                    (val_number)
                    (filesize_unit)))
                (comment)
                (comment)
                (row_condition
                  (path)
                  (val_filesize
                    (val_number)
                    (filesize_unit)))
                (comment)
                (row_condition
                  (path)
                  (val_string
                    (string_content)))))))))))

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
      (row_condition_command
        (row_condition
          (row_condition
            (expr_parenthesized
              (pipeline
                (pipe_element
                  (command
                    (cmd_identifier)
                    (val_string)
                    (val_filesize
                      (val_number)
                      (filesize_unit)))))))
          (row_condition
            (val_bool)))))))

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
      (row_condition_command
        (row_condition
          (val_bool)))))
  (pipeline
    (pipe_element
      (row_condition_command
        (row_condition
          (expr_unary
            (expr_parenthesized
              (pipeline
                (pipe_element
                  (val_variable)))))))))
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (row_condition_command
              (row_condition
                (row_condition
                  (val_bool))
                (row_condition
                  (path)
                  (val_string))))))))))

=====
where-008-operators
=====

ls | where name has "e"
ls | where name not-has "e"
$foo | where foo-bar?! == 'baz'
$foo | where 'foo-bar'?.'baz' == 'quz'

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        head: (cmd_identifier)))
    (pipe_element
      (row_condition_command
        predicate: (row_condition
          lhs: (path)
          rhs: (val_string
            (string_content))))))
  (pipeline
    (pipe_element
      (command
        head: (cmd_identifier)))
    (pipe_element
      (row_condition_command
        predicate: (row_condition
          lhs: (path)
          rhs: (val_string
            (string_content))))))
  (pipeline
    (pipe_element
      (val_variable
        name: (identifier)))
    (pipe_element
      (row_condition_command
        predicate: (row_condition
          lhs: (path)
          rhs: (val_string
            (string_content))))))
  (pipeline
    (pipe_element
      (val_variable
        name: (identifier)))
    (pipe_element
      (row_condition_command
        predicate: (row_condition
          lhs: (path
            (val_string
              (string_content)))
          lhs: (path
            (val_string
              (string_content)))
          rhs: (val_string
            (string_content)))))))

=====
where-009-variable
=====

ls | where $foo.bar and $foo.baz

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        head: (cmd_identifier)))
    (pipe_element
      (row_condition_command
        predicate: (row_condition
          lhs: (row_condition
            (val_variable
              name: (identifier)
              (cell_path
                (path))))
          rhs: (row_condition
            (val_variable
              name: (identifier)
              (cell_path
                (path)))))))))

=====
row-condition-commands-001
=====

any name =~ foo
all name =~ foo
take until name =~ foo
skip while name =~ foo
chunk-by name =~ foo

-----

(nu_script
  (pipeline
    (pipe_element
      (row_condition_command
        (row_condition
          (path)
          (val_string)))))
  (pipeline
    (pipe_element
      (row_condition_command
        (row_condition
          (path)
          (val_string)))))
  (pipeline
    (pipe_element
      (row_condition_command
        (row_condition
          (path)
          (val_string)))))
  (pipeline
    (pipe_element
      (row_condition_command
        (row_condition
          (path)
          (val_string)))))
  (pipeline
    (pipe_element
      (row_condition_command
        (row_condition
          (path)
          (val_string))))))

=====
row-condition-commands-002
=====

any-foo
all-foo
take-until-foo
skip-while-foo
chunk-by-foo

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))
