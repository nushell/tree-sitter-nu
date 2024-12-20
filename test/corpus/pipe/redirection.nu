=====
redir-001-command-redirection
=====

echo this o> /dev/null
echo this e>> $foo
echo this e+o>> ./foo
echo this err+out> 32

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (redirection
          (val_string)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (redirection
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (redirection
          (val_string)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (redirection
          (val_string))))))

=====
redir-002-expression-redirection
=====

1 + 1 + 1 o> /dev/null
(
true == not false
  o+e>> ./foo
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (expr_binary
          (val_number)
          (val_number))
        (val_number))
      (redirection
        (val_string))))
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_binary
              (val_bool)
              (expr_unary
                (val_bool)))
            (redirection
              (val_string))))))))

=====
redir-003-pipe-redirection
=====

echo foo e>| $in

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (val_variable))))
