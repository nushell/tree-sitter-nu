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
def bar --wrapped --env  [...args] {}
def --wrapped bar --env  [...args] {}

-----

(nu_script
  (decl_def
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks)
    (block))
  (decl_def
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block))
  (decl_def
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block))
  (decl_def
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block))
  (decl_def
    (cmd_identifier)
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (block))
  (decl_def
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_rest
          (identifier))))
    (returns
      (flat_type)
      (flat_type))
    (block)))

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
    (long_flag
      (long_flag_identifier))
    (cmd_identifier)
    (parameter_bracks)
    (returns
      (flat_type)
      (flat_type)
      (flat_type)
      (flat_type))
    (block))
  (decl_def
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
    (long_flag
      (long_flag_identifier))
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
    (long_flag
      (long_flag_identifier))
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
          (long_flag_identifier))))
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
          (long_flag_identifier))
        (flag_capsule
          (param_short_flag
            (param_short_flag_identifier)))))
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
          (long_flag_identifier))
        (param_type
          (flat_type))))
    (block)))

======
def-010-short-flag
======

def test [
  -?
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (param_short_flag
          (param_short_flag_identifier))))
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
        (param_short_flag
          (param_short_flag_identifier))
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
          (long_flag_identifier))
        (flag_capsule
          (param_short_flag
            (param_short_flag_identifier)))))
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
          (long_flag_identifier))
        (flag_capsule
          (param_short_flag
            (param_short_flag_identifier)))
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

======
def-032-parameters-with-defaults
======

def test [
  x: int = 42,
  y: string = (true),
  --zero(-z): string
= hello,
] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (flat_type))
        (param_value
          (val_number)))
      (parameter
        (identifier)
        (param_type
          (flat_type))
        (param_value
          (expr_parenthesized
            (pipeline
              (pipe_element
                (val_bool))))))
      (parameter
        (param_long_flag
          (long_flag_identifier))
        (flag_capsule
          (param_short_flag
            (param_short_flag_identifier)))
        (param_type
          (flat_type))
        (param_value
          (val_string))))
    (block)))

======
def-033-types-with-completion
======

def test [
  x: int@cmd,
  y: string@"cmd",
  --zero(-z): list<string@cmd>
= hello,
  --one=one: int
] {}

-----

(nu_script
  (decl_def
    unquoted_name: (cmd_identifier)
    parameters: (parameter_bracks
      (parameter
        param_name: (identifier)
        (param_type
          type: (flat_type)
          completion: (param_cmd
            unquoted_name: (cmd_identifier))))
      (parameter
        param_name: (identifier)
        (param_type
          type: (flat_type)
          completion: (param_cmd
            quoted_name: (val_string
              (string_content)))))
      (parameter
        param_long_flag: (param_long_flag
          (long_flag_identifier))
        flag_capsule: (flag_capsule
          (param_short_flag
            name: (param_short_flag_identifier)))
        (param_type
          type: (list_type
            type: (flat_type)
            completion: (param_cmd
              unquoted_name: (cmd_identifier))))
        (param_value
          param_value: (val_string)))
      (parameter
        param_long_flag: (param_long_flag
          (long_flag_identifier))
        (param_value
          param_value: (val_string))
        (param_type
          type: (flat_type))))
    body: (block)))

======
def-034-types-multiline-collection
======

def open-pr [
    pr: record<
        branch: string
        title: string
        body: string
    >
] {}

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
            (flat_type)
            (identifier)
            (flat_type)
            (identifier)
            (flat_type)))))
    (block)))

======
def-035-composite-types
======

def composite-type [
    input: oneof<
      int
      list<record>
    >
]: oneof<int, bool> -> oneof<nothing,
oneof<int, bool>> {}

-----

(nu_script
  (decl_def
    unquoted_name: (cmd_identifier)
    parameters: (parameter_bracks
      (parameter
        param_name: (identifier)
        (param_type
          type: (composite_type
            type: (flat_type)
            type: (list_type
              type: (flat_type))))))
    return_type: (returns
      type: (composite_type
        type: (flat_type)
        type: (flat_type))
      type: (composite_type
        type: (flat_type)
        type: (composite_type
          type: (flat_type)
          type: (flat_type))))
    body: (block)))

=====
def-036-untyped-collection-body
=====

def test [name: record<name>, quoted: record<"name">] {}
def test [name: record<name,>, quoted: record<"name",>] {}
def test [name: record<name, value>, name: record<"name", "value">] {}
def test [name: record<name, value,>, name: record<"name", "value",>] {}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier))))
      (parameter
        (identifier)
        (param_type
          (collection_type
            (val_string
              (string_content))))))
    (block))
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier))))
      (parameter
        (identifier)
        (param_type
          (collection_type
            (val_string
              (string_content))))))
    (block))
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (identifier))))
      (parameter
        (identifier)
        (param_type
          (collection_type
            (val_string
              (string_content))
            (val_string
              (string_content))))))
    (block))
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (collection_type
            (identifier)
            (identifier))))
      (parameter
        (identifier)
        (param_type
          (collection_type
            (val_string
              (string_content))
            (val_string
              (string_content))))))
    (block)))
