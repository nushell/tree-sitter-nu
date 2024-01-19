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

=====
module-004-re-export
=====

export module another.nu
export module 'other.nu'
export module others

----

(nu_script
  (decl_module
    (cmd_identifier))
  (decl_module
    (val_string))
  (decl_module
    (cmd_identifier)))
