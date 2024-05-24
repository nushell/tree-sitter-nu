[
  (expr_parenthesized)
  (parameter_bracks)

  (val_record)
  (val_list)
  (val_closure)
  (val_table)

  (block)
] @indent.begin

(("|") @indent.begin
  (#set! indent.immediate 1))

[
  "}"
  "]"
  ")"
] @indent.end

[
  "}"
  "]"
  ")"
] @indent.branch

(comment) @indent.auto
