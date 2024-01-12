=====
record-001-basic
=====

{'key': 'value'}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_entry
          (val_string)
          (val_string))))))

=====
record-002-empty
=====

{}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record))))
