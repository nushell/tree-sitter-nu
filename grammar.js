/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
module.exports = grammar({
  name: "nu",

  word: ($) => $.identifier,

  extras: ($) => [/[ \t]/, $.comment],

  inline: ($) => [
    $._do_expression,
    $._flag_value,
    $._item_expression,
    $._match_expression,
    $._separator,
    $._spread_listish,
    $._spread_recordish,
    $._stringish,
    $._terminator,
  ],

  // externals: $ => [
  // ],

  conflicts: ($) => [
    [$._binary_predicate_parenthesized],
    [$._block_body, $.record_body, $.val_closure],
    [$._block_body, $.shebang],
    [$._block_body, $.val_closure],
    [$._expression_parenthesized, $._expr_binary_expression_parenthesized],
    [$._match_pattern_list, $.val_list],
    [$._match_pattern_record, $.val_record],
    [$._match_pattern_record_variable, $._value],
    [$._match_pattern_value, $._value],
    [$._parenthesized_body],
    [$._val_number_decimal],
    [$.block, $.val_closure],
    [$.block, $.val_record],
    [$.ctrl_if_parenthesized],
    [$.ctrl_try_parenthesized],
    [$.expr_binary_parenthesized],
    [$.list_body, $.val_table],
    [$.parameter, $.param_type, $.param_value],
    [$.pipeline],
    [$.pipeline_parenthesized],
  ],

  rules: {
    /// File

    nu_script: ($) => seq(optional($.shebang), optional($._block_body)),

    shebang: (_$) => seq(repeat(_$._newline), "#!", /.*\r?\n?/),

    ...block_body_rules(),

    ...parenthesized_body_rules(),

    _block_body: ($) =>
      general_body_rules(
        "",
        $._block_body_statement,
        $._terminator,
        null,
        null,
        $._terminator,
      ),

    /// Identifiers
    // NOTE:
    // probably needs an external scanner for cmd_identifier
    // to behave exactly the same as the nushell parser
    cmd_identifier: ($) => {
      const excluded = "\\[\\]\\{}<>=\"`':";
      const pattern_repeat = repeat(none_of(excluded));
      const pattern_one = repeat1(none_of(excluded));
      return choice(
        token(
          prec(PREC().low, seq(none_of(excluded + "^#$\\-"), pattern_repeat)),
        ),
        ...Object.values(KEYWORD()).map((x) =>
          token(seq(x, token.immediate(pattern_repeat))),
        ),
        ...Object.values(MODIFIER()).map((x) =>
          token(seq(x, token.immediate(pattern_repeat))),
        ),
        ...Object.values(SPECIAL()).map((x) =>
          seq(x, token.immediate(pattern_one)),
        ),
        seq(
          seq(
            $._val_number_decimal,
            optional(
              choice(
                alias($.duration_unit, "_unit"),
                alias($.filesize_unit, "_unit"),
              ),
            ),
          ),
          token.immediate(prec(PREC().lowest, pattern_one)),
        ),
      );
    },
    identifier: (_$) => _identifier_rules(false),

    long_flag_identifier: (_$) =>
      token.immediate(/[0-9\p{XID_Start}_][\p{XID_Continue}?_-]*/),

    _command_name: ($) =>
      choice(
        field("unquoted_name", $.cmd_identifier),
        field("quoted_name", $.val_string),
      ),

    _variable_name: ($) =>
      choice(
        field("var_name", $.identifier),
        field("dollar_name", $.val_variable),
      ),

    // remove newline characters from extras to reduce ambiguity
    // manually controlled by adding the following to parenthesized rules
    _newline: (_$) => /\r?\n/,
    _space: (_$) => /[ \t]+/,
    _separator: ($) => choice($._space, $._newline),
    _terminator: ($) => choice(PUNC().semicolon, $._newline),
    _pipe_separator: ($) =>
      repeat1(seq(repeat($._newline), choice(PUNC().pipe, ...REDIR_PIPE()))),

    /// Top Level Items

    decl_def: ($) =>
      seq(
        optional(MODIFIER().visibility),
        KEYWORD().def,
        repeat($.long_flag),
        field("name", $._command_name),
        field("parameters", choice($.parameter_parens, $.parameter_bracks)),
        field("return_type", optional($.returns)),
        field("body", $.block),
      ),

    decl_export: ($) => seq(KEYWORD().export_env, field("body", $.block)),

    decl_extern: ($) =>
      prec.right(
        1,
        seq(
          optional(MODIFIER().visibility),
          KEYWORD().extern,
          field("name", $._command_name),
          field("signature", choice($.parameter_parens, $.parameter_bracks)),
          field("body", optional($.block)),
        ),
      ),

    decl_module: ($) =>
      seq(
        optional(MODIFIER().visibility),
        KEYWORD().module,
        field("name", $._command_name),
        optional(field("body", $.block)),
      ),

    decl_use: ($) =>
      prec.right(
        1,
        seq(
          optional(MODIFIER().visibility),
          KEYWORD().use,
          field("module", choice($.unquoted, $._stringish)),
          optional(field("import_pattern", $.scope_pattern)),
        ),
      ),

    /// Return types
    returns: ($) =>
      seq(optional(PUNC().colon), choice($._multiple_types, $._one_type)),

    _one_type: ($) =>
      seq($._type_annotation, PUNC().thin_arrow, $._type_annotation),

    _multiple_types: ($) =>
      seq(
        BRACK().open_brack,
        optional(
          general_body_rules("", $._one_type, $._entry_separator, $._newline),
        ),
        BRACK().close_brack,
      ),

    /// Parameters

    parameter_parens: ($) =>
      seq(
        BRACK().open_paren,
        repeat($._newline),
        repeat($.parameter),
        BRACK().close_paren,
      ),

    parameter_bracks: ($) =>
      seq(
        BRACK().open_brack,
        repeat($._newline),
        repeat($.parameter),
        BRACK().close_brack,
      ),

    parameter_pipes: ($) =>
      seq(PUNC().pipe, repeat($._newline), repeat($.parameter), PUNC().pipe),

    parameter: ($) =>
      seq(
        choice(
          $._param_name,
          seq(
            field("param_long_flag", $.param_long_flag),
            field("flag_capsule", optional($.flag_capsule)),
          ),
        ),
        repeat(choice($.param_type, $.param_value)),
        repeat(choice($._newline, PUNC().comma)),
      ),

    _param_name: ($) =>
      choice(
        field("param_rest", $.param_rest),
        field("param_optional", $.param_opt),
        field("param_name", seq(optional("$"), $.identifier)),
        field("param_short_flag", $.param_short_flag),
      ),

    param_type: ($) =>
      seq(
        repeat($._newline),
        PUNC().colon,
        repeat($._newline),
        $._type_annotation,
        field("completion", optional($.param_cmd)),
      ),

    param_value: ($) =>
      seq(
        repeat($._newline),
        PUNC().eq,
        repeat($._newline),
        field(
          "param_value",
          choice(
            $._item_expression,
            alias($._unquoted_in_list, $.val_string),
            alias($._unquoted_in_list_with_expr, $.val_string),
          ),
        ),
      ),

    _type_annotation: ($) =>
      field("type", choice($.list_type, $.collection_type, $.flat_type)),

    _all_type: ($) =>
      field("type", choice($.list_type, $.collection_type, $.flat_type)),

    flat_type: (_$) => field("flat_type", FLAT_TYPES()),

    collection_type: ($) => {
      const key = field(
        "key",
        choice($.identifier, alias($.val_string, $.identifier)),
      );

      return seq(
        choice("record", "table"),
        seq(
          token.immediate(BRACK().open_angle),
          repeat(
            seq(
              seq(
                key,
                optional(
                  seq(
                    PUNC().colon,
                    $._all_type,
                    field("completion", optional($.param_cmd)),
                  ),
                ),
              ),
              optional(PUNC().comma),
            ),
          ),
          BRACK().close_angle,
        ),
      );
    },

    list_type: ($) =>
      seq(
        "list",
        seq(
          token.immediate(BRACK().open_angle),
          field("inner", optional($._all_type)),
          field("completion", optional($.param_cmd)),
          BRACK().close_angle,
        ),
      ),

    param_cmd: ($) =>
      seq(token.immediate(PUNC().at), field("name", $._command_name)),

    param_rest: ($) =>
      seq(PUNC().rest, optional(PUNC().dollar), field("name", $.identifier)),

    param_opt: ($) =>
      seq(field("name", $.identifier), token.immediate(PUNC().question)),

    param_long_flag: ($) => seq(OPR().long_flag, $.long_flag_identifier),

    flag_capsule: ($) =>
      seq(BRACK().open_paren, $.param_short_flag, BRACK().close_paren),

    param_short_flag: ($) =>
      seq(OPR().minus, field("name", $.param_short_flag_identifier)),

    param_short_flag_identifier: (_$) =>
      token.immediate(/[\p{Punctuation}\p{Symbol}\p{XID_Continue}]/),

    /// Controls

    _control: ($) =>
      prec(
        STATEMENT_PREC().control,
        choice($._ctrl_statement, $._ctrl_expression),
      ),

    // control statements cannot be used in pipeline because they
    // do not return values
    _ctrl_statement: ($) =>
      choice($.ctrl_for, $.ctrl_loop, $.ctrl_while, $.ctrl_error),

    // control expressions *return values and can be used in pipelines
    //
    // * `break` and `continue` do not return values (yet?) but can be
    // used in pipelines
    _ctrl_expression: ($) =>
      choice(
        field("ctrl_break", KEYWORD().break),
        field("ctrl_continue", KEYWORD().continue),
        $.ctrl_do,
        $.ctrl_if,
        $.ctrl_try,
        $.ctrl_match,
        $.ctrl_return,
      ),

    _ctrl_expression_parenthesized: ($) =>
      choice(
        field("ctrl_break", KEYWORD().break),
        field("ctrl_continue", KEYWORD().continue),
        alias($.ctrl_do_parenthesized, $.ctrl_do),
        alias($.ctrl_if_parenthesized, $.ctrl_if),
        alias($.ctrl_try_parenthesized, $.ctrl_try),
        $.ctrl_match,
        $.ctrl_return,
      ),

    // Standalone Controls

    ctrl_for: ($) =>
      seq(
        // `for` has the `--numbered` flag
        KEYWORD().for,
        optional($._flag),
        field("looping_var", $._variable_name),
        optional($._flag),
        KEYWORD().in,
        optional($._flag),
        field("iterable", $._expression),
        optional($._flag),
        field("body", $.block),
      ),

    ctrl_loop: ($) => seq(KEYWORD().loop, field("body", $.block)),

    ctrl_error: ($) =>
      seq(
        KEYWORD().error,
        MODIFIER().error_make,
        optional($._flag),
        field("error_record", $.val_record),
      ),

    ctrl_while: ($) =>
      seq(
        KEYWORD().while,
        field("condition", $._expression),
        field("body", $.block),
      ),

    // Nestable Controls
    _do_expression: ($) =>
      choice(
        $._item_expression,
        $._flag,
        alias($.unquoted, $.val_string),
        alias($._unquoted_with_expr, $.val_string),
      ),

    ctrl_do: ($) =>
      prec.left(
        PREC().low,
        seq(
          KEYWORD().do,
          repeat($._flag),
          choice($._blosure, $.val_variable),
          repeat($._do_expression),
        ),
      ),

    ctrl_do_parenthesized: ($) =>
      prec.left(
        PREC().low,
        seq(
          KEYWORD().do,
          optional(seq(repeat($._flags_parenthesized))),
          repeat1($._separator),
          choice($._blosure, $.val_variable),
          repeat(seq(repeat($._newline), $._do_expression)),
        ),
      ),

    ctrl_if: _ctrl_if_rule(false),
    ctrl_if_parenthesized: _ctrl_if_rule(true),

    ctrl_match: ($) =>
      seq(
        KEYWORD().match,
        field(
          "scrutinee",
          choice($._item_expression, alias($.unquoted, $.val_string)),
        ),
        BRACK().open_brace,
        optional(
          general_body_rules(
            "",
            choice($.match_arm, $.default_arm),
            $._entry_separator,
            $._newline,
          ),
        ),
        BRACK().close_brace,
      ),

    match_arm: ($) =>
      seq(
        field("pattern", $.match_pattern),
        PUNC().fat_arrow,
        field("expression", $._match_expression),
      ),

    default_arm: ($) =>
      seq(
        field("default_pattern", PUNC().underscore),
        PUNC().fat_arrow,
        field("expression", $._match_expression),
      ),

    _match_expression: ($) =>
      choice($._item_expression, prec.dynamic(10, $.block)),

    match_pattern: ($) =>
      choice(
        seq(PUNC().underscore, $.match_guard),
        seq($._match_pattern, optional($.match_guard)),
        seq($._match_pattern, repeat(seq(PUNC().pipe, $._match_pattern))),
      ),

    _match_pattern: ($) =>
      choice($._match_pattern_expression, alias($.unquoted, $.val_string)),

    match_guard: ($) => seq(KEYWORD().if, $._expression),

    _match_pattern_expression: ($) =>
      choice($._match_pattern_value, $.val_range, $.expr_parenthesized),

    _match_pattern_value: ($) =>
      choice(
        $.val_variable,
        $.val_nothing,
        $.val_bool,
        $.val_number,
        $.val_duration,
        $.val_filesize,
        $.val_binary,
        $.val_string,
        $.val_date,
        alias($._match_pattern_list, $.val_list),
        alias($._match_pattern_record, $.val_record),
        $.val_table,
      ),

    _match_pattern_list: ($) =>
      seq(
        BRACK().open_brack,
        repeat(
          field(
            "item",
            seq(
              choice(
                $._match_pattern_expression,
                alias($._unquoted_in_list, $.val_string),
              ),
              optional(PUNC().comma),
            ),
          ),
        ),
        optional(
          field(
            "rest",
            choice(
              alias($._match_pattern_rest, $.val_variable),
              OPR().range_inclusive,
            ),
          ),
        ),
        BRACK().close_brack,
      ),

    _match_pattern_rest: ($) =>
      seq(
        OPR().range_inclusive,
        seq(token.immediate(PUNC().dollar), $.identifier),
      ),

    _match_pattern_record: ($) =>
      seq(
        BRACK().open_brace,
        repeat(
          field(
            "entry",
            choice($.record_entry, $._match_pattern_record_variable),
          ),
        ),
        BRACK().close_brace,
        optional($.cell_path),
      ),

    _match_pattern_record_variable: ($) =>
      seq($.val_variable, optional(PUNC().comma)),

    ctrl_try: _ctrl_try_rule(false),
    ctrl_try_parenthesized: _ctrl_try_rule(true),

    ctrl_return: ($) =>
      choice(
        prec(
          1,
          seq(
            KEYWORD().return,
            choice(
              $._expression,
              $.ctrl_do,
              $.ctrl_if,
              $.ctrl_try,
              $.ctrl_match,
            ),
          ),
        ),
        KEYWORD().return,
      ),

    /// Pipelines

    pipe_element: ($) =>
      choice(
        seq(
          _env_variable_rule(false, $),
          $._expression,
          optional($.redirection),
        ),
        seq(_env_variable_rule(false, $), $.command),
        $._ctrl_expression,
        $.where_command,
      ),

    pipe_element_parenthesized: ($) =>
      choice(
        seq(
          _env_variable_rule(true, $),
          $._expression_parenthesized,
          optional($.redirection),
        ),
        seq(
          _env_variable_rule(true, $),
          alias($._command_parenthesized, $.command),
        ),
        $._ctrl_expression_parenthesized,
        alias($.where_command_parenthesized, $.where_command),
      ),

    /// Scope Statements

    stmt_source: ($) =>
      seq(
        choice(KEYWORD().source, KEYWORD().source_env),
        field("file", choice(alias($.unquoted, $.val_string), $._stringish)),
      ),

    stmt_register: ($) =>
      prec.left(
        PREC().low,
        seq(
          KEYWORD().register,
          field(
            "plugin",
            choice(alias($.unquoted, $.val_string), $.val_variable),
          ),
          field("signature", optional($.val_record)),
        ),
      ),

    _stmt_hide: ($) => choice($.hide_mod, $.hide_env),

    hide_mod: ($) =>
      prec.right(
        1,
        seq(
          KEYWORD().hide,
          field("module", $._command_name),
          optional($.scope_pattern),
        ),
      ),

    hide_env: ($) =>
      seq(
        KEYWORD().hide_env,
        repeat($._flag),
        field("variable", $._variable_name),
      ),

    _stmt_overlay: ($) =>
      choice($.overlay_hide, $.overlay_list, $.overlay_new, $.overlay_use),

    overlay_list: (_$) => seq(KEYWORD().overlay, MODIFIER().overlay_list),

    overlay_hide: ($) =>
      prec.right(
        5,
        seq(
          KEYWORD().overlay,
          MODIFIER().overlay_hide,
          field("overlay", $._command_name),
        ),
      ),

    overlay_new: ($) =>
      seq(KEYWORD().overlay, MODIFIER().overlay_new, $._command_name),

    overlay_use: ($) =>
      prec.right(
        1,
        seq(
          KEYWORD().overlay,
          MODIFIER().overlay_use,
          repeat($._flag),
          field("overlay", $.identifier),
          repeat($._flag),
          optional(seq(KEYWORD().as, field("rename", $._command_name))),
        ),
      ),

    scope_pattern: ($) =>
      choice(
        field("wildcard", $.wild_card),
        field("command", $._command_name),
        field("command_list", $.command_list),
      ),

    wild_card: (_$) => token("*"),

    command_list: ($) =>
      seq(
        BRACK().open_brack,
        optional(
          general_body_rules(
            "cmd",
            $._command_name,
            $._entry_separator,
            $._newline,
          ),
        ),
        BRACK().close_brack,
      ),

    /// Block

    block: ($) =>
      seq(BRACK().open_brace, optional($._block_body), BRACK().close_brace),

    _blosure: ($) => choice(prec.dynamic(10, $.block), $.val_closure),

    // the where command has a unique argument pattern that breaks the
    // general command parsing, so we handle it separately
    _where_predicate_lhs: ($) =>
      seq(
        choice(alias($.identifier, $.val_string), $.val_number),
        optional(PUNC().question),
        optional($.cell_path),
      ),

    where_command: _where_clause_rule(false),
    where_command_parenthesized: _where_clause_rule(true),

    _binary_predicate: _binary_predicate_rule(false),
    _binary_predicate_parenthesized: _binary_predicate_rule(true),

    _predicate: ($) =>
      choice(
        $.val_bool,
        $.expr_unary,
        $.expr_parenthesized,
        ...PREDICATE().map(([precedence, opr]) =>
          prec.left(
            precedence,
            seq(
              field(
                "lhs",
                choice(
                  $._where_predicate_lhs,
                  $.val_variable,
                  $.expr_parenthesized,
                ),
              ),
              field("opr", opr),
              field(
                "rhs",
                choice(
                  $._value,
                  $.val_range,
                  $.expr_unary,
                  $.expr_parenthesized,
                  alias($.unquoted, $.val_string),
                  alias($._unquoted_with_expr, $.val_string),
                ),
              ),
            ),
          ),
        ),
      ),

    /// Expressions

    _expression: ($) =>
      choice(
        $._value,
        $.expr_binary,
        $.expr_unary,
        $.val_range,
        $.expr_parenthesized,
      ),

    _expression_parenthesized: ($) =>
      choice(
        $._value,
        $.expr_unary,
        $.val_range,
        $.expr_parenthesized,
        alias($.expr_binary_parenthesized, $.expr_binary),
      ),

    /// Composite Expressions

    expr_unary: ($) => {
      const after_not = choice(
        $.val_bool,
        $.expr_parenthesized,
        $.val_variable,
        $.expr_unary,
      );

      return choice(
        // "not" should be followed by space
        // to distinguish from unquoted e.g. $foo == nothing
        seq(alias(token(seq(OPR().not, /\s/)), OPR().not), after_not),
        $._expr_unary_minus,
      );
    },

    _expr_unary_minus: ($) =>
      seq(
        token(OPR().minus),
        seq(
          // ensure the expression immediately follows the
          // opening paren
          token.immediate(BRACK().open_paren),
          $._block_body,
          BRACK().close_paren,
        ),
      ),

    expr_binary: _expr_binary_rule(false),
    expr_binary_parenthesized: _expr_binary_rule(true),

    _expr_binary_expression: ($) =>
      choice($._value, $.expr_binary, $.expr_unary, $.expr_parenthesized),

    _expr_binary_expression_parenthesized: ($) =>
      choice(
        $._value,
        alias($.expr_binary_parenthesized, $.expr_binary),
        $.expr_unary,
        $.expr_parenthesized,
      ),

    expr_parenthesized: ($) =>
      seq(
        BRACK().open_paren,
        optional($._parenthesized_body),
        BRACK().close_paren,
        optional($.cell_path),
      ),

    _spread_parenthesized: ($) =>
      seq(
        BRACK().spread_open_paren,
        optional($._parenthesized_body),
        BRACK().close_paren,
        optional($.cell_path),
      ),

    _expr_parenthesized_immediate: ($) =>
      seq(
        token.immediate(BRACK().open_paren),
        optional($._parenthesized_body),
        BRACK().close_paren,
      ),

    _parenthesized_body: ($) =>
      general_body_rules(
        "",
        $._block_body_statement_parenthesized,
        $._terminator,
        null,
        [
          repeat1(seq(repeat($._newline), PUNC().semicolon)),
          repeat($._newline),
        ],
        $._terminator,
      ),

    val_range: _range_rule(false),
    _val_range: _range_rule(true),
    _val_range_with_end: _range_rule(true, true),

    _immediate_decimal: _decimal_rule(true),

    /// Simple Expressions

    _value: ($) =>
      choice(
        $.val_variable,
        $.val_nothing,
        $.val_bool,
        $.val_number,
        $.val_duration,
        $.val_filesize,
        $.val_binary,
        $.val_string,
        $.val_interpolated,
        $.val_date,
        $.val_list,
        $.val_record,
        $.val_table,
        $.val_closure,
      ),

    /// Literals
    val_nothing: (_$) =>
      choice(
        SPECIAL().null,
        seq(token(BRACK().open_paren), token.immediate(BRACK().close_paren)),
      ),

    val_bool: (_$) => choice(SPECIAL().true, SPECIAL().false),

    _spread_variable: ($) =>
      seq(
        PUNC().spread_dollar,
        field("name", $.identifier),
        optional($.cell_path),
      ),

    val_variable: ($) =>
      seq(
        PUNC().dollar,
        field("name", choice("nu", "in", "env", $.identifier)),
        optional($.cell_path),
      ),

    val_number: ($) => $._val_number,

    _val_number_decimal: _decimal_rule(false),

    // separating floats from integers does not end well
    // especially when it comes to incorporation with ranges.
    _val_number: ($) =>
      choice(
        $._val_number_decimal,
        /0x[0-9a-fA-F_]+/,
        /0b[01_]+/,
        /0o[0-7_]+/,
        SPECIAL().pos_infinity,
        SPECIAL().neg_infinity,
        SPECIAL().not_a_number,
      ),

    val_duration: ($) =>
      seq(
        field("value", alias($._val_number_decimal, $.val_number)),
        field("unit", $.duration_unit),
      ),

    val_filesize: ($) =>
      choice(
        // "0b" as single terminal in both $.val_binary and $.val_number
        // not able to further split it into value and unit
        "0b",
        seq(
          field("value", alias($._val_number_decimal, $.val_number)),
          field("unit", $.filesize_unit),
        ),
      ),

    // prettier-ignore
    filesize_unit: (_$) => token.immediate(choice(
      "b", "B",

      "kb", "kB", "Kb", "KB",
      "mb", "mB", "Mb", "MB",
      "gb", "gB", "Gb", "GB",
      "tb", "tB", "Tb", "TB",
      "pb", "pB", "Pb", "PB",
      "eb", "eB", "Eb", "EB",

      "kib", "kiB", "kIB", "kIb", "Kib", "KIb", "KIB",
      "mib", "miB", "mIB", "mIb", "Mib", "MIb", "MIB",
      "gib", "giB", "gIB", "gIb", "Gib", "GIb", "GIB",
      "tib", "tiB", "tIB", "tIb", "Tib", "TIb", "TIB",
      "pib", "piB", "pIB", "pIb", "Pib", "PIb", "PIB",
      "eib", "eiB", "eIB", "eIb", "Eib", "EIb", "EIB",
    )),

    // prettier-ignore
    duration_unit: (_$) => token.immediate(choice(
      "ns", "µs", "us", "ms", "sec", "min", "hr", "day", "wk"
    )),

    val_binary: ($) =>
      seq(
        choice("0b", "0o", "0x"),
        token.immediate(BRACK().open_brack),
        repeat(field("digit", seq($.hex_digit, optional(PUNC().comma)))),
        BRACK().close_brack,
      ),

    hex_digit: (_$) => token(/[0-9a-fA-F]+/),

    val_date: (_$) =>
      token(
        choice(
          /[0-9]{4}-[0-9]{2}-[0-9]{2}/i,
          /[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}(\.[0-9]+)?([Zz]|([\+-])([01]\d|2[0-3]):?([0-5]\d)?)?/,
        ),
      ),

    _stringish: ($) =>
      choice(
        $.val_string,
        $.val_interpolated,
        $.expr_parenthesized,
        $.val_variable,
      ),

    val_string: ($) =>
      choice($._str_double_quotes, $._str_single_quotes, $._str_back_ticks),

    _str_double_quotes: ($) =>
      seq(
        '"',
        repeat(
          choice(
            $._escaped_str_content,
            // double quoted strings accept escapes
            $.escape_sequence,
          ),
        ),
        '"',
      ),

    _escaped_str_content: (_$) => token.immediate(prec(1, /[^"\\]+/)),

    _str_single_quotes: (_$) => /'[^']*'/,

    _str_back_ticks: (_$) => /`[^`]*`/,

    escape_sequence: (_$) =>
      token.immediate(
        seq(
          "\\",
          choice(
            /[^xu]/,
            /u[0-9a-fA-F]{4}/,
            /u\{[0-9a-fA-F]+\}/,
            /x[0-9a-fA-F]{2}/,
          ),
        ),
      ),

    /// String Interpolation

    val_interpolated: ($) =>
      choice($._inter_single_quotes, $._inter_double_quotes),

    escaped_interpolated_content: (_$) => token.immediate(prec(1, /[^"\\(]+/)),

    unescaped_interpolated_content: (_$) => token.immediate(prec(1, /[^'(]+/)),

    _inter_single_quotes: ($) =>
      seq(
        "$'",
        repeat(
          choice(
            field("expr", $.expr_interpolated),
            $.unescaped_interpolated_content,
          ),
        ),
        token.immediate("'"),
      ),

    _inter_double_quotes: ($) =>
      seq(
        '$"',
        repeat(
          choice(
            field("expr", $.expr_interpolated),
            $.inter_escape_sequence,
            // double quoted strings accept escapes
            $.escaped_interpolated_content,
          ),
        ),
        token.immediate('"'),
      ),

    inter_escape_sequence: (_$) =>
      token.immediate(
        seq(
          "\\",
          choice(
            /[^xu]/,
            /u[0-9a-fA-F]{4}/,
            /u\{[0-9a-fA-F]+\}/,
            /x[0-9a-fA-F]{2}/,
            "(",
          ),
        ),
      ),

    expr_interpolated: ($) =>
      seq(BRACK().open_paren, $._parenthesized_body, BRACK().close_paren),

    /// Collections

    val_list: ($) =>
      seq(
        BRACK().open_brack,
        optional($.list_body),
        BRACK().close_brack,
        optional($.cell_path),
      ),

    _spread_list: ($) =>
      seq(
        BRACK().spread_open_brack,
        optional($.list_body),
        BRACK().close_brack,
        optional($.cell_path),
      ),

    _spread_listish: ($) =>
      choice(
        alias($._spread_list, $.val_list),
        alias($._spread_variable, $.val_variable),
        alias($._spread_parenthesized, $.expr_parenthesized),
      ),

    list_body: ($) =>
      general_body_rules(
        "entry",
        $.val_entry,
        $._entry_separator,
        $._newline,
        null,
        choice($._newline, PUNC().comma),
      ),

    val_entry: ($) =>
      prec(
        10,
        field(
          "item",
          choice(
            $._item_expression,
            field("spread", $._spread_listish),
            alias($._unquoted_in_list, $.val_string),
            alias($._unquoted_in_list_with_expr, $.val_string),
          ),
        ),
      ),

    _item_expression: ($) =>
      choice($._value, $.val_range, $.expr_parenthesized),

    val_record: ($) =>
      seq(
        BRACK().open_brace,
        optional($.record_body),
        BRACK().close_brace,
        optional($.cell_path),
      ),

    _spread_record: ($) =>
      seq(
        BRACK().spread_open_brace,
        optional($.record_body),
        BRACK().close_brace,
        optional($.cell_path),
      ),

    _spread_recordish: ($) =>
      choice(
        alias($._spread_record, $.val_record),
        alias($._spread_variable, $.val_variable),
        alias($._spread_parenthesized, $.expr_parenthesized),
      ),

    record_body: ($) =>
      general_body_rules(
        "entry",
        $.record_entry,
        $._entry_separator,
        $._newline,
      ),

    _entry_separator: (_$) =>
      token(prec(PREC().higher, choice(PUNC().comma, /\s/))),

    record_entry: ($) =>
      choice(
        field("spread", $._spread_recordish),
        seq(
          field(
            "key",
            choice(
              // Without $.cmd_identifier, cannot correctly distinguish between record and closure
              alias($.cmd_identifier, $.identifier),
              alias($._record_key, $.identifier),
              $.val_string,
              $.val_number,
              $.val_variable,
              $.expr_parenthesized,

              // This distinguish between record keys and keywords
              ...Object.values(KEYWORD()).map((x) => alias(x, $.identifier)),
              ...Object.values(MODIFIER()).map((x) => alias(x, $.identifier)),
            ),
          ),
          alias(
            token(prec(PREC().higher, seq(/\s*/, PUNC().colon))),
            PUNC().colon,
          ),
          field(
            "value",
            choice(
              $._item_expression,
              alias($._unquoted_in_record, $.val_string),
              alias($._unquoted_in_record_with_expr, $.val_string),
            ),
          ),
        ),
      ),

    _record_key: (_$) => {
      const excluded = "\\[\\]{}\"`':,";
      const pattern_repeat = repeat(none_of(excluded));
      // This distinguish number and identifier starting with -/+
      return seq(
        choice(token(OPR().minus), token(OPR().plus)),
        token.immediate(pattern_repeat),
      );
    },

    _table_head_separator: (_$) =>
      token(prec(PREC().higher, seq(/\s*/, PUNC().semicolon))),

    val_table: ($) =>
      seq(
        BRACK().open_brack,
        repeat($._newline),
        field("head", $.val_list),
        alias($._table_head_separator, PUNC().semicolon),
        optional(
          general_body_rules("row", $.val_list, $._entry_separator, $._newline),
        ),
        BRACK().close_brack,
        optional($.cell_path),
      ),

    val_closure: ($) =>
      seq(
        BRACK().open_brace,
        repeat($._newline),
        optional(field("parameters", $.parameter_pipes)),
        $._block_body,
        BRACK().close_brace,
      ),

    /// CellPaths

    cell_path: ($) => repeat1($.path),

    path: ($) => {
      const path = choice(
        token.immediate(prec(PREC().low, repeat1(none_of("\\[\\]{}.,:?")))),
        alias($.val_string, "quoted"),
      );

      return seq(
        token.immediate(PUNC().dot),
        choice(
          field("raw_path", path),
          field("protected_path", seq(path, PUNC().question)),
        ),
      );
    },

    /// Single-use env variables: FOO=BAR cmd

    env_var: ($) =>
      seq(
        field(
          "variable",
          alias(
            token(prec(PREC().low, seq(_identifier_rules(false), PUNC().eq))),
            $.identifier,
          ),
        ),
        field("value", alias(_identifier_rules(true), $.val_string)),
      ),

    /// Commands

    command: _command_rule(false),
    _command_parenthesized: _command_rule(true),

    _cmd_arg: ($) =>
      choice(
        field("redir", prec.right(10, $.redirection)),
        field("flag", prec.right(9, $._flag)),
        field("arg", prec.right(8, $._value)),
        field("arg", prec.right(8, $.val_range)),
        field("arg", prec.right(7, $.expr_parenthesized)),
        field("arg_spread", $._spread_listish),
        // lowest precedence to make it a last resort
        field("arg_str", alias($.unquoted, $.val_string)),
        field("arg_str", alias($._unquoted_with_expr, $.val_string)),
      ),

    flag_value: ($) => choice($._value, $.val_string),

    redirection: ($) =>
      seq(
        choice(...REDIR_APPEND()),
        seq(
          $._space,
          field(
            "file_path",
            choice(alias($._unquoted_naive, $.val_string), $._stringish),
          ),
        ),
      ),

    _flag: ($) => prec.right(5, choice($.short_flag, $.long_flag)),

    _flags_parenthesized: ($) => seq(repeat1($._separator), $._flag),

    _flag_value: ($) => choice($._value, alias($.unquoted, $.val_string)),

    short_flag: ($) =>
      seq(
        OPR().minus,
        optional(field("name", $.short_flag_identifier)),
        optional(
          seq(token.immediate(PUNC().eq), field("value", $._flag_value)),
        ),
      ),

    short_flag_identifier: (_$) => token.immediate(/[\p{XID_Continue}?@!%_-]+/),

    long_flag: ($) =>
      seq(
        OPR().long_flag,
        optional(field("name", $.long_flag_identifier)),
        optional(
          seq(token.immediate(PUNC().eq), field("value", $._flag_value)),
        ),
      ),

    _unquoted_naive: (_$) => token(repeat1(none_of("{}"))),
    unquoted: _unquoted_rule("command"),
    _unquoted_in_list: _unquoted_rule("list"),
    _unquoted_in_record: _unquoted_rule("record"),
    _unquoted_with_expr: _unquoted_with_expr_rule("command"),
    _unquoted_in_list_with_expr: _unquoted_with_expr_rule("list"),
    _unquoted_in_record_with_expr: _unquoted_with_expr_rule("record"),

    _unquoted_anonymous_prefix: ($) =>
      choice(
        ...REDIR_APPEND(),
        SPECIAL().null,
        alias($.val_bool, "_prefix"),
        alias($.val_date, "_prefix"),
        seq(
          $._val_number_decimal,
          choice(
            alias($.duration_unit, "_unit"),
            alias($.filesize_unit, "_unit"),
          ),
        ),
      ),

    /// Comments

    comment: (_$) => seq(PUNC().hash, /.*/),
  },
});

