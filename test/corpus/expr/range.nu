=====
range-001-basic
=====

1..3
4..=6
7..<10
0..-5

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number)))))

=====
range-002-float-exponent
=====

[
  1..2.3
  1...3
  23..3.4e1
  1.2..3.4
  1.2e-1..3.4
  0..=1.5e+1
  0..<1.5e+1
  1...=1.5e+1
  1.2..<1.5e+1
]

-----

(nu_script
  (pipeline
    (pipe_element
      (val_list
        (list_body
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number)))
          (val_entry
            (val_range
              (val_number)
              (val_number))))))))

=====
range-003-only-start
=====

1..
1...
.5..
1.5e+1..

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)))))

=====
range-004-only-end
=====

..5
...1
...1e+1
..<5
..<.1
..<.1e+1
..=5
..=.1
..=.1e+1

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)))))

=====
range-005-variable
=====

$begin..$end
$begin..=$end
$begin..<$end
$begin..
..$end
..=$end
..<$end

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))))))

=====
range-006-subexpr
=====

(1 + 2)..(3 + 4)
(1 + 2)..=(3 + 4)
(1 + 2)..<(3 + 4)

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number))))))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number))))))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))))))

=====
range-007-subexpr-only-begin
=====

(1 + 2)..

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))))))

=====
range-008-subexpr-only-end
=====

..(3 + 4)
..=(3 + 4)
..<(3 + 4)

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number))))))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number))))))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))))))

=====
range-009-pipe
=====

1..3 | each { $in * 2 }
ls | range 1..3

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_closure
          (pipeline
            (pipe_element
              (expr_binary
                (val_variable)
                (val_number))))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_number)
          (val_number))))))

=====
range-010-step
=====

1..3..10
1.5..3.0..9.0
$begin..$step..$end
(1 + 2)..(3 + 4)..(10 + 20)

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))
        (val_variable
          (identifier))
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))))))

=====
range-011-step-without-begin
=====

..5..=20
..5..<20
..$step..=$end
..(3 + 4)..<(10 + 20)

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))))))

=====
range-012-step-without-end
=====

1..5..
$begin..$step..
(1 + 2)..(3 + 4)..

-----

(nu_script
  (pipeline
    (pipe_element
      (val_range
        (val_number)
        (val_number))))
  (pipeline
    (pipe_element
      (val_range
        (val_variable
          (identifier))
        (val_variable
          (identifier)))))
  (pipeline
    (pipe_element
      (val_range
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))
        (expr_parenthesized
          (pipeline
            (pipe_element
              (expr_binary
                (val_number)
                (val_number)))))))))

=====
range-013-cmd
=====

range 1..3
range 1..=5
range 10..<20
range 1..
range ..10
range ..=15
range ..<20

-----

(nu_script
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
          (val_number))))))

=====
range-014-cmd-variable
=====

range $begin..<$end
range $begin..$step..<$end

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))
          (val_variable
            (identifier))
          (val_variable
            (identifier)))))))

=====
range-015-cmd-variable-without-end
=====

range $begin..
range $begin..$step..

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))
          (val_variable
            (identifier)))))))

=====
range-016-cmd-variable-without-begin
=====

range ..=$end
range ..<$end
range ..$step..=$end

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (val_variable
            (identifier))
          (val_variable
            (identifier)))))))

=====
range-017-cmd-subexpr
=====

range (1 + 2)..<(3 * 4)
range ($n + 1)..($n + 3)..=([$a $b] | math max)

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_number)
                  (val_number)))))
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_number)
                  (val_number)))))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_variable
                    (identifier))
                  (val_number)))))
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_variable
                    (identifier))
                  (val_number)))))
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_list
                  (list_body
                    (val_entry
                      (val_variable
                        (identifier)))
                    (val_entry
                      (val_variable
                        (identifier))))))
              (pipe_element
                (command
                  (cmd_identifier)
                  (val_string))))))))))

=====
range-018-cmd-subexpr-without-end
=====

range ($xs | length)..
range ($n + 1)..($n + 3)..

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_variable
                  (identifier)))
              (pipe_element
                (command
                  (cmd_identifier)))))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_variable
                    (identifier))
                  (val_number)))))
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_variable
                    (identifier))
                  (val_number))))))))))

=====
range-019-cmd-subexpr-without-begin
=====

range ..<(3 * 4)
range ..($n + 3)..=([$a $b] | math max)

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_number)
                  (val_number)))))))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)
        (val_range
          (expr_parenthesized
            (pipeline
              (pipe_element
                (expr_binary
                  (val_variable
                    (identifier))
                  (val_number)))))
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_list
                  (list_body
                    (val_entry
                      (val_variable
                        (identifier)))
                    (val_entry
                      (val_variable
                        (identifier))))))
              (pipe_element
                (command
                  (cmd_identifier)
                  (val_string))))))))))
