const PREC = {
    PAREN_DECLARATOR: -10,
    // PIPE: -5,
    DEFAULT: 0,
    LOGICAL_OR: 1,
    LOGICAL_AND: 2,
    // INCLUSIVE_OR: 3,
    // EXCLUSIVE_OR: 4,
    // BITWISE_AND: 5,
    EQUAL: 6,
    RELATIONAL: 7,
    SHIFT: 9,
    ADD: 10,
    MULTIPLY: 11,
    UNARY: 13,
    ASSIGN: 16,
};

const SPECIAL_CHARACTERS = [
    "'", '"', '`', '@',
    '{', '}',
    '\\[', '\\]',
    '(', ')',
    '\\', '\\s',
    '$', ';', '.', '|',
    '#',
    '\\-',
];

const OPERATOR_PREC = [
    // ['|', PREC.PIPE],
    ['+', PREC.ADD],
    ['-', PREC.ADD],
    ['*', PREC.MULTIPLY],
    ['/', PREC.MULTIPLY],
    ['%', PREC.MULTIPLY],
    ['=', PREC.ASSIGN],
    ['mod', PREC.MULTIPLY],
    ['||', PREC.LOGICAL_OR],
    ['&&', PREC.LOGICAL_AND],
    // ['^', PREC.EXCLUSIVE_OR],
    // ['&', PREC.BITWISE_AND],
    ['=~', PREC.EQUAL],
    ['==', PREC.EQUAL],
    ['!=', PREC.EQUAL],
    ['in', PREC.EQUAL],
    ['>', PREC.RELATIONAL],
    ['>=', PREC.RELATIONAL],
    ['<=', PREC.RELATIONAL],
    ['<', PREC.RELATIONAL],
    ['<<', PREC.SHIFT],
    ['>>', PREC.SHIFT],
];


