=====
values-001-numbers
=====

[69 6.9 0b1000101 0o105 6.9e1 6.9E+1 0x45 -69 +69 .69 69.]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))))

=====
values-002-booleans
=====


[true false (not true)]

------

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_bool))
          (val_entry
            (val_bool))
          (val_entry
            (expr_parenthesized
              (pipeline
                (pipe_element
                  (expr_unary
                    (val_bool)))))))))))

=====
values-003-nothing
=====

[
  null
  ()
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_nothing))
          (val_entry
            (val_nothing)))))))

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

=====
values-005-numbers-with-underscore
=====

[
  10_000,
  1.234_5,
  1.234_5e6
  1_234.567_8,
  1_234.567_8e9,
  .123_4,
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))))

=====
values-006-infinity-number
=====

[
  inf
  Inf
  INF
  Infinity
  INFINITY
  -inf
  -Inf
  -INF
  -Infinity
  -INFINITY
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))))

=====
values-006-not-a-number
=====

[
  nan
  NaN
  NAN
  Nan
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number))
          (val_entry
            (val_number)))))))

=====
values-007-interpolated-string
=====

$"foo(1)bar"
$'foo(1)bar'

-----

(nu_script
  (pipeline
    (pipe_element
      (val_interpolated
        (escaped_interpolated_content)
        (expr_interpolated
          (pipeline
            (pipe_element
              (val_number))))
        (escaped_interpolated_content))))
  (pipeline
    (pipe_element
      (val_interpolated
        (unescaped_interpolated_content)
        (expr_interpolated
          (pipeline
            (pipe_element
              (val_number))))
        (unescaped_interpolated_content)))))

=====
values-008-interpolated-string-multiline-command
=====

$'foo(
  echo foo # should be single pipeline
  $'( # comment
    echo nested
    val_interpolated # should be command argument
  )'
)bar'

-----

(nu_script
  (pipeline
    (pipe_element
      (val_interpolated
        (unescaped_interpolated_content)
        (expr_interpolated
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)
                (comment)
                (val_interpolated
                  (expr_interpolated
                    (comment)
                    (pipeline
                      (pipe_element
                        (command
                          (cmd_identifier)
                          (val_string)
                          (val_string)
                          (comment))))))))))
        (unescaped_interpolated_content)))))
