=====
binary-expr-001-smoke-test
=====

420 + 69

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (val_number)))))

====
binary-expr-002-preceedence
====

420 + 69 * 9001

----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (expr_binary
          (val_number)
          (val_number))))))

====
binary-expr-003-rhs-unquoted
====

'foo' == bar

----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_string)
        (val_string)))))

====
binary-expr-004-rhs-unquoted-with-expr
====

'foo' == bar('baz')

----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_string)
        (val_string
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_string)))))))))

====
binary-expr-005-multiline-fail-without-parenthesis
:error
====

1 +
2

----



====
binary-expr-006-multiline
====

(
 1
  +
 1
)

----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_binary
              (val_number)
              (val_number))))))))

====
binary-expr-007-multiline-nested
====

(
 1
  +
(1
+

1 +

  1
  + 1;
1);
 1
+

1
)

----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_binary
              (val_number)
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (expr_binary
                      (expr_binary
                        (expr_binary
                          (val_number)
                          (val_number))
                        (val_number))
                      (val_number))))
                (pipeline
                  (pipe_element
                    (val_number)))))))
        (pipeline
          (pipe_element
            (expr_binary
              (val_number)
              (val_number))))))))

====
binary-expr-008-multiline-precedence
====

(1
  + # lower
  1 * 5 # higher
+

  7)

----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_binary
              (expr_binary
                (val_number)
                (comment)
                (expr_binary
                  (val_number)
                  (val_number)
                  (comment)))
              (val_number))))))))

====
binary-expr-009-multiline-precedence-2
====

(1 == 1
and 1 == 1
and true
)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (expr_binary
              (expr_binary
                (expr_binary
                  (val_number)
                  (val_number))
                (expr_binary
                  (val_number)
                  (val_number)))
              (val_bool))))))))

====
binary-expr-010-range
====

1 in 1..=3

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_binary
        (val_number)
        (val_range
          (val_number)
          (val_number))))))
