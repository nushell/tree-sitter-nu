#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 89
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 82
#define ALIAS_COUNT 1
#define TOKEN_COUNT 48
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 11

enum {
  sym_line_comment = 1,
  anon_sym_PIPE = 2,
  anon_sym_SEMI = 3,
  anon_sym_def = 4,
  anon_sym_LBRACK = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RBRACK = 7,
  anon_sym_RPAREN = 8,
  sym_identifier = 9,
  anon_sym_QMARK = 10,
  anon_sym_COLON = 11,
  anon_sym_COMMA = 12,
  anon_sym_int = 13,
  anon_sym_float = 14,
  anon_sym_range = 15,
  anon_sym_bool = 16,
  anon_sym_string = 17,
  anon_sym_block = 18,
  anon_sym_duration = 19,
  anon_sym_date = 20,
  anon_sym_filesize = 21,
  anon_sym_number = 22,
  anon_sym_table = 23,
  anon_sym_error = 24,
  anon_sym_binary = 25,
  anon_sym_LBRACE = 26,
  anon_sym_RBRACE = 27,
  sym_metavariable = 28,
  anon_sym_EQ = 29,
  anon_sym_DOT_DOT = 30,
  anon_sym_DOT_DOT_DOT = 31,
  anon_sym_DOT_DOT_EQ = 32,
  anon_sym_let = 33,
  sym_mutable_specifier = 34,
  anon_sym__ = 35,
  anon_sym_DQUOTE = 36,
  aux_sym__double_quoted_string_literal_token1 = 37,
  anon_sym_SQUOTE = 38,
  aux_sym__single_quoted_string_literal_token1 = 39,
  anon_sym_BQUOTE = 40,
  aux_sym__backticked_quoted_string_literal_token1 = 41,
  sym_integer_literal = 42,
  anon_sym_DASH = 43,
  sym_char_literal = 44,
  sym_escape_sequence = 45,
  anon_sym_true = 46,
  anon_sym_false = 47,
  sym_source_file = 48,
  sym__statement = 49,
  sym_custom_command = 50,
  sym_custom_command_signature = 51,
  sym_parameter = 52,
  sym_type = 53,
  sym_block = 54,
  sym_expression_statement = 55,
  sym__expression = 56,
  sym__expression_except_range = 57,
  sym_assignment_expression = 58,
  sym_range_expression = 59,
  sym__expression_ending_with_block = 60,
  sym__declaration_statement = 61,
  sym_let_declaration = 62,
  sym__pattern = 63,
  sym_mut_pattern = 64,
  sym_range_pattern = 65,
  sym__literal_pattern = 66,
  sym__literal = 67,
  sym__double_quoted_string_literal = 68,
  sym__single_quoted_string_literal = 69,
  sym__backticked_quoted_string_literal = 70,
  sym_string_literal = 71,
  sym_negative_literal = 72,
  sym_boolean_literal = 73,
  sym__type = 74,
  sym__type_identifier = 75,
  sym__path = 76,
  aux_sym_source_file_repeat1 = 77,
  aux_sym_custom_command_signature_repeat1 = 78,
  aux_sym__double_quoted_string_literal_repeat1 = 79,
  aux_sym__single_quoted_string_literal_repeat1 = 80,
  aux_sym__backticked_quoted_string_literal_repeat1 = 81,
  alias_sym_type_identifier = 82,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_line_comment] = "line_comment",
  [anon_sym_PIPE] = "|",
  [anon_sym_SEMI] = ";",
  [anon_sym_def] = "def",
  [anon_sym_LBRACK] = "[",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RBRACK] = "]",
  [anon_sym_RPAREN] = ")",
  [sym_identifier] = "identifier",
  [anon_sym_QMARK] = "\?",
  [anon_sym_COLON] = ":",
  [anon_sym_COMMA] = ",",
  [anon_sym_int] = "int",
  [anon_sym_float] = "float",
  [anon_sym_range] = "range",
  [anon_sym_bool] = "bool",
  [anon_sym_string] = "string",
  [anon_sym_block] = "block",
  [anon_sym_duration] = "duration",
  [anon_sym_date] = "date",
  [anon_sym_filesize] = "filesize",
  [anon_sym_number] = "number",
  [anon_sym_table] = "table",
  [anon_sym_error] = "error",
  [anon_sym_binary] = "binary",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_metavariable] = "metavariable",
  [anon_sym_EQ] = "=",
  [anon_sym_DOT_DOT] = "..",
  [anon_sym_DOT_DOT_DOT] = "...",
  [anon_sym_DOT_DOT_EQ] = "..=",
  [anon_sym_let] = "let",
  [sym_mutable_specifier] = "mutable_specifier",
  [anon_sym__] = "_",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym__double_quoted_string_literal_token1] = "_double_quoted_string_literal_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym__single_quoted_string_literal_token1] = "_single_quoted_string_literal_token1",
  [anon_sym_BQUOTE] = "`",
  [aux_sym__backticked_quoted_string_literal_token1] = "_backticked_quoted_string_literal_token1",
  [sym_integer_literal] = "integer_literal",
  [anon_sym_DASH] = "-",
  [sym_char_literal] = "char_literal",
  [sym_escape_sequence] = "escape_sequence",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_custom_command] = "custom_command",
  [sym_custom_command_signature] = "custom_command_signature",
  [sym_parameter] = "parameter",
  [sym_type] = "type",
  [sym_block] = "block",
  [sym_expression_statement] = "expression_statement",
  [sym__expression] = "_expression",
  [sym__expression_except_range] = "_expression_except_range",
  [sym_assignment_expression] = "assignment_expression",
  [sym_range_expression] = "range_expression",
  [sym__expression_ending_with_block] = "_expression_ending_with_block",
  [sym__declaration_statement] = "_declaration_statement",
  [sym_let_declaration] = "let_declaration",
  [sym__pattern] = "_pattern",
  [sym_mut_pattern] = "mut_pattern",
  [sym_range_pattern] = "range_pattern",
  [sym__literal_pattern] = "_literal_pattern",
  [sym__literal] = "_literal",
  [sym__double_quoted_string_literal] = "_double_quoted_string_literal",
  [sym__single_quoted_string_literal] = "_single_quoted_string_literal",
  [sym__backticked_quoted_string_literal] = "_backticked_quoted_string_literal",
  [sym_string_literal] = "string_literal",
  [sym_negative_literal] = "negative_literal",
  [sym_boolean_literal] = "boolean_literal",
  [sym__type] = "_type",
  [sym__type_identifier] = "_type_identifier",
  [sym__path] = "_path",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_custom_command_signature_repeat1] = "custom_command_signature_repeat1",
  [aux_sym__double_quoted_string_literal_repeat1] = "_double_quoted_string_literal_repeat1",
  [aux_sym__single_quoted_string_literal_repeat1] = "_single_quoted_string_literal_repeat1",
  [aux_sym__backticked_quoted_string_literal_repeat1] = "_backticked_quoted_string_literal_repeat1",
  [alias_sym_type_identifier] = "type_identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_line_comment] = sym_line_comment,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_def] = anon_sym_def,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_identifier] = sym_identifier,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_range] = anon_sym_range,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_block] = anon_sym_block,
  [anon_sym_duration] = anon_sym_duration,
  [anon_sym_date] = anon_sym_date,
  [anon_sym_filesize] = anon_sym_filesize,
  [anon_sym_number] = anon_sym_number,
  [anon_sym_table] = anon_sym_table,
  [anon_sym_error] = anon_sym_error,
  [anon_sym_binary] = anon_sym_binary,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_metavariable] = sym_metavariable,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [anon_sym_DOT_DOT_DOT] = anon_sym_DOT_DOT_DOT,
  [anon_sym_DOT_DOT_EQ] = anon_sym_DOT_DOT_EQ,
  [anon_sym_let] = anon_sym_let,
  [sym_mutable_specifier] = sym_mutable_specifier,
  [anon_sym__] = anon_sym__,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym__double_quoted_string_literal_token1] = aux_sym__double_quoted_string_literal_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym__single_quoted_string_literal_token1] = aux_sym__single_quoted_string_literal_token1,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym__backticked_quoted_string_literal_token1] = aux_sym__backticked_quoted_string_literal_token1,
  [sym_integer_literal] = sym_integer_literal,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_char_literal] = sym_char_literal,
  [sym_escape_sequence] = sym_escape_sequence,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_custom_command] = sym_custom_command,
  [sym_custom_command_signature] = sym_custom_command_signature,
  [sym_parameter] = sym_parameter,
  [sym_type] = sym_type,
  [sym_block] = sym_block,
  [sym_expression_statement] = sym_expression_statement,
  [sym__expression] = sym__expression,
  [sym__expression_except_range] = sym__expression_except_range,
  [sym_assignment_expression] = sym_assignment_expression,
  [sym_range_expression] = sym_range_expression,
  [sym__expression_ending_with_block] = sym__expression_ending_with_block,
  [sym__declaration_statement] = sym__declaration_statement,
  [sym_let_declaration] = sym_let_declaration,
  [sym__pattern] = sym__pattern,
  [sym_mut_pattern] = sym_mut_pattern,
  [sym_range_pattern] = sym_range_pattern,
  [sym__literal_pattern] = sym__literal_pattern,
  [sym__literal] = sym__literal,
  [sym__double_quoted_string_literal] = sym__double_quoted_string_literal,
  [sym__single_quoted_string_literal] = sym__single_quoted_string_literal,
  [sym__backticked_quoted_string_literal] = sym__backticked_quoted_string_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_negative_literal] = sym_negative_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym__type] = sym__type,
  [sym__type_identifier] = sym__type_identifier,
  [sym__path] = sym__path,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_custom_command_signature_repeat1] = aux_sym_custom_command_signature_repeat1,
  [aux_sym__double_quoted_string_literal_repeat1] = aux_sym__double_quoted_string_literal_repeat1,
  [aux_sym__single_quoted_string_literal_repeat1] = aux_sym__single_quoted_string_literal_repeat1,
  [aux_sym__backticked_quoted_string_literal_repeat1] = aux_sym__backticked_quoted_string_literal_repeat1,
  [alias_sym_type_identifier] = alias_sym_type_identifier,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_range] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_block] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_duration] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_date] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_filesize] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_number] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_table] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_error] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_binary] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_metavariable] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [sym_mutable_specifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__double_quoted_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__single_quoted_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__backticked_quoted_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym_char_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_custom_command] = {
    .visible = true,
    .named = true,
  },
  [sym_custom_command_signature] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__expression_except_range] = {
    .visible = false,
    .named = true,
  },
  [sym_assignment_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_range_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__expression_ending_with_block] = {
    .visible = false,
    .named = true,
  },
  [sym__declaration_statement] = {
    .visible = false,
    .named = true,
  },
  [sym_let_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__pattern] = {
    .visible = false,
    .named = true,
  },
  [sym_mut_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_range_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym__literal_pattern] = {
    .visible = false,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym__double_quoted_string_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__single_quoted_string_literal] = {
    .visible = false,
    .named = true,
  },
  [sym__backticked_quoted_string_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_negative_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym__type_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym__path] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_custom_command_signature_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__double_quoted_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__single_quoted_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__backticked_quoted_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_custom_command_name = 1,
  field_left = 2,
  field_pattern = 3,
  field_right = 4,
  field_type = 5,
  field_value = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_custom_command_name] = "custom_command_name",
  [field_left] = "left",
  [field_pattern] = "pattern",
  [field_right] = "right",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [6] = {.index = 6, .length = 2},
  [7] = {.index = 8, .length = 2},
  [8] = {.index = 10, .length = 3},
  [9] = {.index = 13, .length = 2},
  [10] = {.index = 15, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_left, 0},
    {field_right, 2},
  [2] =
    {field_custom_command_name, 1},
  [3] =
    {field_pattern, 0},
  [4] =
    {field_pattern, 1},
    {field_value, 3},
  [6] =
    {field_pattern, 2},
    {field_value, 4},
  [8] =
    {field_pattern, 0},
    {field_type, 2},
  [10] =
    {field_pattern, 1},
    {field_type, 3},
    {field_value, 5},
  [13] =
    {field_pattern, 0},
    {field_type, 3},
  [15] =
    {field_pattern, 2},
    {field_type, 4},
    {field_value, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [4] = {
    [0] = alias_sym_type_identifier,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
};

static inline bool sym_identifier_character_set_1(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 931
            ? (c < 748
              ? (c < 192
                ? (c < 170
                  ? (c < '_'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= 'z')
                  : (c <= 170 || (c < 186
                    ? c == 181
                    : c <= 186)))
                : (c <= 214 || (c < 710
                  ? (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)
                  : (c <= 721 || (c >= 736 && c <= 740)))))
              : (c <= 748 || (c < 895
                ? (c < 886
                  ? (c < 880
                    ? c == 750
                    : c <= 884)
                  : (c <= 887 || (c >= 891 && c <= 893)))
                : (c <= 895 || (c < 908
                  ? (c < 904
                    ? c == 902
                    : c <= 906)
                  : (c <= 908 || (c >= 910 && c <= 929)))))))
            : (c <= 1013 || (c < 1649
              ? (c < 1376
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1015 && c <= 1153)
                    : c <= 1327)
                  : (c <= 1366 || c == 1369))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_identifier_character_set_2(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 931
            ? (c < 748
              ? (c < 192
                ? (c < 170
                  ? (c < 'a'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= 'z')
                  : (c <= 170 || (c < 186
                    ? c == 181
                    : c <= 186)))
                : (c <= 214 || (c < 710
                  ? (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)
                  : (c <= 721 || (c >= 736 && c <= 740)))))
              : (c <= 748 || (c < 895
                ? (c < 886
                  ? (c < 880
                    ? c == 750
                    : c <= 884)
                  : (c <= 887 || (c >= 891 && c <= 893)))
                : (c <= 895 || (c < 908
                  ? (c < 904
                    ? c == 902
                    : c <= 906)
                  : (c <= 908 || (c >= 910 && c <= 929)))))))
            : (c <= 1013 || (c < 1649
              ? (c < 1376
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1015 && c <= 1153)
                    : c <= 1327)
                  : (c <= 1366 || c == 1369))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_identifier_character_set_3(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 910
            ? (c < 736
              ? (c < 186
                ? (c < 'a'
                  ? (c < '_'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= '_')
                  : (c <= 'z' || (c < 181
                    ? c == 170
                    : c <= 181)))
                : (c <= 186 || (c < 248
                  ? (c < 216
                    ? (c >= 192 && c <= 214)
                    : c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))))
              : (c <= 740 || (c < 891
                ? (c < 880
                  ? (c < 750
                    ? c == 748
                    : c <= 750)
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 904
                  ? (c < 902
                    ? c == 895
                    : c <= 902)
                  : (c <= 906 || c == 908))))))
            : (c <= 929 || (c < 1649
              ? (c < 1376
                ? (c < 1162
                  ? (c < 1015
                    ? (c >= 931 && c <= 1013)
                    : c <= 1153)
                  : (c <= 1327 || (c < 1369
                    ? (c >= 1329 && c <= 1366)
                    : c <= 1369)))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_identifier_character_set_4(int32_t c) {
  return (c < 43616
    ? (c < 3782
      ? (c < 2748
        ? (c < 2045
          ? (c < 1015
            ? (c < 710
              ? (c < 181
                ? (c < '_'
                  ? (c < 'A'
                    ? (c >= '0' && c <= '9')
                    : c <= 'Z')
                  : (c <= '_' || (c < 170
                    ? (c >= 'a' && c <= 'z')
                    : c <= 170)))
                : (c <= 181 || (c < 192
                  ? (c < 186
                    ? c == 183
                    : c <= 186)
                  : (c <= 214 || (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)))))
              : (c <= 721 || (c < 891
                ? (c < 750
                  ? (c < 748
                    ? (c >= 736 && c <= 740)
                    : c <= 748)
                  : (c <= 750 || (c < 886
                    ? (c >= 768 && c <= 884)
                    : c <= 887)))
                : (c <= 893 || (c < 908
                  ? (c < 902
                    ? c == 895
                    : c <= 906)
                  : (c <= 908 || (c < 931
                    ? (c >= 910 && c <= 929)
                    : c <= 1013)))))))
            : (c <= 1153 || (c < 1519
              ? (c < 1425
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1155 && c <= 1159)
                    : c <= 1327)
                  : (c <= 1366 || (c < 1376
                    ? c == 1369
                    : c <= 1416)))
                : (c <= 1469 || (c < 1476
                  ? (c < 1473
                    ? c == 1471
                    : c <= 1474)
                  : (c <= 1477 || (c < 1488
                    ? c == 1479
                    : c <= 1514)))))
              : (c <= 1522 || (c < 1770
                ? (c < 1646
                  ? (c < 1568
                    ? (c >= 1552 && c <= 1562)
                    : c <= 1641)
                  : (c <= 1747 || (c < 1759
                    ? (c >= 1749 && c <= 1756)
                    : c <= 1768)))
                : (c <= 1788 || (c < 1869
                  ? (c < 1808
                    ? c == 1791
                    : c <= 1866)
                  : (c <= 1969 || (c < 2042
                    ? (c >= 1984 && c <= 2037)
                    : c <= 2042)))))))))
          : (c <= 2045 || (c < 2558
            ? (c < 2451
              ? (c < 2200
                ? (c < 2144
                  ? (c < 2112
                    ? (c >= 2048 && c <= 2093)
                    : c <= 2139)
                  : (c <= 2154 || (c < 2185
                    ? (c >= 2160 && c <= 2183)
                    : c <= 2190)))
                : (c <= 2273 || (c < 2417
                  ? (c < 2406
                    ? (c >= 2275 && c <= 2403)
                    : c <= 2415)
                  : (c <= 2435 || (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)))))
              : (c <= 2472 || (c < 2507
                ? (c < 2486
                  ? (c < 2482
                    ? (c >= 2474 && c <= 2480)
                    : c <= 2482)
                  : (c <= 2489 || (c < 2503
                    ? (c >= 2492 && c <= 2500)
                    : c <= 2504)))
                : (c <= 2510 || (c < 2527
                  ? (c < 2524
                    ? c == 2519
                    : c <= 2525)
                  : (c <= 2531 || (c < 2556
                    ? (c >= 2534 && c <= 2545)
                    : c <= 2556)))))))
            : (c <= 2558 || (c < 2635
              ? (c < 2610
                ? (c < 2575
                  ? (c < 2565
                    ? (c >= 2561 && c <= 2563)
                    : c <= 2570)
                  : (c <= 2576 || (c < 2602
                    ? (c >= 2579 && c <= 2600)
                    : c <= 2608)))
                : (c <= 2611 || (c < 2620
                  ? (c < 2616
                    ? (c >= 2613 && c <= 2614)
                    : c <= 2617)
                  : (c <= 2620 || (c < 2631
                    ? (c >= 2622 && c <= 2626)
                    : c <= 2632)))))
              : (c <= 2637 || (c < 2693
                ? (c < 2654
                  ? (c < 2649
                    ? c == 2641
                    : c <= 2652)
                  : (c <= 2654 || (c < 2689
                    ? (c >= 2662 && c <= 2677)
                    : c <= 2691)))
                : (c <= 2701 || (c < 2730
                  ? (c < 2707
                    ? (c >= 2703 && c <= 2705)
                    : c <= 2728)
                  : (c <= 2736 || (c < 2741
                    ? (c >= 2738 && c <= 2739)
                    : c <= 2745)))))))))))
        : (c <= 2757 || (c < 3168
          ? (c < 2958
            ? (c < 2866
              ? (c < 2809
                ? (c < 2768
                  ? (c < 2763
                    ? (c >= 2759 && c <= 2761)
                    : c <= 2765)
                  : (c <= 2768 || (c < 2790
                    ? (c >= 2784 && c <= 2787)
                    : c <= 2799)))
                : (c <= 2815 || (c < 2831
                  ? (c < 2821
                    ? (c >= 2817 && c <= 2819)
                    : c <= 2828)
                  : (c <= 2832 || (c < 2858
                    ? (c >= 2835 && c <= 2856)
                    : c <= 2864)))))
              : (c <= 2867 || (c < 2908
                ? (c < 2887
                  ? (c < 2876
                    ? (c >= 2869 && c <= 2873)
                    : c <= 2884)
                  : (c <= 2888 || (c < 2901
                    ? (c >= 2891 && c <= 2893)
                    : c <= 2903)))
                : (c <= 2909 || (c < 2929
                  ? (c < 2918
                    ? (c >= 2911 && c <= 2915)
                    : c <= 2927)
                  : (c <= 2929 || (c < 2949
                    ? (c >= 2946 && c <= 2947)
                    : c <= 2954)))))))
            : (c <= 2960 || (c < 3031
              ? (c < 2984
                ? (c < 2972
                  ? (c < 2969
                    ? (c >= 2962 && c <= 2965)
                    : c <= 2970)
                  : (c <= 2972 || (c < 2979
                    ? (c >= 2974 && c <= 2975)
                    : c <= 2980)))
                : (c <= 2986 || (c < 3014
                  ? (c < 3006
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3010)
                  : (c <= 3016 || (c < 3024
                    ? (c >= 3018 && c <= 3021)
                    : c <= 3024)))))
              : (c <= 3031 || (c < 3132
                ? (c < 3086
                  ? (c < 3072
                    ? (c >= 3046 && c <= 3055)
                    : c <= 3084)
                  : (c <= 3088 || (c < 3114
                    ? (c >= 3090 && c <= 3112)
                    : c <= 3129)))
                : (c <= 3140 || (c < 3157
                  ? (c < 3146
                    ? (c >= 3142 && c <= 3144)
                    : c <= 3149)
                  : (c <= 3158 || (c < 3165
                    ? (c >= 3160 && c <= 3162)
                    : c <= 3165)))))))))
          : (c <= 3171 || (c < 3450
            ? (c < 3293
              ? (c < 3242
                ? (c < 3205
                  ? (c < 3200
                    ? (c >= 3174 && c <= 3183)
                    : c <= 3203)
                  : (c <= 3212 || (c < 3218
                    ? (c >= 3214 && c <= 3216)
                    : c <= 3240)))
                : (c <= 3251 || (c < 3270
                  ? (c < 3260
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3268)
                  : (c <= 3272 || (c < 3285
                    ? (c >= 3274 && c <= 3277)
                    : c <= 3286)))))
              : (c <= 3294 || (c < 3346
                ? (c < 3313
                  ? (c < 3302
                    ? (c >= 3296 && c <= 3299)
                    : c <= 3311)
                  : (c <= 3314 || (c < 3342
                    ? (c >= 3328 && c <= 3340)
                    : c <= 3344)))
                : (c <= 3396 || (c < 3412
                  ? (c < 3402
                    ? (c >= 3398 && c <= 3400)
                    : c <= 3406)
                  : (c <= 3415 || (c < 3430
                    ? (c >= 3423 && c <= 3427)
                    : c <= 3439)))))))
            : (c <= 3455 || (c < 3570
              ? (c < 3520
                ? (c < 3482
                  ? (c < 3461
                    ? (c >= 3457 && c <= 3459)
                    : c <= 3478)
                  : (c <= 3505 || (c < 3517
                    ? (c >= 3507 && c <= 3515)
                    : c <= 3517)))
                : (c <= 3526 || (c < 3542
                  ? (c < 3535
                    ? c == 3530
                    : c <= 3540)
                  : (c <= 3542 || (c < 3558
                    ? (c >= 3544 && c <= 3551)
                    : c <= 3567)))))
              : (c <= 3571 || (c < 3718
                ? (c < 3664
                  ? (c < 3648
                    ? (c >= 3585 && c <= 3642)
                    : c <= 3662)
                  : (c <= 3673 || (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)))
                : (c <= 3722 || (c < 3751
                  ? (c < 3749
                    ? (c >= 3724 && c <= 3747)
                    : c <= 3749)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))))))))))
      : (c <= 3782 || (c < 8025
        ? (c < 5888
          ? (c < 4688
            ? (c < 3953
              ? (c < 3872
                ? (c < 3804
                  ? (c < 3792
                    ? (c >= 3784 && c <= 3789)
                    : c <= 3801)
                  : (c <= 3807 || (c < 3864
                    ? c == 3840
                    : c <= 3865)))
                : (c <= 3881 || (c < 3897
                  ? (c < 3895
                    ? c == 3893
                    : c <= 3895)
                  : (c <= 3897 || (c < 3913
                    ? (c >= 3902 && c <= 3911)
                    : c <= 3948)))))
              : (c <= 3972 || (c < 4256
                ? (c < 4038
                  ? (c < 3993
                    ? (c >= 3974 && c <= 3991)
                    : c <= 4028)
                  : (c <= 4038 || (c < 4176
                    ? (c >= 4096 && c <= 4169)
                    : c <= 4253)))
                : (c <= 4293 || (c < 4304
                  ? (c < 4301
                    ? c == 4295
                    : c <= 4301)
                  : (c <= 4346 || (c < 4682
                    ? (c >= 4348 && c <= 4680)
                    : c <= 4685)))))))
            : (c <= 4694 || (c < 4882
              ? (c < 4786
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c < 4752
                    ? (c >= 4746 && c <= 4749)
                    : c <= 4784)))
                : (c <= 4789 || (c < 4802
                  ? (c < 4800
                    ? (c >= 4792 && c <= 4798)
                    : c <= 4800)
                  : (c <= 4805 || (c < 4824
                    ? (c >= 4808 && c <= 4822)
                    : c <= 4880)))))
              : (c <= 4885 || (c < 5112
                ? (c < 4969
                  ? (c < 4957
                    ? (c >= 4888 && c <= 4954)
                    : c <= 4959)
                  : (c <= 4977 || (c < 5024
                    ? (c >= 4992 && c <= 5007)
                    : c <= 5109)))
                : (c <= 5117 || (c < 5761
                  ? (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)
                  : (c <= 5786 || (c < 5870
                    ? (c >= 5792 && c <= 5866)
                    : c <= 5880)))))))))
          : (c <= 5909 || (c < 6688
            ? (c < 6176
              ? (c < 6016
                ? (c < 5984
                  ? (c < 5952
                    ? (c >= 5919 && c <= 5940)
                    : c <= 5971)
                  : (c <= 5996 || (c < 6002
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6003)))
                : (c <= 6099 || (c < 6112
                  ? (c < 6108
                    ? c == 6103
                    : c <= 6109)
                  : (c <= 6121 || (c < 6159
                    ? (c >= 6155 && c <= 6157)
                    : c <= 6169)))))
              : (c <= 6264 || (c < 6470
                ? (c < 6400
                  ? (c < 6320
                    ? (c >= 6272 && c <= 6314)
                    : c <= 6389)
                  : (c <= 6430 || (c < 6448
                    ? (c >= 6432 && c <= 6443)
                    : c <= 6459)))
                : (c <= 6509 || (c < 6576
                  ? (c < 6528
                    ? (c >= 6512 && c <= 6516)
                    : c <= 6571)
                  : (c <= 6601 || (c < 6656
                    ? (c >= 6608 && c <= 6618)
                    : c <= 6683)))))))
            : (c <= 6750 || (c < 7232
              ? (c < 6847
                ? (c < 6800
                  ? (c < 6783
                    ? (c >= 6752 && c <= 6780)
                    : c <= 6793)
                  : (c <= 6809 || (c < 6832
                    ? c == 6823
                    : c <= 6845)))
                : (c <= 6862 || (c < 7019
                  ? (c < 6992
                    ? (c >= 6912 && c <= 6988)
                    : c <= 7001)
                  : (c <= 7027 || (c < 7168
                    ? (c >= 7040 && c <= 7155)
                    : c <= 7223)))))
              : (c <= 7241 || (c < 7380
                ? (c < 7312
                  ? (c < 7296
                    ? (c >= 7245 && c <= 7293)
                    : c <= 7304)
                  : (c <= 7354 || (c < 7376
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7378)))
                : (c <= 7418 || (c < 7968
                  ? (c < 7960
                    ? (c >= 7424 && c <= 7957)
                    : c <= 7965)
                  : (c <= 8005 || (c < 8016
                    ? (c >= 8008 && c <= 8013)
                    : c <= 8023)))))))))))
        : (c <= 8025 || (c < 11720
          ? (c < 8458
            ? (c < 8178
              ? (c < 8126
                ? (c < 8031
                  ? (c < 8029
                    ? c == 8027
                    : c <= 8029)
                  : (c <= 8061 || (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)))
                : (c <= 8126 || (c < 8144
                  ? (c < 8134
                    ? (c >= 8130 && c <= 8132)
                    : c <= 8140)
                  : (c <= 8147 || (c < 8160
                    ? (c >= 8150 && c <= 8155)
                    : c <= 8172)))))
              : (c <= 8180 || (c < 8336
                ? (c < 8276
                  ? (c < 8255
                    ? (c >= 8182 && c <= 8188)
                    : c <= 8256)
                  : (c <= 8276 || (c < 8319
                    ? c == 8305
                    : c <= 8319)))
                : (c <= 8348 || (c < 8421
                  ? (c < 8417
                    ? (c >= 8400 && c <= 8412)
                    : c <= 8417)
                  : (c <= 8432 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))))))
            : (c <= 8467 || (c < 11499
              ? (c < 8490
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || (c < 8488
                    ? c == 8486
                    : c <= 8488)))
                : (c <= 8505 || (c < 8526
                  ? (c < 8517
                    ? (c >= 8508 && c <= 8511)
                    : c <= 8521)
                  : (c <= 8526 || (c < 11264
                    ? (c >= 8544 && c <= 8584)
                    : c <= 11492)))))
              : (c <= 11507 || (c < 11647
                ? (c < 11565
                  ? (c < 11559
                    ? (c >= 11520 && c <= 11557)
                    : c <= 11559)
                  : (c <= 11565 || (c < 11631
                    ? (c >= 11568 && c <= 11623)
                    : c <= 11631)))
                : (c <= 11670 || (c < 11696
                  ? (c < 11688
                    ? (c >= 11680 && c <= 11686)
                    : c <= 11694)
                  : (c <= 11702 || (c < 11712
                    ? (c >= 11704 && c <= 11710)
                    : c <= 11718)))))))))
          : (c <= 11726 || (c < 42623
            ? (c < 12540
              ? (c < 12337
                ? (c < 11744
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 11775 || (c < 12321
                    ? (c >= 12293 && c <= 12295)
                    : c <= 12335)))
                : (c <= 12341 || (c < 12441
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12442 || (c < 12449
                    ? (c >= 12445 && c <= 12447)
                    : c <= 12538)))))
              : (c <= 12543 || (c < 19968
                ? (c < 12704
                  ? (c < 12593
                    ? (c >= 12549 && c <= 12591)
                    : c <= 12686)
                  : (c <= 12735 || (c < 13312
                    ? (c >= 12784 && c <= 12799)
                    : c <= 19903)))
                : (c <= 42124 || (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42539 || (c < 42612
                    ? (c >= 42560 && c <= 42607)
                    : c <= 42621)))))))
            : (c <= 42737 || (c < 43232
              ? (c < 42965
                ? (c < 42891
                  ? (c < 42786
                    ? (c >= 42775 && c <= 42783)
                    : c <= 42888)
                  : (c <= 42954 || (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)))
                : (c <= 42969 || (c < 43072
                  ? (c < 43052
                    ? (c >= 42994 && c <= 43047)
                    : c <= 43052)
                  : (c <= 43123 || (c < 43216
                    ? (c >= 43136 && c <= 43205)
                    : c <= 43225)))))
              : (c <= 43255 || (c < 43471
                ? (c < 43312
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43309)
                  : (c <= 43347 || (c < 43392
                    ? (c >= 43360 && c <= 43388)
                    : c <= 43456)))
                : (c <= 43481 || (c < 43584
                  ? (c < 43520
                    ? (c >= 43488 && c <= 43518)
                    : c <= 43574)
                  : (c <= 43597 || (c >= 43600 && c <= 43609)))))))))))))))
    : (c <= 43638 || (c < 71453
      ? (c < 67639
        ? (c < 65345
          ? (c < 64312
            ? (c < 43888
              ? (c < 43785
                ? (c < 43744
                  ? (c < 43739
                    ? (c >= 43642 && c <= 43714)
                    : c <= 43741)
                  : (c <= 43759 || (c < 43777
                    ? (c >= 43762 && c <= 43766)
                    : c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c < 43868
                    ? (c >= 43824 && c <= 43866)
                    : c <= 43881)))))
              : (c <= 44010 || (c < 63744
                ? (c < 44032
                  ? (c < 44016
                    ? (c >= 44012 && c <= 44013)
                    : c <= 44025)
                  : (c <= 55203 || (c < 55243
                    ? (c >= 55216 && c <= 55238)
                    : c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || (c < 64298
                    ? (c >= 64285 && c <= 64296)
                    : c <= 64310)))))))
            : (c <= 64316 || (c < 65075
              ? (c < 64612
                ? (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)))
                : (c <= 64829 || (c < 65008
                  ? (c < 64914
                    ? (c >= 64848 && c <= 64911)
                    : c <= 64967)
                  : (c <= 65017 || (c < 65056
                    ? (c >= 65024 && c <= 65039)
                    : c <= 65071)))))
              : (c <= 65076 || (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65101 && c <= 65103)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65296
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65305 || (c < 65343
                    ? (c >= 65313 && c <= 65338)
                    : c <= 65343)))))))))
          : (c <= 65370 || (c < 66513
            ? (c < 65664
              ? (c < 65536
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65382 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c < 65498
                    ? (c >= 65490 && c <= 65495)
                    : c <= 65500)))
                : (c <= 65547 || (c < 65596
                  ? (c < 65576
                    ? (c >= 65549 && c <= 65574)
                    : c <= 65594)
                  : (c <= 65597 || (c < 65616
                    ? (c >= 65599 && c <= 65613)
                    : c <= 65629)))))
              : (c <= 65786 || (c < 66304
                ? (c < 66176
                  ? (c < 66045
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66045)
                  : (c <= 66204 || (c < 66272
                    ? (c >= 66208 && c <= 66256)
                    : c <= 66272)))
                : (c <= 66335 || (c < 66432
                  ? (c < 66384
                    ? (c >= 66349 && c <= 66378)
                    : c <= 66426)
                  : (c <= 66461 || (c < 66504
                    ? (c >= 66464 && c <= 66499)
                    : c <= 66511)))))))
            : (c <= 66517 || (c < 66979
              ? (c < 66864
                ? (c < 66736
                  ? (c < 66720
                    ? (c >= 66560 && c <= 66717)
                    : c <= 66729)
                  : (c <= 66771 || (c < 66816
                    ? (c >= 66776 && c <= 66811)
                    : c <= 66855)))
                : (c <= 66915 || (c < 66956
                  ? (c < 66940
                    ? (c >= 66928 && c <= 66938)
                    : c <= 66954)
                  : (c <= 66962 || (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)))))
              : (c <= 66993 || (c < 67456
                ? (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)))
                : (c <= 67461 || (c < 67584
                  ? (c < 67506
                    ? (c >= 67463 && c <= 67504)
                    : c <= 67514)
                  : (c <= 67589 || (c < 67594
                    ? c == 67592
                    : c <= 67637)))))))))))
        : (c <= 67640 || (c < 69956
          ? (c < 68448
            ? (c < 68101
              ? (c < 67828
                ? (c < 67680
                  ? (c < 67647
                    ? c == 67644
                    : c <= 67669)
                  : (c <= 67702 || (c < 67808
                    ? (c >= 67712 && c <= 67742)
                    : c <= 67826)))
                : (c <= 67829 || (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68099)))))
              : (c <= 68102 || (c < 68192
                ? (c < 68121
                  ? (c < 68117
                    ? (c >= 68108 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c < 68159
                    ? (c >= 68152 && c <= 68154)
                    : c <= 68159)))
                : (c <= 68220 || (c < 68297
                  ? (c < 68288
                    ? (c >= 68224 && c <= 68252)
                    : c <= 68295)
                  : (c <= 68326 || (c < 68416
                    ? (c >= 68352 && c <= 68405)
                    : c <= 68437)))))))
            : (c <= 68466 || (c < 69424
              ? (c < 68912
                ? (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c < 68864
                    ? (c >= 68800 && c <= 68850)
                    : c <= 68903)))
                : (c <= 68921 || (c < 69296
                  ? (c < 69291
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69292)
                  : (c <= 69297 || (c < 69415
                    ? (c >= 69376 && c <= 69404)
                    : c <= 69415)))))
              : (c <= 69456 || (c < 69759
                ? (c < 69600
                  ? (c < 69552
                    ? (c >= 69488 && c <= 69509)
                    : c <= 69572)
                  : (c <= 69622 || (c < 69734
                    ? (c >= 69632 && c <= 69702)
                    : c <= 69749)))
                : (c <= 69818 || (c < 69872
                  ? (c < 69840
                    ? c == 69826
                    : c <= 69864)
                  : (c <= 69881 || (c < 69942
                    ? (c >= 69888 && c <= 69940)
                    : c <= 69951)))))))))
          : (c <= 69959 || (c < 70459
            ? (c < 70282
              ? (c < 70108
                ? (c < 70016
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70003)
                    : c <= 70006)
                  : (c <= 70084 || (c < 70094
                    ? (c >= 70089 && c <= 70092)
                    : c <= 70106)))
                : (c <= 70108 || (c < 70206
                  ? (c < 70163
                    ? (c >= 70144 && c <= 70161)
                    : c <= 70199)
                  : (c <= 70206 || (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)))))
              : (c <= 70285 || (c < 70405
                ? (c < 70320
                  ? (c < 70303
                    ? (c >= 70287 && c <= 70301)
                    : c <= 70312)
                  : (c <= 70378 || (c < 70400
                    ? (c >= 70384 && c <= 70393)
                    : c <= 70403)))
                : (c <= 70412 || (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)))))))
            : (c <= 70468 || (c < 70855
              ? (c < 70502
                ? (c < 70480
                  ? (c < 70475
                    ? (c >= 70471 && c <= 70472)
                    : c <= 70477)
                  : (c <= 70480 || (c < 70493
                    ? c == 70487
                    : c <= 70499)))
                : (c <= 70508 || (c < 70736
                  ? (c < 70656
                    ? (c >= 70512 && c <= 70516)
                    : c <= 70730)
                  : (c <= 70745 || (c < 70784
                    ? (c >= 70750 && c <= 70753)
                    : c <= 70853)))))
              : (c <= 70855 || (c < 71236
                ? (c < 71096
                  ? (c < 71040
                    ? (c >= 70864 && c <= 70873)
                    : c <= 71093)
                  : (c <= 71104 || (c < 71168
                    ? (c >= 71128 && c <= 71133)
                    : c <= 71232)))
                : (c <= 71236 || (c < 71360
                  ? (c < 71296
                    ? (c >= 71248 && c <= 71257)
                    : c <= 71352)
                  : (c <= 71369 || (c >= 71424 && c <= 71450)))))))))))))
      : (c <= 71467 || (c < 119973
        ? (c < 77824
          ? (c < 72760
            ? (c < 72016
              ? (c < 71945
                ? (c < 71680
                  ? (c < 71488
                    ? (c >= 71472 && c <= 71481)
                    : c <= 71494)
                  : (c <= 71738 || (c < 71935
                    ? (c >= 71840 && c <= 71913)
                    : c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71989 || (c < 71995
                    ? (c >= 71991 && c <= 71992)
                    : c <= 72003)))))
              : (c <= 72025 || (c < 72263
                ? (c < 72154
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72151)
                  : (c <= 72161 || (c < 72192
                    ? (c >= 72163 && c <= 72164)
                    : c <= 72254)))
                : (c <= 72263 || (c < 72368
                  ? (c < 72349
                    ? (c >= 72272 && c <= 72345)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72758)))))))
            : (c <= 72768 || (c < 73056
              ? (c < 72968
                ? (c < 72850
                  ? (c < 72818
                    ? (c >= 72784 && c <= 72793)
                    : c <= 72847)
                  : (c <= 72871 || (c < 72960
                    ? (c >= 72873 && c <= 72886)
                    : c <= 72966)))
                : (c <= 72969 || (c < 73020
                  ? (c < 73018
                    ? (c >= 72971 && c <= 73014)
                    : c <= 73018)
                  : (c <= 73021 || (c < 73040
                    ? (c >= 73023 && c <= 73031)
                    : c <= 73049)))))
              : (c <= 73061 || (c < 73440
                ? (c < 73104
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73102)
                  : (c <= 73105 || (c < 73120
                    ? (c >= 73107 && c <= 73112)
                    : c <= 73129)))
                : (c <= 73462 || (c < 74752
                  ? (c < 73728
                    ? c == 73648
                    : c <= 74649)
                  : (c <= 74862 || (c < 77712
                    ? (c >= 74880 && c <= 75075)
                    : c <= 77808)))))))))
          : (c <= 78894 || (c < 110576
            ? (c < 93027
              ? (c < 92864
                ? (c < 92736
                  ? (c < 92160
                    ? (c >= 82944 && c <= 83526)
                    : c <= 92728)
                  : (c <= 92766 || (c < 92784
                    ? (c >= 92768 && c <= 92777)
                    : c <= 92862)))
                : (c <= 92873 || (c < 92928
                  ? (c < 92912
                    ? (c >= 92880 && c <= 92909)
                    : c <= 92916)
                  : (c <= 92982 || (c < 93008
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93017)))))
              : (c <= 93047 || (c < 94176
                ? (c < 93952
                  ? (c < 93760
                    ? (c >= 93053 && c <= 93071)
                    : c <= 93823)
                  : (c <= 94026 || (c < 94095
                    ? (c >= 94031 && c <= 94087)
                    : c <= 94111)))
                : (c <= 94177 || (c < 94208
                  ? (c < 94192
                    ? (c >= 94179 && c <= 94180)
                    : c <= 94193)
                  : (c <= 100343 || (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)))))))
            : (c <= 110579 || (c < 118528
              ? (c < 110960
                ? (c < 110592
                  ? (c < 110589
                    ? (c >= 110581 && c <= 110587)
                    : c <= 110590)
                  : (c <= 110882 || (c < 110948
                    ? (c >= 110928 && c <= 110930)
                    : c <= 110951)))
                : (c <= 111355 || (c < 113792
                  ? (c < 113776
                    ? (c >= 113664 && c <= 113770)
                    : c <= 113788)
                  : (c <= 113800 || (c < 113821
                    ? (c >= 113808 && c <= 113817)
                    : c <= 113822)))))
              : (c <= 118573 || (c < 119210
                ? (c < 119149
                  ? (c < 119141
                    ? (c >= 118576 && c <= 118598)
                    : c <= 119145)
                  : (c <= 119154 || (c < 119173
                    ? (c >= 119163 && c <= 119170)
                    : c <= 119179)))
                : (c <= 119213 || (c < 119894
                  ? (c < 119808
                    ? (c >= 119362 && c <= 119364)
                    : c <= 119892)
                  : (c <= 119964 || (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)))))))))))
        : (c <= 119974 || (c < 124912
          ? (c < 120746
            ? (c < 120134
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c < 120128
                    ? (c >= 120123 && c <= 120126)
                    : c <= 120132)))))
              : (c <= 120134 || (c < 120572
                ? (c < 120488
                  ? (c < 120146
                    ? (c >= 120138 && c <= 120144)
                    : c <= 120485)
                  : (c <= 120512 || (c < 120540
                    ? (c >= 120514 && c <= 120538)
                    : c <= 120570)))
                : (c <= 120596 || (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)))))))
            : (c <= 120770 || (c < 122907
              ? (c < 121476
                ? (c < 121344
                  ? (c < 120782
                    ? (c >= 120772 && c <= 120779)
                    : c <= 120831)
                  : (c <= 121398 || (c < 121461
                    ? (c >= 121403 && c <= 121452)
                    : c <= 121461)))
                : (c <= 121476 || (c < 122624
                  ? (c < 121505
                    ? (c >= 121499 && c <= 121503)
                    : c <= 121519)
                  : (c <= 122654 || (c < 122888
                    ? (c >= 122880 && c <= 122886)
                    : c <= 122904)))))
              : (c <= 122913 || (c < 123214
                ? (c < 123136
                  ? (c < 122918
                    ? (c >= 122915 && c <= 122916)
                    : c <= 122922)
                  : (c <= 123180 || (c < 123200
                    ? (c >= 123184 && c <= 123197)
                    : c <= 123209)))
                : (c <= 123214 || (c < 124896
                  ? (c < 123584
                    ? (c >= 123536 && c <= 123566)
                    : c <= 123641)
                  : (c <= 124902 || (c < 124909
                    ? (c >= 124904 && c <= 124907)
                    : c <= 124910)))))))))
          : (c <= 124926 || (c < 126557
            ? (c < 126521
              ? (c < 126469
                ? (c < 125184
                  ? (c < 125136
                    ? (c >= 124928 && c <= 125124)
                    : c <= 125142)
                  : (c <= 125259 || (c < 126464
                    ? (c >= 125264 && c <= 125273)
                    : c <= 126467)))
                : (c <= 126495 || (c < 126503
                  ? (c < 126500
                    ? (c >= 126497 && c <= 126498)
                    : c <= 126500)
                  : (c <= 126503 || (c < 126516
                    ? (c >= 126505 && c <= 126514)
                    : c <= 126519)))))
              : (c <= 126521 || (c < 126541
                ? (c < 126535
                  ? (c < 126530
                    ? c == 126523
                    : c <= 126530)
                  : (c <= 126535 || (c < 126539
                    ? c == 126537
                    : c <= 126539)))
                : (c <= 126543 || (c < 126551
                  ? (c < 126548
                    ? (c >= 126545 && c <= 126546)
                    : c <= 126548)
                  : (c <= 126551 || (c < 126555
                    ? c == 126553
                    : c <= 126555)))))))
            : (c <= 126557 || (c < 126629
              ? (c < 126580
                ? (c < 126564
                  ? (c < 126561
                    ? c == 126559
                    : c <= 126562)
                  : (c <= 126564 || (c < 126572
                    ? (c >= 126567 && c <= 126570)
                    : c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c < 126625
                    ? (c >= 126603 && c <= 126619)
                    : c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 131072
                  ? (c < 130032
                    ? (c >= 126635 && c <= 126651)
                    : c <= 130041)
                  : (c <= 173791 || (c < 177984
                    ? (c >= 173824 && c <= 177976)
                    : c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 917760 && c <= 917999)))))))))))))))));
}