/**
 * @param {boolean} immediate
 */
function _identifier_rules(immediate) {
  const func = immediate ? token.immediate : token;
  const excluded = "\\[\\]\\-{}<>=\"`'@?,:.";
  return func(seq(none_of(excluded + "&*!^+#$"), repeat(none_of(excluded))));
}

/**
 * for rules of repeated pattern that require separator in-between
 * e.g. list, record, blocks
 * @param {string} field_name
 * @param {any} entry base build block
 * @param {any} separator separator between entries
 * @param {any} preceding separator before first entry, defaults to separator
 * @param {array} alt_sep array of rules to override default separator
 * @param {any} empty_unit optional for empty body
 */
function general_body_rules(
  field_name,
  entry,
  separator,
  preceding = null,
  alt_sep = null,
  empty_unit = null,
) {
  const field_entry = field_name.length == 0 ? entry : field(field_name, entry);
  const prec_sep = preceding || separator;
  // Normal entries MUST have a separator
  const sep_array = alt_sep || [repeat1(separator)];
  const rule = prec(
    PREC().higher,
    seq(
      repeat(prec_sep),
      repeat(seq(field_entry, ...sep_array)),
      field_entry,
      // Final entry may or may not have separator
      repeat(separator),
    ),
  );
  return empty_unit ? choice(repeat1(empty_unit), rule) : rule;
}

