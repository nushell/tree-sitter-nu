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
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))

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
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))

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
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))

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
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))

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
        (val_string)
        (val_string)))))

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
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))

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
        (val_string)
        (val_string)
        (val_string)))))

=====
list-008-separated-by-comma
=====

[abc,def,123]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (val_string)
        (val_string)
        (val_number)))))

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
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))
