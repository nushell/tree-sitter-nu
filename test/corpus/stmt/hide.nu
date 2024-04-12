=====
hide-mod-001-smoke-test
=====

hide module

-----

(nu_script
  (hide_mod
    (cmd_identifier)))

=====
hide-mod-002-semicolon
=====

hide module;

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
