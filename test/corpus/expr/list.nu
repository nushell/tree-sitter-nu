=====
list-001-item-string
=====

[
  unquoted
  'single quoted'
  "double quoted"
  unquoted.nu
  -u
  -unquoted
  --unquoted-string
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string
              (long_flag_identifier))))))))

=====
list-002-unquoted-starts-with-numeric
=====

[
  127abc
  info
  5e652a7e-bbce-11ee-8dfd-00155dd76211
  7.3eabc
  information
  192.168.0.1
  nanometer
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-003-unquoted-arithmetic-operator
=====

[
  +
  -
  *
  /
  mod
  //
  **
  ++
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-004-unquoted-comparison-operator
=====

[
  ==
  !=
  <
  <=
  >
  >=
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-005-unquoted-regex-operator
=====

[
  =~
  !~
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-006-unquoted-assignment-operator
=====

[
  +=
  -=
  *=
  /=
  ++=
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-007-unquoted-range-operator
=====

[
  ..
  ..=
  ..<
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-008-separated-by-comma
=====

[abc,def,123]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_number)))))))

=====
list-009-unquoted-path
=====

[
  .
  ./
  ./dir
  ..
  ../
  ../file.txt
  ...
  .../
  .../file.txt
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-010-unquoted-vs-type
=====

[
  infms
  nankb
  true-foo
  null-foo
  e>foo
  1ms-foo
  1mb-foo
  .1foo
  1.foo
  1.1foo
  -1.1e-10.
  1991-02-02foo
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

=====
list-011-unquoted-vs-range
=====

[
  .1...
  ..2.2
  .0...0
  ..1..=2.2
  .1...0..=0.
  # unquoted following
  .1..foo
  .1...2foo
  .1...1...2foo
  .1...0..=0.foo
  1...2foo
  ..=.2foo
  ..1..=2.foo
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_range
              (val_number)))
          (val_entry
            (val_range
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)
              (val_number)))
          (comment)
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

======
list-012-unquoted-vs-range-followed-by-dot
======

[
  .1...foo
  1...2.foo
  .1...0.
  ..=.2.
  ..<22.2.
  ..1..=2..
  .1...0..=0..
  .1...0..=0..foo
  .1...1..<2.foo
]

------

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string))
          (val_entry
            (val_string)))))))

======
list-013-unquoted-with-immediate-expr-parenthesized
======

[
  foo(
'bar')baz(
1)
  foo('bar')()
  .()
  true()
  null()
  .1ms()
  .1mb()
  2024-01-01()
  .1()
  e>()
  ..=1()
  ..1..<1()
  .1..=1()
  1...1..=1()
  ..=1.foo()
  1...()
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_string
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (val_string))))
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (val_number))))))
          (val_entry
            (val_string
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (val_string))))
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized)))
          (val_entry
            (val_string
              (expr_parenthesized))))))))
