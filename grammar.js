// Precedence with the highest number has the highest precedence.
// Taken from nushell
const PRECEDENCE = {
    RANGE: 110,
    POW: 100,
    MULTIPLY: 95,
    DIVIDE: 95,
    MODULO: 95,
    FLOOR_DIVISION: 95,
    PLUS: 90,
    MINUS: 90,
    SHIFT_LEFT: 85,
    SHIFT_RIGHT: 85,
    NOT_REGEX_MATCH: 80,
    REGEX_MATCH: 80,
    STARTS_WITH: 80,
    ENDS_WITH: 80,
    LESS_THAN: 80,
    LESS_THAN_OR_EQUAL: 80,
    GREATER_THAN: 80,
    GREATER_THAN_OR_EQUAL: 80,
    EQUAL: 80,
    NOT_EQUAL: 80,
    IN: 80,
    NOT_IN: 80,
    BIT_AND: 75,
    BIT_XOR: 70,
    BIT_OR: 60,
    AND: 50,
    OR: 40,
    ASSIGN: 0,
};

const SPECIAL_CHARACTERS = [
    "'", '"', '`',  // supported quotes
    '@', // custom completion
    '{', '}', // braces
    '\\[', '\\]', // brackets
    '(', ')', // parentheses
    '\\', // backslash
    '$',  // dollar sign
    ';', // semicolon
    '|', // pipe
    '#', // hash
];

// Mapping operators to prcedence names. Taken from nushell with a few additions.
const OPERATOR_PRECEDENCE = [
    ['==', PRECEDENCE.EQUAL],
    ['!=', PRECEDENCE.NOT_EQUAL],
    ['<', PRECEDENCE.LESS_THAN],
    ['<=', PRECEDENCE.LESS_THAN_OR_EQUAL],
    ['>', PRECEDENCE.GREATER_THAN],
    ['>=', PRECEDENCE.GREATER_THAN_OR_EQUAL],
    ['=~', PRECEDENCE.REGEX_MATCH],
    ['!~', PRECEDENCE.NOT_REGEX_MATCH],
    ['+', PRECEDENCE.PLUS],
    ['-', PRECEDENCE.MINUS],
    ['*', PRECEDENCE.MULTIPLY],
    ['/', PRECEDENCE.DIVIDE],
    ['//', PRECEDENCE.FLOOR_DIVISION],
    ['in', PRECEDENCE.IN],
    ['not-in', PRECEDENCE.NOT_IN],
    ['mod', PRECEDENCE.MODULO],
    ['%', PRECEDENCE.MODULO],
    ['bit-or', PRECEDENCE.BIT_OR],
    ['bit-xor', PRECEDENCE.BIT_XOR],
    ['bit-and', PRECEDENCE.BIT_AND],
    ['bit-shl', PRECEDENCE.SHIFT_LEFT],
    ['<<', PRECEDENCE.SHIFT_LEFT],
    ['bit-shr', PRECEDENCE.SHIFT_RIGHT],
    ['>>', PRECEDENCE.SHIFT_RIGHT],
    ['starts-with', PRECEDENCE.STARTS_WITH],
    ['ends-with', PRECEDENCE.ENDS_WITH],
    ['&&', PRECEDENCE.AND],
    ['and', PRECEDENCE.AND],
    ['||', PRECEDENCE.OR],
    ['or', PRECEDENCE.OR],
    ['**', PRECEDENCE.POW],
];


