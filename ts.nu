# | A bunch of commands for developing `tree-sitter-nu`
#
# # requirements
# - tree-sitter cli


# Generates a parser from the grammar
export def "ts gen" [] {   # -> nothing
    clear
    tree-sitter generate
}

# Performs highlighting on the specified file(s) and
# prints the highlighted result(s) to stdout
export def "ts hl" [       # -> string
    glob: string           # the file(s) to highlight
] {
    clear
    tree-sitter highlight $glob
}

# Runs all tests in the repo
export def "ts test" [] {  # -> string
    clear
    tree-sitter test
}

# Parses the specified file(s) and prints their ASTs to
# std-out
export def "ts parse" [    # -> string
    glob: string,          # the file(s) to parse
    --debug(-d),           # print debug info along with the AST
    --stat(-s),            # only print success stats instead of the AST
] {
    clear
    if $debug {
        tree-sitter parse $file -d
    } else if $stat {
        tree-sitter parse $file -sq
    } else {
        tree-sitter parse $file
    }
}
