=====
cellpath-001-int-access
=====

let x = $list.4

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_variable
          (identifier)
          (cell_path
            (path)))))))

======
cellpath-002-str-access
======

let x = $env.PATH

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_variable
          (cell_path
            (path)))))))

====
cellpath-003-multiple-access
====

let x = $list.PATH.4

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_variable
          (identifier)
          (cell_path
            (path)
            (path)))))))

====
cellpath-004-underscore-in-path
====

let x = $env.LAST_EXIT_CODE

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_variable
          (cell_path
            (path)))))))

====
cellpath-005-hyphen-in-path
====

let x = $nu.home-path

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_variable
          (cell_path
            (path)))))))

====
cellpath-006-immediate-punctuation
====

($env.PATH)
[$env.PATH]
{$env.PATH}
{$env.PATH: 1}
[$env.PATH,]

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (val_variable
              (cell_path
                (path))))))))
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_variable
              (cell_path
                (path))))))))
  (pipeline
    (pipe_element
      (val_closure
        (pipeline
          (pipe_element
            (val_variable
              (cell_path
                (path))))))))
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (val_variable
              (cell_path
                (path)))
            (val_number))))))
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_variable
              (cell_path
                (path)))))))))

====
cellpath-007-allowed-punctuation
====

$env.$var.$!@#% # comment

-----

(nu_script
  (pipeline
    (pipe_element
      (val_variable
        (cell_path
          (path)
          (path)))))
  (comment))
