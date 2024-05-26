=====
closure-007-record-value
=====

{
  closure: {|x| $x * 2}
  closure2: { 'closure' }
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_closure
              (parameter_pipes
                (parameter
                  (identifier)))
              (pipeline
                (pipe_element
                  (expr_binary
                    (val_variable
                      (identifier))
                    (val_number))))))
          (record_entry
            (identifier)
            (val_closure
              (pipeline
                (pipe_element
                  (val_string))))))))))
