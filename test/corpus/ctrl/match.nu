=====
match-001-guards
=====

match $x {
   $x if $x == 4 => {},
   _ => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_variable
              (identifier))
            (match_guard
              (expr_binary
                (val_variable
                  (identifier))
                (val_number))))
          (block))
        (default_arm
          (block))))))

====
match-002-block
====

match $x {
  {key: $val} => {$val | print}
  _ => {{}}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_record
              (record_body
                (record_entry
                  (identifier)
                  (val_variable
                    (identifier))))))
          (block
            (pipeline
              (pipe_element
                (val_variable
                  (identifier)))
              (pipe_element
                (command
                  (cmd_identifier))))))
        (default_arm
          (block
            (pipeline
              (pipe_element
                (val_record)))))))))

=====
match-003-list
=====

match $xs {
   [] => {},
   [1] => {},
   [1, 2] => {},
   [$x] => {},
   _ => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_list))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_number))))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_number)
                (val_number))))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))))
          (block))
        (default_arm
          (block))))))

=====
match-004-range
=====

match $xs {
   1..3 => {}
   4..<6 => {}
   6..=9 => {}
   10.. => {}
   [1..3, 4..<10] => {}
   _ => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_range
              (val_number)
              (val_number)))
          (block))
        (match_arm
          (match_pattern
            (val_range
              (val_number)
              (val_number)))
          (block))
        (match_arm
          (match_pattern
            (val_range
              (val_number)
              (val_number)))
          (block))
        (match_arm
          (match_pattern
            (val_range
              (val_number)))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_range
                  (val_number)
                  (val_number))
                (val_range
                  (val_number)
                  (val_number)))))
          (block))
        (default_arm
          (block))))))

=====
match-005-rest-pattern
=====

match $xs {
   [1 ..$tail] => {}
   [2, ..] => {}
   [$head ..$tail] if ($tail | length) < 3 => {}
   [..$tail] => {}
   _ => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_number))
              (val_variable
                (identifier))))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_number))))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))
              (val_variable
                (identifier)))
            (match_guard
              (expr_binary
                (expr_parenthesized
                  (pipeline
                    (pipe_element
                      (val_variable
                        (identifier)))
                    (pipe_element
                      (command
                        (cmd_identifier)))))
                (val_number))))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (val_variable
                (identifier))))
          (block))
        (default_arm
          (block))))))

=====
match-006-or
=====

match $xs {
   [1] | [2 3] => {},
   _ => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_number)))
            (val_list
              (list_body
                (val_number)
                (val_number))))
          (block))
        (default_arm
          (block))))))

=====
match-007-unquoted
=====

match foo {
   foo => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_string)
        (match_arm
          (match_pattern
            (val_string))
          (block))))))

=====
match-008-record
=====

match $x {
  {$y} => {}
  {$foo, $bar} => {}
  {$a, b: c} => {}
  {a: b, b: c} => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_record
              (record_body
                (val_variable
                  (identifier)))))
          (block))
        (match_arm
          (match_pattern
            (val_record
              (record_body
                (val_variable
                  (identifier))
                (val_variable
                  (identifier)))))
          (block))
        (match_arm
          (match_pattern
            (val_record
              (record_body
                (val_variable
                  (identifier))
                (record_entry
                  (identifier)
                  (val_string)))))
          (block))
        (match_arm
          (match_pattern
            (val_record
              (record_body
                (record_entry
                  (identifier)
                  (val_string))
                (record_entry
                  (identifier)
                  (val_string)))))
          (block))))))

=====
match-009-defaults
=====

match $x {
   _ if $x == 4 => {},
   _ => {}
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (match_guard
              (expr_binary
                (val_variable
                  (identifier))
                (val_number))))
          (block))
        (default_arm
          (block))))))

=====
match-010-empty
=====

match [true] {}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_list
          (list_body
            (val_entry
              (val_bool))))))))

=====
match-011-separator
=====

