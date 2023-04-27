;;; ---
;;; keywords
[
    "def"
    "def-env"
    "alias"
    "export-env"
    "export"
    "extern"

    "let"
    "let-env"
    "mut"
    "const"

    "hide-env"

    "source"
    "source-env"

    "overlay"
    "register"

    "loop"
    "while"
    "error"

    "do"
    "if"
    "else"
    "try"
    "catch"
    "match"

    "break"
    "continue"
    "return"

] @keyword

(hide_mod "hide" @keyword)
(decl_use "use" @keyword)

(ctrl_for 
  "for" @keyword
  "in" @keyword)
(overlay_list "list" @keyword.storage.modifier)
(overlay_hide "hide" @keyword.storage.modifier)
(overlay_new "new" @keyword.storage.modifier)
(overlay_use
  "use" @keyword.storage.modifier
  "as" @keyword
  )
(ctrl_error "make" @keyword.storage.modifier)

;;; ---
;;; literals
(val_number) @constant.numeric
(val_duration
  unit: [
 "ns" "µs" "us" "ms" "sec" "min" "hr" "day" "wk"
 ] @variable.parameter)
(val_filesize
  unit: [
    "b" "B"

    "kb" "kB" "Kb" "KB"
    "mb" "mB" "Mb" "MB"
    "gb" "gB" "Gb" "GB"
    "tb" "tB" "Tb" "TB"
    "pb" "pB" "Pb" "PB"
    "eb" "eB" "Eb" "EB"
    "zb" "zB" "Zb" "ZB"

    "kib" "kiB" "kIB" "kIb" "Kib" "KIb" "KIB"
    "mib" "miB" "mIB" "mIb" "Mib" "MIb" "MIB"
    "gib" "giB" "gIB" "gIb" "Gib" "GIb" "GIB"
    "tib" "tiB" "tIB" "tIb" "Tib" "TIb" "TIB"
    "pib" "piB" "pIB" "pIb" "Pib" "PIb" "PIB"
    "eib" "eiB" "eIB" "eIb" "Eib" "EIb" "EIB"
    "zib" "ziB" "zIB" "zIb" "Zib" "ZIb" "ZIB"
  ] @variable.parameter)
(val_binary
  [
   "0b"
   "0o"
   "0x"
  ] @constant.numeric
  "[" @punctuation.bracket
  digit: [ 
      "," @punctuation.delimiter
      (hex_digit) @constant.number
  ]
  "]" @punctuation.bracket
  ) @constant.numeric
(val_bool) @constant.builtin
(val_nothing) @constant.builtin
(val_string) @string
(inter_escape_sequence) @constant.character.escape
(escape_sequence) @constant.character.escape
(val_interpolated
  [
   "$\""
   "$\'"
   "\""
   "\'"
   ] @string)
(unescaped_interpolated_content) @string
(escaped_interpolated_content) @string
(expr_interpolated
  [
   "(" ")"
   ] @variable.parameter)

;;; ---
;;; operators
(expr_binary
  [
    "+"
    "-"
    "*"
    "/"
    "mod"
    "//"
    "**"
    "=="
    "!="
    "<"
    "<="
    ">"
    ">="
    "=~"
    "!~"
    "and"
    "or"
    "xor"
    "bit-or"
    "bit-xor"
    "bit-and"
    "bit-shl"
    "bit-shr"
    "in"
    "not-in"
    "starts-with"
    "ends-with"
] @operator )

(assignment
  [
   "="
   "+="
   "-="
   "*="
   "/="
   "++="
  ] @operator)

(expr_unary
  ["not" "-"] @operator)

(val_range
  [
   ".."
   "..="
   "..<"
  ] @operator)

["=>" "=" "|"] @operator

[
 "o>"   "out>"
 "e>"   "err>"
 "e+o>" "err+out>"
 "o+e>" "out+err>"
] @special

;;; ---
;;; punctuation
[
 ","
 ";"
] @punctuation.delimiter

(param_short_flag
  "-" @punctuation.delimiter)
(short_flag
  "-" @punctuation.delimiter)
(param_long_flag
    ["--"] @punctuation.delimiter)
(long_flag
    ["--"] @punctuation.delimiter)
(param_rest
  "..." @punctuation.delimiter)
(param_type
  [":"] @punctuation.special)
(param_value
  ["="] @punctuation.special)
(param_cmd
  ["@"] @punctuation.special)
(param_opt
  ["?"] @punctuation.special)

[
 "(" ")"
 "{" "}"
 "[" "]"
 ] @punctuation.bracket

;;; ---
;;; identifiers
(param_rest
  name: (_) @variable.parameter)
(param_opt
  name: (_) @variable.parameter)
(parameter
  param_name: (_) @variable.parameter)
(param_cmd
  (cmd_identifier) @string)
(param_long_flag) @variable.parameter
(param_short_flag) @variable.parameter

(short_flag) @variable.parameter
(long_flag) @variable.parameter

(val_variable
  ["$"] @variable.parameter)

(scope_pattern
  [(wild_card) @function])

(cmd_identifier) @function

(cmd_head_sub
  "^" @punctuation.delimiter
  head: (_) @function
  sub: (_) @function.method)
(cmd_prefix_head_sub
  prefix: (_) @namespace
  "^" @punctuation.delimiter
  head: (_) @function
  sub: (_) @function.method)

(path) @variable.parameter

;;; ---
;;; types
(param_type
 [
    "any" "binary" "block" "bool" "cell-path" "closure" "cond"
    "datetime" "directory" "duration" "directory" "duration"
    "error" "expr" "float" "decimal" "filesize" "full-cell-path"
    "glob" "int" "import-pattern" "keyword" "math" "nothing"
    "number" "one-of" "operator" "path" "range" "record" "signature"
    "string" "table" "variable" "var-with-opt-type" 
     (list_type
       "list" @type.enum
       ["<" ">"] @punctuation.bracket
       )
 ] @type.builtin

 )



(comment) @comment
