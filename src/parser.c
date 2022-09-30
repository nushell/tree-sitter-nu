#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 139
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 101
#define ALIAS_COUNT 0
#define TOKEN_COUNT 69
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 8

enum {
  anon_sym_let = 1,
  anon_sym_EQ = 2,
  anon_sym_LBRACK = 3,
  anon_sym_LPAREN = 4,
  anon_sym_RBRACK = 5,
  anon_sym_RPAREN = 6,
  anon_sym_COLON = 7,
  anon_sym_LF = 8,
  anon_sym_CR = 9,
  anon_sym_CR_LF = 10,
  anon_sym_PIPE = 11,
  anon_sym_SEMI = 12,
  anon_sym_COMMA = 13,
  anon_sym_QMARK = 14,
  sym_flag_name = 15,
  sym_flag_shorthand_name = 16,
  anon_sym_DOT_DOT_DOTrest = 17,
  anon_sym_AT = 18,
  anon_sym_export = 19,
  anon_sym_def = 20,
  anon_sym_int = 21,
  anon_sym_float = 22,
  anon_sym_range = 23,
  anon_sym_bool = 24,
  anon_sym_string = 25,
  anon_sym_block = 26,
  anon_sym_duration = 27,
  anon_sym_date = 28,
  anon_sym_filesize = 29,
  anon_sym_number = 30,
  anon_sym_table = 31,
  anon_sym_error = 32,
  anon_sym_binary = 33,
  anon_sym_DOLLAR = 34,
  anon_sym_DQUOTE = 35,
  aux_sym_string_token1 = 36,
  anon_sym_SQUOTE = 37,
  aux_sym_string_token2 = 38,
  anon_sym_BQUOTE = 39,
  aux_sym_string_token3 = 40,
  sym_number_literal = 41,
  anon_sym_DOT = 42,
  aux_sym_file_path_token1 = 43,
  aux_sym_file_path_token2 = 44,
  sym_flag_arg = 45,
  anon_sym_DOT_DOT = 46,
  sym_word = 47,
  anon_sym_LBRACE = 48,
  anon_sym_RBRACE = 49,
  sym_identifier = 50,
  anon_sym_PLUS = 51,
  anon_sym_DASH = 52,
  anon_sym_STAR = 53,
  anon_sym_SLASH = 54,
  anon_sym_PERCENT = 55,
  anon_sym_mod = 56,
  anon_sym_PIPE_PIPE = 57,
  anon_sym_AMP_AMP = 58,
  anon_sym_EQ_TILDE = 59,
  anon_sym_EQ_EQ = 60,
  anon_sym_BANG_EQ = 61,
  anon_sym_in = 62,
  anon_sym_GT = 63,
  anon_sym_GT_EQ = 64,
  anon_sym_LT_EQ = 65,
  anon_sym_LT = 66,
  anon_sym_LT_LT = 67,
  anon_sym_GT_GT = 68,
  sym_source_file = 69,
  sym__statements = 70,
  sym__statement = 71,
  sym__definition = 72,
  sym__line_terminator = 73,
  sym_signature = 74,
  sym_parameter = 75,
  sym_flag = 76,
  sym_rest = 77,
  sym_default_parameter_assignment = 78,
  sym_function_definition = 79,
  sym_type = 80,
  sym_string = 81,
  sym_value_path = 82,
  sym_file_path = 83,
  sym_range = 84,
  sym_record_or_block = 85,
  sym_block = 86,
  sym_block_args = 87,
  sym__expression = 88,
  sym_table = 89,
  sym_array = 90,
  sym__cmd_expr = 91,
  sym_cmd_invocation = 92,
  sym_binary_expression = 93,
  aux_sym_source_file_repeat1 = 94,
  aux_sym__statements_repeat1 = 95,
  aux_sym_signature_repeat1 = 96,
  aux_sym_value_path_repeat1 = 97,
  aux_sym_block_args_repeat1 = 98,
  aux_sym_table_repeat1 = 99,
  aux_sym_array_repeat1 = 100,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_LBRACK] = "[",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RBRACK] = "]",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_CR_LF] = "\r\n",
  [anon_sym_PIPE] = "|",
  [anon_sym_SEMI] = ";",
  [anon_sym_COMMA] = ",",
  [anon_sym_QMARK] = "\?",
  [sym_flag_name] = "flag_name",
  [sym_flag_shorthand_name] = "flag_shorthand_name",
  [anon_sym_DOT_DOT_DOTrest] = "...rest",
  [anon_sym_AT] = "@",
  [anon_sym_export] = "export",
  [anon_sym_def] = "def",
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
  [anon_sym_DOLLAR] = "$",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token2] = "string_token2",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_string_token3] = "string_token3",
  [sym_number_literal] = "number_literal",
  [anon_sym_DOT] = ".",
  [aux_sym_file_path_token1] = "file_path_token1",
  [aux_sym_file_path_token2] = "file_path_token2",
  [sym_flag_arg] = "flag_arg",
  [anon_sym_DOT_DOT] = "..",
  [sym_word] = "word",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_identifier] = "identifier",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_mod] = "mod",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_EQ_TILDE] = "=~",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_in] = "in",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_GT_GT] = ">>",
  [sym_source_file] = "source_file",
  [sym__statements] = "_statements",
  [sym__statement] = "_statement",
  [sym__definition] = "_definition",
  [sym__line_terminator] = "_line_terminator",
  [sym_signature] = "signature",
  [sym_parameter] = "parameter",
  [sym_flag] = "flag",
  [sym_rest] = "rest",
  [sym_default_parameter_assignment] = "default_parameter_assignment",
  [sym_function_definition] = "function_definition",
  [sym_type] = "type",
  [sym_string] = "string",
  [sym_value_path] = "value_path",
  [sym_file_path] = "file_path",
  [sym_range] = "range",
  [sym_record_or_block] = "record_or_block",
  [sym_block] = "block",
  [sym_block_args] = "block_args",
  [sym__expression] = "_expression",
  [sym_table] = "table",
  [sym_array] = "array",
  [sym__cmd_expr] = "_cmd_expr",
  [sym_cmd_invocation] = "cmd_invocation",
  [sym_binary_expression] = "binary_expression",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_signature_repeat1] = "signature_repeat1",
  [aux_sym_value_path_repeat1] = "value_path_repeat1",
  [aux_sym_block_args_repeat1] = "block_args_repeat1",
  [aux_sym_table_repeat1] = "table_repeat1",
  [aux_sym_array_repeat1] = "array_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_CR_LF] = anon_sym_CR_LF,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [sym_flag_name] = sym_flag_name,
  [sym_flag_shorthand_name] = sym_flag_shorthand_name,
  [anon_sym_DOT_DOT_DOTrest] = anon_sym_DOT_DOT_DOTrest,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_export] = anon_sym_export,
  [anon_sym_def] = anon_sym_def,
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
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_string_token3] = aux_sym_string_token3,
  [sym_number_literal] = sym_number_literal,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym_file_path_token1] = aux_sym_file_path_token1,
  [aux_sym_file_path_token2] = aux_sym_file_path_token2,
  [sym_flag_arg] = sym_flag_arg,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [sym_word] = sym_word,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_identifier] = sym_identifier,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_mod] = anon_sym_mod,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_EQ_TILDE] = anon_sym_EQ_TILDE,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [sym_source_file] = sym_source_file,
  [sym__statements] = sym__statements,
  [sym__statement] = sym__statement,
  [sym__definition] = sym__definition,
  [sym__line_terminator] = sym__line_terminator,
  [sym_signature] = sym_signature,
  [sym_parameter] = sym_parameter,
  [sym_flag] = sym_flag,
  [sym_rest] = sym_rest,
  [sym_default_parameter_assignment] = sym_default_parameter_assignment,
  [sym_function_definition] = sym_function_definition,
  [sym_type] = sym_type,
  [sym_string] = sym_string,
  [sym_value_path] = sym_value_path,
  [sym_file_path] = sym_file_path,
  [sym_range] = sym_range,
  [sym_record_or_block] = sym_record_or_block,
  [sym_block] = sym_block,
  [sym_block_args] = sym_block_args,
  [sym__expression] = sym__expression,
  [sym_table] = sym_table,
  [sym_array] = sym_array,
  [sym__cmd_expr] = sym__cmd_expr,
  [sym_cmd_invocation] = sym_cmd_invocation,
  [sym_binary_expression] = sym_binary_expression,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_signature_repeat1] = aux_sym_signature_repeat1,
  [aux_sym_value_path_repeat1] = aux_sym_value_path_repeat1,
  [aux_sym_block_args_repeat1] = aux_sym_block_args_repeat1,
  [aux_sym_table_repeat1] = aux_sym_table_repeat1,
  [aux_sym_array_repeat1] = aux_sym_array_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
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
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [sym_flag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_flag_shorthand_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT_DOT_DOTrest] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_export] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
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
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_number_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_file_path_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_file_path_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_flag_arg] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mod] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statements] = {
    .visible = false,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym__line_terminator] = {
    .visible = false,
    .named = true,
  },
  [sym_signature] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_flag] = {
    .visible = true,
    .named = true,
  },
  [sym_rest] = {
    .visible = true,
    .named = true,
  },
  [sym_default_parameter_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_value_path] = {
    .visible = true,
    .named = true,
  },
  [sym_file_path] = {
    .visible = true,
    .named = true,
  },
  [sym_range] = {
    .visible = true,
    .named = true,
  },
  [sym_record_or_block] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_block_args] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_table] = {
    .visible = true,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym__cmd_expr] = {
    .visible = false,
    .named = true,
  },
  [sym_cmd_invocation] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__statements_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_signature_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_value_path_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_args_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_array_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_block_param = 1,
  field_custom_command_name = 2,
  field_from = 3,
  field_left = 4,
  field_operator = 5,
  field_right = 6,
  field_to = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_block_param] = "block_param",
  [field_custom_command_name] = "custom_command_name",
  [field_from] = "from",
  [field_left] = "left",
  [field_operator] = "operator",
  [field_right] = "right",
  [field_to] = "to",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [6] = {.index = 6, .length = 2},
  [7] = {.index = 8, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_custom_command_name, 1},
  [1] =
    {field_custom_command_name, 2},
  [2] =
    {field_block_param, 0},
  [3] =
    {field_block_param, 1, .inherited = true},
  [4] =
    {field_block_param, 0, .inherited = true},
    {field_block_param, 1, .inherited = true},
  [6] =
    {field_from, 0},
    {field_to, 2},
  [8] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
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
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
};

