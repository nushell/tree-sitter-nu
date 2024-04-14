=====
export-env-001-smoke-test
=====

export-env {}

-----

(nu_script
  (decl_export
    (block)))

=====
export-env-002-with-commands
=====

export-env {
    load-env {NAME: ABE, AGE: UNKNOWN}
}

-----

(nu_script
  (decl_export
    (block
      (pipeline
        (pipe_element
          (command
            (cmd_identifier)
            (val_record
              (record_entry
                (identifier)
                (val_string))
              (record_entry
                (identifier)
                (val_string)))))))))
