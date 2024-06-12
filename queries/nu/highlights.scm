;;; ---
;;; keywords
[
    "def"
    "alias"
    "export-env"
    "export"
    "extern"
    "module"

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
    "in" @keyword
)
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
(val_number) @number
(val_duration unit: _ @variable.parameter)
(val_filesize unit: _ @variable.parameter)
(val_binary
    [
       "0b"
       "0o"
       "0x"
    ] @number
    "[" @punctuation.bracket
    digit: [
        "," @punctuation.delimiter
        (hex_digit) @number
    ]
    "]" @punctuation.bracket
) @number
(val_bool) @constant.builtin
(val_nothing) @constant.builtin
(val_string) @string
arg_str: (val_string) @variable.parameter
file_path: (val_string) @variable.parameter
(val_date) @number
(inter_escape_sequence) @constant.character.escape
(escape_sequence) @constant.character.escape
(val_interpolated [
    "$\""
    "$\'"
    "\""
    "\'"
] @string)
(unescaped_interpolated_content) @string
(escaped_interpolated_content) @string
(expr_interpolated ["(" ")"] @variable.parameter)

;;; ---
;;; operators
(expr_binary [
    "+"
    "-"
    "*"
    "/"
    "mod"
    "//"
    "++"
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

(where_command [
    "+"
    "-"
    "*"
    "/"
    "mod"
    "//"
    "++"
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
] @operator)

(assignment [
    "="
    "+="
    "-="
    "*="
    "/="
    "++="
] @operator)

(expr_unary ["not" "-"] @operator)

(val_range [
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
] @operator

;;; ---
;;; punctuation
[
    ","
    ";"
] @punctuation.special

(param_short_flag "-" @punctuation.delimiter)
(param_long_flag ["--"] @punctuation.delimiter)
(long_flag ["--"] @punctuation.delimiter)
(param_rest "..." @punctuation.delimiter)
(param_type [":"] @punctuation.special)
(param_value ["="] @punctuation.special)
(param_cmd ["@"] @punctuation.special)
(param_opt ["?"] @punctuation.special)
(returns "->" @punctuation.special)

[
    "(" ")"
    "{" "}"
    "[" "]"
] @punctuation.bracket

(val_record
  (record_entry ":" @punctuation.delimiter))
key: (identifier) @property

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

(scope_pattern [(wild_card) @function])

(cmd_identifier) @function

(command
    "^" @punctuation.delimiter
    head: (_) @function
)

"where" @function

(path
  ["." "?"] @punctuation.delimiter
) @variable.parameter

(val_variable
  "$" @punctuation.special
  [
   (identifier) @variable
   "in" @special
   "nu" @namespace
   "env" @constant
  ]
) @none

(record_entry
  ":" @punctuation.special)

;;; ---
;;; types
(flat_type) @type
(list_type
    "list" @type.enum
    ["<" ">"] @punctuation.bracket
)
(collection_type
    ["record" "table"] @type.enum
    "<" @punctuation.bracket
    key: (_) @variable.parameter
    ["," ":"] @punctuation.special
    ">" @punctuation.bracket
)

(shebang) @keyword.directive
(comment) @comment
(
 (comment) @comment.documentation
 (decl_def)
)
(
 (parameter)
 (comment) @comment.documentation
)
