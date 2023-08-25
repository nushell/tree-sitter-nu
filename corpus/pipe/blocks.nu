====
blocks-001-block
====

if $a {
  print qwe
  print rty
}

-----

(nu_script
  (ctrl_if
    (val_variable
      (identifier))
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
            (val_string)))))))
====
blocks-002-block-oneline
====

if $a { print qwe; print rty }

-----

(nu_script
  (ctrl_if
    (val_variable
      (identifier))
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
            (val_string)))))))
====
blocks-003-braced
====

(print qwe; print rty)

-----

(nu_script
  (pipeline
    (pipe_element
      (expr_parenthesized
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)
              (val_string))))
        (pipeline
          (pipe_element
            (command
              (cmd_identifier)
              (val_string))))))))

====
blocks-004-multiline-command
====

(ls
  --all
  -l
  ../
)

-----

(nu_script
  (pipeline
	  (pipe_element
		  (expr_parenthesized
			  (pipeline
				  (pipe_element
					  (command
						  (cmd_identifier)
							(long_flag)
							(short_flag)
							(val_string))))))))


====
blocks-005-closures
====

let a = {||
  print qwe
  print rty
}

let b = {|| print qwe; print rty }

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_closure
          (parameter_pipes)
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string))))
          (pipeline
            (pipe_element
              (command
                (cmd_identifier)
                (val_string))))))))
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_closure
          (parameter_pipes)
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