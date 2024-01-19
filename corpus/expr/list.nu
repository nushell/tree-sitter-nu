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
