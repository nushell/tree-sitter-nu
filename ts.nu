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
    # check for test title surroundings on previous and next line
    | where $it.1 =~ "=+$" and $it.2 =~ "=+$"
    | each {|g| $g.0}
}

def list-tests-in-dir [dir: path] {
    cd $dir
    | ls
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
    list-tests-in-dir ./corpus | sort
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

# Regenerates tree-sitter bindings and generated manifests
export def "ts regen" [] {
    # remove all top level files as defined below:
    # https://github.com/tree-sitter/tree-sitter/blob/v0.25.9/docs/src/cli/init.md#binding-files
    (
      rm --force
        CMakeLists.txt
        Cargo.toml
        Makefile
        Package.swift
        binding.gyp
        go.mod
        pyproject.toml
        setup.py
    )
    rm -rf bindings/
    tree-sitter init --update
    return
}
