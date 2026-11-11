=====
extern-001-smoke-test
=====

extern cargo []

-----

(nu_script
  (decl_extern
    (cmd_identifier)
    (parameter_bracks)))

=====
extern-002-semicolon
=====

extern cargo [];

-----

(nu_script
  (decl_extern
    (cmd_identifier)
    (parameter_bracks)))

=====
extern-003-exported
=====

export extern cargo []

-----

(nu_script
  (decl_extern
    (cmd_identifier)
    (parameter_bracks)))

=====
extern-004-with-block
=====

export extern cargo [] {}

-----

(nu_script
  (decl_extern
    (cmd_identifier)
    (parameter_bracks)
    (block)))

=====
extern-005-strict
=====

extern --strict "tool" [--verbose (-v), ...args]
export extern --strict tool2 []

-----

(nu_script
  (decl_extern
    (long_flag
      (long_flag_identifier))
    (val_string
      (string_content))
    (parameter_bracks
      (parameter
        (param_long_flag
          (long_flag_identifier))
        (flag_capsule
          (param_short_flag
            (param_short_flag_identifier))))
      (parameter
        (param_rest
          (identifier)))))
  (decl_extern
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks)))
