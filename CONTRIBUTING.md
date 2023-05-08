# contributing

Thank you for wanting to make `tree-sitter-nu` better. This document
will take you through how to setup and contribute to `tree-sitter-nu`

## requirements

- [`nushell`][001]
- [`tree-sitter cli`][002]

## organization
the most important sections of this repo and the ones which you will
interact with the most are:

- [grammar.js][101] -> this is the file where the parser rules are
written. to learn how to write rules, consider visiting the official
[tree-sitter docs][003] or check out the [tree-sitter github org][004]
for some implementations

- [queries/][102] -> this directory contains [queries][005] which, among
other things, help with syntax highlighting. to learn how to write queries,
consider [the official docs][005]

- [corpus/][103] -> this directory contains tests for the parser. the tests
roughly organized in directories with their nodes. add a file with a descriprive
name that should generally cover a node to the right folder and write the
tests using the [special test syntax][006]

## hacking
the [`ts.nu`][104] module wraps the [`tree-sitter cli`][002]. to use the module, run

```nu
> use ts.nu * 
```

- `ts gen`   -> wraps `tree-sitter generate`, use this after making changes
to the grammar to generate a new parser. 

- `ts test`  -> wraps `tree-sitter test`, use this to run all the tests. you
can optionally supply a string to only run the tests that contain it

```nu
> ts test     # run all the tests
> ts test let # run all tests that contain 'let'
```

- `ts parse` -> wraps `tree-sitter parse`, use this to parse a specific file
and print out its AST. 
  - pass `--debug` or `-d` to print the AST along with debug info
  - pass `--stat` or `-s` to only print a success or failure message

```nu
> ts parse ts.nu
```

- `ts hl`    -> wraps `tree-sitter highlight`, use this to syntax highlight
a file and print the results. this requires some setup in order to tell `tree-sitter`
what colors to apply to what node.

> **Note**
> You only have to do this once

```nu
# generate the config file
> ts config

# open the generated file in your favorite editor
> vim <path> 
```

a [`sample config file`][105] is provided to get you started.

```
> ts hl ts.nu
```

## using the parser from rust
1. the code is located at [`exanples/main.rs`][106]
2. run it with `cargo run --example main`

## tips
- A line in the grammar.js that begins with `$._blah` means that `blah` is anonymous and won't show up in the final syntax tree.
- Most of the grammar how-to is found [here](https://tree-sitter.github.io/tree-sitter/creating-parsers#the-grammar-dsl)


## getting help

if you need any help or have a question, ping me `(@1Kinoti)` on the
[official editor support channel on discord][007] and i will try and answer it

## further reading

- https://tree-sitter.github.io/tree-sitter/
- https://github.com/tree-sitter/tree-sitter/issues/418
- https://siraben.dev/2022/03/22/tree-sitter-linter.html
- https://derek.stride.host/posts/comprehensive-introduction-to-tree-sitter
- https://rfdonnelly.github.io/posts/using-tree-sitter-parsers-in-rust/
- https://deepsource.io/blog/lightweight-linting/
- https://github.com/DerekStride/tree-sitter-math

<!--External Links-->
[001]: https://github.com/nushell/nushell "nushell"
[002]: https://tree-sitter.github.io/tree-sitter/creating-parsers#installation "installation"
[003]: https://tree-sitter.github.io/tree-sitter/creating-parsers#writing-the-grammar "writing grammar"
[004]: https://github.com/tree-sitter "tree-sitter organization"
[005]: https://tree-sitter.github.io/tree-sitter/using-parsers#pattern-matching-with-queries "writing queries"
[006]: https://tree-sitter.github.io/tree-sitter/creating-parsers#command-test "writing tests"
[007]: https://discord.com/channels/601130461678272522/1066353495638278194 "editor support channel"

<!--Internal Links-->
[101]: ./grammar.js
[102]: ./queries/
[103]: ./corpus/
[104]: ./ts.nu
[105]: ./resources/sample-config.json
[106]: ./examples/main.rs
