=====
module-001-smoke-test
=====

module iter {}

-----

(nu_script
  (decl_module
    (cmd_identifier)
    (block)))

=====
module-002-semicolon
=====

module iter {};

----

(nu_script
  (decl_module
    (cmd_identifier)
    (block)))

=====
module-003-exported
=====

export module iter {}


----

(nu_script
  (decl_module
    (cmd_identifier)
    (block)))