static inline bool sym_identifier_character_set_5(int32_t c) {
  return (c < 43616
    ? (c < 3782
      ? (c < 2748
        ? (c < 2045
          ? (c < 1015
            ? (c < 710
              ? (c < 181
                ? (c < '_'
                  ? (c < 'A'
                    ? (c >= '0' && c <= '9')
                    : c <= 'Z')
                  : (c <= '_' || (c < 170
                    ? (c >= 'b' && c <= 'z')
                    : c <= 170)))
                : (c <= 181 || (c < 192
                  ? (c < 186
                    ? c == 183
                    : c <= 186)
                  : (c <= 214 || (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)))))
              : (c <= 721 || (c < 891
                ? (c < 750
                  ? (c < 748
                    ? (c >= 736 && c <= 740)
                    : c <= 748)
                  : (c <= 750 || (c < 886
                    ? (c >= 768 && c <= 884)
                    : c <= 887)))
                : (c <= 893 || (c < 908
                  ? (c < 902
                    ? c == 895
                    : c <= 906)
                  : (c <= 908 || (c < 931
                    ? (c >= 910 && c <= 929)
                    : c <= 1013)))))))
            : (c <= 1153 || (c < 1519
              ? (c < 1425
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1155 && c <= 1159)
                    : c <= 1327)
                  : (c <= 1366 || (c < 1376
                    ? c == 1369
                    : c <= 1416)))
                : (c <= 1469 || (c < 1476
                  ? (c < 1473
                    ? c == 1471
                    : c <= 1474)
                  : (c <= 1477 || (c < 1488
                    ? c == 1479
                    : c <= 1514)))))
              : (c <= 1522 || (c < 1770
                ? (c < 1646
                  ? (c < 1568
                    ? (c >= 1552 && c <= 1562)
                    : c <= 1641)
                  : (c <= 1747 || (c < 1759
                    ? (c >= 1749 && c <= 1756)
                    : c <= 1768)))
                : (c <= 1788 || (c < 1869
                  ? (c < 1808
                    ? c == 1791
                    : c <= 1866)
                  : (c <= 1969 || (c < 2042
                    ? (c >= 1984 && c <= 2037)
                    : c <= 2042)))))))))
          : (c <= 2045 || (c < 2558
            ? (c < 2451
              ? (c < 2200
                ? (c < 2144
                  ? (c < 2112
                    ? (c >= 2048 && c <= 2093)
                    : c <= 2139)
                  : (c <= 2154 || (c < 2185
                    ? (c >= 2160 && c <= 2183)
                    : c <= 2190)))
                : (c <= 2273 || (c < 2417
                  ? (c < 2406
                    ? (c >= 2275 && c <= 2403)
                    : c <= 2415)
                  : (c <= 2435 || (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)))))
              : (c <= 2472 || (c < 2507
                ? (c < 2486
                  ? (c < 2482
                    ? (c >= 2474 && c <= 2480)
                    : c <= 2482)
                  : (c <= 2489 || (c < 2503
                    ? (c >= 2492 && c <= 2500)
                    : c <= 2504)))
                : (c <= 2510 || (c < 2527
                  ? (c < 2524
                    ? c == 2519
                    : c <= 2525)
                  : (c <= 2531 || (c < 2556
                    ? (c >= 2534 && c <= 2545)
                    : c <= 2556)))))))
            : (c <= 2558 || (c < 2635
              ? (c < 2610
                ? (c < 2575
                  ? (c < 2565
                    ? (c >= 2561 && c <= 2563)
                    : c <= 2570)
                  : (c <= 2576 || (c < 2602
                    ? (c >= 2579 && c <= 2600)
                    : c <= 2608)))
                : (c <= 2611 || (c < 2620
                  ? (c < 2616
                    ? (c >= 2613 && c <= 2614)
                    : c <= 2617)
                  : (c <= 2620 || (c < 2631
                    ? (c >= 2622 && c <= 2626)
                    : c <= 2632)))))
              : (c <= 2637 || (c < 2693
                ? (c < 2654
                  ? (c < 2649
                    ? c == 2641
                    : c <= 2652)
                  : (c <= 2654 || (c < 2689
                    ? (c >= 2662 && c <= 2677)
                    : c <= 2691)))
                : (c <= 2701 || (c < 2730
                  ? (c < 2707
                    ? (c >= 2703 && c <= 2705)
                    : c <= 2728)
                  : (c <= 2736 || (c < 2741
                    ? (c >= 2738 && c <= 2739)
                    : c <= 2745)))))))))))
        : (c <= 2757 || (c < 3168
          ? (c < 2958
            ? (c < 2866
              ? (c < 2809
                ? (c < 2768
                  ? (c < 2763
                    ? (c >= 2759 && c <= 2761)
                    : c <= 2765)
                  : (c <= 2768 || (c < 2790
                    ? (c >= 2784 && c <= 2787)
                    : c <= 2799)))
                : (c <= 2815 || (c < 2831
                  ? (c < 2821
                    ? (c >= 2817 && c <= 2819)
                    : c <= 2828)
                  : (c <= 2832 || (c < 2858
                    ? (c >= 2835 && c <= 2856)
                    : c <= 2864)))))
              : (c <= 2867 || (c < 2908
                ? (c < 2887
                  ? (c < 2876
                    ? (c >= 2869 && c <= 2873)
                    : c <= 2884)
                  : (c <= 2888 || (c < 2901
                    ? (c >= 2891 && c <= 2893)
                    : c <= 2903)))
                : (c <= 2909 || (c < 2929
                  ? (c < 2918
                    ? (c >= 2911 && c <= 2915)
                    : c <= 2927)
                  : (c <= 2929 || (c < 2949
                    ? (c >= 2946 && c <= 2947)
                    : c <= 2954)))))))
            : (c <= 2960 || (c < 3031
              ? (c < 2984
                ? (c < 2972
                  ? (c < 2969
                    ? (c >= 2962 && c <= 2965)
                    : c <= 2970)
                  : (c <= 2972 || (c < 2979
                    ? (c >= 2974 && c <= 2975)
                    : c <= 2980)))
                : (c <= 2986 || (c < 3014
                  ? (c < 3006
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3010)
                  : (c <= 3016 || (c < 3024
                    ? (c >= 3018 && c <= 3021)
                    : c <= 3024)))))
              : (c <= 3031 || (c < 3132
                ? (c < 3086
                  ? (c < 3072
                    ? (c >= 3046 && c <= 3055)
                    : c <= 3084)
                  : (c <= 3088 || (c < 3114
                    ? (c >= 3090 && c <= 3112)
                    : c <= 3129)))
                : (c <= 3140 || (c < 3157
                  ? (c < 3146
                    ? (c >= 3142 && c <= 3144)
                    : c <= 3149)
                  : (c <= 3158 || (c < 3165
                    ? (c >= 3160 && c <= 3162)
                    : c <= 3165)))))))))
          : (c <= 3171 || (c < 3450
            ? (c < 3293
              ? (c < 3242
                ? (c < 3205
                  ? (c < 3200
                    ? (c >= 3174 && c <= 3183)
                    : c <= 3203)
                  : (c <= 3212 || (c < 3218
                    ? (c >= 3214 && c <= 3216)
                    : c <= 3240)))
                : (c <= 3251 || (c < 3270
                  ? (c < 3260
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3268)
                  : (c <= 3272 || (c < 3285
                    ? (c >= 3274 && c <= 3277)
                    : c <= 3286)))))
              : (c <= 3294 || (c < 3346
                ? (c < 3313
                  ? (c < 3302
                    ? (c >= 3296 && c <= 3299)
                    : c <= 3311)
                  : (c <= 3314 || (c < 3342
                    ? (c >= 3328 && c <= 3340)
                    : c <= 3344)))
                : (c <= 3396 || (c < 3412
                  ? (c < 3402
                    ? (c >= 3398 && c <= 3400)
                    : c <= 3406)
                  : (c <= 3415 || (c < 3430
                    ? (c >= 3423 && c <= 3427)
                    : c <= 3439)))))))
            : (c <= 3455 || (c < 3570
              ? (c < 3520
                ? (c < 3482
                  ? (c < 3461
                    ? (c >= 3457 && c <= 3459)
                    : c <= 3478)
                  : (c <= 3505 || (c < 3517
                    ? (c >= 3507 && c <= 3515)
                    : c <= 3517)))
                : (c <= 3526 || (c < 3542
                  ? (c < 3535
                    ? c == 3530
                    : c <= 3540)
                  : (c <= 3542 || (c < 3558
                    ? (c >= 3544 && c <= 3551)
                    : c <= 3567)))))
              : (c <= 3571 || (c < 3718
                ? (c < 3664
                  ? (c < 3648
                    ? (c >= 3585 && c <= 3642)
                    : c <= 3662)
                  : (c <= 3673 || (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)))
                : (c <= 3722 || (c < 3751
                  ? (c < 3749
                    ? (c >= 3724 && c <= 3747)
                    : c <= 3749)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))))))))))
      : (c <= 3782 || (c < 8025
        ? (c < 5888
          ? (c < 4688
            ? (c < 3953
              ? (c < 3872
                ? (c < 3804
                  ? (c < 3792
                    ? (c >= 3784 && c <= 3789)
                    : c <= 3801)
                  : (c <= 3807 || (c < 3864
                    ? c == 3840
                    : c <= 3865)))
                : (c <= 3881 || (c < 3897
                  ? (c < 3895
                    ? c == 3893
                    : c <= 3895)
                  : (c <= 3897 || (c < 3913
                    ? (c >= 3902 && c <= 3911)
                    : c <= 3948)))))
              : (c <= 3972 || (c < 4256
                ? (c < 4038
                  ? (c < 3993
                    ? (c >= 3974 && c <= 3991)
                    : c <= 4028)
                  : (c <= 4038 || (c < 4176
                    ? (c >= 4096 && c <= 4169)
                    : c <= 4253)))
                : (c <= 4293 || (c < 4304
                  ? (c < 4301
                    ? c == 4295
                    : c <= 4301)
                  : (c <= 4346 || (c < 4682
                    ? (c >= 4348 && c <= 4680)
                    : c <= 4685)))))))
            : (c <= 4694 || (c < 4882
              ? (c < 4786
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c < 4752
                    ? (c >= 4746 && c <= 4749)
                    : c <= 4784)))
                : (c <= 4789 || (c < 4802
                  ? (c < 4800
                    ? (c >= 4792 && c <= 4798)
                    : c <= 4800)
                  : (c <= 4805 || (c < 4824
                    ? (c >= 4808 && c <= 4822)
                    : c <= 4880)))))
              : (c <= 4885 || (c < 5112
                ? (c < 4969
                  ? (c < 4957
                    ? (c >= 4888 && c <= 4954)
                    : c <= 4959)
                  : (c <= 4977 || (c < 5024
                    ? (c >= 4992 && c <= 5007)
                    : c <= 5109)))
                : (c <= 5117 || (c < 5761
                  ? (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)
                  : (c <= 5786 || (c < 5870
                    ? (c >= 5792 && c <= 5866)
                    : c <= 5880)))))))))
          : (c <= 5909 || (c < 6688
            ? (c < 6176
              ? (c < 6016
                ? (c < 5984
                  ? (c < 5952
                    ? (c >= 5919 && c <= 5940)
                    : c <= 5971)
                  : (c <= 5996 || (c < 6002
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6003)))
                : (c <= 6099 || (c < 6112
                  ? (c < 6108
                    ? c == 6103
                    : c <= 6109)
                  : (c <= 6121 || (c < 6159
                    ? (c >= 6155 && c <= 6157)
                    : c <= 6169)))))
              : (c <= 6264 || (c < 6470
                ? (c < 6400
                  ? (c < 6320
                    ? (c >= 6272 && c <= 6314)
                    : c <= 6389)
                  : (c <= 6430 || (c < 6448
                    ? (c >= 6432 && c <= 6443)
                    : c <= 6459)))
                : (c <= 6509 || (c < 6576
                  ? (c < 6528
                    ? (c >= 6512 && c <= 6516)
                    : c <= 6571)
                  : (c <= 6601 || (c < 6656
                    ? (c >= 6608 && c <= 6618)
                    : c <= 6683)))))))
            : (c <= 6750 || (c < 7232
              ? (c < 6847
                ? (c < 6800
                  ? (c < 6783
                    ? (c >= 6752 && c <= 6780)
                    : c <= 6793)
                  : (c <= 6809 || (c < 6832
                    ? c == 6823
                    : c <= 6845)))
                : (c <= 6862 || (c < 7019
                  ? (c < 6992
                    ? (c >= 6912 && c <= 6988)
                    : c <= 7001)
                  : (c <= 7027 || (c < 7168
                    ? (c >= 7040 && c <= 7155)
                    : c <= 7223)))))
              : (c <= 7241 || (c < 7380
                ? (c < 7312
                  ? (c < 7296
                    ? (c >= 7245 && c <= 7293)
                    : c <= 7304)
                  : (c <= 7354 || (c < 7376
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7378)))
                : (c <= 7418 || (c < 7968
                  ? (c < 7960
                    ? (c >= 7424 && c <= 7957)
                    : c <= 7965)
                  : (c <= 8005 || (c < 8016
                    ? (c >= 8008 && c <= 8013)
                    : c <= 8023)))))))))))
        : (c <= 8025 || (c < 11720
          ? (c < 8458
            ? (c < 8178
              ? (c < 8126
                ? (c < 8031
                  ? (c < 8029
                    ? c == 8027
                    : c <= 8029)
                  : (c <= 8061 || (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)))
                : (c <= 8126 || (c < 8144
                  ? (c < 8134
                    ? (c >= 8130 && c <= 8132)
                    : c <= 8140)
                  : (c <= 8147 || (c < 8160
                    ? (c >= 8150 && c <= 8155)
                    : c <= 8172)))))
              : (c <= 8180 || (c < 8336
                ? (c < 8276
                  ? (c < 8255
                    ? (c >= 8182 && c <= 8188)
                    : c <= 8256)
                  : (c <= 8276 || (c < 8319
                    ? c == 8305
                    : c <= 8319)))
                : (c <= 8348 || (c < 8421
                  ? (c < 8417
                    ? (c >= 8400 && c <= 8412)
                    : c <= 8417)
                  : (c <= 8432 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))))))
            : (c <= 8467 || (c < 11499
              ? (c < 8490
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || (c < 8488
                    ? c == 8486
                    : c <= 8488)))
                : (c <= 8505 || (c < 8526
                  ? (c < 8517
                    ? (c >= 8508 && c <= 8511)
                    : c <= 8521)
                  : (c <= 8526 || (c < 11264
                    ? (c >= 8544 && c <= 8584)
                    : c <= 11492)))))
              : (c <= 11507 || (c < 11647
                ? (c < 11565
                  ? (c < 11559
                    ? (c >= 11520 && c <= 11557)
                    : c <= 11559)
                  : (c <= 11565 || (c < 11631
                    ? (c >= 11568 && c <= 11623)
                    : c <= 11631)))
                : (c <= 11670 || (c < 11696
                  ? (c < 11688
                    ? (c >= 11680 && c <= 11686)
                    : c <= 11694)
                  : (c <= 11702 || (c < 11712
                    ? (c >= 11704 && c <= 11710)
                    : c <= 11718)))))))))
          : (c <= 11726 || (c < 42623
            ? (c < 12540
              ? (c < 12337
                ? (c < 11744
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 11775 || (c < 12321
                    ? (c >= 12293 && c <= 12295)
                    : c <= 12335)))
                : (c <= 12341 || (c < 12441
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12442 || (c < 12449
                    ? (c >= 12445 && c <= 12447)
                    : c <= 12538)))))
              : (c <= 12543 || (c < 19968
                ? (c < 12704
                  ? (c < 12593
                    ? (c >= 12549 && c <= 12591)
                    : c <= 12686)
                  : (c <= 12735 || (c < 13312
                    ? (c >= 12784 && c <= 12799)
                    : c <= 19903)))
                : (c <= 42124 || (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42539 || (c < 42612
                    ? (c >= 42560 && c <= 42607)
                    : c <= 42621)))))))
            : (c <= 42737 || (c < 43232
              ? (c < 42965
                ? (c < 42891
                  ? (c < 42786
                    ? (c >= 42775 && c <= 42783)
                    : c <= 42888)
                  : (c <= 42954 || (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)))
                : (c <= 42969 || (c < 43072
                  ? (c < 43052
                    ? (c >= 42994 && c <= 43047)
                    : c <= 43052)
                  : (c <= 43123 || (c < 43216
                    ? (c >= 43136 && c <= 43205)
                    : c <= 43225)))))
              : (c <= 43255 || (c < 43471
                ? (c < 43312
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43309)
                  : (c <= 43347 || (c < 43392
                    ? (c >= 43360 && c <= 43388)
                    : c <= 43456)))
                : (c <= 43481 || (c < 43584
                  ? (c < 43520
                    ? (c >= 43488 && c <= 43518)
                    : c <= 43574)
                  : (c <= 43597 || (c >= 43600 && c <= 43609)))))))))))))))
    : (c <= 43638 || (c < 71453
      ? (c < 67639
        ? (c < 65345
          ? (c < 64312
            ? (c < 43888
              ? (c < 43785
                ? (c < 43744
                  ? (c < 43739
                    ? (c >= 43642 && c <= 43714)
                    : c <= 43741)
                  : (c <= 43759 || (c < 43777
                    ? (c >= 43762 && c <= 43766)
                    : c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c < 43868
                    ? (c >= 43824 && c <= 43866)
                    : c <= 43881)))))
              : (c <= 44010 || (c < 63744
                ? (c < 44032
                  ? (c < 44016
                    ? (c >= 44012 && c <= 44013)
                    : c <= 44025)
                  : (c <= 55203 || (c < 55243
                    ? (c >= 55216 && c <= 55238)
                    : c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || (c < 64298
                    ? (c >= 64285 && c <= 64296)
                    : c <= 64310)))))))
            : (c <= 64316 || (c < 65075
              ? (c < 64612
                ? (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)))
                : (c <= 64829 || (c < 65008
                  ? (c < 64914
                    ? (c >= 64848 && c <= 64911)
                    : c <= 64967)
                  : (c <= 65017 || (c < 65056
                    ? (c >= 65024 && c <= 65039)
                    : c <= 65071)))))
              : (c <= 65076 || (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65101 && c <= 65103)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65296
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65305 || (c < 65343
                    ? (c >= 65313 && c <= 65338)
                    : c <= 65343)))))))))
          : (c <= 65370 || (c < 66513
            ? (c < 65664
              ? (c < 65536
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65382 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c < 65498
                    ? (c >= 65490 && c <= 65495)
                    : c <= 65500)))
                : (c <= 65547 || (c < 65596
                  ? (c < 65576
                    ? (c >= 65549 && c <= 65574)
                    : c <= 65594)
                  : (c <= 65597 || (c < 65616
                    ? (c >= 65599 && c <= 65613)
                    : c <= 65629)))))
              : (c <= 65786 || (c < 66304
                ? (c < 66176
                  ? (c < 66045
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66045)
                  : (c <= 66204 || (c < 66272
                    ? (c >= 66208 && c <= 66256)
                    : c <= 66272)))
                : (c <= 66335 || (c < 66432
                  ? (c < 66384
                    ? (c >= 66349 && c <= 66378)
                    : c <= 66426)
                  : (c <= 66461 || (c < 66504
                    ? (c >= 66464 && c <= 66499)
                    : c <= 66511)))))))
            : (c <= 66517 || (c < 66979
              ? (c < 66864
                ? (c < 66736
                  ? (c < 66720
                    ? (c >= 66560 && c <= 66717)
                    : c <= 66729)
                  : (c <= 66771 || (c < 66816
                    ? (c >= 66776 && c <= 66811)
                    : c <= 66855)))
                : (c <= 66915 || (c < 66956
                  ? (c < 66940
                    ? (c >= 66928 && c <= 66938)
                    : c <= 66954)
                  : (c <= 66962 || (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)))))
              : (c <= 66993 || (c < 67456
                ? (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)))
                : (c <= 67461 || (c < 67584
                  ? (c < 67506
                    ? (c >= 67463 && c <= 67504)
                    : c <= 67514)
                  : (c <= 67589 || (c < 67594
                    ? c == 67592
                    : c <= 67637)))))))))))
        : (c <= 67640 || (c < 69956
          ? (c < 68448
            ? (c < 68101
              ? (c < 67828
                ? (c < 67680
                  ? (c < 67647
                    ? c == 67644
                    : c <= 67669)
                  : (c <= 67702 || (c < 67808
                    ? (c >= 67712 && c <= 67742)
                    : c <= 67826)))
                : (c <= 67829 || (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68099)))))
              : (c <= 68102 || (c < 68192
                ? (c < 68121
                  ? (c < 68117
                    ? (c >= 68108 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c < 68159
                    ? (c >= 68152 && c <= 68154)
                    : c <= 68159)))
                : (c <= 68220 || (c < 68297
                  ? (c < 68288
                    ? (c >= 68224 && c <= 68252)
                    : c <= 68295)
                  : (c <= 68326 || (c < 68416
                    ? (c >= 68352 && c <= 68405)
                    : c <= 68437)))))))
            : (c <= 68466 || (c < 69424
              ? (c < 68912
                ? (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c < 68864
                    ? (c >= 68800 && c <= 68850)
                    : c <= 68903)))
                : (c <= 68921 || (c < 69296
                  ? (c < 69291
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69292)
                  : (c <= 69297 || (c < 69415
                    ? (c >= 69376 && c <= 69404)
                    : c <= 69415)))))
              : (c <= 69456 || (c < 69759
                ? (c < 69600
                  ? (c < 69552
                    ? (c >= 69488 && c <= 69509)
                    : c <= 69572)
                  : (c <= 69622 || (c < 69734
                    ? (c >= 69632 && c <= 69702)
                    : c <= 69749)))
                : (c <= 69818 || (c < 69872
                  ? (c < 69840
                    ? c == 69826
                    : c <= 69864)
                  : (c <= 69881 || (c < 69942
                    ? (c >= 69888 && c <= 69940)
                    : c <= 69951)))))))))
          : (c <= 69959 || (c < 70459
            ? (c < 70282
              ? (c < 70108
                ? (c < 70016
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70003)
                    : c <= 70006)
                  : (c <= 70084 || (c < 70094
                    ? (c >= 70089 && c <= 70092)
                    : c <= 70106)))
                : (c <= 70108 || (c < 70206
                  ? (c < 70163
                    ? (c >= 70144 && c <= 70161)
                    : c <= 70199)
                  : (c <= 70206 || (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)))))
              : (c <= 70285 || (c < 70405
                ? (c < 70320
                  ? (c < 70303
                    ? (c >= 70287 && c <= 70301)
                    : c <= 70312)
                  : (c <= 70378 || (c < 70400
                    ? (c >= 70384 && c <= 70393)
                    : c <= 70403)))
                : (c <= 70412 || (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)))))))
            : (c <= 70468 || (c < 70855
              ? (c < 70502
                ? (c < 70480
                  ? (c < 70475
                    ? (c >= 70471 && c <= 70472)
                    : c <= 70477)
                  : (c <= 70480 || (c < 70493
                    ? c == 70487
                    : c <= 70499)))
                : (c <= 70508 || (c < 70736
                  ? (c < 70656
                    ? (c >= 70512 && c <= 70516)
                    : c <= 70730)
                  : (c <= 70745 || (c < 70784
                    ? (c >= 70750 && c <= 70753)
                    : c <= 70853)))))
              : (c <= 70855 || (c < 71236
                ? (c < 71096
                  ? (c < 71040
                    ? (c >= 70864 && c <= 70873)
                    : c <= 71093)
                  : (c <= 71104 || (c < 71168
                    ? (c >= 71128 && c <= 71133)
                    : c <= 71232)))
                : (c <= 71236 || (c < 71360
                  ? (c < 71296
                    ? (c >= 71248 && c <= 71257)
                    : c <= 71352)
                  : (c <= 71369 || (c >= 71424 && c <= 71450)))))))))))))
      : (c <= 71467 || (c < 119973
        ? (c < 77824
          ? (c < 72760
            ? (c < 72016
              ? (c < 71945
                ? (c < 71680
                  ? (c < 71488
                    ? (c >= 71472 && c <= 71481)
                    : c <= 71494)
                  : (c <= 71738 || (c < 71935
                    ? (c >= 71840 && c <= 71913)
                    : c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71989 || (c < 71995
                    ? (c >= 71991 && c <= 71992)
                    : c <= 72003)))))
              : (c <= 72025 || (c < 72263
                ? (c < 72154
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72151)
                  : (c <= 72161 || (c < 72192
                    ? (c >= 72163 && c <= 72164)
                    : c <= 72254)))
                : (c <= 72263 || (c < 72368
                  ? (c < 72349
                    ? (c >= 72272 && c <= 72345)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72758)))))))
            : (c <= 72768 || (c < 73056
              ? (c < 72968
                ? (c < 72850
                  ? (c < 72818
                    ? (c >= 72784 && c <= 72793)
                    : c <= 72847)
                  : (c <= 72871 || (c < 72960
                    ? (c >= 72873 && c <= 72886)
                    : c <= 72966)))
                : (c <= 72969 || (c < 73020
                  ? (c < 73018
                    ? (c >= 72971 && c <= 73014)
                    : c <= 73018)
                  : (c <= 73021 || (c < 73040
                    ? (c >= 73023 && c <= 73031)
                    : c <= 73049)))))
              : (c <= 73061 || (c < 73440
                ? (c < 73104
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73102)
                  : (c <= 73105 || (c < 73120
                    ? (c >= 73107 && c <= 73112)
                    : c <= 73129)))
                : (c <= 73462 || (c < 74752
                  ? (c < 73728
                    ? c == 73648
                    : c <= 74649)
                  : (c <= 74862 || (c < 77712
                    ? (c >= 74880 && c <= 75075)
                    : c <= 77808)))))))))
          : (c <= 78894 || (c < 110576
            ? (c < 93027
              ? (c < 92864
                ? (c < 92736
                  ? (c < 92160
                    ? (c >= 82944 && c <= 83526)
                    : c <= 92728)
                  : (c <= 92766 || (c < 92784
                    ? (c >= 92768 && c <= 92777)
                    : c <= 92862)))
                : (c <= 92873 || (c < 92928
                  ? (c < 92912
                    ? (c >= 92880 && c <= 92909)
                    : c <= 92916)
                  : (c <= 92982 || (c < 93008
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93017)))))
              : (c <= 93047 || (c < 94176
                ? (c < 93952
                  ? (c < 93760
                    ? (c >= 93053 && c <= 93071)
                    : c <= 93823)
                  : (c <= 94026 || (c < 94095
                    ? (c >= 94031 && c <= 94087)
                    : c <= 94111)))
                : (c <= 94177 || (c < 94208
                  ? (c < 94192
                    ? (c >= 94179 && c <= 94180)
                    : c <= 94193)
                  : (c <= 100343 || (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)))))))
            : (c <= 110579 || (c < 118528
              ? (c < 110960
                ? (c < 110592
                  ? (c < 110589
                    ? (c >= 110581 && c <= 110587)
                    : c <= 110590)
                  : (c <= 110882 || (c < 110948
                    ? (c >= 110928 && c <= 110930)
                    : c <= 110951)))
                : (c <= 111355 || (c < 113792
                  ? (c < 113776
                    ? (c >= 113664 && c <= 113770)
                    : c <= 113788)
                  : (c <= 113800 || (c < 113821
                    ? (c >= 113808 && c <= 113817)
                    : c <= 113822)))))
              : (c <= 118573 || (c < 119210
                ? (c < 119149
                  ? (c < 119141
                    ? (c >= 118576 && c <= 118598)
                    : c <= 119145)
                  : (c <= 119154 || (c < 119173
                    ? (c >= 119163 && c <= 119170)
                    : c <= 119179)))
                : (c <= 119213 || (c < 119894
                  ? (c < 119808
                    ? (c >= 119362 && c <= 119364)
                    : c <= 119892)
                  : (c <= 119964 || (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)))))))))))
        : (c <= 119974 || (c < 124912
          ? (c < 120746
            ? (c < 120134
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c < 120128
                    ? (c >= 120123 && c <= 120126)
                    : c <= 120132)))))
              : (c <= 120134 || (c < 120572
                ? (c < 120488
                  ? (c < 120146
                    ? (c >= 120138 && c <= 120144)
                    : c <= 120485)
                  : (c <= 120512 || (c < 120540
                    ? (c >= 120514 && c <= 120538)
                    : c <= 120570)))
                : (c <= 120596 || (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)))))))
            : (c <= 120770 || (c < 122907
              ? (c < 121476
                ? (c < 121344
                  ? (c < 120782
                    ? (c >= 120772 && c <= 120779)
                    : c <= 120831)
                  : (c <= 121398 || (c < 121461
                    ? (c >= 121403 && c <= 121452)
                    : c <= 121461)))
                : (c <= 121476 || (c < 122624
                  ? (c < 121505
                    ? (c >= 121499 && c <= 121503)
                    : c <= 121519)
                  : (c <= 122654 || (c < 122888
                    ? (c >= 122880 && c <= 122886)
                    : c <= 122904)))))
              : (c <= 122913 || (c < 123214
                ? (c < 123136
                  ? (c < 122918
                    ? (c >= 122915 && c <= 122916)
                    : c <= 122922)
                  : (c <= 123180 || (c < 123200
                    ? (c >= 123184 && c <= 123197)
                    : c <= 123209)))
                : (c <= 123214 || (c < 124896
                  ? (c < 123584
                    ? (c >= 123536 && c <= 123566)
                    : c <= 123641)
                  : (c <= 124902 || (c < 124909
                    ? (c >= 124904 && c <= 124907)
                    : c <= 124910)))))))))
          : (c <= 124926 || (c < 126557
            ? (c < 126521
              ? (c < 126469
                ? (c < 125184
                  ? (c < 125136
                    ? (c >= 124928 && c <= 125124)
                    : c <= 125142)
                  : (c <= 125259 || (c < 126464
                    ? (c >= 125264 && c <= 125273)
                    : c <= 126467)))
                : (c <= 126495 || (c < 126503
                  ? (c < 126500
                    ? (c >= 126497 && c <= 126498)
                    : c <= 126500)
                  : (c <= 126503 || (c < 126516
                    ? (c >= 126505 && c <= 126514)
                    : c <= 126519)))))
              : (c <= 126521 || (c < 126541
                ? (c < 126535
                  ? (c < 126530
                    ? c == 126523
                    : c <= 126530)
                  : (c <= 126535 || (c < 126539
                    ? c == 126537
                    : c <= 126539)))
                : (c <= 126543 || (c < 126551
                  ? (c < 126548
                    ? (c >= 126545 && c <= 126546)
                    : c <= 126548)
                  : (c <= 126551 || (c < 126555
                    ? c == 126553
                    : c <= 126555)))))))
            : (c <= 126557 || (c < 126629
              ? (c < 126580
                ? (c < 126564
                  ? (c < 126561
                    ? c == 126559
                    : c <= 126562)
                  : (c <= 126564 || (c < 126572
                    ? (c >= 126567 && c <= 126570)
                    : c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c < 126625
                    ? (c >= 126603 && c <= 126619)
                    : c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 131072
                  ? (c < 130032
                    ? (c >= 126635 && c <= 126651)
                    : c <= 130041)
                  : (c <= 173791 || (c < 177984
                    ? (c >= 173824 && c <= 177976)
                    : c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 917760 && c <= 917999)))))))))))))))));
}

