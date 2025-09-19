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
        # C/C++
        Makefile
        CMakeLists.txt
        bindings/c/tree_sitter/tree-sitter-language.h
        bindings/c/tree-sitter-language.pc
        # Go
        go.mod
        bindings/go/binding.go
        bindings/go/binding_test.go
        # Node
        binding.gyp
        package.json
        bindings/node/binding.cc
        bindings/node/index.js
        bindings/node/index.d.ts
        bindings/node/binding_test.js
        # Python
        pyproject.toml
        setup.py
        bindings/python/tree_sitter_language/binding.c
        bindings/python/tree_sitter_language/__init__.py
        bindings/python/tree_sitter_language/__init__.pyi
        bindings/python/tree_sitter_language/py.typed
        bindings/python/tests/test_binding.py

        # Rust
        Cargo.toml
        bindings/rust/lib.rs
        bindings/rust/build.rs
        # Swift
        Package.swift
        bindings/swift/TreeSitterLanguage/language.h
        bindings/swift/TreeSitterLanguageTests/TreeSitterLanguageTests.swift
    )
    tree-sitter init --update
    return
}