function parenthesized_body_rules() {
  return {
    ..._block_body_rules("_parenthesized"),

    /// pipeline

    pipeline_parenthesized: ($) =>
      seq(
        repeat(
          seq(
            alias($.pipe_element_parenthesized, $.pipe_element),
            $._pipe_separator,
            repeat($._newline),
          ),
        ),
        alias($.pipe_element_parenthesized, $.pipe_element),
      ),
  };
}

function block_body_rules() {
  return {
    ..._block_body_rules(""),

    /// pipeline

    pipeline: ($) =>
      seq(
        repeat(seq($.pipe_element, $._pipe_separator, optional($._newline))),
        $.pipe_element,
      ),
  };
}

/// To parse pipelines correctly grammar needs to know now pipeline may end.
/// For example in following closure
/// ```
/// {||
///   print qwe
///   print rty
/// }
/// ```
/// two print calls must be separated either by newline or ';', but last call
/// may not be separated from closing bracket at all `{|| print qwe; print rty}`
/// and in `()` blocks newlines are not considered statement terminators at all.
/// To correctly parse these situations distinct rules for different types of
/// statements are needed. These rules are differentiated by suffix, and only
/// difference between them is terminator parameter used in pipeline rule that
/// is terminating statements. This function automatically generates all rules
/// for a given terminator and names them with specified suffix.
/**
 * @param {string} suffix
 */
