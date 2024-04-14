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
