=====
source-001-smoke-test
=====

source file.nu

-----

(nu_script
  (stmt_source
    (val_string)))

=====
source-002-semicolon
=====

source file.nu;

-----

(nu_script
  (stmt_source
    (val_string)))

=====
source-003-variable
=====

source $plugin

-----

(nu_script
  (stmt_source
    (val_variable
      (identifier))))

=====
source-env-001-smoke-test
=====

source-env FOO

----

(nu_script
  (stmt_source
    (val_string)))
