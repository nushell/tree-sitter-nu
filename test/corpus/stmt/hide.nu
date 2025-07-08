=====
hide-mod-001-smoke-test
=====

hide modulename

-----

(nu_script
  (hide_mod
    (cmd_identifier)))

=====
hide-mod-002-semicolon
=====

hide modulename;

-----

(nu_script
  (hide_mod
    (cmd_identifier)))

=====
hide-env-001-smoke-test
=====

hide-env FOO

-----

(nu_script
  (hide_env
    (identifier)))

=====
hide-env-002-semicolon
=====

hide-env FOO;

-----

(nu_script
  (hide_env
    (identifier)))

=====
hide-env-003-flag
=====

hide-env -i FOO;
hide-env --ignore-errors FOO;

-----

(nu_script
  (hide_env
    (short_flag
      (short_flag_identifier))
    (identifier))
  (hide_env
    (long_flag
      (long_flag_identifier))
    (identifier)))

=====
hide-env-004-multiple-names
=====

hide-env -i FOO BAR;
hide-env FOO BAR;

-----

(nu_script
  (hide_env
    (short_flag
      name: (short_flag_identifier))
    var_name: (identifier)
    var_name: (identifier))
  (hide_env
    var_name: (identifier)
    var_name: (identifier)))
