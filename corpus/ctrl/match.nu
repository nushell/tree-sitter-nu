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
          (val_record))
        (default_arm
          (val_record))))
