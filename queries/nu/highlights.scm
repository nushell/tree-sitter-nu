;;; ---
;;; keywords
[
    "alias"
    "break"
    "const"
    "continue"
    "def"
    "export"
    "export alias"
    "export const"
    "export def"
    "export extern"
    "export module"
    "export use"
    "export-env"
    "extern"
    "for"
    "hide"
    "if"
    "let"
    "loop"
    "match"
    "module"
    "mut"
    "overlay"
    "overlay hide"
    "overlay new"
    "overlay use"
    "plugin use"
    "return"
    "source"
    "source-env"
    "try"
    "use"
    "where"
    "while"
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
    "="
    "+="
    "++="
    "-="
    "*="
    "/="
    "like"
    "not-like"
    "not"
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
    "="
    "+="
    "++="
    "-="
    "*="
    "/="
    "like"
    "not-like"
    "not"
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

(param_long_flag ["--"] @punctuation.delimiter)
(long_flag ["--"] @punctuation.delimiter)
(short_flag ["-"] @punctuation.delimiter)
(long_flag ["="] @punctuation.special)
(short_flag ["="] @punctuation.special)
(param_short_flag ["-"] @punctuation.delimiter)
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
    "...["
    "...("
    "...{"
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

(param_long_flag (long_flag_identifier) @attribute)
(param_short_flag (param_short_flag_identifier) @attribute)

(short_flag (short_flag_identifier) @attribute)
(long_flag_identifier) @attribute

(scope_pattern [(wild_card) @function])

(cmd_identifier) @function
; generated with Nu 0.100.1
; help commands | 
;    where command_type == built-in or command_type == plugin |
;    get name | 
;    each { $'"($in)"'} | 
;    str join ' ' | 
;    str wrap 
(command
  head: [
    (cmd_identifier) @function.builtin
    (#any-of? @function.builtin
        "all" "ansi" "ansi gradient" "ansi link" "ansi strip" "any" "append" "ast"
        "bits" "bits and" "bits not" "bits or" "bits rol" "bits ror" "bits shl" "bits
        shr" "bits xor" "bytes" "bytes add" "bytes at" "bytes build" "bytes collect"
        "bytes ends-with" "bytes index-of" "bytes length" "bytes remove" "bytes replace"
        "bytes reverse" "bytes starts-with" "cal" "cd" "char" "chunks" "clear" "collect"
        "columns" "commandline" "commandline edit" "commandline get-cursor" "commandline
        set-cursor" "compact" "complete" "config" "config env" "config nu" "config
        reset" "cp" "date" "date format" "date humanize" "date list-timezone" "date now"
        "date to-record" "date to-table" "date to-timezone" "debug" "debug info" "debug
        profile" "decode" "decode base32" "decode base32hex" "decode base64" "decode
        hex" "default" "describe" "detect columns" "do" "drop" "drop column" "drop nth"
        "dt" "dt add" "dt diff" "dt format" "dt now" "dt part" "dt to" "dt utcnow" "du"
        "each" "each while" "echo" "emoji" "encode" "encode base32" "encode base32hex"
        "encode base64" "encode hex" "enumerate" "error make" "every" "exec" "exit"
        "explain" "explore" "explore ir" "file" "fill" "filter" "find" "first" "flatten"
        "fmt" "format" "format date" "format duration" "format filesize" "format
        pattern" "from" "from bz2" "from csv" "from eml" "from gz" "from ics" "from ini"
        "from json" "from msgpack" "from msgpackz" "from nuon" "from ods" "from parquet"
        "from plist" "from png" "from ssv" "from toml" "from tsv" "from url" "from vcf"
        "from xlsx" "from xml" "from xz" "from yaml" "from yml" "from zst" "generate"
        "get" "gitql" "glob" "grid" "group-by" "gstat" "hash" "hash md5" "hash sha256"
        "headers" "help" "help aliases" "help commands" "help escapes" "help externs"
        "help modules" "help operators" "hide-env" "histogram" "history" "history
        import" "history session" "http" "http delete" "http get" "http head" "http
        options" "http patch" "http post" "http put" "ignore" "inc" "input" "input list"
        "input listen" "insert" "inspect" "interleave" "into" "into binary" "into bits"
        "into bool" "into cell-path" "into datetime" "into duration" "into filesize"
        "into float" "into glob" "into int" "into record" "into sqlite" "into string"
        "into value" "is-admin" "is-empty" "is-not-empty" "is-terminal" "items" "join"
        "json path" "jwalk" "keybindings" "keybindings default" "keybindings list"
        "keybindings listen" "kill" "last" "length" "let-env" "lines" "load-env" "math"
        "math abs" "math arccos" "math arccosh" "math arcsin" "math arcsinh" "math
        arctan" "math arctanh" "math avg" "math ceil" "math cos" "math cosh" "math exp"
        "math floor" "math ln" "math log" "math max" "math median" "math min" "math
        mode" "math product" "math round" "math sin" "math sinh" "math sqrt" "math
        stddev" "math sum" "math tan" "math tanh" "math variance" "merge" "metadata"
        "metadata access" "metadata set" "mkdir" "mktemp" "move" "mv" "nu-check" "nu-
        highlight" "open" "overlay list" "panic" "par-each" "parse" "path" "path
        basename" "path dirname" "path exists" "path expand" "path join" "path parse"
        "path relative-to" "path split" "path type" "plugin" "plugin add" "plugin list"
        "plugin rm" "plugin stop" "polars" "polars agg" "polars agg-groups" "polars all-
        false" "polars all-true" "polars append" "polars arg-max" "polars arg-min"
        "polars arg-sort" "polars arg-true" "polars arg-unique" "polars arg-where"
        "polars as" "polars as-date" "polars as-datetime" "polars cache" "polars cast"
        "polars col" "polars collect" "polars columns" "polars concat" "polars concat-
        str" "polars contains" "polars count" "polars count-null" "polars cumulative"
        "polars datepart" "polars decimal" "polars drop" "polars drop-duplicates"
        "polars drop-nulls" "polars dummies" "polars explode" "polars expr-not" "polars
        fetch" "polars fill-nan" "polars fill-null" "polars filter" "polars filter-with"
        "polars first" "polars flatten" "polars get" "polars get-day" "polars get-hour"
        "polars get-minute" "polars get-month" "polars get-nanosecond" "polars get-
        ordinal" "polars get-second" "polars get-week" "polars get-weekday" "polars get-
        year" "polars group-by" "polars implode" "polars integer" "polars into-df"
        "polars into-lazy" "polars into-nu" "polars is-duplicated" "polars is-in"
        "polars is-not-null" "polars is-null" "polars is-unique" "polars join" "polars
        last" "polars len" "polars lit" "polars lowercase" "polars max" "polars mean"
        "polars median" "polars min" "polars n-unique" "polars not" "polars open"
        "polars otherwise" "polars pivot" "polars profile" "polars quantile" "polars
        query" "polars rename" "polars replace" "polars replace-all" "polars reverse"
        "polars rolling" "polars sample" "polars save" "polars schema" "polars select"
        "polars set" "polars set-with-idx" "polars shape" "polars shift" "polars slice"
        "polars sort-by" "polars std" "polars store-get" "polars store-ls" "polars
        store-rm" "polars str-join" "polars str-lengths" "polars str-slice" "polars
        strftime" "polars sum" "polars summary" "polars take" "polars unique" "polars
        unnest" "polars unpivot" "polars uppercase" "polars value-counts" "polars var"
        "polars when" "polars with-column" "port" "prepend" "print" "ps" "query" "query
        db" "query git" "query json" "query web" "query webpage-info" "query xml"
        "random" "random binary" "random bool" "random chars" "random dice" "random
        float" "random int" "random uuid" "range" "reduce" "regex" "reject" "rename"
        "reverse" "rm" "roll" "roll down" "roll left" "roll right" "roll up" "rotate"
        "run-external" "save" "schema" "scope" "scope aliases" "scope commands" "scope
        engine-stats" "scope externs" "scope modules" "scope variables" "select" "seq"
        "seq char" "seq date" "shuffle" "skip" "skip until" "skip while" "sleep" "sort"
        "sort-by" "split" "split cell-path" "split chars" "split column" "split list"
        "split row" "split words" "split-by" "start" "stor" "stor create" "stor delete"
        "stor export" "stor import" "stor insert" "stor open" "stor reset" "stor update"
        "str" "str bexpand" "str camel-case" "str capitalize" "str compress" "str
        contains" "str decompress" "str dedent" "str deunicode" "str distance" "str
        downcase" "str ends-with" "str expand" "str indent" "str index-of" "str join"
        "str kebab-case" "str length" "str pascal-case" "str replace" "str reverse" "str
        screaming-snake-case" "str similarity" "str snake-case" "str starts-with" "str
        stats" "str substring" "str title-case" "str trim" "str upcase" "str wrap" "sys"
        "sys cpu" "sys disks" "sys host" "sys mem" "sys net" "sys temp" "sys users"
        "table" "take" "take until" "take while" "tee" "term" "term query" "term size"
        "timeit" "to" "to bz2" "to csv" "to gz" "to html" "to json" "to md" "to msgpack"
        "to msgpackz" "to nuon" "to parquet" "to plist" "to png" "to text" "to toml" "to
        tsv" "to xml" "to xz" "to yaml" "to zst" "touch" "transpose" "tutor" "ulimit"
        "uname" "uniq" "uniq-by" "update" "update cells" "upsert" "url" "url build-
        query" "url decode" "url encode" "url join" "url parse" "url split-query"
        "utouch" "values" "version" "view" "view files" "view ir" "view source" "view
        span" "watch" "which" "whoami" "window" "with-env" "wrap" "zip"
    )
  ])

(command
    "^" @punctuation.delimiter
    head: (_) @function
)

"where" @function.builtin

(path
  ["." "?"] @punctuation.delimiter
) @variable.parameter

(stmt_let (identifier) @variable)

(val_variable
  "$"? @punctuation.special
  "...$"? @punctuation.special
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