module.exports = grammar({
    name: 'nu',

    // rules: {
    //   // TODO: add the actual grammar rules
    //   source_file: $ => 'hello'
    // }
    rules: {
        source_file: $ => repeat($._definition),

        _statements: $ => seq(
            repeat(seq(
                $._statement,
                $._line_terminator
            )),
            $._statement,
            optional($._line_terminator)
        ),

        _statement: $ => choice(
            $.variable_declaration,
            $.env_export,
            $.function_definition,
            $.alias,
            $.if_statement,
            $._expression,
            // A record entry is not a 'real' statement, but treating it as such
            // makes life much easier
            repeat1(seq($.record_entry, optional(",")))
        ),

        variable_declaration: $ => seq(
            'let',
            choice(field('name', $.identifier), $.number_literal),
            '=',
            field('value', $._expression),
        ),

        _definition: $ => choice(
            $.function_definition
            // TODO: other kinds of definitions
        ),

        def_open_chars: $ => choice(
            '[',
            '(',
        ),
        def_close_chars: $ => choice(
            ']',
            ')',
        ),
        def_type_separator: $ => choice(
            ':',
        ),
        _line_terminator: $ => choice(
            '\n',
            '\r',
            '\r\n',
            '|',
            ';'
        ),
        signature: $ => seq(
            choice('[', '('),
            repeat(
                seq(
                    choice(
                        $.parameter,
                        $.flag,
                        $.rest
                    ),
                    optional(',')
                )
            ),
            choice(']', ')')
        ),
        parameter: $ => seq(
            $.identifier,
            optional(seq(':', $.type)),
            optional('?'),
            optional($.default_parameter_assignment),
        ),
        flag: $ => seq(
            $.flag_name,
            optional(
                seq('(', $.flag_shorthand_name, ')')
            ),
            optional(seq(':', $.type)),
            optional($.default_parameter_assignment),
        ),
        flag_name: $ => /--[a-zA-Z_]+[a-zA-Z_0-9]*/,
        flag_shorthand_name: $ => /-[a-zA-Z0-9]/,
        rest: $ => seq(
            '...rest',
            optional(seq(':', $.type)),
        ),
        default_parameter_assignment: $ => seq(
            choice(
                seq("=", $._cmd_expr),
                seq("@", $.identifier))
        ),
        function_definition: $ => seq(
            optional('export'),
            'def',
            field('custom_command_name', choice($.identifier, $.string)),
            $.signature,
            $.block
        ),

        parameter_list: $ => seq(
            '(',
            // TODO: parameters
            ')'
        ),

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

        string: $ => seq(optional('$'), choice(
            seq(
                '"',
                token(prec(-1, /[^"]*/)),
                '"'
            ),
            seq(
                '\'',
                token(prec(-1, /([^']|)*/)),
                '\''
            ),
            seq(
                '`',
                token(prec(-1, /[^`]*/)),
                '`'
            ),
        )),

        number_literal: $ => /[\d]+(\.[\d]+)?/,

        value_path: $ => seq(
            '$',
            choice($.identifier, $.number_literal),
            repeat(seq(token.immediate('.'), choice($.identifier, $.number_literal)))
        ),

        file_path: $ => choice(
            // '-', //previous pwd (conflicts with operator)
            /[^\S\r\n]\.\.|\s\.[^\S\r\n]/, //Expect ws before .|.. and after (but exclude newline)
            /(([\w\-\.~]+\/)*)([\w\-\.~]+)\.\w+/, //filepath must end with <.file_ending> for now
        ),

        flag_arg: $ => /-?-[a-zA-Z_]+[a-zA-Z_0-9\-]*/,

        range: $ => seq(
            field('from', $.number_literal),
            '..',
            field('to', $.number_literal),
        ),

        word: $ => token(prec(-1, repeat1(choice(
            noneOf(...SPECIAL_CHARACTERS),
            seq('\\', noneOf('\\s'))
        )))),

        // In LR(1) its undecidable whether `{ ident ... }` is a record or block
        // backtracking is not allowed in ts. Therefore we have a catch both rule
        record_or_block: $ => seq(
            '{',
            optional($.block_args),
            optional($._statements),
            '}'
        ),

        block: $ => seq(
            '{',
            optional($.block_args),
            optional($._statements),
            '}'
        ),

        block_args: $ => seq(
            '|',
            repeat(seq(field("block_param", $.identifier), optional(','))),
            '|',
        ),

        _statement: $ => choice(
            $._expression
            // TODO: other kinds of statements
        ),

        _expression: $ => choice(
            $.identifier,
        ),

        table: $ => seq(
            '[', $.array, ';', repeat($.array), ']'
        ),

        array: $ => seq(
            '[', repeat(seq($._expression, optional(','))), ']'
        ),

        _cmd_expr: $ => choice(
            $.identifier,
            $.number_literal,
            $.string,
            $.value_path,
            $.file_path, // TODO
            $.flag_arg,
            $.range,
            $.record_or_block,
            // $.operator,
            $.cmd_invocation,
            $.table,
            $.array,
            $.binary_expression,
            $.word,
        ),

        identifier: $ => /[a-zA-Z_][a-zA-Z0-9_\-]*/,

        cmd_invocation: $ => seq(
            '(',
            $._statements,
            ')',
            repeat(seq(token.immediate('.'), choice($.identifier, $.number_literal)))
        ),

        operator: $ => choice(...OPERATOR_PREC.map(([operator, _]) => {
            return seq(operator)
        })),

        binary_expression: $ => {
            return choice(...OPERATOR_PREC.map(([operator, precedence]) => {
                return prec.left(precedence, seq(
                    field('left', $._expression),
                    field('operator', operator),
                    field('right', $._expression)
                ))
            }));
        },
    }
});

function noneOf(...characters) {
    const negatedString = characters.map(c => c == '\\' ? '\\\\' : c).join('')
    return new RegExp('[^' + negatedString + ']')
}