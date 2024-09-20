#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <stdbool.h>

enum TokenType {
    RAW_STRING_BEGIN,
    RAW_STRING_CONTENT,
    RAW_STRING_END,
};

typedef struct {
    uint8_t level;
    bool emitted_content;
} Scanner;

static uint8_t consume_chars(TSLexer *lexer, char c) {
  uint8_t count = 0;
  while (lexer->lookahead == c) {
    lexer->advance(lexer, false);
    ++count;
  }
  return count;
}

static void consume_until(TSLexer *lexer, char c) {
  while (lexer->lookahead != c) {
    lexer->advance(lexer, false);
  }
}

void *tree_sitter_nu_external_scanner_create(void) {
    Scanner *scanner = ts_malloc(sizeof(Scanner));
    scanner->level = 0;
    scanner->emitted_content = false;
    return scanner;
}


void tree_sitter_nu_external_scanner_destroy(void *payload) {
    ts_free(payload);
}


unsigned tree_sitter_nu_external_scanner_serialize(
    void *payload,
    char *buffer
) {
    buffer[0] = ((Scanner*) payload)->level;
    buffer[1] = ((Scanner*) payload)->emitted_content;
    return 2;
}


void tree_sitter_nu_external_scanner_deserialize(
    void *payload,
    const char *buffer,
    unsigned length
) {
    if (length > 0) {
        ((Scanner *)payload)->level = buffer[0];
        ((Scanner *)payload)->emitted_content = buffer[1];
    }
}

bool tree_sitter_nu_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *) payload;

    if (valid_symbols[RAW_STRING_BEGIN] && scanner->level == 0) {
        lexer->log(lexer, "raw_str could begin.\n");
        // scan for r#' r##' or more #
        if (lexer->lookahead == 'r') {
            lexer->log(lexer, "Detected 'r'.\n");
            lexer->advance(lexer, false);
            uint8_t level = consume_chars(lexer, '#');
            lexer->log(lexer, "num #: %i\n", level);
            if (lexer->lookahead == '\'') {
                lexer->advance(lexer, false);
                lexer->log(lexer, "Detected level: %i\n", level);
                scanner->level = level;
                lexer->result_symbol = RAW_STRING_BEGIN;
                return true;
            }
        }
    }

    if ((valid_symbols[RAW_STRING_CONTENT] || valid_symbols[RAW_STRING_END]) && scanner->level != 0) {
        lexer->log(lexer, "content or end\n");

        if (valid_symbols[RAW_STRING_CONTENT]
                && !scanner->emitted_content) {
            lexer->log(lexer, "Emitting content.\n");
            scanner->emitted_content = true;
            lexer->result_symbol = RAW_STRING_CONTENT;
            return true;
        }
        if (valid_symbols[RAW_STRING_END] ) {
            lexer->log(lexer, "Consuming until '.\n");
            consume_until(lexer, '\'');
            lexer->log(lexer, "Consumed until '.\n");
            lexer->advance(lexer, false);
            uint8_t level = consume_chars(lexer, '#');
            lexer->log(lexer, "Consumed %i #. Expecting %i #\n", level, scanner->level);
            if (level == scanner->level) {
                lexer->log(lexer, "Detected end\n");
                lexer->result_symbol = RAW_STRING_END;
                scanner->level = 0;
                scanner->emitted_content = false;
                return true;
            }
        }
    }

    return false;
}
