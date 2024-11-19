====
id-001-variable
====

let foo = 1
let 42 = 1
$foo
$42

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number))))
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number))))
  (pipeline
    (pipe_element
      (val_variable
        (identifier))))
  (pipeline
    (pipe_element
      (val_variable
        (identifier)))))

====
id-002-variable-invalid-dash
:error
====

let foo-bar = 1

-----



====
id-003-variable-invalid-hash
:error
====

let #foo = 1

-----



====
id-004-variable-unicode
====

let こ = 1;
let 🙌 = 1
$こ
$🙌

-----

(nu_script
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number))))
  (stmt_let
    (identifier)
    (pipeline
      (pipe_element
        (val_number))))
  (pipeline
    (pipe_element
      (val_variable
        (identifier))))
  (pipeline
    (pipe_element
      (val_variable
        (identifier)))))

====
id-005-def
====

def foo [
  参
🤖
  ...0
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier))
      (parameter
        (identifier))
      (parameter
        (param_rest
          (identifier))))
    (block)))

====
cmd-id-001-external
====

^tree-sitter
^7z
^g++

-----

(nu_script
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))

====
cmd-id-002-command-vs-value
====

# values
null
7b
nan
# commands
g++
7z
7mss
truee
nann
nulll
users

-----

(nu_script
  (comment)
  (pipeline
    (pipe_element
      (val_nothing)))
  (pipeline
    (pipe_element
      (val_filesize
        (val_number)
        (filesize_unit))))
  (pipeline
    (pipe_element
      (val_number)))
  (comment)
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier))))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))

====
cmd-id-003-path
====

/usr/bin/env nu
~/foo.nu

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
        (cmd_identifier)))))

====
cmd-id-004-unicode
====

def 🤖👀 [] {}

🤖👀

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (block))
  (pipeline
    (pipe_element
      (command
        (cmd_identifier)))))