function _block_body_rules(suffix) {
  /**
   * @param {{ [x: string]: string; }} $
   * @param {string} rule_name
   * @param {string} suffix
   */
  function alias_for_suffix($, rule_name, suffix) {
    if (suffix == "") {
      return $[rule_name];
    } else {
      return alias($[rule_name + suffix], $[rule_name]);
    }
  }

  return {
    ["_block_body_statement" + suffix]: (
      /** @type {{ [x: string]: RuleOrLiteral; }} */ $,
    ) => choice($["_declaration" + suffix], $["_statement" + suffix]),

    /// Declarations
    ["_declaration" + suffix]: (
      /** @type {{ [x: string]: string; decl_def?: any; decl_export?: any; decl_extern?: any; decl_module?: any; decl_use?: any; }} */ $,
    ) =>
      choice(
        alias_for_suffix($, "decl_alias", suffix),
        $.decl_def,
        $.decl_export,
        $.decl_extern,
        $.decl_module,
        $.decl_use,
      ),

    ["decl_alias" + suffix]: (
      /** @type {{ [x: string]: string; _command_name?: any; }} */ $,
    ) =>
      seq(
        optional(MODIFIER().visibility),
        KEYWORD().alias,
        field("name", $._command_name),
        PUNC().eq,
        field("value", alias_for_suffix($, "pipeline", suffix)),
      ),

    /// Storage statements

    ["stmt_let" + suffix]: (/** @type {{ [x: string]: RuleOrLiteral; }} */ $) =>
      prec.right(
        PREC().assignment,
        seq(
          choice(KEYWORD().let, KEYWORD().let_env),
          $["_assignment_pattern" + suffix],
        ),
      ),

    ["stmt_mut" + suffix]: (/** @type {{ [x: string]: RuleOrLiteral; }} */ $) =>
      prec.right(1, seq(KEYWORD().mut, $["_assignment_pattern" + suffix])),

    ["stmt_const" + suffix]: (
      /** @type {{ [x: string]: RuleOrLiteral; }} */ $,
    ) =>
      prec.right(
        PREC().assignment,
        seq(
          optional(MODIFIER().visibility),
          KEYWORD().const,
          $["_assignment_pattern" + suffix],
        ),
      ),

    ["assignment" + suffix]: (
      /** @type {{ [x: string]: RuleOrLiteral; }} */ $,
    ) =>
      prec.right(PREC().assignment, $["_mutable_assignment_pattern" + suffix]),

    ["_assignment_pattern" + suffix]: (
      /** @type {{ [x: string]: string; _variable_name?: any; param_type?: any; }} */ $,
    ) =>
      seq(
        field("name", $._variable_name),
        field("type", optional($.param_type)),
        PUNC().eq,
        field("value", alias_for_suffix($, "pipeline", suffix)),
      ),

    ["_mutable_assignment_pattern" + suffix]: (
      /** @type {{ [x: string]: string; _variable_name?: any; param_type?: any; }} */ $,
    ) =>
      seq(
        field("lhs", $.val_variable),
        field(
          "opr",
          choice(
            PUNC().eq,
            OPR().assign_add,
            OPR().assign_sub,
            OPR().assign_mul,
            OPR().assign_div,
            OPR().assign_append,
          ),
        ),
        field("rhs", alias_for_suffix($, "pipeline", suffix)),
      ),

    /// Statements

    ["_statement" + suffix]: (
      /**⋅@type {any} */ /** @type {{ [x: string]: string; _ctrl_statement?: any; _stmt_hide?: any; _stmt_overlay?: any; stmt_register?: any; stmt_source?: any; assignment?: any; }} */ $,
    ) =>
      choice(
        $._ctrl_statement,
        $._stmt_hide,
        $._stmt_overlay,
        $.stmt_register,
        $.stmt_source,
        alias_for_suffix($, "assignment", suffix),
        alias_for_suffix($, "stmt_let", suffix),
        alias_for_suffix($, "stmt_mut", suffix),
        alias_for_suffix($, "stmt_const", suffix),
        alias_for_suffix($, "pipeline", suffix),
      ),
  };
}

