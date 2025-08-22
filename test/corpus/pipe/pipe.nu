=====
pipe-001-normal-pipe
=====

echo this | str split "i"

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string
          (string_content))))))

=====
pipe-002-across-the-line
=====

echo this
| split row "i"
| str join

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string
          (string_content))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
pipe-003-crossing-too-much-lines
=====

echo this
| split row "i"
|
|
|
| str join
| print $in

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string
          (string_content))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable)))))

=====
pipe-004-end-of-line
=====

echo this
| split row "i" |
  str join

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string
          (string_content))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
pipe-005-unquoted-1-character
=====

'nushell' | str contains n

-----

(nu_script
  (pipeline
    (pipe_element
      (val_string
        (string_content)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)))))

=====
pipe-006-terminated-by-newline
=====

ls | each {|x| echo $x}
let x = 42

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (parameter_pipes
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_variable
                  (identifier)))))))))
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

=====
pipe-007-next-line-after-match
=====

match $x {
  1 => [1]
  _ => [2 3 4]
}
  | each {|x| $x * 2}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_number))
          (val_list
            (list_body
              (val_entry
                (val_number)))))
        (default_arm
          (val_list
            (list_body
              (val_entry
                (val_number))
              (val_entry
                (val_number))
              (val_entry
                (val_number)))))))
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
pipe-008-next-line-after-if
=====

if $cond {
  [1]
} else {
  [2, 3]
}
  | each {|x| $x * 2}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        (val_variable
          (identifier))
        (block
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number)))))))
        (block
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number))
                  (val_entry
                    (val_number)))))))))
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
pipe-009-next-line-after-do
=====

do { [1] }
  | each {|x| $x * 2}

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number)))))))))
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
pipe-010-next-line-after-try
=====

try {
  [1]
}
  | each {|x| $x * 2}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_try
        (block
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number)))))))))
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
pipe-011-next-line-after-catch
=====

try {
  [1]
} catch {
  [2 3]
}
  | each {|x| $x * 2}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_try
        (block
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number)))))))
        (block
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number))
                  (val_entry
                    (val_number)))))))))
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
pipe-012-next-line-after-value
=====

[1 2]
  | length

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
        (cmd_identifier)))))

=====
pipe-013-next-line-after-variable
=====

$xs
  | first

-----

(nu_script
  (pipeline
    (pipe_element
      (val_variable
        (identifier)))
    (pipe_element
      (command
        (cmd_identifier)))))

=====
pipe-014-same-line-with-variable
=====

$xs | first

-----

(nu_script
  (pipeline
    (pipe_element
      (val_variable
        (identifier)))
    (pipe_element
      (command
        (cmd_identifier)))))

=====
pipe-015-end-of-line
=====

do { [1] } |
  each {|x| $x * 2}

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (pipeline
            (pipe_element
              (val_list
                (list_body
                  (val_entry
                    (val_number)))))))))
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
