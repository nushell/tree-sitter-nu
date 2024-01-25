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
def-001-flags
======

def --env foo [] {}
def --env --wrapped bar [...args] {}
def --wrapped foo [...args] {}
def --wrapped --env bar [...args] {}

-----

(nu_script
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks)
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block))
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block)))

======
def-004-flag-with-one-return-type
======

def --env test []: nothing -> string {}
def --env --wrapped test [...args]: nothing -> string {}
def --wrapped test [...args]: nothing -> string {}
def --wrapped --env test [...args]: nothing -> string {}

-----

(nu_script
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type))
    (block))
  )

======
def-005-env-with-multiple-return-types
======

def --env test []: [nothing -> string, nothing -> int] {}
def --env --wrapped test [...args]: [nothing -> string, nothing -> int] {}
def --wrapped --env test [...args]: [nothing -> string, nothing -> int] {}
def --wrapped test [...args]: [nothing -> string, nothing -> int] {}

-----

(nu_script
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (flat_type)
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type)
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type)
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type)
      (flat_type)
      (flat_type))
    (block)))

======
def-006-flag-with-return-type-complex
======

def --env test []: nothing -> record<a: string, b: int> {}
def --env --wrapped test [...args]: nothing -> record<a: string, b: int> {}
def --wrapped --env test [...args]: nothing -> record<a: string, b: int> {}
def --wrapped test [...args]: nothing -> record<a: string, b: int> {}

-----

(nu_script
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (flat_type)
        (identifier)
        (flat_type)))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (flat_type)
        (identifier)
        (flat_type)))
    (block))
  (decl_def
    (long_flag)
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (flat_type)
        (identifier)
        (flat_type)))
    (block))
  (decl_def
    (long_flag)
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
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

======
def-017-long-flag-with-short-without-space
======

def test [
  --long-flag(-l)
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
def-018-long-flag-with-short-and-type
======

def test [
  --long-flag(-l): int
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
          (param_short_flag))
        (param_type
          (flat_type))))
    (block)))

======
def-019-type-list-of-list
======

def test [
  x: list<list<int>>
]: nothing -> list<list<int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (list_type
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (list_type
        (list_type
          (flat_type))))
    (block)))

======
def-020-type-list-of-record
======

def test [
  x: list<record<key: string>>
]: nothing -> list<record<key: string>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (list_type
            (collection_type
              (identifier)
              (flat_type))))))
    (returns
      (flat_type)
      (list_type
        (collection_type
          (identifier)
          (flat_type))))
    (block)))

======
def-021-type-list-of-table
======

def test [
  x: list<table<key1: string, key2: int>>
]: nothing -> list<table<key1: string, key2: int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (list_type
            (collection_type
              (identifier)
              (flat_type)
              (identifier)
              (flat_type))))))
    (returns
      (flat_type)
      (list_type
        (collection_type
          (identifier)
          (flat_type)
          (identifier)
          (flat_type))))
    (block)))

======
def-022-type-record-of-list
======

def test [
  x: record<key: list<int>>
]: nothing -> record<key: list<int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (list_type
          (flat_type))))
    (block)))

======
def-023-type-record-of-record
======

def test [
  x: record<key: list<int>>
]: nothing -> record<key: list<int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (list_type
          (flat_type))))
    (block)))

======
def-024-type-record-of-table
======

def test [
  x: record<key: table<key: int>>
]: nothing -> record<key: table<key: int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (collection_type
              (identifier)
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (collection_type
          (identifier)
          (flat_type))))
    (block)))

======
def-025-type-table-of-list
======

def test [
  x: table<key: list<string>>
]: nothing -> table<key: list<string>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (list_type
          (flat_type))))
    (block)))

======
def-026-type-table-of-record
======

def test [
  x: table<key: record<key1: string, key2: int>>
]: nothing -> table<key: record<key1: string, key2: int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (collection_type
              (identifier)
              (flat_type)
              (identifier)
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (collection_type
          (identifier)
          (flat_type)
          (identifier)
          (flat_type))))
    (block)))

======
def-027-type-table-of-table
======

def test [
  x: table<key: table<key1: string, key2: int>>
]: nothing -> table<key: table<key1: string, key2: int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (collection_type
              (identifier)
              (flat_type)
              (identifier)
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (collection_type
          (identifier)
          (flat_type)
          (identifier)
          (flat_type))))
    (block)))

======
def-028-type-one-line
======

def test [x: record<key: list<int>>]: nothing -> record<key: list<int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (list_type
          (flat_type))))
    (block)))

======
def-029-type-two-line
======

def test [x: record<key: list<int>>
]: nothing -> record<key: list<int>> {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (list_type
          (flat_type))))
    (block)))

======
def-030-type-two-line
======

def test [x: record<key: list<int>>]: nothing -> record<key: list<int>> {
}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (list_type
              (flat_type))))))
    (returns
      (flat_type)
      (collection_type
        (identifier)
        (list_type
          (flat_type))))
    (block)))

======
def-031-name-special-keys
======

def a_-!? [] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks)
    (block)))
