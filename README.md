# tree-sitter nu

[**WIP**] [nushell](https://github.com/nushell/nushell) grammar for [tree-sitter](https://tree-sitter.github.io/tree-sitter/)

# issues
1. unquoted strings

![treesitter-nu.readme.1.png](resources/treesitter-nu.readme.1.png)

2. blocks vs records
since we cannot backtrack, it is difficult to tell apart blocks and
records. so currently, blocks are not parsed as values

![treesitter-nu.readme.2.png](resources/treesitter-nu.readme.2.png)

3. cellpaths with numbers

![treesitter-nu.readme.3.png](resources/treesitter-nu.readme.3.png)

4. command arguments are parsed as strings

![treesitter-nu.readme.4.png](resources/treesitter-nu.readme.4.png)

here `2`, `-f`, `arg` will all be parsed as strings
