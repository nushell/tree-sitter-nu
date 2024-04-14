=====
register-001-smoke-test
=====

register ~/plugins/nu-plugin-math

-----

(nu_script
  (stmt_register
    (val_string)))

=====
register-002-semicolon
=====

register ~/plugins/nu-plugin-math;

-----

(nu_script
  (stmt_register
    (val_string)))

=====
register-003-signature
=====

register ~/plugins/nu-plugin-math {
    "sig": {
        "name": "nu-plugin-math",
        "usage": "Math stuff",
        "extra_usage": "",
        "input_type": "Any",
        "output_type": "Any",
        "required_positional": [
            {
                "name": "a",
                "desc": "required integer value",
                "shape": "Int",
                "var_id": None,
            },
            {
                "name": "b",
                "desc": "required string value",
                "shape": "String",
                "var_id": None,
            },
        ],
    }
}

-----

(nu_script
      (stmt_register
        (val_string))
      (pipeline
        (pipe_element
          (val_record
            (record_entry
              (val_string)
              (val_record
                (record_entry
                  (val_string)
                  (val_string))
                (record_entry
                  (val_string)
                  (val_string))
                (record_entry
                  (val_string)
                  (val_string))
                (record_entry
                  (val_string)
                  (val_string))
                (record_entry
                  (val_string)
                  (val_string))
                (record_entry
                  (val_string)
                  (val_list
                    (val_record
                      (record_entry
                        (val_string)
                        (val_string))
                      (record_entry
                        (val_string)
                        (val_string))
                      (record_entry
                        (val_string)
                        (val_string))
                      (record_entry
                        (val_string)
                        (val_string)))
                    (val_record
                      (record_entry
                        (val_string)
                        (val_string))
                      (record_entry
                        (val_string)
                        (val_string))
                      (record_entry
                        (val_string)
                        (val_string))
                      (record_entry
                        (val_string)
                        (val_string)))))))))))

=====
register-004-variable
=====

register $plugin

-----

(nu_script
  (stmt_register
    (val_variable
      (identifier))))