/**
 * Insert repeat($._newline) in-between
 * @param {array} sequence
 * @param {boolean} begin allow newline in beginning
 * @param {boolean} end allow newline in end
 */
function _insert_newline($, sequence, begin = false, end = true) {
  var result = [repeat($._newline)];
  for (const item of sequence) {
    result.push(item);
    result.push(repeat($._newline));
  }
  result = begin ? result : result.slice(1);
  result = end ? result : result.slice(0, -1);
  return seq(...result);
}

/**
 * @param {boolean} parenthesized
 */
function _command_rule(parenthesized) {
  return (/** @type {any} */ $) => {
    const sep = parenthesized ? $._separator : $._space;
    return prec.right(
      seq(
        choice(
          field("head", seq(optional(PUNC().caret), $.cmd_identifier)),
          field("head", seq(PUNC().caret, $._stringish)),
        ),
        repeat(seq(sep, optional($._cmd_arg))),
      ),
    );
  };
}

/**
 * @param {boolean} parenthesized
 * @param {any} $
 */
function _env_variable_rule(parenthesized, $) {
  const sep = parenthesized ? $._separator : $._space;
  return repeat(seq($.env_var, repeat1(sep)));
}

/**
 * @param {boolean} parenthesized
 */
function _ctrl_try_rule(parenthesized) {
  return (/** @type {any} */ $) => {
    const seq_catch_array = [
      KEYWORD().catch,
      field("catch_branch", $._blosure),
    ];
    const seq_array = [
      KEYWORD().try,
      field("try_branch", $.block),
      optional(
        parenthesized
          ? _insert_newline($, seq_catch_array, true, false)
          : seq(...seq_catch_array),
      ),
    ];
    return parenthesized
      ? _insert_newline($, seq_array, false, false)
      : seq(...seq_array);
  };
}

