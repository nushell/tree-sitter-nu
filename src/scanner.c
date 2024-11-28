#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include <wctype.h>

#define skip lexer->advance(lexer, true)
#define adv lexer->advance(lexer, false)
#define eof lexer->eof(lexer)

enum TokenType {
    RAW_STRING_BEGIN,
    RAW_STRING_CONTENT,
    RAW_STRING_END,
    ERROR_SENTINEL,
};

typedef struct {
    uint8_t level;
} Scanner;

static uint8_t consume_chars(TSLexer *lexer, char c) {
    uint8_t count = 0;
    while (lexer->lookahead == c && !eof) {
        adv;
        ++count;
    }
    return count;
}

static uint32_t consume_until(TSLexer *lexer, char c) {
    uint32_t count = 0;
    while (lexer->lookahead != c && !eof) {
        adv;
        count++;
    }
    return count;
}

static void skip_whitespace(TSLexer *lexer) {
    while (iswspace(lexer->lookahead) && !eof) {
        skip;
    }
}


void *tree_sitter_nu_external_scanner_create(void) {
    Scanner *scanner = ts_malloc(sizeof(Scanner));
    scanner->level = 0;
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
    return 1;
}


void tree_sitter_nu_external_scanner_deserialize(
    void *payload,
    const char *buffer,
    unsigned length
) {
    Scanner *s = (Scanner *) payload;
    s->level = 0;
    if (length == 1) {
        s->level = buffer[0];
    }
}

static bool scan_raw_string_begin(TSLexer *lexer, Scanner *s) {
    lexer->log(lexer, "BEGIN\n");
    // scan for r#' r##' or more #
    skip_whitespace(lexer);

    if (lexer->lookahead != 'r') {
        return false;
    }
    lexer->log(lexer, "Detected 'r'.\n");
    adv;
    uint8_t level = consume_chars(lexer, '#');
    lexer->log(lexer, "num #: %i\n", level);
    if (lexer->lookahead == '\'') {
        adv;
        lexer->log(lexer, "Detected level: %i\n", level);
        s->level = level;
        return true;
    }
    return false;
}

static bool scan_raw_string_content(TSLexer *lexer, Scanner *s) {
    uint32_t len = 0;
    lexer->log(lexer, "CONTENT\n");
    while (!eof) {
        uint32_t num = consume_until(lexer, '\'');
        lexer->log(lexer, "Set mark\n");
        lexer->mark_end(lexer);
        len += num;
        adv;
        uint8_t level = consume_chars(lexer, '#');
        lexer->log(lexer, "Consumed [%i] #\n", level);
        if (level == s->level) {
            lexer->log(lexer, "Detected end\n" );
            return true;
        }
    }

    return false;
}

static bool scan_raw_string_end(TSLexer *lexer, Scanner *s) {
    lexer->log(lexer, "END\n");
    // HINT: scan_raw_string_content already determines the content's length
    // so we only advance to the end of the delimiter and return true.
    adv;
    while (s->level > 0) {
        adv;
        s->level--;
    }
    return true;
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
    lexer->log(lexer, "Nu Scanner: level [%i]\n", s->level);

    if (valid_symbols[RAW_STRING_BEGIN] && s->level == 0) {
        lexer->result_symbol = RAW_STRING_BEGIN;
        return scan_raw_string_begin(lexer, s);
    }
    if (valid_symbols[RAW_STRING_CONTENT] && s->level != 0) {
        lexer->result_symbol = RAW_STRING_CONTENT;
        return scan_raw_string_content(lexer, s);
    }

    if (valid_symbols[RAW_STRING_END] && s->level != 0
            && lexer->lookahead == '\'') {
        lexer->result_symbol = RAW_STRING_END;
        return scan_raw_string_end(lexer, s);
    }

    return false;
}
