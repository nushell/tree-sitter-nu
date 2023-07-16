=====
alias-001-smoke-test
=====

alias change-directory = cd

-----

(nu_script
  (decl_alias
    (cmd_identifier)
    (pipeline
      (pipe_element
        (command
          (cmd_identifier))))))

=====
alias-002-semicolon
=====

alias change-directory = cd;

-----

(nu_script
  (decl_alias
    (cmd_identifier)
    (pipeline
      (pipe_element
        (command
          (cmd_identifier))))))

=====
alias-003-exported
=====

export alias change-directory = cd;

-----

(nu_script
  (decl_alias
    (cmd_identifier)
    (pipeline
      (pipe_element
        (command
          (cmd_identifier))))))
