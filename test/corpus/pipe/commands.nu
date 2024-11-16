=====
cmd-001-head
=====

cmd

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))

======
cmd-002-head-sub
======

cmd sub

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
cmd-003-external-cmd
=====

^cmd 42

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_number)))))

=====
cmd-004-command-in-different-line
=====

print this
print this
print this
if $a == true {
    print this
    print this
}

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (ctrl_if
        (expr_binary
          (val_variable
            (identifier))
          (val_bool))
        (block
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string))))
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string)))))))))

=====
cmd-005-command-with-semicolon
=====

print $a; print $b; echo $c | print $in

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable
          (identifier))))
    (pipe_element
      (command
        (cmd_identifier)
        (val_variable)))))

=====
cmd-006-so-many-arguments
=====

foo this is only for testing

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string)
        (val_string)
        (val_string)
        (val_string)))))

====
cmd-007-if-oneline
====

if $a { 0 } else { ls | print; ls | print; }

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_if
        (val_variable
          (identifier))
        (block
          (pipeline
            (pipe_element
              (val_number))))
        (block
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)))
            (pipe_element
              (command
                (cmd_identifier))))
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)))
            (pipe_element
              (command
                (cmd_identifier)))))))))

=====
cmd-008-unquoted-1-character
=====

echo n

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

=====
cmd-009-terminated-by-newline
=====

echo hello
let x = 42

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number)))))

======
cmd-010-long-flag
======

cmd --long-flag --42

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (long_flag (long_flag_identifier))
        (long_flag (long_flag_identifier))))))

======
cmd-011-path-string-1-dot
======

cargo install --path .
cargo install --path ./
cargo install --path ./dir

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (long_flag (long_flag_identifier))
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (long_flag (long_flag_identifier))
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (long_flag (long_flag_identifier))
        (val_string)))))

======
cmd-012-path-string-2-dots
======

cd ..
cd ../
cd ../dir

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-013-path-string-3-dots
======

cd ...
cd .../
cd .../dir

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-014-path-string-4-dots
======

cd ....
cd ..../
cd ..../dir

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-015-unquoted-starts-with-numeric
======

echo 127abc
log info
debug info
print information
print nanometer
print 5e652a7e-bbce-11ee-8dfd-00155dd76211
print 7.3eabc
print 192.168.0.1

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-016-args-contains-comma
======

echo hello,world
echo hello, world
echo ,hello world
echo [hello,world]

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_list
          (list_body
            (val_entry
              (val_string))
            (val_entry
              (val_string))))))))

======
cmd-017-string-external
======

^'ls'

------

(nu_script
  (pipeline
    (pipe_element
      (command
        head: (val_string)))))

======
cmd-018-pipe-external
======

^('ls')

------

(nu_script
  (pipeline
    (pipe_element
      (command
        head: (expr_parenthesized
          (pipeline
            (pipe_element
              (val_string))))))))

=====
cmd-019-flags-with-values
=====

bla --weird-that=this --behaved-differently=than-this --level=2

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
          (long_flag
            (long_flag_equals_value
              (long_flag_identifier)
              (long_flag_value
                (val_string))))
          (long_flag
            (long_flag_equals_value
              (long_flag_identifier)
              (long_flag_value
                (val_string))))
          (long_flag
            (long_flag_equals_value
              (long_flag_identifier)
              (long_flag_value
                (val_number))))))))

======
cmd-020-variable-external
======

^$cmd

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (val_variable
          (identifier))))))

======
cmd-021-variable-external-parenthesized
======

(^$cmd
  arg
)

------

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (val_variable
                (identifier))
              (val_string))))))))

======
cmd-022-unquoted-string-vs-type
======

echo infms
echo nankb
echo true-foo
echo null-foo
echo e>foo
echo 1ms-foo
echo 1mb-foo
echo .1foo
echo 1.foo
echo 1.1foo
echo 1.1e-10.
echo 1991-02-02foo

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-023-unquoted-string-vs-range
======

echo .1...
echo ..2.2
echo .0...0
echo ..1..=2.2
echo .1...0..=0.
# unquoted following
echo .1..foo
echo .1...2foo
echo .1...1...2foo
echo .1...0..=0.foo
echo 1...2foo
echo ..=.2foo
echo ..1..=2.foo

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)
          (val_number)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)
          (val_number)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)
          (val_number)
          (val_number)))))
  (comment)
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-024-unquoted-string-vs-range-followed-by-dot
======

echo .1...foo
echo 1...2.foo
echo .1...0.
echo ..=.2.
echo ..<22.2.
echo ..1..=2..
echo .1...0..=0..
echo .1...0..=0..foo
echo .1...1..<2.foo

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string)))))

======
cmd-025-unquoted-string-with-immediate-expr-parenthesized
======

echo foo(
'bar')baz(
1)
echo foo('bar')()
echo .()
echo true()
echo null()
echo .1ms()
echo .1mb()
echo 2024-01-01()
echo .1()
echo e>()
echo ..=1()
echo ..1..<1()
echo .1..=1()
echo 1...1..=1()
echo ..=1.foo()
echo 1...()

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_string))))
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_number))))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_string))))
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized))))))

======
cmd-026-unquoted-string-with-leading-plus
======

echo +100
echo +_.1
echo +1.
echo +1..
echo +.1..()
# unquoted below
chmod +x
echo +1.f
echo +.1f
echo +..1
echo +
echo +-
echo ++1
echo +.x
echo +()
echo +.1()
echo +..1()

------

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_number))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_number))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_number))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)
          (expr_parenthesized)))))
  (comment)
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized)))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_string
          (expr_parenthesized))))))

