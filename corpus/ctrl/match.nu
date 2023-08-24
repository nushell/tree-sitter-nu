=====
match-001-guards
=====

match $x {
   $x if $x == 4 => {},
   _ => {}
}

-----

(nu_script
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
          (block))))

====
match-002-block
====

match $x {
  {key: $val} => {$val | print}
  _ => {{}}
}

-----

(nu_script
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
            (val_record)))))))