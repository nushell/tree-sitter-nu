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

======
def-007-long-flag
======

def test [
  --long-flag
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_long_flag
          (identifier))))
    (block)))

======
def-008-long-flag-with-short
======

def test [
  --long-flag (-l)
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_long_flag
          (identifier))
        (flag_capsule
          (param_short_flag))))
    (block)))

======
def-009-long-flag-with-type
======

def test [
  --long-flag: string
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_long_flag
          (identifier))
        (param_type
          (flat_type))))
    (block)))

======
def-010-short-flag
======

def test [
  -s
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_short_flag)))
    (block)))

======
def-011-short-flag-with-type
======

def test [
  -s: int
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_short_flag)
      (param_type
        (flat_type))))
    (block)))

======
def-012-parameter
======

def test [
  foo
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)))
    (block)))

======
def-013-parameter-with-type
======

def test [
  foo: string
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (flat_type))))
    (block)))

======
def-014-optional-parameter
======

def test [
  foo?
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_opt
          (identifier))))
    (block)))

======
def-015-optional-parameter-with-type
======

def test [
  foo?: string
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_opt
          (identifier))
        (param_type
          (flat_type))))
    (block)))

======
def-016-rest-parameter
======

def test [
  ...rest
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block)))
