=====
do-001-smoke-test
=====

do {echo hello}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_do
        (block
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)))))))))

=====
do-002-flags
=====

do -c --env { thisisnotarealcommand } # flags before block
do -c { thisisnotarealcommand } --env # flags on both sides

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_do
        (short_flag
          (short_flag_identifier))
        (long_flag
          (long_flag_identifier))
        (block
          (pipeline
            (pipe_element
              (command
                (cmd_identifier))))))))
  (comment)
  (pipeline
    (pipe_element
      (ctrl_do
        (short_flag
          (short_flag_identifier))
        (block
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)))))
        (long_flag
          (long_flag_identifier)))))
  (comment))

=====
do-003-parameters
=====

do {|x,y| $x} 77 100 # 2 positional parameters
do {|x,y| $x} 77, -c unquoted # flags in-between

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_do
        (val_closure
          (parameter_pipes
            (parameter
              (identifier))
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (val_variable
                (identifier)))))
        (val_number)
        (val_number))))
  (comment)
  (pipeline
    (pipe_element
      (ctrl_do
        (val_closure
          (parameter_pipes
            (parameter
              (identifier))
            (parameter
              (identifier)))
          (pipeline
            (pipe_element
              (val_variable
                (identifier)))))
        (val_string)
        (short_flag
          (short_flag_identifier))
        (val_string))))
  (comment))

=====
do-004-parenthesized
=====

$'(do
{|x,y| $x} 77, # string
...2 # range

-c # flag

(1 + 1) foo('bar')
unquoted; # string
another_pipeline
)'

-----

(nu_script
  (pipeline
    (pipe_element
      (val_interpolated
        (expr_interpolated
          (pipeline
            (pipe_element
              (ctrl_do
                (val_closure
                  (parameter_pipes
                    (parameter
                      (identifier))
                    (parameter
                      (identifier)))
                  (pipeline
                    (pipe_element
                      (val_variable
                        (identifier)))))
                (val_string)
                (comment)
                (val_range
                  (val_number))
                (comment)
                (short_flag
                  (short_flag_identifier))
                (comment)
                (expr_parenthesized
                  (pipeline
                    (pipe_element
                      (expr_binary
                        (val_number)
                        (val_number)))))
                (val_string
                  (expr_parenthesized
                    (pipeline
                      (pipe_element
                        (val_string)))))
                (val_string))))
          (comment)
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)))))))))

=====
do-005-parenthesized-no-arguments
=====

(do {} #lkj
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (ctrl_do
              (block))))
        (comment)))))