/**
 * @param {boolean} parenthesized
 */
function _ctrl_if_rule(parenthesized) {
  return (/** @type {any} */ $) => {
    const _expr = parenthesized ? $._expression_parenthesized : $._expression;
    const seq_else_array = [
      KEYWORD().else,
      choice(
        field("else_block", choice($.block, _expr, $.command)),
        field(
          "else_branch",
          parenthesized ? alias($.ctrl_if_parenthesized, $.ctrl_if) : $.ctrl_if,
        ),
      ),
    ];
    const seq_array = [
      KEYWORD().if,
      field("condition", _expr),
      field("then_branch", $.block),
      optional(
        parenthesized
          ? _insert_newline($, seq_else_array, true, false)
          : seq(...seq_else_array),
      ),
    ];
    return parenthesized
      ? _insert_newline($, seq_array, false, false)
      : seq(...seq_array);
  };
}

/**
 * @param {boolean} parenthesized
 */
function _expr_binary_rule(parenthesized) {
  return (/** @type {any} */ $) => {
    const _expr = parenthesized
      ? $._expr_binary_expression_parenthesized
      : $._expr_binary_expression;
    return choice(
      ...TABLE().map(([precedence, opr]) => {
        const seq_array = [
          field("lhs", _expr),
          field("opr", operator_with_separator(opr, parenthesized)),
          field(
            "rhs",
            choice(
              _expr,
              alias($.unquoted, $.val_string),
              alias($._unquoted_with_expr, $.val_string),
            ),
          ),
        ];
        return parenthesized
          ? prec.left(precedence, _insert_newline($, seq_array))
          : prec.left(precedence, seq(...seq_array));
      }),
    );
  };
}

