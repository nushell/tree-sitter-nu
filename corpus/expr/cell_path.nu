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
=====

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
=====

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
