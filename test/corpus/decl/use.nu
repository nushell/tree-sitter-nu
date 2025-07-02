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

=====
use-003-pipe
=====

use ('file.nu')

-----

(nu_script
  (decl_use
    module: (expr_parenthesized
      (pipeline
        (pipe_element
          (val_string
            (string_content)))))))

=====
use-004-interpolated-string
=====

use $"('s' + 't' + 'd')"

-----

(nu_script
  (decl_use
    (val_interpolated
      (expr_interpolated
        (pipeline
          (pipe_element
            (expr_binary
              (expr_binary
                (val_string
                  (string_content))
                (val_string
                  (string_content)))
              (val_string
                (string_content)))))))))

=====
use-005-multiple-commands
=====

use foo.nu [
  foo
  bar,
  baz
]

-----

(nu_script
  (decl_use
    (unquoted)
    (scope_pattern
      (command_list
        (cmd_identifier)
        (cmd_identifier)
        (cmd_identifier)))))
