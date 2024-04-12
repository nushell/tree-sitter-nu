=====
use-001-smoke-test
=====

use file.nu

-----

(nu_script
  (decl_use
    (unquoted)))

=====
use-002-semicolon
=====

use dir/file.nu;

-----

(nu_script
  (decl_use
    (unquoted)))
