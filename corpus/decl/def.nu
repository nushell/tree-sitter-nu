=====
def-001-smoke-test
=====

def test [] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (block)))

=====
def-002-semicolon
=====

def test [] {};

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (block)))

=====
def-003-exported
=====

export def test [] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (block)))

======
def-env-001-smoke-test
======

def-env test [] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (block)))

======
def-env-004-with-one-return-type
======

def-env test []: nothing -> string {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (flat_type))
    (block)))

======
def-env-005-with-multiple-return-types
======

def-env test []: [nothing -> string, nothing -> int] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (flat_type)
      (flat_type)
      (flat_type))
    (block)))

======
def-env-006-with-return-type-complex
======

def-env test []: nothing -> record<a: string, b: int> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (flat_type)
        (identifier)
        (flat_type)))
    (block)))