match null {
1 => 0 2unquote => 1
# comment

3 => $x.0.0, 4 => {$x.0}
# comment
,

}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_nothing)
        (match_arm
          (match_pattern
            (val_number))
          (val_number))
        (match_arm
          (match_pattern
            (val_string))
          (val_number))
        (comment)
        (match_arm
          (match_pattern
            (val_number))
          (val_variable
            (identifier)
            (cell_path
              (path)
              (path))))
        (match_arm
          (match_pattern
            (val_number))
          (block
            (pipeline
              (pipe_element
                (val_variable
                  (identifier)
                  (cell_path
                    (path)))))))
        (comment)))))

=====
match-012-unary-not-allowed
:error
=====

match 1 {
_ => not true
}

-----



=====
match-013-binary-not-allowed
:error
=====

match 1 {
_ => 1 + 1
}

-----



=====
match-014-default-only
=====

match 1 {#comment
  _ => 1
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_number)
        (comment)
        (default_arm
          (val_number))))))

=====
match-015-multiline-pattern
=====

match [] {
  [
    $a
    $b
  ] => 1
}

match {} {
  {
    foo: $a
    $b
  } => 1
}

match  a {
  a
  |b|c => 42
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        scrutinee: (val_list)
        (match_arm
          pattern: (match_pattern
            (val_list
              (list_body
                entry: (val_variable
                  name: (identifier))
                entry: (val_variable
                  name: (identifier)))))
          expression: (val_number)))))
  (pipeline
    (pipe_element
      (ctrl_match
        scrutinee: (val_record)
        (match_arm
          pattern: (match_pattern
            (val_record
              (record_body
                entry: (record_entry
                  key: (identifier)
                  value: (val_variable
                    name: (identifier)))
                entry: (val_variable
                  name: (identifier)))))
          expression: (val_number)))))
  (pipeline
    (pipe_element
      (ctrl_match
        scrutinee: (val_string)
        (match_arm
          pattern: (match_pattern
            (val_string)
            (val_string)
            (val_string))
          expression: (val_number))))))

=====
match-016-rest-anywhere
=====

match $l {
  [$first, ..$middle, $last] => $middle
  [.., 1] => 1
  [$a .. $c] => $c
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))
              (val_variable
                (identifier))
              (list_body
                (val_variable
                  (identifier)))))
          (val_variable
            (identifier)))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_number))))
          (val_number))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))
              (list_body
                (val_variable
                  (identifier)))))
          (val_variable
            (identifier)))))))

=====
match-017-alternatives-with-guard
=====

match $x { 1 | 2 | 3 if $y => "small", _ => "other" }

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_number)
            (val_number)
            (val_number)
            (match_guard
              (val_variable
                (identifier))))
          (val_string
            (string_content)))
        (default_arm
          (val_string
            (string_content)))))))

=====
match-018-rest-then-separator
=====

match $l {
  [ ..$r ] => $r
  [ $a, ..$r ] => $r
  [$a, .. ] => $a
  [..$r, ] => $r
  [
    $a
    ..$r
  ] => $r
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_list
              (val_variable
                (identifier))))
          (val_variable
            (identifier)))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))
              (val_variable
                (identifier))))
          (val_variable
            (identifier)))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))))
          (val_variable
            (identifier)))
        (match_arm
          (match_pattern
            (val_list
              (val_variable
                (identifier))))
          (val_variable
            (identifier)))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_variable
                  (identifier)))
              (val_variable
                (identifier))))
          (val_variable
            (identifier)))))))

=====
match-019-minus-entries
=====

match $l {
  [-] => 1
  [-$y] => 2
  [-(3)] => 3
}

-----

(nu_script
  (pipeline
    (pipe_element
      (ctrl_match
        (val_variable
          (identifier))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (val_string))))
          (val_number))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (expr_unary
                  (val_variable
                    (identifier))))))
          (val_number))
        (match_arm
          (match_pattern
            (val_list
              (list_body
                (expr_unary
                  (pipeline
                    (pipe_element
                      (val_number)))))))
          (val_number))))))
