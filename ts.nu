# | A bunch of commands for developing `tree-sitter-nu`
#
# # requirements
# - tree-sitter cli

def list-tests-in-file [file: path] {
    open --raw $file
    | to text
    | lines
    | do {|x|
        ($x | skip 1)       # target line
        | zip $x            # previous line of target line
        | zip ($x | skip 2) # next line of target line
    } $in
    | each {|group| $group | flatten}
    | filter {|g|
        # check for test title surroundings on previous and next line
        $g.1 =~ "=+$" and $g.2 =~ "=+$"
    }
    | each {|g| $g.0}
}

def list-tests-in-dir [dir: path] {
    ls $dir
    | each {|it|
        if $it.type == "dir" {
            list-tests-in-dir $it.name | flatten
        } else if $it.type == "file" {
            list-tests-in-file $it.name
        }
    }
    | flatten
}

def "completion ts test" [] {
    list-tests-in-dir ./corpus
}


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
export def "ts test" [    # -> string
    test_name?: string@"completion ts test"     # specific test name to run
] {
    clear
    if ($test_name == null) {
        tree-sitter test
    } else {
        tree-sitter test -f $test_name
    }
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
        tree-sitter parse $glob -d
    } else if $stat {
        tree-sitter parse $glob -sq
    } else {
        tree-sitter parse $glob
    }
}

# Generates a default config file and prints out its path
export def "ts config" [] {
    tree-sitter init-config
}
