/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
module.exports = grammar({
  name: "nu",

  word: ($) => $.identifier,

  extras: ($) => [/\s/, $.comment],

  conflicts: ($) => [
    [$._declaration, $._declaration_last],
    [$._declaration_parenthesized, $._declaration_parenthesized_last],
    [$._statement, $._statement_last],
    [$._statement_parenthesized, $._statement_parenthesized_last],
    [$.pipeline, $.pipeline_last],
    [$.pipeline_parenthesized, $.pipeline_parenthesized_last],
    [$.pipe_element, $.pipe_element_last],
    [$.pipe_element_parenthesized, $.pipe_element_parenthesized_last],
    [$.block, $.val_record],
    [$.block, $.val_closure],
    [$.decl_module],
    [$._val_number_decimal],
    [$._immediate_decimal],
    [$.expr_parenthesized],
    [$.val_variable],
    [$._expression, $._expr_binary_expression],
    [$._match_pattern_value, $._value],
    [$._match_pattern_expression, $._list_item_expression],
    [$._match_pattern_list, $.val_list],
    [$._match_pattern_record, $.val_record],
    [$._match_pattern_record_variable, $._value],
  ],

  rules: {
    /// File

    nu_script: ($) => seq(optional($.shebang), optional($._block_body)),

    shebang: (_$) => seq("#!", /.*\n/),

    ...block_body_rules("", (/** @type {any} */ $) => $._terminator),
    ...block_body_rules("_last", (/** @type {any} */ $) =>
      optional($._terminator),
    ),

    // Because everything inside of the parentheses are treated as if they were written together,
    // terminator must be semicolon.
    ...parenthesized_body_rules(
      "",
      // @ts-ignore
      (/** @type {any} */ _$) => PUNC().semicolon,
    ),
    // @ts-ignore
    ...parenthesized_body_rules("_last", (/** @type {any} */ _$) =>
      optional(PUNC().semicolon),
    ),

    _block_body: ($) =>
      seq(
        prec.right(repeat(seq($._block_body_statement, repeat($._terminator)))),
        $._block_body_statement_last,
        repeat($._terminator),
      ),

    /// Identifiers
    // NOTE:
    // for simplicity, i used the `rust` definition of an identifier and some symbols
    // but in `nu` the rule is way more relaxed than this

    cmd_identifier: (_$) => token(/[_\p{XID_Start}][_\-\p{XID_Continue}!?.]*/),

    identifier: (_$) => token(/[_\p{XID_Start}][_\p{XID_Continue}]*/),

    _long_flag_identifier: (_$) =>
      token.immediate(/[\p{XID_Start}_][\p{XID_Continue}_-]*/),

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

    _terminator: (_$) => choice(PUNC().semicolon, "\n"),

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
          field(
            "module",
            choice(
              $.val_string,
              $.val_interpolated,
              $.expr_parenthesized,
              $.unquoted,
            ),
          ),
          optional(field("import_pattern", $.scope_pattern)),
        ),
      ),

    /// Return types
    returns: ($) => seq(PUNC().colon, choice($._multiple_types, $._one_type)),

    _one_type: ($) =>
      seq($._type_annotation, PUNC().thin_arrow, $._type_annotation),

    _multiple_types: ($) =>
      seq(
        BRACK().open_brack,
        repeat(seq($._one_type, optional(PUNC().comma))),
        BRACK().close_brack,
      ),

    /// Parameters

    parameter_parens: ($) =>
      seq(BRACK().open_paren, repeat($.parameter), BRACK().close_paren),

    parameter_bracks: ($) =>
      seq(BRACK().open_brack, repeat($.parameter), BRACK().close_brack),

    parameter_pipes: ($) => seq(PUNC().pipe, repeat($.parameter), PUNC().pipe),

    parameter: ($) =>
      seq(
        choice(
          $._param_name,
          field("param_long_flag", $.param_long_flag),
          field(
            "param_long_flag",
            seq($.param_long_flag, field("flag_capsule", $.flag_capsule)),
          ),
        ),
        optional(
          choice(
            $.param_type,
            $.param_value,
            seq($.param_value, $.param_type),
            seq($.param_type, $.param_value),
          ),
        ),
        optional(PUNC().comma),
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
        PUNC().colon,
        $._type_annotation,
        field("completion", optional($.param_cmd)),
      ),

    param_value: ($) => seq(PUNC().eq, field("param_value", $._expression)),

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
              seq(key, optional(seq(PUNC().colon, $._all_type))),
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
          BRACK().close_angle,
        ),
      ),

    param_cmd: ($) => seq(PUNC().at, field("name", $._command_name)),

    param_rest: ($) => seq(PUNC().rest, field("name", $.identifier)),

    param_opt: ($) =>
      seq(field("name", $.identifier), token.immediate(PUNC().question)),

    param_long_flag: ($) =>
      seq("--", alias($._long_flag_identifier, $.identifier)),

    flag_capsule: ($) =>
      seq(BRACK().open_paren, $.param_short_flag, BRACK().close_paren),

    param_short_flag: (_$) =>
      seq("-", field("name", token.immediate(/[a-zA-Z0-9]/))),

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
        $.ctrl_do,
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

    ctrl_do: ($) =>
      prec.left(
        -1,
        seq(
          // `do` has 4 flags, is there a better way to do this?
          KEYWORD().do,
          optional($._flag),
          optional($._flag),
          optional($._flag),
          optional($._flag),
          choice($._blosure, $.val_variable),
          optional($._flag),
          optional($._flag),
          optional($._flag),
          optional($._flag),
          optional($._expression),
          optional($._flag),
          optional($._flag),
          optional($._flag),
          optional($._flag),
        ),
      ),

    ctrl_if: ($) =>
      seq(
        KEYWORD().if,
        field("condition", choice($._expression, $.identifier)),
        field("then_branch", $.block),
        optional(
          seq(
            KEYWORD().else,
            choice(
              field("else_block", choice($.block, $._expression, $.command)),
              field("else_branch", $.ctrl_if),
            ),
          ),
        ),
      ),

    ctrl_if_parenthesized: ($) =>
      prec.right(
        seq(
          KEYWORD().if,
          field("condition", choice($._expression, $.identifier)),
          field("then_branch", $.block),
          optional(
            seq(
              optional("\n"),
              KEYWORD().else,
              choice(
                field("else_block", choice($.block, $._expression, $.command)),
                field("else_branch", alias($.ctrl_if_parenthesized, $.ctrl_if)),
              ),
            ),
          ),
        ),
      ),

    ctrl_match: ($) =>
      seq(
        KEYWORD().match,
        field(
          "scrutinee",
          choice($._expression, alias($.unquoted, $.val_string)),
        ),
        BRACK().open_brace,
        repeat($.match_arm),
        optional($.default_arm),
        BRACK().close_brace,
      ),

    match_arm: ($) =>
      seq(
        field("pattern", $.match_pattern),
        PUNC().fat_arrow,
        field("expression", $._match_expression),
        optional(PUNC().comma),
      ),

    default_arm: ($) =>
      seq(
        field("default_pattern", PUNC().underscore),
        PUNC().fat_arrow,
        field("expression", $._match_expression),
        optional(PUNC().comma),
      ),

    _match_expression: ($) => choice($._expression, prec.dynamic(10, $.block)),

    match_pattern: ($) =>
      choice(
        seq($._match_pattern, optional($.match_guard)),
        seq($._match_pattern, repeat(seq(PUNC().pipe, $._match_pattern))),
      ),

    _match_pattern: ($) =>
      choice($._match_pattern_expression, alias($.unquoted, $.val_string)),

    match_guard: ($) => seq(KEYWORD().if, $._expression),

    _match_pattern_expression: ($) =>
      choice(
        $._match_pattern_value,
        alias($._expr_unary_minus, $.expr_unary),
        $.val_range,
        $.expr_parenthesized,
      ),

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
                alias($.short_flag, $.val_string),
                alias($.long_flag, $.val_string),
                alias($._list_item_starts_with_sign, $.val_string),
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
              $._match_pattern_ignore_rest,
            ),
          ),
        ),
        BRACK().close_brack,
      ),

    _match_pattern_rest: ($) =>
      seq(
        PUNC().dot,
        token.immediate(PUNC().dot),
        seq(token.immediate(PUNC().dollar), $.identifier),
      ),

    _match_pattern_ignore_rest: (_$) =>
      seq(PUNC().dot, token.immediate(PUNC().dot)),

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

    ctrl_try: ($) =>
      seq(
        KEYWORD().try,
        field("try_branch", $.block),
        optional(seq(KEYWORD().catch, field("catch_branch", $._blosure))),
      ),

    ctrl_try_parenthesized: ($) =>
      prec.right(
        seq(
          KEYWORD().try,
          field("try_branch", $.block),
          optional(
            seq(
              optional("\n"),
              KEYWORD().catch,
              field("catch_branch", $._blosure),
            ),
          ),
        ),
      ),

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
      seq(
        choice(
          prec.right(69, $._expression),
          $._ctrl_expression,
          $.where_command,
          $.command,
        ),
        // Allow for empty pipeline elements like `ls | | print`
        repeat1(seq(optional("\n"), PUNC().pipe)),
        optional("\n"),
      ),

    pipe_element_parenthesized: ($) =>
      seq(
        choice(
          prec.right(69, $._expression),
          $._ctrl_expression_parenthesized,
          $.where_command,
          alias($._command_parenthesized_body, $.command),
        ),
        // Allow for empty pipeline elements like `ls | | print`
        repeat1(seq(optional("\n"), PUNC().pipe)),
        optional("\n"),
      ),

    pipe_element_last: ($) =>
      choice($._expression, $._ctrl_expression, $.where_command, $.command),

    pipe_element_parenthesized_last: ($) =>
      choice(
        $._expression,
        $._ctrl_expression_parenthesized,
        $.where_command,
        alias($._command_parenthesized_body, $.command),
      ),

    /// Scope Statements

    stmt_source: ($) =>
      seq(
        choice(KEYWORD().source, KEYWORD().source_env),
        field(
          "file",
          choice(
            alias($.unquoted, $.val_string),
            $.val_string,
            $.expr_parenthesized,
            $.val_variable,
            $.val_interpolated,
          ),
        ),
      ),

    stmt_register: ($) =>
      prec.left(
        -1,
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
      seq(KEYWORD().hide_env, field("variable", $._variable_name)),

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
        repeat(seq(field("cmd", $._command_name), optional(PUNC().comma))),
        BRACK().close_brack,
      ),

    /// Assignment Statement

    assignment: ($) => {
      const opr = [
        PUNC().eq,
        OPR().assign_add,
        OPR().assign_sub,
        OPR().assign_mul,
        OPR().assign_div,
        OPR().assign_append,
      ];

      return prec.left(
        PREC().assignment,
        seq(
          field("lhs", $.val_variable),
          field("opr", choice(...opr)),
          field("rhs", $._expression),
        ),
      );
    },

    /// Block

    block: ($) =>
      seq(BRACK().open_brace, optional($._block_body), BRACK().close_brace),

    _blosure: ($) => choice(prec.dynamic(10, $.block), $.val_closure),

    // the where command has a unique argument pattern that breaks the
    // general command parsing, so we handle it separately
    where_command: ($) =>
      seq(
        "where",
        choice(
          $._where_predicate,
          $._expression,
          alias($.block, $.val_closure),
        ),
      ),

    _where_predicate: ($) =>
      choice(
        ...TABLE().map(([precedence, opr]) =>
          prec.left(
            // @ts-ignore
            precedence,
            seq(
              field(
                "lhs",
                choice(
                  seq(
                    choice(alias($.identifier, $.val_string), $.val_number),
                    optional(PUNC().question),
                    optional($.cell_path),
                  ),
                  $.val_variable,
                ),
              ),
              optional(
                seq(
                  // @ts-ignore
                  field("opr", opr),
                  field("rhs", choice($._expression, $._where_predicate)),
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

    /// Composite Expressions

    expr_unary: ($) => {
      const after_not = choice(
        $.val_bool,
        $.expr_parenthesized,
        $.val_variable,
        $.expr_unary,
      );

      return choice(seq(OPR().not, after_not), $._expr_unary_minus);
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

    expr_binary: ($) =>
      choice(
        ...TABLE().map(([precedence, opr]) =>
          prec.right(
            // @ts-ignore
            precedence,
            seq(
              field("lhs", $._expr_binary_expression),
              // @ts-ignore
              field("opr", opr),
              field(
                "rhs",
                choice(
                  $._expr_binary_expression,
                  alias($.unquoted, $.val_string),
                ),
              ),
            ),
          ),
        ),
      ),

    _expr_binary_expression: ($) =>
      choice($._value, $.expr_binary, $.expr_unary, $.expr_parenthesized),

    expr_parenthesized: ($) =>
      seq(
        BRACK().open_paren,
        $._parenthesized_body,
        BRACK().close_paren,
        optional($.cell_path),
      ),

    _parenthesized_body: ($) =>
      seq(
        prec.right(
          repeat(
            seq($._block_body_statement_parenthesized, repeat($._terminator)),
          ),
        ),
        $._block_body_statement_parenthesized_last,
        repeat($._terminator),
      ),

    val_range: ($) => {
      // Divide each dot as a token to distinguish $.val_range and $.val_number
      const create_opr = (/** @type {boolean} */ immediate) => {
        const head_token = immediate ? token.immediate : token;
        return {
          opr: choice(
            alias(
              seq(head_token(PUNC().dot), token.immediate(PUNC().dot)),
              OPR().range_inclusive,
            ),
            alias(
              seq(
                head_token(PUNC().dot),
                token.immediate(PUNC().dot),
                token.immediate(PUNC().eq),
              ),
              OPR().range_inclusive2,
            ),
            alias(
              seq(
                head_token(PUNC().dot),
                token.immediate(PUNC().dot),
                token.immediate(BRACK().open_angle),
              ),
              OPR().range_exclusive,
            ),
          ),
          step: alias(
            seq(head_token(PUNC().dot), token.immediate(PUNC().dot)),
            OPR().range_inclusive,
          ),
        };
      };

      const { opr, step: opr_step } = create_opr(false);
      const { opr: opr_imm, step: opr_step_imm } = create_opr(true);

      const member = choice(
        $.expr_parenthesized,
        alias($._val_number_decimal, $.val_number),
        $.val_variable,
      );
      const step_or_end = choice(
        $.expr_parenthesized,
        alias($._immediate_decimal, $.val_number),
        $.val_variable,
      );

      const start = field("start", member);
      const end = field("end", step_or_end);
      const step = field("step", step_or_end);

      return prec.right(
        PREC().range,
        choice(
          seq(start, opr_imm, end),
          seq(start, opr_imm),
          seq(opr, end),
          seq(start, opr_step_imm, step, opr_imm, end),
          seq(opr_step, step, opr_imm, end),
          seq(start, opr_step_imm, step, opr_imm),
        ),
      );
    },

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

    val_variable: ($) => choice($._var, seq($._var, $.cell_path)),

    _var: ($) =>
      seq(
        PUNC().dollar,
        field("name", choice("nu", "in", "env", $.identifier)),
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
      seq(field("value", $.val_number), field("unit", $.duration_unit)),

    val_filesize: ($) =>
      seq(field("value", $.val_number), field("unit", $.filesize_unit)),

    // prettier-ignore
    filesize_unit: (_$) => token(choice(
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
    duration_unit: (_$) => token(choice(
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
      seq(BRACK().open_paren, $._block_body, BRACK().close_paren),

    /// Collections

    val_list: ($) =>
      seq(
        BRACK().open_brack,
        optional($.list_body),
        BRACK().close_brack,
        optional($.cell_path),
      ),

    list_body: general_body_rules("entry", "val_entry", "_entry_separator"),

    val_entry: ($) =>
      prec(
        10,
        field(
          "item",
          choice(
            $._list_item_expression,
            alias($._unquoted_in_list, $.val_string),
            alias($.short_flag, $.val_string),
            alias($.long_flag, $.val_string),
            alias($._list_item_starts_with_sign, $.val_string),
          ),
        ),
      ),

    _list_item_expression: ($) =>
      choice(
        $._value,
        alias($._expr_unary_minus, $.expr_unary),
        $.val_range,
        $.expr_parenthesized,
      ),

    _list_item_starts_with_sign: (_$) =>
      seq(
        choice(token(OPR().minus), token(OPR().plus)),
        token.immediate(/[^\s\n\t\r{}()\[\]"`';]*/),
      ),

    val_record: ($) =>
      seq(
        BRACK().open_brace,
        optional($.record_body),
        BRACK().close_brace,
        optional($.cell_path),
      ),

    record_body: general_body_rules(
      "entry",
      "record_entry",
      "_entry_separator",
    ),

    _entry_separator: (_$) =>
      prec(20, token(choice(PUNC().comma, /\s/, /[\r\n]/))),

    record_entry: ($) =>
      seq(
        field(
          "key",
          choice(
            // Without $.cmd_identifier, cannot correctly distinguish between record and closure
            alias($.cmd_identifier, $.identifier),
            $.val_string,
            $.val_number,
            $.val_variable,
            $.expr_parenthesized,
            alias($._record_key, $.identifier),

            // This distinguish between record keys and keywords
            ...Object.values(KEYWORD()).map((x) => alias(x, $.identifier)),
            ...Object.values(MODIFIER()).map((x) => alias(x, $.identifier)),
          ),
        ),
        PUNC().colon,
        field(
          "value",
          choice(
            prec.right(10, $._expression),
            alias($.cmd_identifier, $.val_string),
          ),
        ),
      ),

    _record_key: (_$) =>
      choice(
        // This distinguish number and identifier starting with -/+
        seq(
          choice(token(OPR().minus), token(OPR().plus)),
          token.immediate(/[^\s\n\t\r{}()\[\]"`';:,]*/),
        ),
        token(
          prec(-69, /[^$\s\n\t\r{}()\[\]"`';:,][^\s\n\t\r{}()\[\]"`';:,]*/),
        ),
      ),

    val_table: ($) =>
      seq(
        BRACK().open_brack,
        field("head", seq($.val_list, PUNC().semicolon)),
        repeat(field("row", $.val_list)),
        BRACK().close_brack,
        optional($.cell_path),
      ),

    val_closure: ($) =>
      seq(
        BRACK().open_brace,
        optional(field("parameters", $.parameter_pipes)),
        $._block_body,
        BRACK().close_brace,
      ),

    /// CellPaths

    cell_path: ($) => prec.right(1, seq($.path, repeat($.path))),

    path: ($) => {
      const quoted = choice(
        $._str_double_quotes,
        $._str_single_quotes,
        $._str_back_ticks,
      );

      const path = choice(prec.right(2, token(/[0-9a-zA-Z_-]+/)), quoted);

      return seq(
        token.immediate(PUNC().dot),
        choice(
          field("raw_path", path),
          field("protected_path", seq(path, PUNC().question)),
        ),
      );
    },

    /// Commands

    command: ($) =>
      seq(
        choice(
          field("head", seq(optional(PUNC().caret), $.cmd_identifier)),
          field("head", seq(PUNC().caret, $.val_string)), // Support for ^'command' type of syntax.
          field("head", seq(PUNC().caret, $.expr_parenthesized)), // Support for pipes into external command.
        ),
        prec.dynamic(10, repeat($._cmd_arg)),
      ),

    _command_parenthesized_body: ($) =>
      prec.right(
        seq(
          choice(
            field("head", seq(optional(PUNC().caret), $.cmd_identifier)),
            field("head", seq(PUNC().caret, $.val_string)), // Support for ^'command' type of syntax.
            field("head", seq(PUNC().caret, $.expr_parenthesized)), // Support for pipes into external command.
          ),
          prec.dynamic(10, repeat(seq(optional("\n"), $._cmd_arg))),
          optional("\n"),
        ),
      ),

    _cmd_arg: ($) =>
      choice(
        field("redir", prec.right(10, $.redirection)),
        field("flag", prec.right(9, $._flag)),
        field("arg", prec.right(8, $._value)),
        field("arg", prec.right(8, $.val_range)),
        field("arg", prec.right(7, $.expr_parenthesized)),
        // lowest precedence to make it a last resort
        field("arg_str", alias($.unquoted, $.val_string)),
      ),

    redirection: ($) =>
      choice(
        prec.right(
          10,
          seq(
            choice(...REDIR()),
            field(
              "file_path",
              choice(alias($.unquoted, $.val_string), $._expression),
            ),
          ),
        ),
        ...REDIR(),
      ),

    _flag: ($) => prec.right(5, choice($.short_flag, $.long_flag)),

    short_flag: (_$) =>
      seq(token(OPR().minus), token.immediate(/[_\p{XID_Continue}]+/)),

    long_flag: ($) =>
      prec.right(
        10,
        choice(
          alias(seq(token(OPR().minus), token.immediate(OPR().minus)), "--"),
          seq(
            alias(seq(token(OPR().minus), token.immediate(OPR().minus)), "--"),
            $._long_flag_identifier,
          ),
        ),
      ),

    unquoted: _unquoted_rule(false),
    _unquoted_in_list: _unquoted_rule(true),

    /// Comments

    comment: (_$) => seq(PUNC().hash, /.*/),
  },
});

/**
 * @param {string} field_name
 * @param {string} entry
 * @param {string} separator
 */
function general_body_rules(field_name, entry, separator) {
  return (/** @type {{ [x: string]: RuleOrLiteral; }} */ $) =>
    prec(
      20,
      seq(
        repeat(seq(field(field_name, $[entry]), $[separator])), // Normal entries MUST have a separator
        seq(field(field_name, $[entry]), optional($[separator])), // Final entry may or may not have separator
      ),
    );
}

/**
 * @param {string} suffix
 * @param {{ (_$: any): string; (_$: any): ChoiceRule; (arg0: any): RuleOrLiteral; }} terminator
 */
function parenthesized_body_rules(suffix, terminator) {
  const parenthesized = "_parenthesized";
  return {
    ..._block_body_rules(`${parenthesized}${suffix}`),

    /// pipeline

    [`pipeline${parenthesized}${suffix}`]: (
      /** @type {{ pipe_element_parenthesized: RuleOrLiteral; pipe_element: string; pipe_element_parenthesized_last: RuleOrLiteral; }} */ $,
    ) =>
      prec.right(
        seq(
          repeat(alias($.pipe_element_parenthesized, $.pipe_element)),
          alias($.pipe_element_parenthesized_last, $.pipe_element),
          terminator($),
        ),
      ),
  };
}

/**
 * @param {string} suffix
 * @param {{ ($: { _terminator: any; }): any; ($: { _terminator: RuleOrLiteral; }): ChoiceRule; (arg0: any): RuleOrLiteral; }} terminator
 */
function block_body_rules(suffix, terminator) {
  return {
    ..._block_body_rules(suffix),

    /// pipeline

    [`pipeline${suffix}`]: (/** @type {any} */ $) =>
      prec.right(
        seq(
          repeat($.pipe_element),
          alias($.pipe_element_last, $.pipe_element),
          terminator($),
        ),
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
        1,
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
        1,
        seq(
          optional(MODIFIER().visibility),
          KEYWORD().const,
          $["_assignment_pattern" + suffix],
        ),
      ),

    ["_assignment_pattern" + suffix]: (
      /** @type {{ [x: string]: string; _variable_name?: any; param_type?: any; }} */ $,
    ) =>
      seq(
        field("name", $._variable_name),
        field("type", optional($.param_type)),
        PUNC().eq,
        field("value", alias_for_suffix($, "pipeline", suffix)),
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
        $.assignment,
        alias_for_suffix($, "stmt_let", suffix),
        alias_for_suffix($, "stmt_mut", suffix),
        alias_for_suffix($, "stmt_const", suffix),
        alias_for_suffix($, "pipeline", suffix),
      ),
  };
}

/**
 * @param {boolean} immediate
 */
function _decimal_rule(immediate) {
  const exponent = token.immediate(/[eE][-+]?[\d_]*\d[\d_]*/);
  const digits = token.immediate(/[\d_]*\d[\d_]*/);
  const head_token = immediate ? token.immediate : token;

  return (/** @type {any} */ _$) =>
    choice(
      seq(head_token(/[\d_]*\d[\d_]*/), optional(exponent)),
      seq(
        choice(head_token(OPR().minus), head_token(OPR().plus)),
        digits,
        optional(exponent),
      ),
      seq(
        head_token(/[\d_]*\d[\d_]*/),
        token.immediate(PUNC().dot),
        optional(digits),
        optional(exponent),
      ),
      seq(
        choice(head_token(OPR().minus), head_token(OPR().plus)),
        digits,
        token.immediate(PUNC().dot),
        optional(digits),
        optional(exponent),
      ),
      seq(head_token(PUNC().dot), digits, optional(exponent)),
      seq(
        choice(head_token(OPR().minus), head_token(OPR().plus)),
        optional(token.immediate(/_+/)),
        token.immediate(PUNC().dot),
        digits,
        optional(exponent),
      ),
    );
}

/**
 * @param {boolean} in_list
 */
function _unquoted_rule(in_list) {
  const pattern = in_list
    ? /[^-$\s\n\t\r{}()\[\]"`';,][^\s\n\t\r{}()\[\]"`';,]*/
    : /[^-$\s\n\t\r{}()\[\]"`';][^\s\n\t\r{}()\[\]"`';]*/;
  const pattern_repeat = in_list
    ? /[^\s\n\t\r{}()\[\]"`';,]*/
    : /[^\s\n\t\r{}()\[\]"`';]*/;
  const pattern_repeat1 = in_list
    ? /[^\s\n\t\r{}()\[\]"`';,]+/
    : /[^\s\n\t\r{}()\[\]"`';]+/;
  const pattern_once = in_list
    ? /[^\s\n\t\r{}()\[\]"`';,]/
    : /[^\s\n\t\r{}()\[\]"`';]/;
  const pattern_with_dot = in_list
    ? /[^\s\n\t\r{}()\[\]"`';,.]/
    : /[^\s\n\t\r{}()\[\]"`';.]/;
  const pattern_with_le = in_list
    ? /[^\s\n\t\r{}()\[\]"`';,=<]/
    : /[^\s\n\t\r{}()\[\]"`';=<]/;
  const pattern_with_dollar = in_list
    ? /[^\s\n\t\r{}()\[\]"`';,$]/
    : /[^\s\n\t\r{}()\[\]"`';$]/;

  // because this catches almost anything, we want to ensure it is
  // picked as the a last resort after everything else has failed.
  // so we give it a ridiculously low precedence and place it at the
  // very end
  return (
    /** @type {{ _val_number_decimal: RuleOrLiteral; _immediate_decimal: RuleOrLiteral; }} */ $,
  ) =>
    prec.left(
      -69,
      choice(
        token(prec(-69, token(pattern))),

        // distinguish between unquoted and val_range in cmd_arg
        seq(
          token(PUNC().dot),
          token.immediate(pattern_with_dot),
          token.immediate(pattern_repeat1),
        ),
        seq(
          token(PUNC().dot),
          token.immediate(PUNC().dot),
          token.immediate(pattern_with_le),
          token.immediate(pattern_repeat),
        ),
        seq(
          token(PUNC().dot),
          token.immediate(PUNC().dot),
          token.immediate(PUNC().eq),
          token.immediate(pattern_with_dollar),
          token.immediate(pattern_repeat),
        ),
        seq(
          token(PUNC().dot),
          token.immediate(PUNC().dot),
          token.immediate(BRACK().open_angle),
          token.immediate(pattern_with_dollar),
          token.immediate(pattern_repeat),
        ),
        seq(
          token(PUNC().dot),
          token.immediate(PUNC().dot),
          token.immediate(PUNC().dot),
          token.immediate(pattern_repeat),
        ),
        seq(
          token(PUNC().dot),
          token.immediate(PUNC().dot),
          choice(
            token.immediate(PUNC().eq),
            token.immediate(BRACK().open_angle),
          ),
        ),
        seq(
          token(PUNC().dot),
          token.immediate(PUNC().dot),
          optional(token.immediate(pattern_once)),
        ),
        seq(token(PUNC().dot), optional(token.immediate(pattern_with_dot))),

        // distinguish between $.val_number and unquoted string starting with numeric characters
        seq(
          choice(
            $._val_number_decimal,
            token(SPECIAL().pos_infinity),
            token(SPECIAL().neg_infinity),
            token(SPECIAL().not_a_number),
          ),
          token.immediate(pattern_once),
          token.immediate(pattern_repeat),
        ),

        // recognize unquoted string starting with numeric characters
        // e.g. 192.168.0.1
        seq(
          $._val_number_decimal,
          token.immediate(PUNC().dot),
          $._immediate_decimal,
          token.immediate(PUNC().dot),
          $._immediate_decimal,
          token.immediate(pattern_repeat1),
        ),
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

    open_brack: "[",
    close_brack: "]",

    open_brace: "{",
    close_brace: "}",

    open_paren: "(",
    close_paren: ")",
  };
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
  };
}

function STATEMENT_PREC() {
  return {
    control: 1,
  };
}

/// map of operators and their precedence
function TABLE() {
  const multiplicatives = choice(
    OPR().times,
    OPR().divide,
    OPR().modulo,
    OPR().floor,
  );

  const comparatives = choice(
    OPR().equal,
    OPR().not_equal,
    OPR().less_than,
    OPR().less_than_equal,
    OPR().greater_than,
    OPR().greater_than_equal,
  );

  const memberships = choice(
    OPR().in,
    OPR().not_in,
    OPR().starts_with,
    OPR().ends_with,
  );

  // `range` is not included here and is handled separately
  return [
    [PREC().power, choice(OPR().power, OPR().append)],
    [PREC().multiplicative, multiplicatives],
    [PREC().additive, choice(OPR().plus, OPR().minus)],
    [PREC().bit_shift, choice(OPR().bit_shl, OPR().bit_shr)],
    [PREC().comparative, comparatives],
    [PREC().membership, memberships],
    [PREC().regex, choice(OPR().regex_match, OPR().regex_not_match)],
    [PREC().bit_and, OPR().bit_and],
    [PREC().bit_xor, OPR().bit_xor],
    [PREC().bit_or, OPR().bit_or],
    [PREC().and, OPR().and],
    [PREC().xor, OPR().xor],
    [PREC().or, OPR().or],
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