/**
 * @param {boolean} parenthesized
 */
function _binary_predicate_rule(parenthesized) {
  return (/** @type {any} */ $) => {
    const _expr = parenthesized
      ? $._binary_predicate_parenthesized
      : $._binary_predicate;
    return choice(
      ...BINARY().map(([precedence, opr]) => {
        const seq_array = [
          field("lhs", choice($._predicate, _expr)),
          field("opr", opr),
          field("rhs", choice($._predicate, _expr)),
        ];
        return parenthesized
          ? prec.left(precedence, _insert_newline($, seq_array))
          : prec.left(precedence, seq(...seq_array));
      }),
    );
  };
}

/**
 * @param {boolean} parenthesized
 */
function _where_clause_rule(parenthesized) {
  return (/** @type {any} */ $) => {
    const seq_array = [
      "where",
      field(
        "predicate",
        choice(
          $._predicate,
          $.val_closure,
          parenthesized
            ? $._binary_predicate_parenthesized
            : $._binary_predicate,
        ),
      ),
    ];
    return parenthesized
      ? prec.left(_insert_newline($, seq_array))
      : seq(...seq_array);
  };
}

/**
 * @param {boolean} immediate
 */
function _decimal_rule(immediate) {
  const exponent = token.immediate(/[eE][-+]?[\d_]*\d[\d_]*/);
  const digits = token.immediate(/[\d_]*\d[\d_]*/);
  const head_token = immediate ? token.immediate : token;
  const head_digits = head_token(/[\d_]*\d[\d_]*/);
  return (/** @type {any} */ _$) =>
    choice(
      seq(head_digits, optional(exponent)),
      seq(
        token(
          seq(choice(head_token(OPR().minus), head_token(OPR().plus)), digits),
        ),
        optional(exponent),
      ),
      seq(
        head_digits,
        token.immediate(PUNC().dot),
        optional(digits),
        optional(exponent),
      ),
      seq(
        token(
          seq(choice(head_token(OPR().minus), head_token(OPR().plus)), digits),
        ),
        token.immediate(PUNC().dot),
        optional(digits),
        optional(exponent),
      ),
      token(seq(head_token(PUNC().dot), digits, optional(exponent))),
      seq(
        token(
          seq(
            choice(head_token(OPR().minus), head_token(OPR().plus)),
            optional(token.immediate(/_+/)),
            token.immediate(PUNC().dot),
            digits,
          ),
        ),
        optional(exponent),
      ),
    );
}

/**
 * @param {boolean} anonymous
 * @param {boolean} with_end_decimal
 */
function _range_rule(anonymous, with_end_decimal = false) {
  // Divide each dot as a token to distinguish $.val_range and $.val_number
  const create_opr = (/** @type {boolean} */ immediate) => {
    const head_token = immediate ? token.immediate : token;
    return {
      opr: choice(
        head_token(OPR().range_inclusive),
        head_token(OPR().range_inclusive2),
        head_token(OPR().range_exclusive),
      ),
      step: head_token(OPR().range_inclusive),
    };
  };

  const { opr, step: opr_step } = create_opr(false);
  const { opr: opr_imm, step: opr_step_imm } = create_opr(true);

  return (/** @type {any} */ $) => {
    const member = choice(
      $.expr_parenthesized,
      alias($._val_number_decimal, $.val_number),
      $.val_variable,
    );
    const step_or_end = choice(
      alias($._expr_parenthesized_immediate, $.expr_parenthesized),
      alias($._immediate_decimal, $.val_number),
      $.val_variable,
    );
    var start = field("start", member);
    var end = field("end", step_or_end);
    var step = field("step", step_or_end);
    if (anonymous) {
      start = $._val_number_decimal;
      step = $._immediate_decimal;
      end = $._immediate_decimal;
    }
    const common_choices = [
      // 1... works as range from 1 to infinity
      seq(start, opr_step_imm, token.immediate(PUNC().dot)),
      seq(opr, end),
      seq(opr_step, step, opr_imm, end),
    ];
    const seq_with_start = [start, optional(seq(opr_step_imm, step)), opr_imm];
    const end_pattern = with_end_decimal ? end : optional(end);

    return prec.right(
      anonymous ? PREC().range - 1 : PREC().range,
      choice(...common_choices, seq(...seq_with_start, end_pattern)),
    );
  };
}

/**
 * For expressions like: foo('bar')baz
 * @param {string} type
 */
function _unquoted_with_expr_rule(type) {
  var excluded = "";
  switch (type) {
    case "list":
      excluded += "\\[\\],";
      break;
    case "record":
      excluded += "{}:,";
      break;
  }
  const pattern_repeat = token(repeat(none_of(excluded)));
  return ($) => {
    var unquoted_head = $.unquoted;
    switch (type) {
      case "list":
        unquoted_head = $._unquoted_in_list;
        break;
      case "record":
        unquoted_head = $._unquoted_in_record;
        break;
    }
    return prec(
      PREC().low,
      seq(
        choice(
          $._unquoted_anonymous_prefix,
          $._val_number_decimal,
          $._val_range_with_end,
          alias(unquoted_head, "_head"),
        ),
        alias($._expr_parenthesized_immediate, $.expr_parenthesized),
        optional(
          repeat(
            seq(
              token.immediate(pattern_repeat),
              alias($._expr_parenthesized_immediate, $.expr_parenthesized),
            ),
          ),
        ),
        token.immediate(pattern_repeat),
      ),
    );
  };
}

/**
 * @param {string} type
 */
function _unquoted_rule(type) {
  var excluded_common = "\\[\\]{}\"`'";
  var excluded_first = excluded_common + "$";
  switch (type) {
    case "list":
      excluded_common += ",";
      excluded_first += ",";
      break;
    case "record":
      excluded_common += ":,";
      excluded_first += ":,";
      break;
    case "command":
      excluded_first += "-";
      break;
  }
  const pattern_once = none_of(excluded_common);
  const pattern = token(seq(none_of(excluded_first), repeat(pattern_once)));
  const pattern_repeat = token(repeat(pattern_once));
  const pattern_repeat1 = token(repeat1(pattern_once));

  // because this catches almost anything, we want to ensure it is
  // picked as the a last resort after everything else has failed.
  // so we give it a ridiculously low precedence and place it at the
  // very end
  return (
    /** @type {{ _val_number_decimal: RuleOrLiteral; _immediate_decimal: RuleOrLiteral; }} */ $,
  ) =>
    prec.left(
      PREC().lowest,
      choice(
        token(prec(PREC().lowest, token(pattern))),

        seq(
          choice(
            $._val_range,
            $._val_number_decimal,
            SPECIAL().pos_infinity,
            SPECIAL().neg_infinity,
            SPECIAL().not_a_number,
          ),
          token.immediate(prec(PREC().lowest, pattern_repeat1)),
        ),

        seq(
          choice(
            OPR().range_inclusive,
            OPR().range_inclusive2,
            OPR().range_exclusive,
          ),
          token.immediate(prec(PREC().lowest, pattern_repeat)),
        ),

        // recognize unquoted string starting with special patterns
        // e.g. true-foo, e>bar, 1ms-baz ...
        seq($._unquoted_anonymous_prefix, token.immediate(pattern_repeat1)),
      ),
    );
}

