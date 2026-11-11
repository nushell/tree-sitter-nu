=====
unary-expr-001-not
=====

not true and not false

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (expr_unary
          (val_bool))
        (expr_unary
          (val_bool))))))

=====
unary-expr-002-minus
=====

-(4 + 8) == -12

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (expr_unary
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (val_number)))))

=====
unary-expr-003-not-vs-unquoted
=====

1 == nothing

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (val_string)))))

=====
unary-expr-004-not-precedence
=====

not $a == $b
not $a > 0 and $b < 1
not 1 in [1 2]

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_unary
        (expr_binary
          (val_variable
            (identifier))
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (expr_binary
        (expr_unary
          (expr_binary
            (val_variable
              (identifier))
            (val_number)))
        (expr_binary
          (val_variable
            (identifier))
          (val_number)))))
  (pipeline
    (pipe_element
      (expr_unary
        (expr_binary
          (val_number)
          (val_list
            (list_body
              (val_entry
                (val_number))
              (val_entry
                (val_number)))))))))

=====
unary-expr-005-minus-variable
=====

-$x
-$r.a
1 + -$x
-$x * 2

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_unary
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (expr_unary
        (val_variable
          (identifier)
          (cell_path
            (path))))))
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (expr_unary
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (expr_binary
        (expr_unary
          (val_variable
            (identifier)))
        (val_number)))))

=====
unary-expr-006-not-parenthesized-multiline
=====

(not $a ==
  $b)
(not $a
  and $b)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_unary
              (expr_binary
                (val_variable
                  (identifier))
                (val_variable
                  (identifier)))))))))
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_binary
              (expr_unary
                (val_variable
                  (identifier)))
              (val_variable
                (identifier)))))))))
