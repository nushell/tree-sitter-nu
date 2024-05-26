=====
record-001-basic
=====

{'key': 'value'}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (val_string)
            (val_string)))))))

=====
record-002-empty
=====

{}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record))))

=====
record-003-number-key
=====

{
  123: number
  -457: number
  +890: number
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (val_number)
            (val_string))
          (record_entry
            (val_number)
            (val_string))
          (record_entry
            (val_number)
            (val_string)))))))

=====
record-004-key-using-symbol
=====

{
  -key: value,
  +key: 'value'
  --key-value: 'value'
  key!: 'value'
  key?: "value"
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_string)))))))

=====
record-005-variable-key
=====

{$key: value}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (val_variable
              (identifier))
            (val_string)))))))

=====
record-006-subexpression-key
=====

{
  ([foo bar] | str join '-'): value
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (expr_parenthesized
              (pipeline
                (pipe_element
                  (val_list
                    (list_body
                      (val_entry
                        (val_string))
                      (val_entry
                        (val_string)))))
                (pipe_element
                  (command
                    (cmd_identifier)
                    (val_string)
                    (val_string)))))
            (val_string)))))))

=====
record-007-keyword-key
=====

{
  error: 'error',
  def: {while: value},
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_record
              (record_body
                (record_entry
                  (identifier)
                  (val_string))))))))))

=====
record-008-modifier-key
=====

{
  export: value,
  use: {export: value},
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_record
              (record_body
                (record_entry
                  (identifier)
                  (val_string))))))))))

=====
record-009-duration
=====

{
    export: 5sec,
    use: {export: value},
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_duration
              (val_number)
              (duration_unit)))
          (record_entry
            (identifier)
            (val_record
              (record_body
                (record_entry
                  (identifier)
                  (val_string))))))))))

=====
record-010-key-value-seperation
=====

{
    export: 556key: 897
}

-----


(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (ERROR
              (identifier))
            (val_number)))))))
