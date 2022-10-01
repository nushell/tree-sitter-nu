const PRECEDENCE = {
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