static inline bool sym_escape_sequence_character_set_1(int32_t c) {
  return (c < 'b'
    ? (c < '/'
      ? (c < '\''
        ? c == '"'
        : c <= '\'')
      : (c <= '/' || c == '\\'))
    : (c <= 'b' || (c < 'r'
      ? (c < 'n'
        ? c == 'f'
        : c <= 'n')
      : (c <= 'r' || c == 't'))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(92);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == '\'') ADVANCE(150);
      if (lookahead == '(') ADVANCE(99);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == ',') ADVANCE(118);
      if (lookahead == '-') ADVANCE(161);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '0') ADVANCE(156);
      if (lookahead == ':') ADVANCE(117);
      if (lookahead == ';') ADVANCE(95);
      if (lookahead == '=') ADVANCE(135);
      if (lookahead == '?') ADVANCE(116);
      if (lookahead == '[') ADVANCE(98);
      if (lookahead == '\\') ADVANCE(68);
      if (lookahead == ']') ADVANCE(100);
      if (lookahead == '_') ADVANCE(144);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'b') ADVANCE(33);
      if (lookahead == 'd') ADVANCE(12);
      if (lookahead == 'e') ADVANCE(56);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(46);
      if (lookahead == 'l') ADVANCE(27);
      if (lookahead == 'm') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(69);
      if (lookahead == 'r') ADVANCE(13);
      if (lookahead == 's') ADVANCE(67);
      if (lookahead == 't') ADVANCE(11);
      if (lookahead == '{') ADVANCE(132);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '}') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(89)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(159);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == '\'') ADVANCE(150);
      if (lookahead == '-') ADVANCE(161);
      if (lookahead == '.') ADVANCE(9);
      if (lookahead == '0') ADVANCE(156);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'f') ADVANCE(102);
      if (lookahead == 't') ADVANCE(109);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(159);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(115);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == '\'') ADVANCE(150);
      if (lookahead == '-') ADVANCE(161);
      if (lookahead == '0') ADVANCE(156);
      if (lookahead == '_') ADVANCE(145);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'f') ADVANCE(102);
      if (lookahead == 'm') ADVANCE(113);
      if (lookahead == 't') ADVANCE(109);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(159);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(115);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(147);
      if (lookahead == '\\') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(148);
      if (lookahead != 0) ADVANCE(147);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == ',') ADVANCE(118);
      if (lookahead == ':') ADVANCE(117);
      if (lookahead == '?') ADVANCE(116);
      if (lookahead == ']') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(115);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(154);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0) ADVANCE(154);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(151);
      if (lookahead == '\'') ADVANCE(149);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(152);
      if (lookahead != 0) ADVANCE(151);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(162);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(137);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(136);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(37);
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == 'l') ADVANCE(51);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(18);
      if (lookahead == 'r') ADVANCE(71);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(29);
      if (lookahead == 'u') ADVANCE(57);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(42);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(66);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 17:
      if (lookahead == 'b') ADVANCE(28);
      END_STATE();
    case 18:
      if (lookahead == 'b') ADVANCE(40);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(36);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(126);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(164);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(166);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(121);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(129);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 29:
      if (lookahead == 'f') ADVANCE(96);
      END_STATE();
    case 30:
      if (lookahead == 'g') ADVANCE(123);
      END_STATE();
    case 31:
      if (lookahead == 'g') ADVANCE(23);
      END_STATE();
    case 32:
      if (lookahead == 'i') ADVANCE(74);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == 'l') ADVANCE(47);
      if (lookahead == 'o') ADVANCE(48);
      END_STATE();
    case 34:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 35:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 36:
      if (lookahead == 'k') ADVANCE(124);
      END_STATE();
    case 37:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 38:
      if (lookahead == 'l') ADVANCE(122);
      END_STATE();
    case 39:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 40:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 41:
      if (lookahead == 'm') ADVANCE(17);
      END_STATE();
    case 42:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(125);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 45:
      if (lookahead == 'n') ADVANCE(30);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 48:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 50:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 51:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(130);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(128);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(58);
      END_STATE();
    case 57:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 58:
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 59:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 60:
      if (lookahead == 's') ADVANCE(22);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(119);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(140);
      END_STATE();
    case 63:
      if (lookahead == 't') ADVANCE(142);
      END_STATE();
    case 64:
      if (lookahead == 't') ADVANCE(120);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(20);
      END_STATE();
    case 66:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 67:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 68:
      if (lookahead == 'u') ADVANCE(86);
      if (sym_escape_sequence_character_set_1(lookahead)) ADVANCE(163);
      END_STATE();
    case 69:
      if (lookahead == 'u') ADVANCE(41);
      END_STATE();
    case 70:
      if (lookahead == 'u') ADVANCE(75);
      if (lookahead == 'x') ADVANCE(82);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 71:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 72:
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 73:
      if (lookahead == 'y') ADVANCE(131);
      END_STATE();
    case 74:
      if (lookahead == 'z') ADVANCE(25);
      END_STATE();
    case 75:
      if (lookahead == '{') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(84);
      END_STATE();
    case 76:
      if (lookahead == '}') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 77:
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(157);
      END_STATE();
    case 78:
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(158);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 81:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 82:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(82);
      END_STATE();
    case 85:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(83);
      END_STATE();
    case 86:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 87:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      END_STATE();
    case 88:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 89:
      if (eof) ADVANCE(92);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == '\'') ADVANCE(150);
      if (lookahead == '(') ADVANCE(99);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == ',') ADVANCE(118);
      if (lookahead == '-') ADVANCE(161);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '0') ADVANCE(156);
      if (lookahead == ':') ADVANCE(117);
      if (lookahead == ';') ADVANCE(95);
      if (lookahead == '=') ADVANCE(135);
      if (lookahead == '?') ADVANCE(116);
      if (lookahead == '[') ADVANCE(98);
      if (lookahead == ']') ADVANCE(100);
      if (lookahead == '_') ADVANCE(144);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'b') ADVANCE(33);
      if (lookahead == 'd') ADVANCE(12);
      if (lookahead == 'e') ADVANCE(56);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(46);
      if (lookahead == 'l') ADVANCE(27);
      if (lookahead == 'm') ADVANCE(72);
      if (lookahead == 'n') ADVANCE(69);
      if (lookahead == 'r') ADVANCE(13);
      if (lookahead == 's') ADVANCE(67);
      if (lookahead == 't') ADVANCE(11);
      if (lookahead == '{') ADVANCE(132);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '}') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(89)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(159);
      END_STATE();
    case 90:
      if (eof) ADVANCE(92);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == '\'') ADVANCE(150);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '0') ADVANCE(156);
      if (lookahead == ':') ADVANCE(117);
      if (lookahead == ';') ADVANCE(95);
      if (lookahead == '=') ADVANCE(135);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'd') ADVANCE(103);
      if (lookahead == 'f') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(104);
      if (lookahead == 't') ADVANCE(109);
      if (lookahead == '{') ADVANCE(132);
      if (lookahead == '}') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(90)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(159);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(115);
      END_STATE();
    case 91:
      if (eof) ADVANCE(92);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '$') ADVANCE(88);
      if (lookahead == '\'') ADVANCE(150);
      if (lookahead == '.') ADVANCE(9);
      if (lookahead == '0') ADVANCE(156);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'd') ADVANCE(103);
      if (lookahead == 'f') ADVANCE(102);
      if (lookahead == 'l') ADVANCE(104);
      if (lookahead == 't') ADVANCE(109);
      if (lookahead == '{') ADVANCE(132);
      if (lookahead == '}') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(91)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(159);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(115);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_def);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(108);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(115);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(107);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(111);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(165);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(167);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(97);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(110);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(114);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(106);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(141);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(143);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(112);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(105);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_duration);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_date);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_filesize);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_error);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_binary);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_metavariable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(138);
      if (lookahead == '=') ADVANCE(139);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOT);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_EQ);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_let);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_mutable_specifier);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_mutable_specifier);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym__);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym__double_quoted_string_literal_token1);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym__double_quoted_string_literal_token1);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '#') ADVANCE(147);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(147);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead == '\'') ADVANCE(162);
      if (lookahead == '\\') ADVANCE(70);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym__single_quoted_string_literal_token1);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym__single_quoted_string_literal_token1);
      if (lookahead == '#') ADVANCE(151);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(152);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(151);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym__backticked_quoted_string_literal_token1);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym__backticked_quoted_string_literal_token1);
      if (lookahead == '#') ADVANCE(154);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(154);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'b') ADVANCE(77);
      if (lookahead == 'o') ADVANCE(78);
      if (lookahead == 'x') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(159);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_integer_literal);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_integer_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_integer_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_char_literal);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_true);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_false);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(115);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 91},
  [2] = {.lex_state = 91},
  [3] = {.lex_state = 91},
  [4] = {.lex_state = 91},
  [5] = {.lex_state = 91},
  [6] = {.lex_state = 90},
  [7] = {.lex_state = 90},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 90},
  [12] = {.lex_state = 90},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 90},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 90},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 90},
  [21] = {.lex_state = 90},
  [22] = {.lex_state = 90},
  [23] = {.lex_state = 90},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 90},
  [26] = {.lex_state = 90},
  [27] = {.lex_state = 90},
  [28] = {.lex_state = 90},
  [29] = {.lex_state = 90},
  [30] = {.lex_state = 90},
  [31] = {.lex_state = 90},
  [32] = {.lex_state = 90},
  [33] = {.lex_state = 90},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 90},
  [36] = {.lex_state = 91},
  [37] = {.lex_state = 91},
  [38] = {.lex_state = 91},
  [39] = {.lex_state = 91},
  [40] = {.lex_state = 91},
  [41] = {.lex_state = 91},
  [42] = {.lex_state = 91},
  [43] = {.lex_state = 91},
  [44] = {.lex_state = 91},
  [45] = {.lex_state = 91},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 3},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 6},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 6},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 4},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 5},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_range] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_block] = ACTIONS(1),
    [anon_sym_duration] = ACTIONS(1),
    [anon_sym_date] = ACTIONS(1),
    [anon_sym_filesize] = ACTIONS(1),
    [anon_sym_number] = ACTIONS(1),
    [anon_sym_table] = ACTIONS(1),
    [anon_sym_error] = ACTIONS(1),
    [anon_sym_binary] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_metavariable] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [anon_sym_DOT_DOT_DOT] = ACTIONS(1),
    [anon_sym_DOT_DOT_EQ] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [sym_mutable_specifier] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_integer_literal] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_char_literal] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(82),
    [sym__statement] = STATE(5),
    [sym_custom_command] = STATE(5),
    [sym_custom_command_signature] = STATE(74),
    [sym_block] = STATE(40),
    [sym_expression_statement] = STATE(5),
    [sym__expression] = STATE(31),
    [sym__expression_except_range] = STATE(31),
    [sym_assignment_expression] = STATE(31),
    [sym_range_expression] = STATE(31),
    [sym__expression_ending_with_block] = STATE(40),
    [sym__declaration_statement] = STATE(5),
    [sym_let_declaration] = STATE(5),
    [sym__literal] = STATE(31),
    [sym__double_quoted_string_literal] = STATE(14),
    [sym__single_quoted_string_literal] = STATE(14),
    [sym__backticked_quoted_string_literal] = STATE(14),
    [sym_string_literal] = STATE(31),
    [sym_boolean_literal] = STATE(31),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_def] = ACTIONS(7),
    [sym_identifier] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_metavariable] = ACTIONS(13),
    [anon_sym_DOT_DOT] = ACTIONS(15),
    [anon_sym_let] = ACTIONS(17),
    [anon_sym_DQUOTE] = ACTIONS(19),
    [anon_sym_SQUOTE] = ACTIONS(21),
    [anon_sym_BQUOTE] = ACTIONS(23),
    [sym_integer_literal] = ACTIONS(13),
    [sym_char_literal] = ACTIONS(13),
    [anon_sym_true] = ACTIONS(25),
    [anon_sym_false] = ACTIONS(25),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 17,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(29), 1,
      anon_sym_def,
    ACTIONS(32), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_LBRACE,
    ACTIONS(41), 1,
      anon_sym_DOT_DOT,
    ACTIONS(44), 1,
      anon_sym_let,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(50), 1,
      anon_sym_SQUOTE,
    ACTIONS(53), 1,
      anon_sym_BQUOTE,
    STATE(74), 1,
      sym_custom_command_signature,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    ACTIONS(56), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(40), 2,
      sym_block,
      sym__expression_ending_with_block,
    ACTIONS(38), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(2), 6,
      sym__statement,
      sym_custom_command,
      sym_expression_statement,
      sym__declaration_statement,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
    STATE(31), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [70] = 17,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(17), 1,
      anon_sym_let,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(59), 1,
      sym_identifier,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    STATE(74), 1,
      sym_custom_command_signature,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(40), 2,
      sym_block,
      sym__expression_ending_with_block,
    ACTIONS(63), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(4), 6,
      sym__statement,
      sym_custom_command,
      sym_expression_statement,
      sym__declaration_statement,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
    STATE(33), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [139] = 17,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(17), 1,
      anon_sym_let,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      anon_sym_RBRACE,
    STATE(74), 1,
      sym_custom_command_signature,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(40), 2,
      sym_block,
      sym__expression_ending_with_block,
    ACTIONS(69), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(2), 6,
      sym__statement,
      sym_custom_command,
      sym_expression_statement,
      sym__declaration_statement,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
    STATE(35), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [208] = 17,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      sym_identifier,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(17), 1,
      anon_sym_let,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(71), 1,
      ts_builtin_sym_end,
    STATE(74), 1,
      sym_custom_command_signature,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(40), 2,
      sym_block,
      sym__expression_ending_with_block,
    ACTIONS(13), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(2), 6,
      sym__statement,
      sym_custom_command,
      sym_expression_statement,
      sym__declaration_statement,
      sym_let_declaration,
      aux_sym_source_file_repeat1,
    STATE(31), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [277] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    ACTIONS(75), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    STATE(32), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
    ACTIONS(73), 12,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [318] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    ACTIONS(79), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    STATE(26), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
    ACTIONS(77), 12,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [359] = 15,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(83), 1,
      sym_metavariable,
    ACTIONS(85), 1,
      sym_mutable_specifier,
    ACTIONS(87), 1,
      anon_sym__,
    ACTIONS(91), 1,
      anon_sym_DASH,
    STATE(77), 1,
      sym__path,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(89), 2,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(78), 3,
      sym__pattern,
      sym_mut_pattern,
      sym_range_pattern,
    STATE(60), 4,
      sym__literal_pattern,
      sym_string_literal,
      sym_negative_literal,
      sym_boolean_literal,
  [414] = 15,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(83), 1,
      sym_metavariable,
    ACTIONS(85), 1,
      sym_mutable_specifier,
    ACTIONS(91), 1,
      anon_sym_DASH,
    ACTIONS(93), 1,
      anon_sym__,
    STATE(77), 1,
      sym__path,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(89), 2,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(75), 3,
      sym__pattern,
      sym_mut_pattern,
      sym_range_pattern,
    STATE(60), 4,
      sym__literal_pattern,
      sym_string_literal,
      sym_negative_literal,
      sym_boolean_literal,
  [469] = 15,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(83), 1,
      sym_metavariable,
    ACTIONS(91), 1,
      anon_sym_DASH,
    ACTIONS(95), 1,
      sym_mutable_specifier,
    ACTIONS(97), 1,
      anon_sym__,
    STATE(77), 1,
      sym__path,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(89), 2,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(79), 3,
      sym__pattern,
      sym_mut_pattern,
      sym_range_pattern,
    STATE(60), 4,
      sym__literal_pattern,
      sym_string_literal,
      sym_negative_literal,
      sym_boolean_literal,
  [524] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(101), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(99), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [552] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(105), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(103), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [580] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(109), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(28), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [622] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(113), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(111), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [650] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(117), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(25), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [692] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(119), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(121), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(26), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [734] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(125), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(123), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [762] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(129), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(27), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [804] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(131), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(133), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(30), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [846] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(137), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(135), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [874] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(141), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(139), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [902] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(145), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(143), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [930] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(149), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(147), 13,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_COLON,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [958] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      anon_sym_DOT_DOT,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(151), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(153), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(29), 7,
      sym__expression,
      sym__expression_except_range,
      sym_assignment_expression,
      sym_range_expression,
      sym__literal,
      sym_string_literal,
      sym_boolean_literal,
  [1000] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_SEMI,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(159), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(155), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1035] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(169), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(167), 12,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1062] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(173), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(171), 10,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1093] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(177), 1,
      anon_sym_SEMI,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(179), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(175), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1128] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(183), 1,
      anon_sym_SEMI,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(185), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(181), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1163] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(189), 1,
      anon_sym_SEMI,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(191), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(187), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1198] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(195), 1,
      anon_sym_SEMI,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(197), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(193), 8,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1233] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(79), 7,
      anon_sym_def,
      sym_identifier,
      anon_sym_DOT_DOT,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(77), 12,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1260] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(195), 1,
      anon_sym_SEMI,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(193), 6,
      anon_sym_LBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
    ACTIONS(197), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1296] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(91), 1,
      anon_sym_DASH,
    ACTIONS(202), 1,
      sym_identifier,
    ACTIONS(25), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(204), 3,
      sym_metavariable,
      sym_integer_literal,
      sym_char_literal,
    STATE(14), 3,
      sym__double_quoted_string_literal,
      sym__single_quoted_string_literal,
      sym__backticked_quoted_string_literal,
    STATE(76), 5,
      sym__literal_pattern,
      sym_string_literal,
      sym_negative_literal,
      sym_boolean_literal,
      sym__path,
  [1336] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(161), 1,
      anon_sym_EQ,
    ACTIONS(163), 1,
      anon_sym_DOT_DOT,
    ACTIONS(195), 1,
      anon_sym_SEMI,
    ACTIONS(206), 1,
      anon_sym_RBRACE,
    ACTIONS(165), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
    ACTIONS(193), 6,
      anon_sym_LBRACE,
      sym_metavariable,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
    ACTIONS(197), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1372] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(211), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(209), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1395] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(215), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(213), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1418] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(219), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(217), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1441] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(223), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(221), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1464] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(197), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(193), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1487] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(227), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(225), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1510] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(231), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(229), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1533] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(235), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(233), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1556] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(239), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(237), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1579] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(243), 6,
      anon_sym_def,
      sym_identifier,
      anon_sym_let,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(241), 9,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_metavariable,
      anon_sym_DOT_DOT,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_integer_literal,
      sym_char_literal,
  [1602] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(56), 1,
      sym_type,
    ACTIONS(245), 13,
      anon_sym_int,
      anon_sym_float,
      anon_sym_range,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_block,
      anon_sym_duration,
      anon_sym_date,
      anon_sym_filesize,
      anon_sym_number,
      anon_sym_table,
      anon_sym_error,
      anon_sym_binary,
  [1624] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(58), 1,
      sym_type,
    ACTIONS(245), 13,
      anon_sym_int,
      anon_sym_float,
      anon_sym_range,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_block,
      anon_sym_duration,
      anon_sym_date,
      anon_sym_filesize,
      anon_sym_number,
      anon_sym_table,
      anon_sym_error,
      anon_sym_binary,
  [1646] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(249), 1,
      anon_sym_QMARK,
    ACTIONS(251), 1,
      anon_sym_COLON,
    ACTIONS(253), 1,
      anon_sym_COMMA,
    ACTIONS(247), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1664] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(257), 1,
      sym_identifier,
    ACTIONS(255), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(52), 2,
      sym_parameter,
      aux_sym_custom_command_signature_repeat1,
  [1679] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(261), 1,
      sym_identifier,
    ACTIONS(259), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(50), 2,
      sym_parameter,
      aux_sym_custom_command_signature_repeat1,
  [1694] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(266), 1,
      anon_sym_COLON,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(264), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1709] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(257), 1,
      sym_identifier,
    ACTIONS(270), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(50), 2,
      sym_parameter,
      aux_sym_custom_command_signature_repeat1,
  [1724] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(272), 2,
      anon_sym_COLON,
      anon_sym_EQ,
    ACTIONS(274), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
  [1736] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(276), 4,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
      anon_sym_COMMA,
  [1746] = 5,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(280), 1,
      anon_sym_DQUOTE,
    ACTIONS(282), 1,
      aux_sym__double_quoted_string_literal_token1,
    ACTIONS(284), 1,
      sym_escape_sequence,
    STATE(63), 1,
      aux_sym__double_quoted_string_literal_repeat1,
  [1762] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(288), 1,
      anon_sym_COMMA,
    ACTIONS(286), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1774] = 5,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(290), 1,
      anon_sym_DQUOTE,
    ACTIONS(292), 1,
      aux_sym__double_quoted_string_literal_token1,
    ACTIONS(295), 1,
      sym_escape_sequence,
    STATE(57), 1,
      aux_sym__double_quoted_string_literal_repeat1,
  [1790] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(300), 1,
      anon_sym_COMMA,
    ACTIONS(298), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1802] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(302), 1,
      sym_identifier,
    ACTIONS(304), 1,
      sym_metavariable,
    STATE(86), 2,
      sym__type,
      sym__type_identifier,
  [1816] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(272), 2,
      anon_sym_COLON,
      anon_sym_EQ,
    ACTIONS(306), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
  [1828] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(302), 1,
      sym_identifier,
    ACTIONS(308), 1,
      sym_metavariable,
    STATE(87), 2,
      sym__type,
      sym__type_identifier,
  [1842] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(310), 4,
      anon_sym_COLON,
      anon_sym_EQ,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
  [1852] = 5,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(312), 1,
      anon_sym_DQUOTE,
    ACTIONS(314), 1,
      aux_sym__double_quoted_string_literal_token1,
    ACTIONS(316), 1,
      sym_escape_sequence,
    STATE(57), 1,
      aux_sym__double_quoted_string_literal_repeat1,
  [1868] = 4,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(318), 1,
      anon_sym_BQUOTE,
    ACTIONS(320), 1,
      aux_sym__backticked_quoted_string_literal_token1,
    STATE(73), 1,
      aux_sym__backticked_quoted_string_literal_repeat1,
  [1881] = 4,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(322), 1,
      anon_sym_SQUOTE,
    ACTIONS(324), 1,
      aux_sym__single_quoted_string_literal_token1,
    STATE(67), 1,
      aux_sym__single_quoted_string_literal_repeat1,
  [1894] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(264), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1903] = 4,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(326), 1,
      anon_sym_SQUOTE,
    ACTIONS(328), 1,
      aux_sym__single_quoted_string_literal_token1,
    STATE(67), 1,
      aux_sym__single_quoted_string_literal_repeat1,
  [1916] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(331), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1925] = 4,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(333), 1,
      anon_sym_SQUOTE,
    ACTIONS(335), 1,
      aux_sym__single_quoted_string_literal_token1,
    STATE(65), 1,
      aux_sym__single_quoted_string_literal_repeat1,
  [1938] = 4,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(337), 1,
      anon_sym_BQUOTE,
    ACTIONS(339), 1,
      aux_sym__backticked_quoted_string_literal_token1,
    STATE(64), 1,
      aux_sym__backticked_quoted_string_literal_repeat1,
  [1951] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(341), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1960] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(343), 3,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_identifier,
  [1969] = 4,
    ACTIONS(278), 1,
      sym_line_comment,
    ACTIONS(345), 1,
      anon_sym_BQUOTE,
    ACTIONS(347), 1,
      aux_sym__backticked_quoted_string_literal_token1,
    STATE(73), 1,
      aux_sym__backticked_quoted_string_literal_repeat1,
  [1982] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    STATE(43), 1,
      sym_block,
  [1992] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(350), 1,
      anon_sym_COLON,
    ACTIONS(352), 1,
      anon_sym_EQ,
  [2002] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(354), 2,
      anon_sym_COLON,
      anon_sym_EQ,
  [2010] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(306), 2,
      anon_sym_DOT_DOT_DOT,
      anon_sym_DOT_DOT_EQ,
  [2018] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(356), 2,
      anon_sym_COLON,
      anon_sym_EQ,
  [2026] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(358), 1,
      anon_sym_COLON,
    ACTIONS(360), 1,
      anon_sym_EQ,
  [2036] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(362), 2,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [2044] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(364), 1,
      sym_integer_literal,
  [2051] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(366), 1,
      ts_builtin_sym_end,
  [2058] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(368), 1,
      anon_sym_LBRACE,
  [2065] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(370), 1,
      anon_sym_LBRACE,
  [2072] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(372), 1,
      sym_identifier,
  [2079] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(374), 1,
      anon_sym_EQ,
  [2086] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(376), 1,
      anon_sym_EQ,
  [2093] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(378), 1,
      anon_sym_EQ,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 70,
  [SMALL_STATE(4)] = 139,
  [SMALL_STATE(5)] = 208,
  [SMALL_STATE(6)] = 277,
  [SMALL_STATE(7)] = 318,
  [SMALL_STATE(8)] = 359,
  [SMALL_STATE(9)] = 414,
  [SMALL_STATE(10)] = 469,
  [SMALL_STATE(11)] = 524,
  [SMALL_STATE(12)] = 552,
  [SMALL_STATE(13)] = 580,
  [SMALL_STATE(14)] = 622,
  [SMALL_STATE(15)] = 650,
  [SMALL_STATE(16)] = 692,
  [SMALL_STATE(17)] = 734,
  [SMALL_STATE(18)] = 762,
  [SMALL_STATE(19)] = 804,
  [SMALL_STATE(20)] = 846,
  [SMALL_STATE(21)] = 874,
  [SMALL_STATE(22)] = 902,
  [SMALL_STATE(23)] = 930,
  [SMALL_STATE(24)] = 958,
  [SMALL_STATE(25)] = 1000,
  [SMALL_STATE(26)] = 1035,
  [SMALL_STATE(27)] = 1062,
  [SMALL_STATE(28)] = 1093,
  [SMALL_STATE(29)] = 1128,
  [SMALL_STATE(30)] = 1163,
  [SMALL_STATE(31)] = 1198,
  [SMALL_STATE(32)] = 1233,
  [SMALL_STATE(33)] = 1260,
  [SMALL_STATE(34)] = 1296,
  [SMALL_STATE(35)] = 1336,
  [SMALL_STATE(36)] = 1372,
  [SMALL_STATE(37)] = 1395,
  [SMALL_STATE(38)] = 1418,
  [SMALL_STATE(39)] = 1441,
  [SMALL_STATE(40)] = 1464,
  [SMALL_STATE(41)] = 1487,
  [SMALL_STATE(42)] = 1510,
  [SMALL_STATE(43)] = 1533,
  [SMALL_STATE(44)] = 1556,
  [SMALL_STATE(45)] = 1579,
  [SMALL_STATE(46)] = 1602,
  [SMALL_STATE(47)] = 1624,
  [SMALL_STATE(48)] = 1646,
  [SMALL_STATE(49)] = 1664,
  [SMALL_STATE(50)] = 1679,
  [SMALL_STATE(51)] = 1694,
  [SMALL_STATE(52)] = 1709,
  [SMALL_STATE(53)] = 1724,
  [SMALL_STATE(54)] = 1736,
  [SMALL_STATE(55)] = 1746,
  [SMALL_STATE(56)] = 1762,
  [SMALL_STATE(57)] = 1774,
  [SMALL_STATE(58)] = 1790,
  [SMALL_STATE(59)] = 1802,
  [SMALL_STATE(60)] = 1816,
  [SMALL_STATE(61)] = 1828,
  [SMALL_STATE(62)] = 1842,
  [SMALL_STATE(63)] = 1852,
  [SMALL_STATE(64)] = 1868,
  [SMALL_STATE(65)] = 1881,
  [SMALL_STATE(66)] = 1894,
  [SMALL_STATE(67)] = 1903,
  [SMALL_STATE(68)] = 1916,
  [SMALL_STATE(69)] = 1925,
  [SMALL_STATE(70)] = 1938,
  [SMALL_STATE(71)] = 1951,
  [SMALL_STATE(72)] = 1960,
  [SMALL_STATE(73)] = 1969,
  [SMALL_STATE(74)] = 1982,
  [SMALL_STATE(75)] = 1992,
  [SMALL_STATE(76)] = 2002,
  [SMALL_STATE(77)] = 2010,
  [SMALL_STATE(78)] = 2018,
  [SMALL_STATE(79)] = 2026,
  [SMALL_STATE(80)] = 2036,
  [SMALL_STATE(81)] = 2044,
  [SMALL_STATE(82)] = 2051,
  [SMALL_STATE(83)] = 2058,
  [SMALL_STATE(84)] = 2065,
  [SMALL_STATE(85)] = 2072,
  [SMALL_STATE(86)] = 2079,
  [SMALL_STATE(87)] = 2086,
  [SMALL_STATE(88)] = 2093,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(85),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(31),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(31),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(55),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(69),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(70),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(17),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range_expression, 1),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_range_expression, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range_expression, 2),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_range_expression, 2),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__single_quoted_string_literal, 3),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__single_quoted_string_literal, 3),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__backticked_quoted_string_literal, 3),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__backticked_quoted_string_literal, 3),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 1),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 1),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__backticked_quoted_string_literal, 2),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__backticked_quoted_string_literal, 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__double_quoted_string_literal, 3),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__double_quoted_string_literal, 3),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__double_quoted_string_literal, 2),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__double_quoted_string_literal, 2),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__single_quoted_string_literal, 2),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__single_quoted_string_literal, 2),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 5, .production_id = 6),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 5, .production_id = 6),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range_expression, 3),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_range_expression, 3),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_expression, 3, .production_id = 1),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment_expression, 3, .production_id = 1),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 7, .production_id = 10),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 7, .production_id = 10),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 6, .production_id = 8),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 6, .production_id = 8),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 4, .production_id = 5),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 4, .production_id = 5),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 1),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_statement, 1),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_expression_statement, 1), SHIFT(38),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [206] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_expression_statement, 1), SHIFT(36),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 4),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 4),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 8, .production_id = 10),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 8, .production_id = 10),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 2),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_statement, 2),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 6, .production_id = 6),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 6, .production_id = 6),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_custom_command, 2),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_custom_command, 2),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 5, .production_id = 5),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 5, .production_id = 5),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_declaration, 7, .production_id = 8),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_declaration, 7, .production_id = 8),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1, .production_id = 3),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_custom_command_signature_repeat1, 2),
  [261] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_custom_command_signature_repeat1, 2), SHIFT_REPEAT(48),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2, .production_id = 3),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__pattern, 1),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__path, 1),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4, .production_id = 9),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__double_quoted_string_literal_repeat1, 2),
  [292] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__double_quoted_string_literal_repeat1, 2), SHIFT_REPEAT(57),
  [295] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__double_quoted_string_literal_repeat1, 2), SHIFT_REPEAT(57),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3, .production_id = 7),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_negative_literal, 2),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [322] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [326] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__single_quoted_string_literal_repeat1, 2),
  [328] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__single_quoted_string_literal_repeat1, 2), SHIFT_REPEAT(67),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 5, .production_id = 9),
  [333] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [337] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3, .production_id = 3),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4, .production_id = 7),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__backticked_quoted_string_literal_repeat1, 2),
  [347] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__backticked_quoted_string_literal_repeat1, 2), SHIFT_REPEAT(73),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range_pattern, 3),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_pattern, 2),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [366] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_custom_command_signature, 4, .production_id = 2),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_custom_command_signature, 5, .production_id = 2),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_identifier, 1, .production_id = 4),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nu(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