static inline bool sym_word_character_set_1(int32_t c) {
  return (c < '-'
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '\''
        ? (c >= '"' && c <= '$')
        : c <= ')')))
    : (c <= '.' || (c < '['
      ? (c < '@'
        ? c == ';'
        : c <= '@')
      : (c <= ']' || (c < '{'
        ? c == '`'
        : c <= '}')))));
}

static inline bool sym_word_character_set_2(int32_t c) {
  return (c < '"'
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || c == ' '))
    : (c <= '$' || (c < '@'
      ? (c < ';'
        ? (c >= '\'' && c <= ')')
        : c <= ';')
      : (c <= ']' || (c >= '`' && c <= '}')))));
}

static inline bool sym_word_character_set_3(int32_t c) {
  return (c < '-'
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '\''
        ? (c >= '"' && c <= '$')
        : c <= ')')))
    : (c <= '-' || (c < '['
      ? (c < '@'
        ? c == ';'
        : c <= '@')
      : (c <= ']' || (c < '{'
        ? c == '`'
        : c <= '}')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(102);
      if (lookahead == '!') ADVANCE(174);
      if (lookahead == '"') ADVANCE(141);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(253);
      if (lookahead == '&') ADVANCE(169);
      if (lookahead == '\'') ADVANCE(145);
      if (lookahead == '(') ADVANCE(108);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == '*') ADVANCE(251);
      if (lookahead == '+') ADVANCE(248);
      if (lookahead == ',') ADVANCE(117);
      if (lookahead == '-') ADVANCE(250);
      if (lookahead == '.') ADVANCE(158);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == ':') ADVANCE(112);
      if (lookahead == ';') ADVANCE(116);
      if (lookahead == '<') ADVANCE(266);
      if (lookahead == '=') ADVANCE(105);
      if (lookahead == '>') ADVANCE(263);
      if (lookahead == '?') ADVANCE(118);
      if (lookahead == '@') ADVANCE(123);
      if (lookahead == '[') ADVANCE(106);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == ']') ADVANCE(110);
      if (lookahead == '`') ADVANCE(149);
      if (lookahead == 'b') ADVANCE(197);
      if (lookahead == 'd') ADVANCE(176);
      if (lookahead == 'e') ADVANCE(222);
      if (lookahead == 'f') ADVANCE(195);
      if (lookahead == 'i') ADVANCE(205);
      if (lookahead == 'l') ADVANCE(190);
      if (lookahead == 'm') ADVANCE(210);
      if (lookahead == 'n') ADVANCE(233);
      if (lookahead == 'r') ADVANCE(177);
      if (lookahead == 's') ADVANCE(232);
      if (lookahead == 't') ADVANCE(175);
      if (lookahead == '{') ADVANCE(238);
      if (lookahead == '|') ADVANCE(115);
      if (lookahead == '}') ADVANCE(240);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(100)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(237);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(113);
      if (lookahead == '\r') ADVANCE(114);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == ';') ADVANCE(116);
      if (lookahead == '|') ADVANCE(115);
      if (lookahead == '}') ADVANCE(240);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '%') ADVANCE(253);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == '*') ADVANCE(251);
      if (lookahead == '+') ADVANCE(248);
      if (lookahead == ',') ADVANCE(117);
      if (lookahead == '-') ADVANCE(250);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == '<') ADVANCE(266);
      if (lookahead == '=') ADVANCE(105);
      if (lookahead == '>') ADVANCE(263);
      if (lookahead == ']') ADVANCE(110);
      if (lookahead == 'i') ADVANCE(245);
      if (lookahead == 'm') ADVANCE(246);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(141);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '\'') ADVANCE(145);
      if (lookahead == '(') ADVANCE(108);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == ',') ADVANCE(117);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '.') ADVANCE(159);
      if (lookahead == ':') ADVANCE(112);
      if (lookahead == ';') ADVANCE(116);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '?') ADVANCE(118);
      if (lookahead == '@') ADVANCE(123);
      if (lookahead == '[') ADVANCE(106);
      if (lookahead == ']') ADVANCE(110);
      if (lookahead == '`') ADVANCE(149);
      if (lookahead == '|') ADVANCE(115);
      if (lookahead == '}') ADVANCE(240);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(155);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(141);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '\'') ADVANCE(145);
      if (lookahead == '(') ADVANCE(108);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == ',') ADVANCE(117);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == ':') ADVANCE(112);
      if (lookahead == ';') ADVANCE(116);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '?') ADVANCE(118);
      if (lookahead == '@') ADVANCE(123);
      if (lookahead == '[') ADVANCE(106);
      if (lookahead == ']') ADVANCE(110);
      if (lookahead == '`') ADVANCE(149);
      if (lookahead == '|') ADVANCE(115);
      if (lookahead == '}') ADVANCE(240);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(155);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(142);
      if (lookahead == '$') ADVANCE(140);
      if (lookahead == '\'') ADVANCE(146);
      if (lookahead == '(') ADVANCE(109);
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '.') ADVANCE(14);
      if (lookahead == '[') ADVANCE(107);
      if (lookahead == '\\') ADVANCE(18);
      if (lookahead == '`') ADVANCE(150);
      if (lookahead == '{') ADVANCE(239);
      if (lookahead == '~') ADVANCE(170);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead == '#' ||
          lookahead == ')' ||
          lookahead == ';' ||
          lookahead == '@' ||
          lookahead == ']' ||
          lookahead == '|' ||
          lookahead == '}') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(153);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      if (lookahead != 0) ADVANCE(173);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(142);
      if (lookahead == '$') ADVANCE(140);
      if (lookahead == '\'') ADVANCE(146);
      if (lookahead == '(') ADVANCE(109);
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '.') ADVANCE(23);
      if (lookahead == '[') ADVANCE(107);
      if (lookahead == '\\') ADVANCE(18);
      if (lookahead == '`') ADVANCE(150);
      if (lookahead == '{') ADVANCE(239);
      if (lookahead == '~') ADVANCE(170);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead == '#' ||
          lookahead == ')' ||
          lookahead == ';' ||
          lookahead == '@' ||
          lookahead == ']' ||
          lookahead == '|' ||
          lookahead == '}') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(153);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(241);
      if (lookahead != 0) ADVANCE(173);
      END_STATE();
    case 7:
      if (lookahead == '&') ADVANCE(257);
      END_STATE();
    case 8:
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == ',') ADVANCE(117);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == ']') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(96);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(21);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '~') ADVANCE(22);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(166);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(97);
      if (lookahead == 'b') ADVANCE(50);
      if (lookahead == 'd') ADVANCE(28);
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == 'f') ADVANCE(48);
      if (lookahead == 'i') ADVANCE(63);
      if (lookahead == 'n') ADVANCE(90);
      if (lookahead == 'r') ADVANCE(29);
      if (lookahead == 's') ADVANCE(89);
      if (lookahead == 't') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      END_STATE();
    case 12:
      if (lookahead == '.') ADVANCE(168);
      END_STATE();
    case 13:
      if (lookahead == '.') ADVANCE(72);
      END_STATE();
    case 14:
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(98);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(22);
      END_STATE();
    case 15:
      if (lookahead == '.') ADVANCE(160);
      END_STATE();
    case 16:
      if (lookahead == '.') ADVANCE(162);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 17:
      if (lookahead == '.') ADVANCE(162);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 18:
      if (lookahead == '.') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(237);
      END_STATE();
    case 19:
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 20:
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 21:
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (('-' <= lookahead && lookahead <= '9') ||
          lookahead == '~') ADVANCE(22);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(166);
      END_STATE();
    case 22:
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '.') ADVANCE(161);
      if (lookahead == '/') ADVANCE(164);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(160);
      END_STATE();
    case 24:
      if (lookahead == '.') ADVANCE(13);
      END_STATE();
    case 25:
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 26:
      if (lookahead == '=') ADVANCE(260);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(33);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(88);
      if (lookahead == 'u') ADVANCE(78);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(87);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(76);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 33:
      if (lookahead == 'b') ADVANCE(55);
      END_STATE();
    case 34:
      if (lookahead == 'b') ADVANCE(44);
      END_STATE();
    case 35:
      if (lookahead == 'c') ADVANCE(53);
      END_STATE();
    case 36:
      if (lookahead == 'd') ADVANCE(254);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(128);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(136);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(134);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(74);
      END_STATE();
    case 45:
      if (lookahead == 'f') ADVANCE(125);
      END_STATE();
    case 46:
      if (lookahead == 'g') ADVANCE(130);
      END_STATE();
    case 47:
      if (lookahead == 'g') ADVANCE(39);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(56);
      if (lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(62);
      if (lookahead == 'l') ADVANCE(65);
      if (lookahead == 'o') ADVANCE(67);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(61);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 53:
      if (lookahead == 'k') ADVANCE(131);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(129);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(43);
      END_STATE();
    case 57:
      if (lookahead == 'm') ADVANCE(34);
      END_STATE();
    case 58:
      if (lookahead == 'n') ADVANCE(261);
      END_STATE();
    case 59:
      if (lookahead == 'n') ADVANCE(132);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 61:
      if (lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(86);
      END_STATE();
    case 64:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 65:
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 66:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 67:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 68:
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 69:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 71:
      if (lookahead == 'p') ADVANCE(66);
      END_STATE();
    case 72:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 73:
      if (lookahead == 'r') ADVANCE(137);
      END_STATE();
    case 74:
      if (lookahead == 'r') ADVANCE(135);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(92);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(80);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(69);
      END_STATE();
    case 81:
      if (lookahead == 's') ADVANCE(85);
      END_STATE();
    case 82:
      if (lookahead == 's') ADVANCE(49);
      END_STATE();
    case 83:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 84:
      if (lookahead == 't') ADVANCE(124);
      END_STATE();
    case 85:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 90:
      if (lookahead == 'u') ADVANCE(57);
      END_STATE();
    case 91:
      if (lookahead == 'x') ADVANCE(71);
      END_STATE();
    case 92:
      if (lookahead == 'y') ADVANCE(138);
      END_STATE();
    case 93:
      if (lookahead == 'z') ADVANCE(41);
      END_STATE();
    case 94:
      if (lookahead == '|') ADVANCE(256);
      END_STATE();
    case 95:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(157);
      END_STATE();
    case 96:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 97:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(121);
      END_STATE();
    case 98:
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(22);
      END_STATE();
    case 99:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(237);
      END_STATE();
    case 100:
      if (eof) ADVANCE(102);
      if (lookahead == '!') ADVANCE(174);
      if (lookahead == '"') ADVANCE(141);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(253);
      if (lookahead == '&') ADVANCE(169);
      if (lookahead == '\'') ADVANCE(145);
      if (lookahead == '(') ADVANCE(108);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == '*') ADVANCE(251);
      if (lookahead == '+') ADVANCE(248);
      if (lookahead == ',') ADVANCE(117);
      if (lookahead == '-') ADVANCE(250);
      if (lookahead == '.') ADVANCE(12);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == ':') ADVANCE(112);
      if (lookahead == ';') ADVANCE(116);
      if (lookahead == '<') ADVANCE(266);
      if (lookahead == '=') ADVANCE(105);
      if (lookahead == '>') ADVANCE(263);
      if (lookahead == '?') ADVANCE(118);
      if (lookahead == '@') ADVANCE(123);
      if (lookahead == '[') ADVANCE(106);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == ']') ADVANCE(110);
      if (lookahead == '`') ADVANCE(149);
      if (lookahead == 'b') ADVANCE(197);
      if (lookahead == 'd') ADVANCE(176);
      if (lookahead == 'e') ADVANCE(222);
      if (lookahead == 'f') ADVANCE(195);
      if (lookahead == 'i') ADVANCE(205);
      if (lookahead == 'l') ADVANCE(190);
      if (lookahead == 'm') ADVANCE(210);
      if (lookahead == 'n') ADVANCE(233);
      if (lookahead == 'r') ADVANCE(177);
      if (lookahead == 's') ADVANCE(232);
      if (lookahead == 't') ADVANCE(175);
      if (lookahead == '{') ADVANCE(238);
      if (lookahead == '|') ADVANCE(115);
      if (lookahead == '}') ADVANCE(240);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(100)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(237);
      END_STATE();
    case 101:
      if (eof) ADVANCE(102);
      if (lookahead == '!') ADVANCE(26);
      if (lookahead == '%') ADVANCE(253);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '*') ADVANCE(251);
      if (lookahead == '+') ADVANCE(248);
      if (lookahead == '-') ADVANCE(249);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == '<') ADVANCE(266);
      if (lookahead == '=') ADVANCE(105);
      if (lookahead == '>') ADVANCE(263);
      if (lookahead == 'd') ADVANCE(42);
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead == 'i') ADVANCE(58);
      if (lookahead == 'm') ADVANCE(64);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(101)
      END_STATE();
    case 102:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(259);
      if (lookahead == '~') ADVANCE(258);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(113);
      if (lookahead == '\r') ADVANCE(114);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(113);
      if (lookahead == '\r') ADVANCE(114);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(120);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_flag_shorthand_name);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_duration);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_date);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_filesize);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_error);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_binary);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(144);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(148);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(152);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(152);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '/') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(154);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(171);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '.') ADVANCE(19);
      if (lookahead == '/') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(154);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(171);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(168);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(13);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(162);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(22);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(22);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_file_path_token2);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(165);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_flag_arg);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '~') ADVANCE(22);
      if (('-' <= lookahead && lookahead <= '9')) ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(166);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_flag_arg);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '~') ADVANCE(22);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(167);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(72);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(257);
      if (lookahead == '\\') ADVANCE(99);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(236);
      if (lookahead == '\\') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(171);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(237);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '-') ADVANCE(22);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(236);
      if (lookahead == '\\') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(171);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(237);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(160);
      if (lookahead == '\\') ADVANCE(99);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(237);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(15);
      if (lookahead == '\\') ADVANCE(99);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(237);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(260);
      if (lookahead == '\\') ADVANCE(99);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(182);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(230);
      if (lookahead == 'e') ADVANCE(192);
      if (lookahead == 'u') ADVANCE(223);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(206);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(231);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(219);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'a') ADVANCE(228);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'b') ADVANCE(191);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'b') ADVANCE(203);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'c') ADVANCE(200);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'd') ADVANCE(254);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(133);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(226);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(128);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(136);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(134);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(227);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'e') ADVANCE(221);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'f') ADVANCE(125);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'g') ADVANCE(130);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'g') ADVANCE(187);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(202);
      if (lookahead == 'l') ADVANCE(216);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(235);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(209);
      if (lookahead == 'l') ADVANCE(211);
      if (lookahead == 'o') ADVANCE(212);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(208);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'i') ADVANCE(213);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'k') ADVANCE(131);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'l') ADVANCE(129);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'l') ADVANCE(186);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'l') ADVANCE(188);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'm') ADVANCE(181);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(261);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(194);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(132);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(193);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(179);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(184);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(183);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(201);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(207);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(220);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(225);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(180);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'p') ADVANCE(215);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(198);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(234);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(137);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(135);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(224);
      if (lookahead == 'x') ADVANCE(217);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(178);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(214);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(229);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 's') ADVANCE(196);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 't') ADVANCE(103);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 't') ADVANCE(127);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 't') ADVANCE(124);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 't') ADVANCE(185);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 't') ADVANCE(199);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 't') ADVANCE(218);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'u') ADVANCE(204);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'y') ADVANCE(138);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == 'z') ADVANCE(189);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (lookahead == '-' ||
          lookahead == '.') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(171);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(237);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(99);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(237);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead == '.') ADVANCE(15);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(243);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '/') ADVANCE(236);
      if (lookahead == '~') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(243);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(236);
      if (lookahead == '~') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == '~') ADVANCE(22);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(243);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(255);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(262);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(244);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(96);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_mod);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_mod);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_EQ_TILDE);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(247);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(264);
      if (lookahead == '>') ADVANCE(268);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(267);
      if (lookahead == '=') ADVANCE(265);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 101},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 101},
  [5] = {.lex_state = 11},
  [6] = {.lex_state = 11},
  [7] = {.lex_state = 11},
  [8] = {.lex_state = 11},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 3},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 3},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 3},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 3},
  [35] = {.lex_state = 3},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 3},
  [38] = {.lex_state = 3},
  [39] = {.lex_state = 3},
  [40] = {.lex_state = 3},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 3},
  [43] = {.lex_state = 3},
  [44] = {.lex_state = 3},
  [45] = {.lex_state = 3},
  [46] = {.lex_state = 3},
  [47] = {.lex_state = 3},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 3},
  [50] = {.lex_state = 3},
  [51] = {.lex_state = 3},
  [52] = {.lex_state = 3},
  [53] = {.lex_state = 3},
  [54] = {.lex_state = 3},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 3},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 3},
  [62] = {.lex_state = 3},
  [63] = {.lex_state = 3},
  [64] = {.lex_state = 101},
  [65] = {.lex_state = 3},
  [66] = {.lex_state = 101},
  [67] = {.lex_state = 3},
  [68] = {.lex_state = 3},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 3},
  [71] = {.lex_state = 3},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 3},
  [75] = {.lex_state = 3},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 3},
  [82] = {.lex_state = 101},
  [83] = {.lex_state = 3},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 101},
  [88] = {.lex_state = 3},
  [89] = {.lex_state = 3},
  [90] = {.lex_state = 101},
  [91] = {.lex_state = 101},
  [92] = {.lex_state = 3},
  [93] = {.lex_state = 101},
  [94] = {.lex_state = 3},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 3},
  [97] = {.lex_state = 3},
  [98] = {.lex_state = 3},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 3},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 3},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 101},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 3},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 11},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 3},
  [129] = {.lex_state = 151},
  [130] = {.lex_state = 147},
  [131] = {.lex_state = 143},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 151},
  [135] = {.lex_state = 147},
  [136] = {.lex_state = 143},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [sym_flag_name] = ACTIONS(1),
    [anon_sym_DOT_DOT_DOTrest] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_export] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
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
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_number_literal] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_mod] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_EQ_TILDE] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(138),
    [sym__definition] = STATE(64),
    [sym_function_definition] = STATE(64),
    [aux_sym_source_file_repeat1] = STATE(64),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_export] = ACTIONS(5),
    [anon_sym_def] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(13), 1,
      sym_identifier,
    ACTIONS(11), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(9), 6,
      anon_sym_EQ,
      anon_sym_DASH,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(15), 13,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [34] = 13,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DOLLAR,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      sym_number_literal,
    ACTIONS(35), 1,
      anon_sym_LBRACE,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(4), 1,
      sym__expression,
    ACTIONS(31), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(33), 2,
      sym_flag_arg,
      sym_word,
    STATE(63), 10,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym_range,
      sym_record_or_block,
      sym_table,
      sym_array,
      sym__cmd_expr,
      sym_cmd_invocation,
      sym_binary_expression,
  [85] = 9,
    ACTIONS(39), 1,
      anon_sym_EQ,
    ACTIONS(45), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(47), 1,
      anon_sym_AMP_AMP,
    ACTIONS(41), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(51), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(53), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(55), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(43), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(49), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [123] = 2,
    STATE(12), 1,
      sym_type,
    ACTIONS(57), 13,
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
  [142] = 2,
    STATE(16), 1,
      sym_type,
    ACTIONS(57), 13,
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
  [161] = 2,
    STATE(18), 1,
      sym_type,
    ACTIONS(57), 13,
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
  [180] = 2,
    STATE(67), 1,
      sym_type,
    ACTIONS(57), 13,
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
  [199] = 6,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(63), 1,
      anon_sym_COLON,
    ACTIONS(65), 1,
      anon_sym_QMARK,
    ACTIONS(67), 1,
      anon_sym_AT,
    STATE(45), 1,
      sym_default_parameter_assignment,
    ACTIONS(61), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [223] = 6,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    ACTIONS(69), 1,
      anon_sym_LPAREN,
    ACTIONS(73), 1,
      anon_sym_COLON,
    STATE(41), 1,
      sym_default_parameter_assignment,
    ACTIONS(71), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [247] = 5,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    ACTIONS(77), 1,
      anon_sym_COLON,
    STATE(38), 1,
      sym_default_parameter_assignment,
    ACTIONS(75), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [268] = 5,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    ACTIONS(81), 1,
      anon_sym_QMARK,
    STATE(46), 1,
      sym_default_parameter_assignment,
    ACTIONS(79), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [289] = 4,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    STATE(61), 1,
      sym_default_parameter_assignment,
    ACTIONS(83), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [307] = 6,
    ACTIONS(87), 1,
      sym_flag_name,
    ACTIONS(90), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(93), 1,
      sym_identifier,
    STATE(14), 1,
      aux_sym_signature_repeat1,
    ACTIONS(85), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(43), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [329] = 1,
    ACTIONS(96), 9,
      anon_sym_EQ,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_QMARK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      anon_sym_AT,
      sym_identifier,
  [341] = 4,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    STATE(42), 1,
      sym_default_parameter_assignment,
    ACTIONS(98), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [359] = 6,
    ACTIONS(102), 1,
      sym_flag_name,
    ACTIONS(104), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(106), 1,
      sym_identifier,
    STATE(14), 1,
      aux_sym_signature_repeat1,
    ACTIONS(100), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(43), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [381] = 4,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    STATE(54), 1,
      sym_default_parameter_assignment,
    ACTIONS(108), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [399] = 4,
    ACTIONS(59), 1,
      anon_sym_EQ,
    ACTIONS(67), 1,
      anon_sym_AT,
    STATE(69), 1,
      sym_default_parameter_assignment,
    ACTIONS(110), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [417] = 6,
    ACTIONS(102), 1,
      sym_flag_name,
    ACTIONS(104), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(106), 1,
      sym_identifier,
    STATE(17), 1,
      aux_sym_signature_repeat1,
    ACTIONS(112), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(43), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [439] = 3,
    ACTIONS(116), 1,
      anon_sym_DOT,
    STATE(28), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(114), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [454] = 1,
    ACTIONS(118), 8,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [465] = 3,
    ACTIONS(116), 1,
      anon_sym_DOT,
    STATE(24), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(120), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [480] = 3,
    ACTIONS(116), 1,
      anon_sym_DOT,
    STATE(28), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(122), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [495] = 1,
    ACTIONS(124), 8,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [506] = 3,
    ACTIONS(116), 1,
      anon_sym_DOT,
    STATE(21), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(126), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [521] = 1,
    ACTIONS(128), 8,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [532] = 3,
    ACTIONS(132), 1,
      anon_sym_DOT,
    STATE(28), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(130), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [547] = 3,
    STATE(95), 1,
      sym__line_terminator,
    ACTIONS(135), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(137), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_PIPE,
      anon_sym_SEMI,
  [562] = 7,
    ACTIONS(139), 1,
      anon_sym_PIPE,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    ACTIONS(143), 1,
      sym_identifier,
    STATE(53), 1,
      sym_block_args,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(124), 1,
      sym__statements,
    STATE(29), 2,
      sym__statement,
      sym__expression,
  [585] = 7,
    ACTIONS(139), 1,
      anon_sym_PIPE,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(145), 1,
      anon_sym_RBRACE,
    STATE(56), 1,
      sym_block_args,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(132), 1,
      sym__statements,
    STATE(29), 2,
      sym__statement,
      sym__expression,
  [608] = 3,
    STATE(94), 1,
      sym__line_terminator,
    ACTIONS(147), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(149), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_PIPE,
      anon_sym_SEMI,
  [623] = 1,
    ACTIONS(151), 8,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [634] = 2,
    ACTIONS(153), 1,
      anon_sym_DOT,
    ACTIONS(130), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [646] = 2,
    ACTIONS(157), 1,
      anon_sym_COLON,
    ACTIONS(155), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [658] = 2,
    ACTIONS(159), 1,
      anon_sym_DOT_DOT,
    ACTIONS(11), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [670] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [679] = 1,
    ACTIONS(163), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [688] = 1,
    ACTIONS(165), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [697] = 1,
    ACTIONS(167), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [706] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [715] = 1,
    ACTIONS(171), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [724] = 2,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(173), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [735] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [744] = 1,
    ACTIONS(110), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [753] = 1,
    ACTIONS(83), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [762] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [771] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [780] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [789] = 6,
    ACTIONS(177), 1,
      anon_sym_DOLLAR,
    ACTIONS(179), 1,
      anon_sym_DQUOTE,
    ACTIONS(181), 1,
      anon_sym_SQUOTE,
    ACTIONS(183), 1,
      anon_sym_BQUOTE,
    ACTIONS(185), 1,
      sym_identifier,
    STATE(85), 1,
      sym_string,
  [808] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [817] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [826] = 5,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(187), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(125), 1,
      sym__statements,
    STATE(29), 2,
      sym__statement,
      sym__expression,
  [843] = 1,
    ACTIONS(75), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [852] = 6,
    ACTIONS(189), 1,
      anon_sym_LBRACK,
    ACTIONS(191), 1,
      anon_sym_RBRACK,
    ACTIONS(193), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_array_repeat1,
    STATE(92), 1,
      sym__expression,
    STATE(123), 1,
      sym_array,
  [871] = 5,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(195), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(117), 1,
      sym__statements,
    STATE(29), 2,
      sym__statement,
      sym__expression,
  [888] = 1,
    ACTIONS(197), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [897] = 2,
    STATE(128), 1,
      sym__line_terminator,
    ACTIONS(199), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_PIPE,
      anon_sym_SEMI,
  [908] = 1,
    ACTIONS(201), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [917] = 1,
    ACTIONS(161), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [926] = 1,
    ACTIONS(203), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [935] = 1,
    ACTIONS(205), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [944] = 1,
    ACTIONS(207), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [953] = 4,
    ACTIONS(5), 1,
      anon_sym_export,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(209), 1,
      ts_builtin_sym_end,
    STATE(66), 3,
      sym__definition,
      sym_function_definition,
      aux_sym_source_file_repeat1,
  [968] = 6,
    ACTIONS(177), 1,
      anon_sym_DOLLAR,
    ACTIONS(179), 1,
      anon_sym_DQUOTE,
    ACTIONS(181), 1,
      anon_sym_SQUOTE,
    ACTIONS(183), 1,
      anon_sym_BQUOTE,
    ACTIONS(211), 1,
      sym_identifier,
    STATE(86), 1,
      sym_string,
  [987] = 4,
    ACTIONS(213), 1,
      ts_builtin_sym_end,
    ACTIONS(215), 1,
      anon_sym_export,
    ACTIONS(218), 1,
      anon_sym_def,
    STATE(66), 3,
      sym__definition,
      sym_function_definition,
      aux_sym_source_file_repeat1,
  [1002] = 1,
    ACTIONS(221), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1011] = 1,
    ACTIONS(223), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1020] = 1,
    ACTIONS(79), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1029] = 1,
    ACTIONS(225), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1038] = 4,
    ACTIONS(227), 1,
      anon_sym_DQUOTE,
    ACTIONS(229), 1,
      anon_sym_SQUOTE,
    ACTIONS(231), 1,
      anon_sym_BQUOTE,
    ACTIONS(233), 2,
      sym_number_literal,
      sym_identifier,
  [1052] = 4,
    ACTIONS(143), 1,
      sym_identifier,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(114), 1,
      sym__statements,
    STATE(29), 2,
      sym__statement,
      sym__expression,
  [1066] = 1,
    ACTIONS(85), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1074] = 3,
    ACTIONS(235), 1,
      sym_identifier,
    STATE(74), 1,
      aux_sym__statements_repeat1,
    STATE(58), 2,
      sym__statement,
      sym__expression,
  [1085] = 4,
    ACTIONS(191), 1,
      anon_sym_RBRACK,
    ACTIONS(193), 1,
      sym_identifier,
    STATE(77), 1,
      aux_sym_array_repeat1,
    STATE(92), 1,
      sym__expression,
  [1098] = 3,
    ACTIONS(189), 1,
      anon_sym_LBRACK,
    ACTIONS(238), 1,
      anon_sym_RBRACK,
    STATE(79), 2,
      sym_array,
      aux_sym_table_repeat1,
  [1109] = 4,
    ACTIONS(193), 1,
      sym_identifier,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
    STATE(81), 1,
      aux_sym_array_repeat1,
    STATE(92), 1,
      sym__expression,
  [1122] = 3,
    ACTIONS(189), 1,
      anon_sym_LBRACK,
    ACTIONS(242), 1,
      anon_sym_RBRACK,
    STATE(76), 2,
      sym_array,
      aux_sym_table_repeat1,
  [1133] = 3,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    ACTIONS(247), 1,
      anon_sym_RBRACK,
    STATE(79), 2,
      sym_array,
      aux_sym_table_repeat1,
  [1144] = 3,
    ACTIONS(249), 1,
      sym_identifier,
    STATE(74), 1,
      aux_sym__statements_repeat1,
    STATE(32), 2,
      sym__statement,
      sym__expression,
  [1155] = 4,
    ACTIONS(251), 1,
      anon_sym_RBRACK,
    ACTIONS(253), 1,
      sym_identifier,
    STATE(81), 1,
      aux_sym_array_repeat1,
    STATE(92), 1,
      sym__expression,
  [1168] = 1,
    ACTIONS(256), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1174] = 3,
    ACTIONS(258), 1,
      anon_sym_PIPE,
    ACTIONS(260), 1,
      sym_identifier,
    STATE(96), 1,
      aux_sym_block_args_repeat1,
  [1184] = 3,
    ACTIONS(227), 1,
      anon_sym_DQUOTE,
    ACTIONS(229), 1,
      anon_sym_SQUOTE,
    ACTIONS(231), 1,
      anon_sym_BQUOTE,
  [1194] = 2,
    STATE(109), 1,
      sym_signature,
    ACTIONS(262), 2,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1202] = 2,
    STATE(110), 1,
      sym_signature,
    ACTIONS(262), 2,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1210] = 1,
    ACTIONS(264), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1216] = 2,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(266), 2,
      anon_sym_PIPE,
      sym_identifier,
  [1224] = 3,
    ACTIONS(260), 1,
      sym_identifier,
    ACTIONS(270), 1,
      anon_sym_PIPE,
    STATE(83), 1,
      aux_sym_block_args_repeat1,
  [1234] = 1,
    ACTIONS(272), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1240] = 1,
    ACTIONS(274), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1246] = 2,
    ACTIONS(278), 1,
      anon_sym_COMMA,
    ACTIONS(276), 2,
      anon_sym_RBRACK,
      sym_identifier,
  [1254] = 1,
    ACTIONS(280), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1260] = 2,
    ACTIONS(284), 1,
      sym_identifier,
    ACTIONS(282), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1268] = 2,
    ACTIONS(284), 1,
      sym_identifier,
    ACTIONS(286), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1276] = 3,
    ACTIONS(288), 1,
      anon_sym_PIPE,
    ACTIONS(290), 1,
      sym_identifier,
    STATE(96), 1,
      aux_sym_block_args_repeat1,
  [1286] = 1,
    ACTIONS(293), 2,
      sym_number_literal,
      sym_identifier,
  [1291] = 2,
    ACTIONS(295), 1,
      sym_identifier,
    STATE(60), 1,
      sym__expression,
  [1298] = 2,
    ACTIONS(297), 1,
      sym_identifier,
    STATE(48), 1,
      sym__expression,
  [1305] = 2,
    ACTIONS(299), 1,
      sym_identifier,
    STATE(49), 1,
      sym__expression,
  [1312] = 2,
    ACTIONS(301), 1,
      sym_identifier,
    STATE(51), 1,
      sym__expression,
  [1319] = 2,
    ACTIONS(303), 1,
      sym_identifier,
    STATE(52), 1,
      sym__expression,
  [1326] = 2,
    ACTIONS(305), 1,
      sym_identifier,
    STATE(37), 1,
      sym__expression,
  [1333] = 1,
    ACTIONS(307), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1338] = 1,
    ACTIONS(309), 2,
      anon_sym_PIPE,
      sym_identifier,
  [1343] = 1,
    ACTIONS(311), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1348] = 1,
    ACTIONS(251), 2,
      anon_sym_RBRACK,
      sym_identifier,
  [1353] = 2,
    ACTIONS(313), 1,
      sym_identifier,
    STATE(47), 1,
      sym__expression,
  [1360] = 2,
    ACTIONS(315), 1,
      anon_sym_LBRACE,
    STATE(82), 1,
      sym_block,
  [1367] = 2,
    ACTIONS(315), 1,
      anon_sym_LBRACE,
    STATE(87), 1,
      sym_block,
  [1374] = 2,
    ACTIONS(317), 1,
      sym_identifier,
    STATE(44), 1,
      sym__expression,
  [1381] = 1,
    ACTIONS(319), 1,
      anon_sym_def,
  [1385] = 1,
    ACTIONS(321), 1,
      anon_sym_BQUOTE,
  [1389] = 1,
    ACTIONS(323), 1,
      anon_sym_RPAREN,
  [1393] = 1,
    ACTIONS(325), 1,
      anon_sym_LBRACE,
  [1397] = 1,
    ACTIONS(327), 1,
      sym_identifier,
  [1401] = 1,
    ACTIONS(329), 1,
      anon_sym_RBRACE,
  [1405] = 1,
    ACTIONS(331), 1,
      sym_flag_shorthand_name,
  [1409] = 1,
    ACTIONS(333), 1,
      anon_sym_LBRACE,
  [1413] = 1,
    ACTIONS(335), 1,
      anon_sym_BQUOTE,
  [1417] = 1,
    ACTIONS(335), 1,
      anon_sym_SQUOTE,
  [1421] = 1,
    ACTIONS(335), 1,
      anon_sym_DQUOTE,
  [1425] = 1,
    ACTIONS(337), 1,
      anon_sym_SEMI,
  [1429] = 1,
    ACTIONS(187), 1,
      anon_sym_RBRACE,
  [1433] = 1,
    ACTIONS(339), 1,
      anon_sym_RBRACE,
  [1437] = 1,
    ACTIONS(321), 1,
      anon_sym_SQUOTE,
  [1441] = 1,
    ACTIONS(321), 1,
      anon_sym_DQUOTE,
  [1445] = 1,
    ACTIONS(284), 1,
      sym_identifier,
  [1449] = 1,
    ACTIONS(341), 1,
      aux_sym_string_token3,
  [1453] = 1,
    ACTIONS(343), 1,
      aux_sym_string_token2,
  [1457] = 1,
    ACTIONS(345), 1,
      aux_sym_string_token1,
  [1461] = 1,
    ACTIONS(195), 1,
      anon_sym_RBRACE,
  [1465] = 1,
    ACTIONS(347), 1,
      anon_sym_RPAREN,
  [1469] = 1,
    ACTIONS(349), 1,
      aux_sym_string_token3,
  [1473] = 1,
    ACTIONS(351), 1,
      aux_sym_string_token2,
  [1477] = 1,
    ACTIONS(353), 1,
      aux_sym_string_token1,
  [1481] = 1,
    ACTIONS(355), 1,
      sym_number_literal,
  [1485] = 1,
    ACTIONS(357), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 34,
  [SMALL_STATE(4)] = 85,
  [SMALL_STATE(5)] = 123,
  [SMALL_STATE(6)] = 142,
  [SMALL_STATE(7)] = 161,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 199,
  [SMALL_STATE(10)] = 223,
  [SMALL_STATE(11)] = 247,
  [SMALL_STATE(12)] = 268,
  [SMALL_STATE(13)] = 289,
  [SMALL_STATE(14)] = 307,
  [SMALL_STATE(15)] = 329,
  [SMALL_STATE(16)] = 341,
  [SMALL_STATE(17)] = 359,
  [SMALL_STATE(18)] = 381,
  [SMALL_STATE(19)] = 399,
  [SMALL_STATE(20)] = 417,
  [SMALL_STATE(21)] = 439,
  [SMALL_STATE(22)] = 454,
  [SMALL_STATE(23)] = 465,
  [SMALL_STATE(24)] = 480,
  [SMALL_STATE(25)] = 495,
  [SMALL_STATE(26)] = 506,
  [SMALL_STATE(27)] = 521,
  [SMALL_STATE(28)] = 532,
  [SMALL_STATE(29)] = 547,
  [SMALL_STATE(30)] = 562,
  [SMALL_STATE(31)] = 585,
  [SMALL_STATE(32)] = 608,
  [SMALL_STATE(33)] = 623,
  [SMALL_STATE(34)] = 634,
  [SMALL_STATE(35)] = 646,
  [SMALL_STATE(36)] = 658,
  [SMALL_STATE(37)] = 670,
  [SMALL_STATE(38)] = 679,
  [SMALL_STATE(39)] = 688,
  [SMALL_STATE(40)] = 697,
  [SMALL_STATE(41)] = 706,
  [SMALL_STATE(42)] = 715,
  [SMALL_STATE(43)] = 724,
  [SMALL_STATE(44)] = 735,
  [SMALL_STATE(45)] = 744,
  [SMALL_STATE(46)] = 753,
  [SMALL_STATE(47)] = 762,
  [SMALL_STATE(48)] = 771,
  [SMALL_STATE(49)] = 780,
  [SMALL_STATE(50)] = 789,
  [SMALL_STATE(51)] = 808,
  [SMALL_STATE(52)] = 817,
  [SMALL_STATE(53)] = 826,
  [SMALL_STATE(54)] = 843,
  [SMALL_STATE(55)] = 852,
  [SMALL_STATE(56)] = 871,
  [SMALL_STATE(57)] = 888,
  [SMALL_STATE(58)] = 897,
  [SMALL_STATE(59)] = 908,
  [SMALL_STATE(60)] = 917,
  [SMALL_STATE(61)] = 926,
  [SMALL_STATE(62)] = 935,
  [SMALL_STATE(63)] = 944,
  [SMALL_STATE(64)] = 953,
  [SMALL_STATE(65)] = 968,
  [SMALL_STATE(66)] = 987,
  [SMALL_STATE(67)] = 1002,
  [SMALL_STATE(68)] = 1011,
  [SMALL_STATE(69)] = 1020,
  [SMALL_STATE(70)] = 1029,
  [SMALL_STATE(71)] = 1038,
  [SMALL_STATE(72)] = 1052,
  [SMALL_STATE(73)] = 1066,
  [SMALL_STATE(74)] = 1074,
  [SMALL_STATE(75)] = 1085,
  [SMALL_STATE(76)] = 1098,
  [SMALL_STATE(77)] = 1109,
  [SMALL_STATE(78)] = 1122,
  [SMALL_STATE(79)] = 1133,
  [SMALL_STATE(80)] = 1144,
  [SMALL_STATE(81)] = 1155,
  [SMALL_STATE(82)] = 1168,
  [SMALL_STATE(83)] = 1174,
  [SMALL_STATE(84)] = 1184,
  [SMALL_STATE(85)] = 1194,
  [SMALL_STATE(86)] = 1202,
  [SMALL_STATE(87)] = 1210,
  [SMALL_STATE(88)] = 1216,
  [SMALL_STATE(89)] = 1224,
  [SMALL_STATE(90)] = 1234,
  [SMALL_STATE(91)] = 1240,
  [SMALL_STATE(92)] = 1246,
  [SMALL_STATE(93)] = 1254,
  [SMALL_STATE(94)] = 1260,
  [SMALL_STATE(95)] = 1268,
  [SMALL_STATE(96)] = 1276,
  [SMALL_STATE(97)] = 1286,
  [SMALL_STATE(98)] = 1291,
  [SMALL_STATE(99)] = 1298,
  [SMALL_STATE(100)] = 1305,
  [SMALL_STATE(101)] = 1312,
  [SMALL_STATE(102)] = 1319,
  [SMALL_STATE(103)] = 1326,
  [SMALL_STATE(104)] = 1333,
  [SMALL_STATE(105)] = 1338,
  [SMALL_STATE(106)] = 1343,
  [SMALL_STATE(107)] = 1348,
  [SMALL_STATE(108)] = 1353,
  [SMALL_STATE(109)] = 1360,
  [SMALL_STATE(110)] = 1367,
  [SMALL_STATE(111)] = 1374,
  [SMALL_STATE(112)] = 1381,
  [SMALL_STATE(113)] = 1385,
  [SMALL_STATE(114)] = 1389,
  [SMALL_STATE(115)] = 1393,
  [SMALL_STATE(116)] = 1397,
  [SMALL_STATE(117)] = 1401,
  [SMALL_STATE(118)] = 1405,
  [SMALL_STATE(119)] = 1409,
  [SMALL_STATE(120)] = 1413,
  [SMALL_STATE(121)] = 1417,
  [SMALL_STATE(122)] = 1421,
  [SMALL_STATE(123)] = 1425,
  [SMALL_STATE(124)] = 1429,
  [SMALL_STATE(125)] = 1433,
  [SMALL_STATE(126)] = 1437,
  [SMALL_STATE(127)] = 1441,
  [SMALL_STATE(128)] = 1445,
  [SMALL_STATE(129)] = 1449,
  [SMALL_STATE(130)] = 1453,
  [SMALL_STATE(131)] = 1457,
  [SMALL_STATE(132)] = 1461,
  [SMALL_STATE(133)] = 1465,
  [SMALL_STATE(134)] = 1469,
  [SMALL_STATE(135)] = 1473,
  [SMALL_STATE(136)] = 1477,
  [SMALL_STATE(137)] = 1481,
  [SMALL_STATE(138)] = 1485,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cmd_expr, 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cmd_expr, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 4),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(10),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(35),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(9),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 6),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 3),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 3),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_invocation, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_invocation, 4),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [132] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(97),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 4),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [159] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 7),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 5),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 3),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range, 3, .production_id = 6),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 2),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 7),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 1),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 2),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_path, 1),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 5),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 4),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_default_parameter_assignment, 2),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [215] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(112),
  [218] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(50),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 3),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 4),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 5),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [235] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(58),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [244] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2), SHIFT_REPEAT(75),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(92),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 1),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 2),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 1, .production_id = 3),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 1),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 4),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 3),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 2, .production_id = 5),
  [290] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 2, .production_id = 5), SHIFT_REPEAT(88),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_args, 2),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 2, .production_id = 3),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_args, 3, .production_id = 4),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 3),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 2),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [357] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