module.exports = grammar({
    name: 'nu',

    conflicts: $ => [
        [$.block, $.expression_statement]
    ],
    
    extras: $ => [/\s/, $.line_comment,],// $.block_comment],

    rules: {

        //robi since she was conceived in Nairobi, Kenya

        // source_file: $ => repeat($.custom_command),
        source_file: $ => repeat($._statement),

        _statement: $ => choice(
            $.expression_statement,
            $._declaration_statement
        ),

        comment: $ => choice(
            $.line_comment,
            // $.block_comment
        ),

        line_comment: $ => token(seq(
            '#',
        )),

        // How lines can end
        line_terminator: $ => choice(
            '\n',
            '\r',
            '\r\n',
            '|',
            ';'
        ),

        // Custom command definition
        custom_command: $ => seq(
            $.custom_command_signature,
            prec(1, $.block),
            ),

        // Custom command signature
        custom_command_signature: $ => seq(
            'def',
            field('custom_command_name', $.identifier),
            choice('[', '('),
            repeat($.parameter),
            choice(']', ')'),
        ),

        // identifier: $ => /[[:alpha:]_\-][a-zA-Z0-9_\-]*/,
        identifier: $ => /[_\p{XID_Start}][_\p{XID_Continue}]*/,

        parameter: $ => seq(
            // optional($.mutable_specifier),
            field('pattern', $.identifier),
            optional('?'),
            optional(seq(':', field('type', $.type))),
            optional(','),
        ),

        // nushell types, taken from parser.rs fn parse_type()
        type: $ => choice(
            "int",
            "float",
            "range",
            "bool",
            "string",
            "block",
            "duration",
            "date",
            "filesize",
            "number",
            "table",
            "error",
            "binary",
        ),

        block: $ => seq(
            '{',
            repeat($._statement),
            optional($._expression),
            '}'
        ),


        expression_statement: $ => choice(
            seq($._expression, optional(';')),
            prec(1, $._expression_ending_with_block)
        ),

        _expression: $ => choice(
            $._expression_except_range,
            $.range_expression,
        ),

        _expression_except_range: $ => choice(
            // $.unary_expression,
            // $.reference_expression,
            // $.try_expression,
            // $.binary_expression,
            $.assignment_expression,
            // $.compound_assignment_expr,
            // $.type_cast_expression,
            // $.call_expression,
            // $.return_expression,
            // $.yield_expression,
            $._literal,
            prec.left($.identifier),
            // alias(choice(...primitive_types), $.identifier),
            // prec.left($._reserved_identifier),
            // $.self,
            // $.scoped_identifier,
            // $.generic_function,
            // $.await_expression,
            // $.field_expression,
            // $.array_expression,
            // $.tuple_expression,
            // prec(1, $.macro_invocation),
            // $.unit_expression,
            // $.break_expression,
            // $.continue_expression,
            // $.index_expression,
            $.metavariable,
            // $.closure_expression,
            // $.parenthesized_expression,
            // $.struct_expression,
            // $._expression_ending_with_block,
        ),

        metavariable: $ => /\$[a-zA-Z_]\w*/,

        assignment_expression: $ => prec.left(PRECEDENCE.ASSIGN, seq(
            field('left', $._expression),
            '=',
            field('right', $._expression)
        )),

        range_expression: $ => prec.left(PRECEDENCE.RANGE, choice(
            seq($._expression, choice('..', '...', '..='), $._expression),
            seq($._expression, '..'),
            seq('..', $._expression),
            '..'
        )),

        _expression_ending_with_block: $ => choice(
            // $.unsafe_block,
            // $.async_block,
            $.block,
            // $.if_expression,
            // $.if_let_expression,
            // $.match_expression,
            // $.while_expression,
            // $.while_let_expression,
            // $.loop_expression,
            // $.for_expression,
            // $.const_block
        ),

        _declaration_statement: $ => choice(
            // $.const_item,
            // $.macro_invocation,
            // $.macro_definition,
            // $.empty_statement,
            // $.attribute_item,
            // $.inner_attribute_item,
            // $.mod_item,
            // $.foreign_mod_item,
            // $.struct_item,
            // $.union_item,
            // $.enum_item,
            // $.type_item,
            // $.function_item,
            // $.function_signature_item,
            $.custom_command_signature,
            // $.impl_item,
            // $.trait_item,
            // $.associated_type,
            $.let_declaration,
            // $.use_declaration,
            // $.extern_crate_declaration,
            // $.static_item
        ),

        let_declaration: $ => seq(
            'let',
            optional($.mutable_specifier),
            field('pattern', $._pattern),
            optional(seq(
                ':',
                field('type', $._type)
            )),
            // optional(seq(
            //     '=',
            //     field('value', $._expression)
            // )),
            seq(
                '=',
                field('value', $._expression)
            ),
           optional(';')
        ),

        mutable_specifier: $ => 'mut',

        _pattern: $ => choice(
            $._literal_pattern,
            // alias(choice(...primitive_types), $.identifier),
            $.identifier,
            // $.scoped_identifier,
            // $.tuple_pattern,
            // $.tuple_struct_pattern,
            // $.struct_pattern,
            // $.ref_pattern,
            // $.slice_pattern,
            // $.captured_pattern,
            // $.reference_pattern,
            // $.remaining_field_pattern,
            $.mut_pattern,
            $.range_pattern,
            // $.or_pattern,
            // $.const_block,
            // $.macro_invocation,
            '_'
        ),

        mut_pattern: $ => prec(-1, seq(
            $.mutable_specifier,
            $._pattern
        )),

        range_pattern: $ => seq(
            choice(
                $._literal_pattern,
                $._path,
            ),
            choice('...', '..='),
            choice(
                $._literal_pattern,
                $._path,
            ),
        ),

        _literal_pattern: $ => choice(
            $.string_literal,
            // $.raw_string_literal,
            $.char_literal,
            $.boolean_literal,
            $.integer_literal,
            // $.float_literal,
            $.negative_literal,
        ),

        _literal: $ => choice(
            $.string_literal,
            // $.raw_string_literal,
            $.char_literal,
            $.boolean_literal,
            $.integer_literal,
            // $.float_literal,
        ),

        string_literal: $ => seq(
            alias(/b?"/, '"'),
            repeat(choice(
                $.escape_sequence,
                // $._string_content
            )),
            token.immediate('"')
        ),

        integer_literal: $ => token(seq(
            choice(
                /[0-9][0-9_]*/,
                /0x[0-9a-fA-F_]+/,
                /0b[01_]+/,
                /0o[0-7_]+/
            ),
            // optional(choice(...numeric_types))
        )),

        negative_literal: $ => seq('-', choice($.integer_literal)),// $.float_literal)),

        char_literal: $ => token(seq(
            // optional('b'),
            '\'',
            optional(choice(
                seq('\\', choice(
                    /[^xu]/,
                    /u[0-9a-fA-F]{4}/,
                    /u{[0-9a-fA-F]+}/,
                    /x[0-9a-fA-F]{2}/
                )),
                /[^\\']/
            )),
            '\''
        )),

        escape_sequence: $ => token.immediate(
            seq('\\',
                choice(
                    /[^xu]/,
                    /u[0-9a-fA-F]{4}/,
                    /u{[0-9a-fA-F]+}/,
                    /x[0-9a-fA-F]{2}/
                )
            )
        ),

        boolean_literal: $ => choice('true', 'false'),

        _type: $ => choice(
            // $.abstract_type,
            // $.reference_type,
            $.metavariable,
            // $.pointer_type,
            // $.generic_type,
            // $.scoped_type_identifier,
            // $.tuple_type,
            // $.unit_type,
            // $.array_type,
            // $.function_type,
            $._type_identifier,
            // $.macro_invocation,
            // $.empty_type,
            // $.dynamic_type,
            // $.bounded_type,
            // alias(choice(...primitive_types), $.primitive_type)
        ),

        _type_identifier: $ => alias($.identifier, $.type_identifier),

        _path: $ => choice(
            // $.self,
            // alias(choice(...primitive_types), $.identifier),
            $.metavariable,
            // $.super,
            // $.crate,
            $.identifier,
            // $.scoped_identifier,
            // $._reserved_identifier,
        ),
    }
});
