=====
table-001-empty-lines
=====
[
  [h1 h2]

  ;

  ['val1',

    'val2']

  ,

  ['val3', 'val4']
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_table
        (val_list
          (list_body
            (val_entry
              (val_string))
            (val_entry
              (val_string))))
        (val_list
          (list_body
            (val_entry
              (val_string))
            (val_entry
              (val_string))))
        (val_list
          (list_body
            (val_entry
              (val_string))
            (val_entry
              (val_string))))))))
