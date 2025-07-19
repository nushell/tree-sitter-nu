=====
attr-001-smoke-test
=====

@test
def test [] {}
@test; def test [] {}

-----

(nu_script
  (decl_def
    (attribute_list
      (attribute
        type: (attribute_identifier)))
    unquoted_name: (cmd_identifier)
    parameters: (parameter_bracks)
    body: (block))
  (decl_def
    (attribute_list
      (attribute
        type: (attribute_identifier)))
    unquoted_name: (cmd_identifier)
    parameters: (parameter_bracks)
    body: (block)))

=====
attr-002-examples
=====

@example "adding some dummy paths to an empty PATH" {
    with-env { PATH: [] } {
        path add "returned" --ret
    }
} --result [returned]
@example "adding paths based on the operating system" {
    path add {linux: "foo"}
}
export def --env "path add" [
    --ret (-r)  # return $env.PATH, useful in pipelines to avoid scoping.
    --append (-a)  # append to $env.PATH instead of prepending to.
] {}

-----

(nu_script
  (decl_def
    (attribute_list
      (attribute
        type: (attribute_identifier)
        arg: (val_string
          (string_content))
        arg: (val_closure
          (pipeline
            (pipe_element
              (command
                head: (cmd_identifier)
                arg: (val_record
                  (record_body
                    entry: (record_entry
                      key: (identifier)
                      value: (val_list))))
                arg: (val_closure
                  (pipeline
                    (pipe_element
                      (command
                        head: (cmd_identifier)
                        arg_str: (val_string)
                        arg: (val_string
                          (string_content))
                        flag: (long_flag
                          name: (long_flag_identifier))))))))))
        flag: (long_flag
          name: (long_flag_identifier))
        arg: (val_list
          (list_body
            entry: (val_entry
              item: (val_string)))))
      (attribute
        type: (attribute_identifier)
        arg: (val_string
          (string_content))
        arg: (val_closure
          (pipeline
            (pipe_element
              (command
                head: (cmd_identifier)
                arg_str: (val_string)
                arg: (val_record
                  (record_body
                    entry: (record_entry
                      key: (identifier)
                      value: (val_string
                        (string_content)))))))))))
    (long_flag
      name: (long_flag_identifier))
    quoted_name: (val_string
      (string_content))
    parameters: (parameter_bracks
      (parameter
        param_long_flag: (param_long_flag
          (long_flag_identifier))
        flag_capsule: (flag_capsule
          (param_short_flag
            name: (param_short_flag_identifier)))
        (comment))
      (parameter
        param_long_flag: (param_long_flag
          (long_flag_identifier))
        flag_capsule: (flag_capsule
          (param_short_flag
            name: (param_short_flag_identifier)))
        (comment)))
    body: (block)))

=====
attr-003-mixed
=====

@search-terms multiply times
@example "random" {2 | double}; @test; def double []: [number -> number] { $in * 2 }

-----

(nu_script
  (decl_def
    (attribute_list
      (attribute
        type: (attribute_identifier)
        arg_str: (val_string)
        arg_str: (val_string))
      (attribute
        type: (attribute_identifier)
        arg: (val_string
          (string_content))
        arg: (val_closure
          (pipeline
            (pipe_element
              (val_number))
            (pipe_element
              (command
                head: (cmd_identifier))))))
      (attribute
        type: (attribute_identifier)))
    unquoted_name: (cmd_identifier)
    parameters: (parameter_bracks)
    return_type: (returns
      type: (flat_type)
      type: (flat_type))
    body: (block
      (pipeline
        (pipe_element
          (expr_binary
            lhs: (val_variable)
            rhs: (val_number)))))))

=====
attr-004-externs
=====

@test
extern eza []

-----

(nu_script
  (decl_extern
    (attribute_list
      (attribute
        (attribute_identifier)))
    (cmd_identifier)
    (parameter_bracks)))
