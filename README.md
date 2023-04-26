# tree-sitter nu

[**WIP**] [nushell](https://github.com/nushell/nushell) grammar for [tree-sitter](https://tree-sitter.github.io/tree-sitter/)

# issues
1. unquoted strings
```nu
# this should parse as a pipeline with two elements
'nushell' | str contains n

# but it is parsed as two pipelines, with one ending
# at `contains`
'nushell' | str contains
n

# quoting the string solves it though
'nushell' | str contains 'n' # <- okay
```

2. blocks vs records
since we cannot backtrack, it is difficult to tell apart blocks and
records. so currently, blocks are not parsed as values
```nu
# this will not parse
ls | each { $in + 4 }

# however this parses
ls | each {|it| $it + 4 }
```

3. cellpaths with numbers
```nu
ls | $in.4 # does not parse
```

4. command arguments are parsed as strings
```nu
some-cmd 2 -f arg
```

here `2`, `-f`, `arg` will all be parsed as strings