/// nushell keywords
function KEYWORD() {
  return {
    def: "def",
    alias: "alias",
    use: "use",
    export_env: "export-env",
    extern: "extern",
    module: "module",

    let: "let",
    let_env: "let-env",
    mut: "mut",
    const: "const",

    hide: "hide",
    hide_env: "hide-env",

    source: "source",
    source_env: "source-env",

    overlay: "overlay",
    register: "register",

    for: "for",
    loop: "loop",
    while: "while",
    error: "error",

    do: "do",
    if: "if",
    else: "else",
    try: "try",
    catch: "catch",
    match: "match",

    break: "break",
    continue: "continue",
    return: "return",

    as: "as",
    in: "in",
  };
}

// modifier keywords
function MODIFIER() {
  return {
    overlay_hide: "hide",
    overlay_list: "list",
    overlay_new: "new",
    overlay_use: "use",

    error_make: "make",

    visibility: "export",
  };
}

// redirection
function REDIR() {
  return ["err>", "out>", "e>", "o>", "err+out>", "out+err>", "o+e>", "e+o>"];
}

function REDIR_APPEND() {
  const rewrite = REDIR();
  const append = rewrite.map((x) => x + ">");
  return rewrite.concat(append);
}

function REDIR_PIPE() {
  return REDIR().map((x) => x + "|");
}

// punctuation
function PUNC() {
  return {
    at: "@",
    dot: ".",
    hash: "#",
    pipe: "|",
    rest: "...",
    eq: "=",
    colon: ":",
    comma: ",",
    caret: "^",
    dollar: "$",
    spread_dollar: "...$",
    fat_arrow: "=>",
    thin_arrow: "->",
    question: "?",
    underscore: "_",

    semicolon: ";",
  };
}

// delimiters
function BRACK() {
  return {
    open_angle: "<",
    close_angle: ">",

    spread_open_brack: "...[",
    open_brack: "[",
    close_brack: "]",

    spread_open_brace: "...{",
    open_brace: "{",
    close_brace: "}",

    spread_open_paren: "...(",
    open_paren: "(",
    close_paren: ")",
  };
}

/**
 * group operator and its preceding/succeeding whitespace/newline
 * @param {string} opr
 * @param {boolean} parenthesized
 */
function operator_with_separator(opr, parenthesized) {
  const sep = parenthesized ? choice(/[ \t]/, /\r?\n/) : /[ \t]/;
  return alias(token(seq(sep, opr, sep)), opr);
}

/**
 * [ele1, array<ele2>] -> array<[ele1, ele2]>
 * @param {any} first
 * @param {array<any>} last_array
 */
function flatten_ops(first, last_array) {
  return last_array.map((x) => [first, x]);
}

// operators
function OPR() {
  return {
    // arithmetic
    plus: "+",
    minus: "-",
    times: "*",
    divide: "/",
    modulo: "mod",
    floor: "//",
    power: "**",
    append: "++",

    // special
    long_flag: "--",

    // comparison
    equal: "==",
    not_equal: "!=",
    less_than: "<",
    less_than_equal: "<=",
    greater_than: ">",
    greater_than_equal: ">=",

    // regex matching
    regex_match: "=~",
    regex_not_match: "!~",

    // logical
    not: "not",
    and: "and",
    or: "or",
    xor: "xor",

    // bitwise
    bit_or: "bit-or",
    bit_xor: "bit-xor",
    bit_and: "bit-and",
    bit_shl: "bit-shl",
    bit_shr: "bit-shr",

    // membership tests
    in: "in",
    not_in: "not-in",
    starts_with: "starts-with",
    ends_with: "ends-with",

    // assignment
    assign_add: "+=",
    assign_sub: "-=",
    assign_mul: "*=",
    assign_div: "/=",
    assign_append: "++=",

    // range
    range_inclusive: "..",
    range_inclusive2: "..=",
    range_exclusive: "..<",
  };
}

/// operator precedence
/// taken from `nu_protocol::`
function PREC() {
  return {
    higher: 20,
    range: 15,
    power: 14,
    multiplicative: 13,
    additive: 12,
    bit_shift: 11,
    comparative: 10,
    membership: 9,
    regex: 8,
    bit_and: 7,
    bit_xor: 6,
    bit_or: 5,
    and: 4,
    xor: 3,
    or: 2,
    assignment: 1,
    low: -1,
    lowest: -69,
  };
}

function STATEMENT_PREC() {
  return {
    control: 1,
  };
}

/// map of operators and their precedence
function TABLE() {
  const multiplicatives = [
    OPR().times,
    OPR().divide,
    OPR().modulo,
    OPR().floor,
  ];

  // `range` is not included here and is handled separately
  return [
    ...flatten_ops(PREC().power, [OPR().power, OPR().append]),
    ...flatten_ops(PREC().multiplicative, multiplicatives),
    ...flatten_ops(PREC().additive, [OPR().plus, OPR().minus]),
    ...flatten_ops(PREC().bit_shift, [OPR().bit_shl, OPR().bit_shr]),
    ...flatten_ops(PREC().regex, [OPR().regex_match, OPR().regex_not_match]),
    [PREC().bit_and, OPR().bit_and],
    [PREC().bit_xor, OPR().bit_xor],
    [PREC().bit_or, OPR().bit_or],
  ].concat(BINARY(), PREDICATE());
}

function BINARY() {
  return [
    [PREC().and, OPR().and],
    [PREC().xor, OPR().xor],
    [PREC().or, OPR().or],
  ];
}

function PREDICATE() {
  const memberships = [
    OPR().in,
    OPR().not_in,
    OPR().starts_with,
    OPR().ends_with,
  ];

  const comparatives = [
    OPR().equal,
    OPR().not_equal,
    OPR().less_than,
    OPR().less_than_equal,
    OPR().greater_than,
    OPR().greater_than_equal,
  ];

  return [
    ...flatten_ops(PREC().membership, memberships),
    ...flatten_ops(PREC().comparative, comparatives),
    ...flatten_ops(PREC().regex, [OPR().regex_match, OPR().regex_not_match]),
  ];
}

/// special tokens
function SPECIAL() {
  return {
    true: "true",
    false: "false",
    null: "null",

    pos_infinity: /[iI][nN][fF]([iI][nN][iI][tT][yY])?/,
    neg_infinity: /-[iI][nN][fF]([iI][nN][iI][tT][yY])?/,
    not_a_number: /[nN][aA][nN]/,
  };
}

/// nushell flat types
/// taken from `nu_parser::parser::parse_shape_name()`
function FLAT_TYPES() {
  // prettier-ignore
  const types = [
    "any", "binary", "block", "bool", "cell-path", "closure", "cond",
    "datetime", "directory", "duration", "directory", "duration",
    "error", "expr", "float", "decimal", "filesize", "full-cell-path",
    "glob", "int", "import-pattern", "keyword", "math", "nothing",
    "number", "one-of", "operator", "path", "range", "signature",
    "string", "table", "variable", "var-with-opt-type", "record", "list",
  ];

  return choice(...types);
}

/**
 * Returns a regular expression that matches any character except the ones
 * provided.
 *
 * @param  {string} excluded
 *
 * @returns {RegExp}
 */
function none_of(excluded = "") {
  return new RegExp("[^\\s\\r\\n\\t\\|();" + excluded + "]");
}
