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
