=====
subexpr-001-command
=====

(echo hello)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)
              (val_string))))))))

=====
subexpr-002-multiline-command
=====

(
  echo
  one
  two
  thre
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)
              (val_string)
              (val_string)
              (val_string))))))))

=====
subexpr-003-pipeline
=====

(ls | where size > 10kb)

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
                (val_number)))))))))

=====
subexpr-004-pipeline-multiline
=====

(
  echo
  one
  two
  thre | str replace t T
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)
              (val_string)
              (val_string)
              (val_string)))
          (pipe_element
            (command
              (cmd_identifier)
              (val_string)
              (val_string)
              (val_string))))))))


=====
subexpr-005-assignment
=====

let xs = (echo one two)

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (expr_parenthesized
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)
                (val_string)))))))))
=====
subexpr-006-multiline-assignment
=====

let xs = (echo
one two)

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (expr_parenthesized
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)
                (val_string)))))))))

=====
subexpr-007-path
=====

(ls).name

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (cmd_identifier))))
        (cell_path
          (path))))))

=====
subexpr-008-contains-statement
=====

(let a = "hello";
echo $a)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (stmt_let
          (identifier)
          (pipeline
            (pipe_element
              (val_string))))
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)
              (val_variable
                (identifier)))))))))

=====
subexpr-009-closure
=====

([1, 2, 3] | each
{|x|
  let y = 2
  $x * $y
})

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
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
                (stmt_let
                  (identifier)
                  (pipeline
                    (pipe_element
                      (val_number))))
                (pipeline
                  (pipe_element
                    (expr_binary
                      (val_variable
                        (identifier))
                      (val_variable
                        (identifier)))))))))))))

=====
subexpr-010-newline-before-else
=====

(
if $cond { echo 'foo' }
else { echo 'bar' }
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (ctrl_if
              (val_variable
                (identifier))
              (block
                (pipeline
                  (pipe_element
                    (command
                      (cmd_identifier)
                      (val_string)))))
              (block
                (pipeline
                  (pipe_element
                    (command
                      (cmd_identifier)
                      (val_string))))))))))))

=====
subexpr-011-newline-before-else-if
=====

(
if $cond { echo 'foo' }
else if $cond2 { echo 'bar' }
else { echo 'foo bar' }
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (ctrl_if
              (val_variable
                (identifier))
              (block
                (pipeline
                  (pipe_element
                    (command
                      (cmd_identifier)
                      (val_string)))))
              (ctrl_if
                (val_variable
                  (identifier))
                (block
                  (pipeline
                    (pipe_element
                      (command
                        (cmd_identifier)
                        (val_string)))))
                (block
                  (pipeline
                    (pipe_element
                      (command
                        (cmd_identifier)
                        (val_string)))))))))))))

=====
subexpr-012-newline-before-catch
=====

(
try { echo 'foo' }
catch { echo 'bar' }
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (ctrl_try
              (block
                (pipeline
                  (pipe_element
                    (command
                      (cmd_identifier)
                      (val_string)))))
              (block
                (pipeline
                  (pipe_element
                    (command
                      (cmd_identifier)
                      (val_string))))))))))))
