=====
values-001-numbers
=====

[69 6.9 0b1000101 0o105 6.9e1 6.9E+1 0x45 -69 +69]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (val_number)
        (val_number)
        (val_number)
        (val_number)
        (val_number)
        (val_number)
        (val_number)
        (val_number)
        (val_number)))))

=====
values-002-booleans
=====


[true false (not true)]

------

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (val_bool)
        (val_bool)
        (expr_parenthesized
          (pipe_element
            (expr_unary
              (val_bool))))))))

=====
values-003-nothing
=====

null

-----

(nu_script
  (pipeline
    (pipe_element
      (val_nothing))))

=====
values-004-binary
=====

0x[1 2 3 4 5] | 0b[100, 100, 100]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_binary
        (hex_digit)
        (hex_digit)
        (hex_digit)
        (hex_digit)
        (hex_digit)))
    (pipe_element
      (val_binary
        (hex_digit)
        (hex_digit)
        (hex_digit)))))
