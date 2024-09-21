#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <stdbool.h>
#include <stdint.h>

#define advance lexer->advance(lexer, false)
#define eof lexer->eof(lexer)

enum TokenType {
    RAW_STRING_BEGIN,
    RAW_STRING_CONTENT,
    RAW_STRING_END,
    ERROR_SENTINEL,
};

typedef struct {
    uint8_t level;
    bool emitted_content;
} Scanner;

static uint8_t consume_chars(TSLexer *lexer, char c) {
    uint8_t count = 0;
    while (lexer->lookahead == c && !eof) {
        advance;
        ++count;
    }
    return count;
}

static uint32_t consume_until(TSLexer *lexer, char c) {
    uint32_t count = 0;
    while (lexer->lookahead != c && !eof) {
        advance;
        count++;
    }
    return count;
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
    Scanner *s = (Scanner *) payload;
    buffer[0] = s->level;
    buffer[1] = s->emitted_content;
    return 2;
}


void tree_sitter_nu_external_scanner_deserialize(
    void *payload,
    const char *buffer,
    unsigned length
) {
    Scanner *s = (Scanner *) payload;
    s->level = 0;
    s->emitted_content = false;
    if (length == 2) {
        s->level = buffer[0];
        s->emitted_content = buffer[1];
    }
}

static bool scan_raw_string_begin(TSLexer *lexer, Scanner *s) {
    lexer->log(lexer, "BEGIN\n");
    // scan for r#' r##' or more #
    if (lexer->lookahead == 'r') {
        lexer->log(lexer, "Detected 'r'.\n");
        advance;
        uint8_t level = consume_chars(lexer, '#');
        lexer->log(lexer, "num #: %i\n", level);
        if (lexer->lookahead == '\'') {
            advance;
            lexer->log(lexer, "Detected level: %i\n", level);
            s->level = level;
            return true;
        }
    }
    return false;
}

static bool scan_raw_string_content(TSLexer *lexer, Scanner *s) {
    uint32_t len = 0;
    lexer->log(lexer, "CONTENT\n");
    while (!eof) {
        uint32_t num = consume_until(lexer, '\'');
        if (num != 0) {
            lexer->log(lexer, "Set mark\n");
        }
        len += num;
        lexer->mark_end(lexer);
        advance;
        uint8_t level = consume_chars(lexer, '#');
        lexer->log(lexer, "Consumed [%i] #\n", level);
        if (level == s->level && len != 0) {
            lexer->log(lexer, "Detected end\n" );
            return true;
        } else if (level == s->level && len == 0) {
            return false;
        }
    }

    return false;
}

bool scan_raw_string_end(TSLexer *lexer, Scanner *s) {
    lexer->log(lexer, "END\n");
    while (!eof) {
        consume_until(lexer, '\'');
        advance;
        uint8_t level = consume_chars(lexer, '#');
        lexer->log(lexer, "Consumed [%i] #\n", level);
        if (level == s->level) {
            lexer->log(lexer, "Emitted end\n" );
            s->level = 0;
            s->emitted_content = false;
            return true;
        }
    }

    return false;
}

bool tree_sitter_nu_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    if (valid_symbols[ERROR_SENTINEL]) {
        return false;
    }

    Scanner *s = (Scanner *) payload;
    lexer->log(lexer, "Nu Scanner: level [%i], emitted [%b]\n", s->level,
               s->emitted_content);

    if (valid_symbols[RAW_STRING_BEGIN] && s->level == 0) {
        lexer->result_symbol = RAW_STRING_BEGIN;
        return scan_raw_string_begin(lexer, s);
    }
    if (valid_symbols[RAW_STRING_CONTENT] && !s->emitted_content || s->level != 0) {
        lexer->result_symbol = RAW_STRING_CONTENT;
        return scan_raw_string_content(lexer, s);
    }

    if (valid_symbols[RAW_STRING_END] || s->level != 0
            || lexer->lookahead == '\'') {
        lexer->result_symbol = RAW_STRING_END;
        return scan_raw_string_end(lexer, s);
    }

    return false;
}
