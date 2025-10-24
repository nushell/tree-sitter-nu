====
env-001-smoke-test
====

FOO=BAR $env.FOO
FOO=BAR $env.FOO == $env.FOO
FOO=BAR foo

-----

(nu_script
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_string))
      (val_variable
        (cell_path
          (path)))))
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_string))
      (expr_binary
        lhs: (val_variable
          (cell_path
            (path)))
        rhs: (val_variable
          (cell_path
            (path))))))
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_string))
      (command
        head: (cmd_identifier)))))

====
env-002-repeat
====

FOO=BAR BAR=FOO foo

-----

(nu_script
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_string))
      (env_var
        variable: (identifier)
        value: (val_string))
      (command
        head: (cmd_identifier)))))

====
env-003-parenthesized
====

(FOO=BAR BAR=FOO foo)
(
  FOO=BAR
# comment
BAR=FOO

$env.FOO
  == # comment
  $env.FOO
  )

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (env_var
              variable: (identifier)
              value: (val_string))
            (env_var
              variable: (identifier)
              value: (val_string))
            (command
              head: (cmd_identifier)))))))
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (env_var
              variable: (identifier)
              value: (val_string))
            (comment)
            (env_var
              variable: (identifier)
              value: (val_string))
            (expr_binary
              lhs: (val_variable
                (cell_path
                  (path)))
              (comment)
              rhs: (val_variable
                (cell_path
                  (path))))))))))

====
env-004-special-characters
====

_SHELL_=🤖 hello=42 hello=你好 foo

-----

(nu_script
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_string))
      (env_var
        variable: (identifier)
        value: (val_string))
      (env_var
        variable: (identifier)
        value: (val_string))
      (command
        head: (cmd_identifier)))))

====
env-005-string
====

FOO='bar' baz
FOO=$"bar(baz)" qux

-----

(nu_script
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_string
          (string_content)))
      (command
        head: (cmd_identifier))))
  (pipeline
    (pipe_element
      (env_var
        variable: (identifier)
        value: (val_interpolated
          (escaped_interpolated_content)
          expr: (expr_interpolated
            (pipeline
              (pipe_element
                (command
                  head: (cmd_identifier)))))))
      (command
        head: (cmd_identifier)))))
