#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 143
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 114
#define ALIAS_COUNT 0
#define TOKEN_COUNT 82
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
  anon_sym_EQ_EQ = 51,
  anon_sym_BANG_EQ = 52,
  anon_sym_LT = 53,
  anon_sym_LT_EQ = 54,
  anon_sym_GT = 55,
  anon_sym_GT_EQ = 56,
  anon_sym_EQ_TILDE = 57,
  anon_sym_BANG_TILDE = 58,
  anon_sym_PLUS = 59,
  anon_sym_DASH = 60,
  anon_sym_STAR = 61,
  anon_sym_SLASH = 62,
  anon_sym_SLASH_SLASH = 63,
  anon_sym_in = 64,
  anon_sym_not_DASHin = 65,
  anon_sym_mod = 66,
  anon_sym_PERCENT = 67,
  anon_sym_bit_DASHor = 68,
  anon_sym_bit_DASHxor = 69,
  anon_sym_bit_DASHand = 70,
  anon_sym_bit_DASHshl = 71,
  anon_sym_LT_LT = 72,
  anon_sym_bit_DASHshr = 73,
  anon_sym_GT_GT = 74,
  anon_sym_starts_DASHwith = 75,
  anon_sym_ends_DASHwith = 76,
  anon_sym_AMP_AMP = 77,
  anon_sym_and = 78,
  anon_sym_PIPE_PIPE = 79,
  anon_sym_or = 80,
  anon_sym_STAR_STAR = 81,
  sym_source_file = 82,
  sym__statements = 83,
  sym__statement = 84,
  sym__definition = 85,
  sym__line_terminator = 86,
  sym_signature = 87,
  sym_parameter = 88,
  sym_flag = 89,
  sym_rest = 90,
  sym_default_parameter_assignment = 91,
  sym_function_definition = 92,
  sym_type = 93,
  sym_string = 94,
  sym_value_path = 95,
  sym_file_path = 96,
  sym_range = 97,
  sym_record_or_block = 98,
  sym_block = 99,
  sym_block_args = 100,
  sym__expression = 101,
  sym_table = 102,
  sym_array = 103,
  sym__cmd_expr = 104,
  sym_cmd_invocation = 105,
  sym_binary_expression = 106,
  aux_sym_source_file_repeat1 = 107,
  aux_sym__statements_repeat1 = 108,
  aux_sym_signature_repeat1 = 109,
  aux_sym_value_path_repeat1 = 110,
  aux_sym_block_args_repeat1 = 111,
  aux_sym_table_repeat1 = 112,
  aux_sym_array_repeat1 = 113,
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
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_EQ_TILDE] = "=~",
  [anon_sym_BANG_TILDE] = "!~",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_SLASH_SLASH] = "//",
  [anon_sym_in] = "in",
  [anon_sym_not_DASHin] = "not-in",
  [anon_sym_mod] = "mod",
  [anon_sym_PERCENT] = "%",
  [anon_sym_bit_DASHor] = "bit-or",
  [anon_sym_bit_DASHxor] = "bit-xor",
  [anon_sym_bit_DASHand] = "bit-and",
  [anon_sym_bit_DASHshl] = "bit-shl",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_bit_DASHshr] = "bit-shr",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_starts_DASHwith] = "starts-with",
  [anon_sym_ends_DASHwith] = "ends-with",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_and] = "and",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_or] = "or",
  [anon_sym_STAR_STAR] = "**",
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
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_EQ_TILDE] = anon_sym_EQ_TILDE,
  [anon_sym_BANG_TILDE] = anon_sym_BANG_TILDE,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_not_DASHin] = anon_sym_not_DASHin,
  [anon_sym_mod] = anon_sym_mod,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_bit_DASHor] = anon_sym_bit_DASHor,
  [anon_sym_bit_DASHxor] = anon_sym_bit_DASHxor,
  [anon_sym_bit_DASHand] = anon_sym_bit_DASHand,
  [anon_sym_bit_DASHshl] = anon_sym_bit_DASHshl,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_bit_DASHshr] = anon_sym_bit_DASHshr,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_starts_DASHwith] = anon_sym_starts_DASHwith,
  [anon_sym_ends_DASHwith] = anon_sym_ends_DASHwith,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
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
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
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
  [anon_sym_EQ_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_TILDE] = {
    .visible = true,
    .named = false,
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
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not_DASHin] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mod] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bit_DASHor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bit_DASHxor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bit_DASHand] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bit_DASHshl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bit_DASHshr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_starts_DASHwith] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ends_DASHwith] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
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
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
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
      if (eof) ADVANCE(139);
      if (lookahead == '!') ADVANCE(210);
      if (lookahead == '"') ADVANCE(177);
      if (lookahead == '$') ADVANCE(175);
      if (lookahead == '%') ADVANCE(344);
      if (lookahead == '&') ADVANCE(205);
      if (lookahead == '\'') ADVANCE(181);
      if (lookahead == '(') ADVANCE(144);
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == '*') ADVANCE(335);
      if (lookahead == '+') ADVANCE(332);
      if (lookahead == ',') ADVANCE(153);
      if (lookahead == '-') ADVANCE(334);
      if (lookahead == '.') ADVANCE(194);
      if (lookahead == '/') ADVANCE(336);
      if (lookahead == ':') ADVANCE(148);
      if (lookahead == ';') ADVANCE(152);
      if (lookahead == '<') ADVANCE(326);
      if (lookahead == '=') ADVANCE(141);
      if (lookahead == '>') ADVANCE(328);
      if (lookahead == '?') ADVANCE(154);
      if (lookahead == '@') ADVANCE(159);
      if (lookahead == '[') ADVANCE(142);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == ']') ADVANCE(146);
      if (lookahead == '`') ADVANCE(185);
      if (lookahead == 'a') ADVANCE(242);
      if (lookahead == 'b') ADVANCE(234);
      if (lookahead == 'd') ADVANCE(212);
      if (lookahead == 'e') ADVANCE(261);
      if (lookahead == 'f') ADVANCE(232);
      if (lookahead == 'i') ADVANCE(243);
      if (lookahead == 'l') ADVANCE(227);
      if (lookahead == 'm') ADVANCE(249);
      if (lookahead == 'n') ADVANCE(272);
      if (lookahead == 'o') ADVANCE(256);
      if (lookahead == 'r') ADVANCE(213);
      if (lookahead == 's') ADVANCE(271);
      if (lookahead == 't') ADVANCE(211);
      if (lookahead == '{') ADVANCE(277);
      if (lookahead == '|') ADVANCE(151);
      if (lookahead == '}') ADVANCE(279);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(137)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(276);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(150);
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == ';') ADVANCE(152);
      if (lookahead == '|') ADVANCE(151);
      if (lookahead == '}') ADVANCE(279);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '!') ADVANCE(30);
      if (lookahead == '%') ADVANCE(344);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == '*') ADVANCE(335);
      if (lookahead == '+') ADVANCE(332);
      if (lookahead == ',') ADVANCE(153);
      if (lookahead == '-') ADVANCE(334);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == '/') ADVANCE(336);
      if (lookahead == '<') ADVANCE(326);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(328);
      if (lookahead == ']') ADVANCE(146);
      if (lookahead == 'a') ADVANCE(301);
      if (lookahead == 'b') ADVANCE(296);
      if (lookahead == 'e') ADVANCE(304);
      if (lookahead == 'i') ADVANCE(302);
      if (lookahead == 'm') ADVANCE(307);
      if (lookahead == 'n') ADVANCE(306);
      if (lookahead == 'o') ADVANCE(309);
      if (lookahead == 's') ADVANCE(315);
      if (lookahead == '|') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(177);
      if (lookahead == '$') ADVANCE(175);
      if (lookahead == '\'') ADVANCE(181);
      if (lookahead == '(') ADVANCE(144);
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == ',') ADVANCE(153);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '.') ADVANCE(195);
      if (lookahead == ':') ADVANCE(148);
      if (lookahead == ';') ADVANCE(152);
      if (lookahead == '=') ADVANCE(141);
      if (lookahead == '?') ADVANCE(154);
      if (lookahead == '@') ADVANCE(159);
      if (lookahead == '[') ADVANCE(142);
      if (lookahead == ']') ADVANCE(146);
      if (lookahead == '`') ADVANCE(185);
      if (lookahead == '|') ADVANCE(151);
      if (lookahead == '}') ADVANCE(279);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(177);
      if (lookahead == '$') ADVANCE(175);
      if (lookahead == '\'') ADVANCE(181);
      if (lookahead == '(') ADVANCE(144);
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == ',') ADVANCE(153);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == ':') ADVANCE(148);
      if (lookahead == ';') ADVANCE(152);
      if (lookahead == '=') ADVANCE(141);
      if (lookahead == '?') ADVANCE(154);
      if (lookahead == '@') ADVANCE(159);
      if (lookahead == '[') ADVANCE(142);
      if (lookahead == ']') ADVANCE(146);
      if (lookahead == '`') ADVANCE(185);
      if (lookahead == '|') ADVANCE(151);
      if (lookahead == '}') ADVANCE(279);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(178);
      if (lookahead == '$') ADVANCE(176);
      if (lookahead == '\'') ADVANCE(182);
      if (lookahead == '(') ADVANCE(145);
      if (lookahead == '-') ADVANCE(12);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '[') ADVANCE(143);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead == '`') ADVANCE(186);
      if (lookahead == '{') ADVANCE(278);
      if (lookahead == '~') ADVANCE(206);
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
          lookahead == '}') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0) ADVANCE(209);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(178);
      if (lookahead == '$') ADVANCE(176);
      if (lookahead == '\'') ADVANCE(182);
      if (lookahead == '(') ADVANCE(145);
      if (lookahead == '-') ADVANCE(12);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '[') ADVANCE(143);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead == '`') ADVANCE(186);
      if (lookahead == '{') ADVANCE(278);
      if (lookahead == '~') ADVANCE(206);
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
          lookahead == '}') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(189);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      if (lookahead != 0) ADVANCE(209);
      END_STATE();
    case 7:
      if (lookahead == '&') ADVANCE(361);
      END_STATE();
    case 8:
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == ',') ADVANCE(153);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == ']') ADVANCE(146);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(133);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(39);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(127);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(25);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == '/') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '~') ADVANCE(26);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(134);
      if (lookahead == 'b') ADVANCE(65);
      if (lookahead == 'd') ADVANCE(36);
      if (lookahead == 'e') ADVANCE(106);
      if (lookahead == 'f') ADVANCE(61);
      if (lookahead == 'i') ADVANCE(84);
      if (lookahead == 'n') ADVANCE(126);
      if (lookahead == 'r') ADVANCE(34);
      if (lookahead == 's') ADVANCE(124);
      if (lookahead == 't') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(64);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(128);
      END_STATE();
    case 16:
      if (lookahead == '.') ADVANCE(204);
      END_STATE();
    case 17:
      if (lookahead == '.') ADVANCE(97);
      END_STATE();
    case 18:
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == '/') ADVANCE(135);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(26);
      END_STATE();
    case 19:
      if (lookahead == '.') ADVANCE(196);
      END_STATE();
    case 20:
      if (lookahead == '.') ADVANCE(198);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 21:
      if (lookahead == '.') ADVANCE(198);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 22:
      if (lookahead == '.') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(276);
      END_STATE();
    case 23:
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 24:
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 25:
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (('-' <= lookahead && lookahead <= '9') ||
          lookahead == '~') ADVANCE(26);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      END_STATE();
    case 26:
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == '.') ADVANCE(197);
      if (lookahead == '/') ADVANCE(200);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(196);
      END_STATE();
    case 28:
      if (lookahead == '.') ADVANCE(17);
      END_STATE();
    case 29:
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 30:
      if (lookahead == '=') ADVANCE(325);
      if (lookahead == '~') ADVANCE(331);
      END_STATE();
    case 31:
      if (lookahead == '=') ADVANCE(324);
      if (lookahead == '~') ADVANCE(330);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(40);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(121);
      if (lookahead == 'u') ADVANCE(103);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(122);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(113);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(83);
      if (lookahead == 'o') ADVANCE(100);
      if (lookahead == 's') ADVANCE(58);
      if (lookahead == 'x') ADVANCE(90);
      END_STATE();
    case 40:
      if (lookahead == 'b') ADVANCE(73);
      END_STATE();
    case 41:
      if (lookahead == 'b') ADVANCE(54);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(70);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(362);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(342);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(349);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(110);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(169);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(164);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(172);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(170);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(111);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 55:
      if (lookahead == 'f') ADVANCE(161);
      END_STATE();
    case 56:
      if (lookahead == 'g') ADVANCE(166);
      END_STATE();
    case 57:
      if (lookahead == 'g') ADVANCE(49);
      END_STATE();
    case 58:
      if (lookahead == 'h') ADVANCE(72);
      END_STATE();
    case 59:
      if (lookahead == 'h') ADVANCE(359);
      END_STATE();
    case 60:
      if (lookahead == 'h') ADVANCE(357);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(74);
      if (lookahead == 'l') ADVANCE(94);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(130);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(117);
      END_STATE();
    case 64:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 65:
      if (lookahead == 'i') ADVANCE(85);
      if (lookahead == 'l') ADVANCE(86);
      if (lookahead == 'o') ADVANCE(87);
      END_STATE();
    case 66:
      if (lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 67:
      if (lookahead == 'i') ADVANCE(82);
      END_STATE();
    case 68:
      if (lookahead == 'i') ADVANCE(123);
      END_STATE();
    case 69:
      if (lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 70:
      if (lookahead == 'k') ADVANCE(167);
      END_STATE();
    case 71:
      if (lookahead == 'l') ADVANCE(165);
      END_STATE();
    case 72:
      if (lookahead == 'l') ADVANCE(351);
      if (lookahead == 'r') ADVANCE(354);
      END_STATE();
    case 73:
      if (lookahead == 'l') ADVANCE(50);
      END_STATE();
    case 74:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 75:
      if (lookahead == 'm') ADVANCE(41);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(338);
      END_STATE();
    case 77:
      if (lookahead == 'n') ADVANCE(168);
      END_STATE();
    case 78:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 79:
      if (lookahead == 'n') ADVANCE(340);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(46);
      if (lookahead == 'x') ADVANCE(95);
      END_STATE();
    case 82:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 84:
      if (lookahead == 'n') ADVANCE(118);
      END_STATE();
    case 85:
      if (lookahead == 'n') ADVANCE(35);
      END_STATE();
    case 86:
      if (lookahead == 'o') ADVANCE(42);
      END_STATE();
    case 87:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 88:
      if (lookahead == 'o') ADVANCE(44);
      END_STATE();
    case 89:
      if (lookahead == 'o') ADVANCE(119);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(101);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 92:
      if (lookahead == 'o') ADVANCE(98);
      END_STATE();
    case 93:
      if (lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 94:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 95:
      if (lookahead == 'p') ADVANCE(93);
      END_STATE();
    case 96:
      if (lookahead == 'r') ADVANCE(365);
      END_STATE();
    case 97:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 98:
      if (lookahead == 'r') ADVANCE(173);
      END_STATE();
    case 99:
      if (lookahead == 'r') ADVANCE(171);
      END_STATE();
    case 100:
      if (lookahead == 'r') ADVANCE(345);
      END_STATE();
    case 101:
      if (lookahead == 'r') ADVANCE(347);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(129);
      END_STATE();
    case 103:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 104:
      if (lookahead == 'r') ADVANCE(125);
      END_STATE();
    case 105:
      if (lookahead == 'r') ADVANCE(114);
      END_STATE();
    case 106:
      if (lookahead == 'r') ADVANCE(108);
      END_STATE();
    case 107:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 108:
      if (lookahead == 'r') ADVANCE(92);
      END_STATE();
    case 109:
      if (lookahead == 's') ADVANCE(115);
      END_STATE();
    case 110:
      if (lookahead == 's') ADVANCE(11);
      END_STATE();
    case 111:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 112:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 113:
      if (lookahead == 't') ADVANCE(163);
      END_STATE();
    case 114:
      if (lookahead == 't') ADVANCE(160);
      END_STATE();
    case 115:
      if (lookahead == 't') ADVANCE(158);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(162);
      END_STATE();
    case 119:
      if (lookahead == 't') ADVANCE(14);
      END_STATE();
    case 120:
      if (lookahead == 't') ADVANCE(59);
      END_STATE();
    case 121:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 122:
      if (lookahead == 't') ADVANCE(69);
      END_STATE();
    case 123:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 124:
      if (lookahead == 't') ADVANCE(107);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 126:
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 127:
      if (lookahead == 'w') ADVANCE(66);
      END_STATE();
    case 128:
      if (lookahead == 'w') ADVANCE(68);
      END_STATE();
    case 129:
      if (lookahead == 'y') ADVANCE(174);
      END_STATE();
    case 130:
      if (lookahead == 'z') ADVANCE(51);
      END_STATE();
    case 131:
      if (lookahead == '|') ADVANCE(364);
      END_STATE();
    case 132:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 133:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 134:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 135:
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(26);
      END_STATE();
    case 136:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(276);
      END_STATE();
    case 137:
      if (eof) ADVANCE(139);
      if (lookahead == '!') ADVANCE(210);
      if (lookahead == '"') ADVANCE(177);
      if (lookahead == '$') ADVANCE(175);
      if (lookahead == '%') ADVANCE(344);
      if (lookahead == '&') ADVANCE(205);
      if (lookahead == '\'') ADVANCE(181);
      if (lookahead == '(') ADVANCE(144);
      if (lookahead == ')') ADVANCE(147);
      if (lookahead == '*') ADVANCE(335);
      if (lookahead == '+') ADVANCE(332);
      if (lookahead == ',') ADVANCE(153);
      if (lookahead == '-') ADVANCE(334);
      if (lookahead == '.') ADVANCE(16);
      if (lookahead == '/') ADVANCE(336);
      if (lookahead == ':') ADVANCE(148);
      if (lookahead == ';') ADVANCE(152);
      if (lookahead == '<') ADVANCE(326);
      if (lookahead == '=') ADVANCE(141);
      if (lookahead == '>') ADVANCE(328);
      if (lookahead == '?') ADVANCE(154);
      if (lookahead == '@') ADVANCE(159);
      if (lookahead == '[') ADVANCE(142);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == ']') ADVANCE(146);
      if (lookahead == '`') ADVANCE(185);
      if (lookahead == 'a') ADVANCE(242);
      if (lookahead == 'b') ADVANCE(234);
      if (lookahead == 'd') ADVANCE(212);
      if (lookahead == 'e') ADVANCE(261);
      if (lookahead == 'f') ADVANCE(232);
      if (lookahead == 'i') ADVANCE(243);
      if (lookahead == 'l') ADVANCE(227);
      if (lookahead == 'm') ADVANCE(249);
      if (lookahead == 'n') ADVANCE(272);
      if (lookahead == 'o') ADVANCE(256);
      if (lookahead == 'r') ADVANCE(213);
      if (lookahead == 's') ADVANCE(271);
      if (lookahead == 't') ADVANCE(211);
      if (lookahead == '{') ADVANCE(277);
      if (lookahead == '|') ADVANCE(151);
      if (lookahead == '}') ADVANCE(279);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(137)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(276);
      END_STATE();
    case 138:
      if (eof) ADVANCE(139);
      if (lookahead == '!') ADVANCE(30);
      if (lookahead == '%') ADVANCE(344);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '*') ADVANCE(335);
      if (lookahead == '+') ADVANCE(332);
      if (lookahead == '-') ADVANCE(333);
      if (lookahead == '/') ADVANCE(336);
      if (lookahead == '<') ADVANCE(326);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(328);
      if (lookahead == 'a') ADVANCE(78);
      if (lookahead == 'b') ADVANCE(63);
      if (lookahead == 'd') ADVANCE(52);
      if (lookahead == 'e') ADVANCE(81);
      if (lookahead == 'i') ADVANCE(76);
      if (lookahead == 'm') ADVANCE(88);
      if (lookahead == 'n') ADVANCE(89);
      if (lookahead == 'o') ADVANCE(96);
      if (lookahead == 's') ADVANCE(116);
      if (lookahead == '|') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(138)
      END_STATE();
    case 139:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(150);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(150);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_flag_shorthand_name);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_duration);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_date);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_filesize);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_error);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_binary);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(180);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(180);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(184);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(184);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(188);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(188);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '-') ADVANCE(26);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(207);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '-') ADVANCE(26);
      if (lookahead == '.') ADVANCE(23);
      if (lookahead == '/') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(190);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(207);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(191);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(192);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(193);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(204);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(17);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(198);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(26);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(26);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_file_path_token2);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '-' ||
          lookahead == '~') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(201);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_flag_arg);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '~') ADVANCE(26);
      if (('-' <= lookahead && lookahead <= '9')) ADVANCE(203);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_flag_arg);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '~') ADVANCE(26);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(203);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(97);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(361);
      if (lookahead == '\\') ADVANCE(136);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '-') ADVANCE(26);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == '/') ADVANCE(275);
      if (lookahead == '\\') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(207);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(276);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '-') ADVANCE(26);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(275);
      if (lookahead == '\\') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(207);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(276);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(136);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(276);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(19);
      if (lookahead == '\\') ADVANCE(136);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(276);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(325);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == '~') ADVANCE(331);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'a') ADVANCE(218);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'a') ADVANCE(269);
      if (lookahead == 'e') ADVANCE(229);
      if (lookahead == 'u') ADVANCE(262);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'a') ADVANCE(244);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'a') ADVANCE(270);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'a') ADVANCE(258);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'a') ADVANCE(267);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'b') ADVANCE(228);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'b') ADVANCE(240);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'c') ADVANCE(237);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'd') ADVANCE(362);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'd') ADVANCE(342);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(169);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(265);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(164);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(172);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(170);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(266);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'e') ADVANCE(260);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'f') ADVANCE(161);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'g') ADVANCE(166);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'g') ADVANCE(224);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(239);
      if (lookahead == 'l') ADVANCE(254);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(274);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(247);
      if (lookahead == 'l') ADVANCE(248);
      if (lookahead == 'o') ADVANCE(250);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(246);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(251);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'k') ADVANCE(167);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'l') ADVANCE(165);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'l') ADVANCE(223);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'l') ADVANCE(225);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'm') ADVANCE(217);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'n') ADVANCE(220);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'n') ADVANCE(338);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'n') ADVANCE(231);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'n') ADVANCE(168);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'n') ADVANCE(230);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'n') ADVANCE(215);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(219);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(221);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(238);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(245);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(259);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(264);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'o') ADVANCE(216);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'p') ADVANCE(253);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(365);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(235);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(273);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(173);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(171);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(263);
      if (lookahead == 'x') ADVANCE(255);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(214);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(252);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'r') ADVANCE(268);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 's') ADVANCE(233);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 't') ADVANCE(140);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 't') ADVANCE(163);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 't') ADVANCE(160);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 't') ADVANCE(222);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 't') ADVANCE(236);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 't') ADVANCE(257);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'u') ADVANCE(241);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'y') ADVANCE(174);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == 'z') ADVANCE(226);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead == '-' ||
          lookahead == '.') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(207);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(276);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(136);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(276);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead == '.') ADVANCE(19);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(286);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == '/') ADVANCE(275);
      if (lookahead == '~') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(286);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(275);
      if (lookahead == '~') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(283);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(135);
      if (lookahead == '~') ADVANCE(26);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(286);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(312);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(305);
      if (lookahead == 'o') ADVANCE(310);
      if (lookahead == 's') ADVANCE(293);
      if (lookahead == 'x') ADVANCE(308);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(363);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(313);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(343);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(350);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(300);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(360);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(358);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(316);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(303);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(318);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(319);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(352);
      if (lookahead == 'r') ADVANCE(355);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(289);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(339);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(341);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(290);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(292);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(317);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(291);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(311);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(366);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(346);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(348);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(320);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(281);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(285);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(287);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(280);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(284);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(294);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(295);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(314);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'w') ADVANCE(298);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'w') ADVANCE(299);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(353);
      if (lookahead == '=') ADVANCE(327);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(329);
      if (lookahead == '>') ADVANCE(356);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_EQ_TILDE);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_BANG_TILDE);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(133);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(367);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(337);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_not_DASHin);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_not_DASHin);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_mod);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_mod);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_bit_DASHor);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_bit_DASHor);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(anon_sym_bit_DASHxor);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_bit_DASHxor);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(anon_sym_bit_DASHand);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_bit_DASHand);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_bit_DASHshl);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(anon_sym_bit_DASHshl);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_bit_DASHshr);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_bit_DASHshr);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_starts_DASHwith);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_starts_DASHwith);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_ends_DASHwith);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_ends_DASHwith);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(323);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 138},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 138},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 13},
  [6] = {.lex_state = 13},
  [7] = {.lex_state = 13},
  [8] = {.lex_state = 13},
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
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 3},
  [35] = {.lex_state = 8},
  [36] = {.lex_state = 3},
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
  [49] = {.lex_state = 138},
  [50] = {.lex_state = 3},
  [51] = {.lex_state = 3},
  [52] = {.lex_state = 3},
  [53] = {.lex_state = 3},
  [54] = {.lex_state = 3},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 3},
  [59] = {.lex_state = 3},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 3},
  [62] = {.lex_state = 3},
  [63] = {.lex_state = 3},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 3},
  [66] = {.lex_state = 3},
  [67] = {.lex_state = 3},
  [68] = {.lex_state = 3},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 3},
  [71] = {.lex_state = 138},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 3},
  [75] = {.lex_state = 3},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 3},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 3},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 3},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 138},
  [91] = {.lex_state = 138},
  [92] = {.lex_state = 3},
  [93] = {.lex_state = 138},
  [94] = {.lex_state = 3},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 138},
  [97] = {.lex_state = 3},
  [98] = {.lex_state = 138},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 3},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 3},
  [109] = {.lex_state = 3},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 3},
  [113] = {.lex_state = 3},
  [114] = {.lex_state = 3},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 13},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 3},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 3},
  [133] = {.lex_state = 187},
  [134] = {.lex_state = 183},
  [135] = {.lex_state = 179},
  [136] = {.lex_state = 138},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 187},
  [139] = {.lex_state = 183},
  [140] = {.lex_state = 179},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
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
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_BANG_TILDE] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_SLASH_SLASH] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_mod] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(142),
    [sym__definition] = STATE(71),
    [sym_function_definition] = STATE(71),
    [aux_sym_source_file_repeat1] = STATE(71),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_export] = ACTIONS(5),
    [anon_sym_def] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(9), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(13), 14,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_TILDE,
      anon_sym_BANG_TILDE,
      anon_sym_PLUS,
      anon_sym_SLASH_SLASH,
      anon_sym_PERCENT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_AMP_AMP,
      anon_sym_PIPE_PIPE,
      anon_sym_STAR_STAR,
    ACTIONS(15), 17,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_in,
      anon_sym_not_DASHin,
      anon_sym_mod,
      anon_sym_bit_DASHor,
      anon_sym_bit_DASHxor,
      anon_sym_bit_DASHand,
      anon_sym_bit_DASHshl,
      anon_sym_bit_DASHshr,
      anon_sym_starts_DASHwith,
      anon_sym_ends_DASHwith,
      anon_sym_and,
      anon_sym_or,
  [46] = 12,
    ACTIONS(27), 1,
      anon_sym_bit_DASHor,
    ACTIONS(29), 1,
      anon_sym_bit_DASHxor,
    ACTIONS(31), 1,
      anon_sym_bit_DASHand,
    ACTIONS(39), 1,
      anon_sym_STAR_STAR,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(21), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(23), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(35), 2,
      anon_sym_AMP_AMP,
      anon_sym_and,
    ACTIONS(37), 2,
      anon_sym_PIPE_PIPE,
      anon_sym_or,
    ACTIONS(25), 3,
      anon_sym_SLASH_SLASH,
      anon_sym_mod,
      anon_sym_PERCENT,
    ACTIONS(33), 4,
      anon_sym_bit_DASHshl,
      anon_sym_LT_LT,
      anon_sym_bit_DASHshr,
      anon_sym_GT_GT,
    ACTIONS(17), 10,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_EQ_TILDE,
      anon_sym_BANG_TILDE,
      anon_sym_in,
      anon_sym_not_DASHin,
      anon_sym_starts_DASHwith,
      anon_sym_ends_DASHwith,
  [102] = 13,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    ACTIONS(43), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      anon_sym_DOLLAR,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(49), 1,
      anon_sym_SQUOTE,
    ACTIONS(51), 1,
      anon_sym_BQUOTE,
    ACTIONS(53), 1,
      sym_number_literal,
    ACTIONS(59), 1,
      anon_sym_LBRACE,
    ACTIONS(61), 1,
      sym_identifier,
    STATE(3), 1,
      sym__expression,
    ACTIONS(55), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(57), 2,
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
  [153] = 2,
    STATE(11), 1,
      sym_type,
    ACTIONS(63), 13,
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
  [172] = 2,
    STATE(17), 1,
      sym_type,
    ACTIONS(63), 13,
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
  [191] = 2,
    STATE(19), 1,
      sym_type,
    ACTIONS(63), 13,
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
  [210] = 2,
    STATE(67), 1,
      sym_type,
    ACTIONS(63), 13,
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
  [229] = 6,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(69), 1,
      anon_sym_COLON,
    ACTIONS(71), 1,
      anon_sym_QMARK,
    ACTIONS(73), 1,
      anon_sym_AT,
    STATE(46), 1,
      sym_default_parameter_assignment,
    ACTIONS(67), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [253] = 6,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    ACTIONS(75), 1,
      anon_sym_LPAREN,
    ACTIONS(79), 1,
      anon_sym_COLON,
    STATE(43), 1,
      sym_default_parameter_assignment,
    ACTIONS(77), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [277] = 5,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    ACTIONS(83), 1,
      anon_sym_QMARK,
    STATE(45), 1,
      sym_default_parameter_assignment,
    ACTIONS(81), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [298] = 5,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    ACTIONS(87), 1,
      anon_sym_COLON,
    STATE(57), 1,
      sym_default_parameter_assignment,
    ACTIONS(85), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [319] = 4,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    STATE(69), 1,
      sym_default_parameter_assignment,
    ACTIONS(89), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [337] = 6,
    ACTIONS(93), 1,
      sym_flag_name,
    ACTIONS(96), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(99), 1,
      sym_identifier,
    STATE(14), 1,
      aux_sym_signature_repeat1,
    ACTIONS(91), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(60), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [359] = 4,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    STATE(50), 1,
      sym_default_parameter_assignment,
    ACTIONS(102), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [377] = 6,
    ACTIONS(106), 1,
      sym_flag_name,
    ACTIONS(108), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(110), 1,
      sym_identifier,
    STATE(14), 1,
      aux_sym_signature_repeat1,
    ACTIONS(104), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(60), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [399] = 4,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    STATE(44), 1,
      sym_default_parameter_assignment,
    ACTIONS(112), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [417] = 1,
    ACTIONS(114), 9,
      anon_sym_EQ,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_QMARK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      anon_sym_AT,
      sym_identifier,
  [429] = 4,
    ACTIONS(65), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_AT,
    STATE(51), 1,
      sym_default_parameter_assignment,
    ACTIONS(116), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [447] = 6,
    ACTIONS(106), 1,
      sym_flag_name,
    ACTIONS(108), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(110), 1,
      sym_identifier,
    STATE(16), 1,
      aux_sym_signature_repeat1,
    ACTIONS(118), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
    STATE(60), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [469] = 1,
    ACTIONS(120), 8,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [480] = 3,
    ACTIONS(124), 1,
      anon_sym_DOT,
    STATE(26), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(122), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [495] = 3,
    ACTIONS(124), 1,
      anon_sym_DOT,
    STATE(33), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(126), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [510] = 1,
    ACTIONS(128), 8,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [521] = 3,
    STATE(97), 1,
      sym__line_terminator,
    ACTIONS(130), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(132), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_PIPE,
      anon_sym_SEMI,
  [536] = 3,
    ACTIONS(136), 1,
      anon_sym_DOT,
    STATE(26), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(134), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [551] = 7,
    ACTIONS(139), 1,
      anon_sym_PIPE,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    ACTIONS(143), 1,
      sym_identifier,
    STATE(54), 1,
      sym_block_args,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(129), 1,
      sym__statements,
    STATE(28), 2,
      sym__statement,
      sym__expression,
  [574] = 3,
    STATE(86), 1,
      sym__line_terminator,
    ACTIONS(145), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(147), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_PIPE,
      anon_sym_SEMI,
  [589] = 1,
    ACTIONS(149), 8,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [600] = 3,
    ACTIONS(124), 1,
      anon_sym_DOT,
    STATE(22), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(151), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [615] = 1,
    ACTIONS(153), 8,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [626] = 7,
    ACTIONS(139), 1,
      anon_sym_PIPE,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(155), 1,
      anon_sym_RBRACE,
    STATE(37), 1,
      sym_block_args,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(122), 1,
      sym__statements,
    STATE(28), 2,
      sym__statement,
      sym__expression,
  [649] = 3,
    ACTIONS(124), 1,
      anon_sym_DOT,
    STATE(26), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(157), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [664] = 2,
    ACTIONS(159), 1,
      anon_sym_DOT,
    ACTIONS(134), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [676] = 2,
    ACTIONS(161), 1,
      anon_sym_DOT_DOT,
    ACTIONS(9), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [688] = 2,
    ACTIONS(165), 1,
      anon_sym_COLON,
    ACTIONS(163), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [700] = 5,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(167), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(141), 1,
      sym__statements,
    STATE(28), 2,
      sym__statement,
      sym__expression,
  [717] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [726] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [735] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [744] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [753] = 1,
    ACTIONS(171), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [762] = 1,
    ACTIONS(173), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [771] = 1,
    ACTIONS(175), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [780] = 1,
    ACTIONS(102), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [789] = 1,
    ACTIONS(89), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [798] = 6,
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
    STATE(88), 1,
      sym_string,
  [817] = 1,
    ACTIONS(187), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [826] = 4,
    ACTIONS(189), 1,
      ts_builtin_sym_end,
    ACTIONS(191), 1,
      anon_sym_export,
    ACTIONS(194), 1,
      anon_sym_def,
    STATE(49), 3,
      sym__definition,
      sym_function_definition,
      aux_sym_source_file_repeat1,
  [841] = 1,
    ACTIONS(197), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [850] = 1,
    ACTIONS(85), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [859] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [868] = 1,
    ACTIONS(199), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [877] = 5,
    ACTIONS(143), 1,
      sym_identifier,
    ACTIONS(201), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(119), 1,
      sym__statements,
    STATE(28), 2,
      sym__statement,
      sym__expression,
  [894] = 6,
    ACTIONS(203), 1,
      anon_sym_LBRACK,
    ACTIONS(205), 1,
      anon_sym_RBRACK,
    ACTIONS(207), 1,
      sym_identifier,
    STATE(79), 1,
      aux_sym_array_repeat1,
    STATE(85), 1,
      sym__expression,
    STATE(121), 1,
      sym_array,
  [913] = 1,
    ACTIONS(209), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [922] = 1,
    ACTIONS(211), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [931] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [940] = 1,
    ACTIONS(213), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [949] = 2,
    ACTIONS(217), 1,
      anon_sym_COMMA,
    ACTIONS(215), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [960] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [969] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [978] = 1,
    ACTIONS(219), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [987] = 2,
    STATE(132), 1,
      sym__line_terminator,
    ACTIONS(221), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_PIPE,
      anon_sym_SEMI,
  [998] = 1,
    ACTIONS(223), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1007] = 1,
    ACTIONS(225), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1016] = 1,
    ACTIONS(227), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1025] = 6,
    ACTIONS(177), 1,
      anon_sym_DOLLAR,
    ACTIONS(179), 1,
      anon_sym_DQUOTE,
    ACTIONS(181), 1,
      anon_sym_SQUOTE,
    ACTIONS(183), 1,
      anon_sym_BQUOTE,
    ACTIONS(229), 1,
      sym_identifier,
    STATE(89), 1,
      sym_string,
  [1044] = 1,
    ACTIONS(81), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1053] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1062] = 4,
    ACTIONS(5), 1,
      anon_sym_export,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(231), 1,
      ts_builtin_sym_end,
    STATE(49), 3,
      sym__definition,
      sym_function_definition,
      aux_sym_source_file_repeat1,
  [1077] = 1,
    ACTIONS(169), 6,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1086] = 4,
    ACTIONS(233), 1,
      anon_sym_DQUOTE,
    ACTIONS(235), 1,
      anon_sym_SQUOTE,
    ACTIONS(237), 1,
      anon_sym_BQUOTE,
    ACTIONS(239), 2,
      sym_number_literal,
      sym_identifier,
  [1100] = 4,
    ACTIONS(143), 1,
      sym_identifier,
    STATE(80), 1,
      aux_sym__statements_repeat1,
    STATE(137), 1,
      sym__statements,
    STATE(28), 2,
      sym__statement,
      sym__expression,
  [1114] = 1,
    ACTIONS(91), 5,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [1122] = 3,
    ACTIONS(241), 1,
      sym_identifier,
    STATE(76), 1,
      aux_sym__statements_repeat1,
    STATE(64), 2,
      sym__statement,
      sym__expression,
  [1133] = 4,
    ACTIONS(205), 1,
      anon_sym_RBRACK,
    ACTIONS(207), 1,
      sym_identifier,
    STATE(79), 1,
      aux_sym_array_repeat1,
    STATE(85), 1,
      sym__expression,
  [1146] = 3,
    ACTIONS(203), 1,
      anon_sym_LBRACK,
    ACTIONS(244), 1,
      anon_sym_RBRACK,
    STATE(83), 2,
      sym_array,
      aux_sym_table_repeat1,
  [1157] = 4,
    ACTIONS(207), 1,
      sym_identifier,
    ACTIONS(246), 1,
      anon_sym_RBRACK,
    STATE(82), 1,
      aux_sym_array_repeat1,
    STATE(85), 1,
      sym__expression,
  [1170] = 3,
    ACTIONS(248), 1,
      sym_identifier,
    STATE(76), 1,
      aux_sym__statements_repeat1,
    STATE(25), 2,
      sym__statement,
      sym__expression,
  [1181] = 3,
    ACTIONS(250), 1,
      anon_sym_LBRACK,
    ACTIONS(253), 1,
      anon_sym_RBRACK,
    STATE(81), 2,
      sym_array,
      aux_sym_table_repeat1,
  [1192] = 4,
    ACTIONS(255), 1,
      anon_sym_RBRACK,
    ACTIONS(257), 1,
      sym_identifier,
    STATE(82), 1,
      aux_sym_array_repeat1,
    STATE(85), 1,
      sym__expression,
  [1205] = 3,
    ACTIONS(203), 1,
      anon_sym_LBRACK,
    ACTIONS(260), 1,
      anon_sym_RBRACK,
    STATE(81), 2,
      sym_array,
      aux_sym_table_repeat1,
  [1216] = 2,
    ACTIONS(264), 1,
      anon_sym_COMMA,
    ACTIONS(262), 2,
      anon_sym_PIPE,
      sym_identifier,
  [1224] = 2,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(266), 2,
      anon_sym_RBRACK,
      sym_identifier,
  [1232] = 2,
    ACTIONS(272), 1,
      sym_identifier,
    ACTIONS(270), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1240] = 3,
    ACTIONS(233), 1,
      anon_sym_DQUOTE,
    ACTIONS(235), 1,
      anon_sym_SQUOTE,
    ACTIONS(237), 1,
      anon_sym_BQUOTE,
  [1250] = 2,
    STATE(99), 1,
      sym_signature,
    ACTIONS(274), 2,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1258] = 2,
    STATE(110), 1,
      sym_signature,
    ACTIONS(274), 2,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
  [1266] = 1,
    ACTIONS(276), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1272] = 1,
    ACTIONS(278), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1278] = 3,
    ACTIONS(280), 1,
      anon_sym_PIPE,
    ACTIONS(282), 1,
      sym_identifier,
    STATE(95), 1,
      aux_sym_block_args_repeat1,
  [1288] = 1,
    ACTIONS(284), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1294] = 3,
    ACTIONS(286), 1,
      anon_sym_PIPE,
    ACTIONS(288), 1,
      sym_identifier,
    STATE(94), 1,
      aux_sym_block_args_repeat1,
  [1304] = 3,
    ACTIONS(282), 1,
      sym_identifier,
    ACTIONS(291), 1,
      anon_sym_PIPE,
    STATE(94), 1,
      aux_sym_block_args_repeat1,
  [1314] = 1,
    ACTIONS(293), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1320] = 2,
    ACTIONS(272), 1,
      sym_identifier,
    ACTIONS(295), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [1328] = 1,
    ACTIONS(297), 3,
      ts_builtin_sym_end,
      anon_sym_export,
      anon_sym_def,
  [1334] = 2,
    ACTIONS(299), 1,
      anon_sym_LBRACE,
    STATE(90), 1,
      sym_block,
  [1341] = 2,
    ACTIONS(301), 1,
      sym_identifier,
    STATE(58), 1,
      sym__expression,
  [1348] = 2,
    ACTIONS(303), 1,
      sym_identifier,
    STATE(61), 1,
      sym__expression,
  [1355] = 2,
    ACTIONS(305), 1,
      sym_identifier,
    STATE(62), 1,
      sym__expression,
  [1362] = 2,
    ACTIONS(307), 1,
      sym_identifier,
    STATE(72), 1,
      sym__expression,
  [1369] = 2,
    ACTIONS(309), 1,
      sym_identifier,
    STATE(70), 1,
      sym__expression,
  [1376] = 2,
    ACTIONS(311), 1,
      sym_identifier,
    STATE(41), 1,
      sym__expression,
  [1383] = 2,
    ACTIONS(313), 1,
      sym_identifier,
    STATE(40), 1,
      sym__expression,
  [1390] = 1,
    ACTIONS(315), 2,
      anon_sym_PIPE,
      sym_identifier,
  [1395] = 1,
    ACTIONS(317), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1400] = 1,
    ACTIONS(255), 2,
      anon_sym_RBRACK,
      sym_identifier,
  [1405] = 2,
    ACTIONS(299), 1,
      anon_sym_LBRACE,
    STATE(91), 1,
      sym_block,
  [1412] = 1,
    ACTIONS(319), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1417] = 2,
    ACTIONS(321), 1,
      sym_identifier,
    STATE(39), 1,
      sym__expression,
  [1424] = 2,
    ACTIONS(323), 1,
      sym_identifier,
    STATE(52), 1,
      sym__expression,
  [1431] = 1,
    ACTIONS(325), 2,
      sym_number_literal,
      sym_identifier,
  [1436] = 2,
    ACTIONS(327), 1,
      sym_identifier,
    STATE(38), 1,
      sym__expression,
  [1443] = 1,
    ACTIONS(329), 1,
      sym_flag_shorthand_name,
  [1447] = 1,
    ACTIONS(331), 1,
      anon_sym_BQUOTE,
  [1451] = 1,
    ACTIONS(333), 1,
      anon_sym_LBRACE,
  [1455] = 1,
    ACTIONS(335), 1,
      anon_sym_RBRACE,
  [1459] = 1,
    ACTIONS(337), 1,
      sym_identifier,
  [1463] = 1,
    ACTIONS(339), 1,
      anon_sym_SEMI,
  [1467] = 1,
    ACTIONS(167), 1,
      anon_sym_RBRACE,
  [1471] = 1,
    ACTIONS(341), 1,
      anon_sym_LBRACE,
  [1475] = 1,
    ACTIONS(343), 1,
      anon_sym_BQUOTE,
  [1479] = 1,
    ACTIONS(343), 1,
      anon_sym_SQUOTE,
  [1483] = 1,
    ACTIONS(343), 1,
      anon_sym_DQUOTE,
  [1487] = 1,
    ACTIONS(345), 1,
      anon_sym_RPAREN,
  [1491] = 1,
    ACTIONS(347), 1,
      sym_number_literal,
  [1495] = 1,
    ACTIONS(201), 1,
      anon_sym_RBRACE,
  [1499] = 1,
    ACTIONS(331), 1,
      anon_sym_SQUOTE,
  [1503] = 1,
    ACTIONS(331), 1,
      anon_sym_DQUOTE,
  [1507] = 1,
    ACTIONS(272), 1,
      sym_identifier,
  [1511] = 1,
    ACTIONS(349), 1,
      aux_sym_string_token3,
  [1515] = 1,
    ACTIONS(351), 1,
      aux_sym_string_token2,
  [1519] = 1,
    ACTIONS(353), 1,
      aux_sym_string_token1,
  [1523] = 1,
    ACTIONS(355), 1,
      anon_sym_def,
  [1527] = 1,
    ACTIONS(357), 1,
      anon_sym_RPAREN,
  [1531] = 1,
    ACTIONS(359), 1,
      aux_sym_string_token3,
  [1535] = 1,
    ACTIONS(361), 1,
      aux_sym_string_token2,
  [1539] = 1,
    ACTIONS(363), 1,
      aux_sym_string_token1,
  [1543] = 1,
    ACTIONS(365), 1,
      anon_sym_RBRACE,
  [1547] = 1,
    ACTIONS(367), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 46,
  [SMALL_STATE(4)] = 102,
  [SMALL_STATE(5)] = 153,
  [SMALL_STATE(6)] = 172,
  [SMALL_STATE(7)] = 191,
  [SMALL_STATE(8)] = 210,
  [SMALL_STATE(9)] = 229,
  [SMALL_STATE(10)] = 253,
  [SMALL_STATE(11)] = 277,
  [SMALL_STATE(12)] = 298,
  [SMALL_STATE(13)] = 319,
  [SMALL_STATE(14)] = 337,
  [SMALL_STATE(15)] = 359,
  [SMALL_STATE(16)] = 377,
  [SMALL_STATE(17)] = 399,
  [SMALL_STATE(18)] = 417,
  [SMALL_STATE(19)] = 429,
  [SMALL_STATE(20)] = 447,
  [SMALL_STATE(21)] = 469,
  [SMALL_STATE(22)] = 480,
  [SMALL_STATE(23)] = 495,
  [SMALL_STATE(24)] = 510,
  [SMALL_STATE(25)] = 521,
  [SMALL_STATE(26)] = 536,
  [SMALL_STATE(27)] = 551,
  [SMALL_STATE(28)] = 574,
  [SMALL_STATE(29)] = 589,
  [SMALL_STATE(30)] = 600,
  [SMALL_STATE(31)] = 615,
  [SMALL_STATE(32)] = 626,
  [SMALL_STATE(33)] = 649,
  [SMALL_STATE(34)] = 664,
  [SMALL_STATE(35)] = 676,
  [SMALL_STATE(36)] = 688,
  [SMALL_STATE(37)] = 700,
  [SMALL_STATE(38)] = 717,
  [SMALL_STATE(39)] = 726,
  [SMALL_STATE(40)] = 735,
  [SMALL_STATE(41)] = 744,
  [SMALL_STATE(42)] = 753,
  [SMALL_STATE(43)] = 762,
  [SMALL_STATE(44)] = 771,
  [SMALL_STATE(45)] = 780,
  [SMALL_STATE(46)] = 789,
  [SMALL_STATE(47)] = 798,
  [SMALL_STATE(48)] = 817,
  [SMALL_STATE(49)] = 826,
  [SMALL_STATE(50)] = 841,
  [SMALL_STATE(51)] = 850,
  [SMALL_STATE(52)] = 859,
  [SMALL_STATE(53)] = 868,
  [SMALL_STATE(54)] = 877,
  [SMALL_STATE(55)] = 894,
  [SMALL_STATE(56)] = 913,
  [SMALL_STATE(57)] = 922,
  [SMALL_STATE(58)] = 931,
  [SMALL_STATE(59)] = 940,
  [SMALL_STATE(60)] = 949,
  [SMALL_STATE(61)] = 960,
  [SMALL_STATE(62)] = 969,
  [SMALL_STATE(63)] = 978,
  [SMALL_STATE(64)] = 987,
  [SMALL_STATE(65)] = 998,
  [SMALL_STATE(66)] = 1007,
  [SMALL_STATE(67)] = 1016,
  [SMALL_STATE(68)] = 1025,
  [SMALL_STATE(69)] = 1044,
  [SMALL_STATE(70)] = 1053,
  [SMALL_STATE(71)] = 1062,
  [SMALL_STATE(72)] = 1077,
  [SMALL_STATE(73)] = 1086,
  [SMALL_STATE(74)] = 1100,
  [SMALL_STATE(75)] = 1114,
  [SMALL_STATE(76)] = 1122,
  [SMALL_STATE(77)] = 1133,
  [SMALL_STATE(78)] = 1146,
  [SMALL_STATE(79)] = 1157,
  [SMALL_STATE(80)] = 1170,
  [SMALL_STATE(81)] = 1181,
  [SMALL_STATE(82)] = 1192,
  [SMALL_STATE(83)] = 1205,
  [SMALL_STATE(84)] = 1216,
  [SMALL_STATE(85)] = 1224,
  [SMALL_STATE(86)] = 1232,
  [SMALL_STATE(87)] = 1240,
  [SMALL_STATE(88)] = 1250,
  [SMALL_STATE(89)] = 1258,
  [SMALL_STATE(90)] = 1266,
  [SMALL_STATE(91)] = 1272,
  [SMALL_STATE(92)] = 1278,
  [SMALL_STATE(93)] = 1288,
  [SMALL_STATE(94)] = 1294,
  [SMALL_STATE(95)] = 1304,
  [SMALL_STATE(96)] = 1314,
  [SMALL_STATE(97)] = 1320,
  [SMALL_STATE(98)] = 1328,
  [SMALL_STATE(99)] = 1334,
  [SMALL_STATE(100)] = 1341,
  [SMALL_STATE(101)] = 1348,
  [SMALL_STATE(102)] = 1355,
  [SMALL_STATE(103)] = 1362,
  [SMALL_STATE(104)] = 1369,
  [SMALL_STATE(105)] = 1376,
  [SMALL_STATE(106)] = 1383,
  [SMALL_STATE(107)] = 1390,
  [SMALL_STATE(108)] = 1395,
  [SMALL_STATE(109)] = 1400,
  [SMALL_STATE(110)] = 1405,
  [SMALL_STATE(111)] = 1412,
  [SMALL_STATE(112)] = 1417,
  [SMALL_STATE(113)] = 1424,
  [SMALL_STATE(114)] = 1431,
  [SMALL_STATE(115)] = 1436,
  [SMALL_STATE(116)] = 1443,
  [SMALL_STATE(117)] = 1447,
  [SMALL_STATE(118)] = 1451,
  [SMALL_STATE(119)] = 1455,
  [SMALL_STATE(120)] = 1459,
  [SMALL_STATE(121)] = 1463,
  [SMALL_STATE(122)] = 1467,
  [SMALL_STATE(123)] = 1471,
  [SMALL_STATE(124)] = 1475,
  [SMALL_STATE(125)] = 1479,
  [SMALL_STATE(126)] = 1483,
  [SMALL_STATE(127)] = 1487,
  [SMALL_STATE(128)] = 1491,
  [SMALL_STATE(129)] = 1495,
  [SMALL_STATE(130)] = 1499,
  [SMALL_STATE(131)] = 1503,
  [SMALL_STATE(132)] = 1507,
  [SMALL_STATE(133)] = 1511,
  [SMALL_STATE(134)] = 1515,
  [SMALL_STATE(135)] = 1519,
  [SMALL_STATE(136)] = 1523,
  [SMALL_STATE(137)] = 1527,
  [SMALL_STATE(138)] = 1531,
  [SMALL_STATE(139)] = 1535,
  [SMALL_STATE(140)] = 1539,
  [SMALL_STATE(141)] = 1543,
  [SMALL_STATE(142)] = 1547,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__cmd_expr, 1),
  [11] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__cmd_expr, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 4),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(10),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(36),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(9),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 6),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 3),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_invocation, 4),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [136] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(114),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_cmd_invocation, 3),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 4),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 3),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [161] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 1),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 7),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 3),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 7),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range, 3, .production_id = 6),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [191] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(136),
  [194] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(47),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 5),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 4),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 2),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 5),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_path, 1),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 1),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_default_parameter_assignment, 2),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 4),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 5),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 3),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [241] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(64),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2), SHIFT_REPEAT(77),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2),
  [257] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(85),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 1, .production_id = 3),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 1),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 1),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 2),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 2, .production_id = 5),
  [288] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 2, .production_id = 5), SHIFT_REPEAT(84),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 4),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 3),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_args_repeat1, 2, .production_id = 3),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_args, 3, .production_id = 4),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_args, 2),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 3),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 2),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [367] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
