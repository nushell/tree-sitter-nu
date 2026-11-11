=====
type-001-smoke-test
=====

type Point = record<x: float, y: float>
type my-id = oneof<int, string>
export type Polygon = list<Point>

-----

(nu_script
  (decl_type
    (flat_type)
    (collection_type
      (identifier)
      (flat_type)
      (identifier)
      (flat_type)))
  (decl_type
    (flat_type)
    (composite_type
      (flat_type)
      (flat_type)))
  (decl_type
    (flat_type)
    (list_type
      (flat_type))))

=====
type-002-alias-usage
=====

def area [p: Polygon, --id: my-id]: nothing -> Point { }
let pt: Point = {x: 1.0, y: 2.0}

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (flat_type)))
      (parameter
        (param_long_flag
          (long_flag_identifier))
        (param_type
          (flat_type))))
    (returns
      (flat_type)
      (flat_type))
    (block))
  (stmt_let
    (identifier)
    (param_type
      (flat_type))
    (pipeline
      (pipe_element
        (val_record
          (record_body
            (record_entry
              (identifier)
              (val_number))
            (record_entry
              (identifier)
              (val_number))))))))

=====
type-003-names-sharing-builtin-prefixes
=====

def f [a: listing, b: table_row, c: records, d: oneof_x, e: list, f: table]: listing -> int { }

-----

(nu_script
  (decl_def
    (cmd_identifier)
    (parameter_bracks
      (parameter
        (identifier)
        (param_type
          (flat_type)))
      (parameter
        (identifier)
        (param_type
          (flat_type)))
      (parameter
        (identifier)
        (param_type
          (flat_type)))
      (parameter
        (identifier)
        (param_type
          (flat_type)))
      (parameter
        (identifier)
        (param_type
          (flat_type)))
      (parameter
        (identifier)
        (param_type
          (flat_type))))
    (returns
      (flat_type)
      (flat_type))
    (block)))
