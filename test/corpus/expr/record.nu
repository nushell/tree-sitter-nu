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
              (val_string))
            (val_number)))))))

=====
record-011-immediate-comma
=====

{
    export: 556,key: 897
}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_number))
          (record_entry
            (identifier)
            (val_number)))))))

=====
record-012-colon-in-unquoted-value
=====

{
  export: "556:error",key: 897
  export: 556:error,key: 897
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
            (val_number))
          (record_entry
            (identifier)
            (ERROR)
            (val_string))
          (record_entry
            (identifier)
            (val_number)))))))

=====
record-013-value-as-signed-number-or-range
=====

{k0.0: -_1_.,k0.1: +_1_.1,k0.2: _1._1e-10,
k1.0: .._1.,k1.1: +_1_._1..=_2.,k1.2: _1_._1..<_2.
k1.3: -._1..(._1 + 1._1)..=_2.}

-----

(nu_script
  (pipeline
    (pipe_element
      (val_record
        (record_body
          (record_entry
            (identifier)
            (val_number))
          (record_entry
            (identifier)
            (val_number))
          (record_entry
            (identifier)
            (val_number))
          (record_entry
            (identifier)
            (val_range
              (val_number)))
          (record_entry
            (identifier)
            (val_range
              (val_number)
              (val_number)))
          (record_entry
            (identifier)
            (val_range
              (val_number)
              (val_number)))
          (record_entry
            (identifier)
            (val_range
              (val_number)
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (expr_binary
                      (val_number)
                      (val_number)))))
              (val_number))))))))

=====
record-014-unquoted-value
=====

{
👍: 👍
k0.0: --long
k0.1: -short
k1.0: infms
k1.1: nankb
k1.2: true-foo
k1.3: null-foo
k2.0: 1ms-foo
k2.1: 1mb-foo
k2.2: 2024-01-01foo
k3.0: .1foo
k3.1: -__.__.1
k3.2: .1.
k3.3: -1.1e-10.
k4.0: foo(
  'bar')baz(
  1)
k4.1:foo('bar')()
  k4.2: .()
k4.3: true()
k4.4: -()
k4.5: ..=1()
k4.6: ..1..<1()
k4.9: 1...()}

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
            (val_string))
          (record_entry
            (identifier)
            (val_string))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (val_string))))
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (val_number))))))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized
                (pipeline
                  (pipe_element
                    (val_string))))
              (expr_parenthesized)))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized)))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized)))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized)))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized)))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized)))
          (record_entry
            (identifier)
            (val_string
              (expr_parenthesized))))))))
