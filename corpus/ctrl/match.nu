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
              (record_entry
                (identifier)
                (val_variable
                  (identifier)))))
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
              (val_number)))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (val_number)
              (val_number)))
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
              (val_range
                (val_number)
                (val_number))
              (val_range
                (val_number)
                (val_number))))
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
              (val_number)
              (val_variable
                (identifier))))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (val_number)))
          (block))
        (match_arm
          (match_pattern
            (val_list
              (val_variable
                (identifier))
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
              (val_number))
            (val_list
              (val_number)
              (val_number)))
          (block))
        (default_arm
          (block))))))
