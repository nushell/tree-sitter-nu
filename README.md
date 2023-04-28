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

## installation guide
### for *neovim* users
> **Warning**  
> This is probably more hands-on than many people will like, but I think that's
> just the state of things at the moment. There are superficially easier
> solutions, but I suspect you might be frustrated by outdated grammars
> resulting in wonky highlights.
>
> The instructions below will at least allow you to maintain your own highlights
> queries for things which you care about. This might result in better
> worst-case highlighting, which is my personal preference.

The ability to add syntax highlighting can be provided by [tree-sitter] using
[nvim-treesitter]  (please refer to its own installation instructions).

```lua
local parser_config = require("nvim-treesitter.parsers").get_parser_configs()

parser_config.nu = {
  install_info = {
    url = "https://github.com/nushell/tree-sitter-nu",
    files = { "src/parser.c" },
    branch = "main",
  },
  filetype = "nu",
}
```

Run `:TSInstall nu` in neovim to install the above parser.

> **Note**  
> To get an overview of how [tree-sitter] is parsing [nushell] code, I recommend
> poking around with [nvim-treesitter/playground].

With [tree-sitter] available, you can now add [highlights queries] to associate
highlight groups with tree-sitter nodes. Run `:highlight` in neovim for a list
of highlight groups.

If you are using the `lazy` package manager for *neovim*, you can run the
following snippet to install the hightlights file and enable the highlighting:
```nushell
let remote = "https://raw.githubusercontent.com/nushell/tree-sitter-nu/main/queries/"
let local = (
    $env.XDG_DATA_HOME?
    | default ($env.HOME | path join ".local" "state")
    | path join "nvim" "lazy" "nvim-treesitter" "queries" "nu"
)

let file = "highlights.scm"

mkdir $local
http get ([$remote $file] | str join "/") | save ($local | path join $file)
```

[tree-sitter]: https://tree-sitter.github.io/tree-sitter/
[nvim-treesitter]: https://github.com/nvim-treesitter/nvim-treesitter
[nvim-treesitter/playground]: https://github.com/nvim-treesitter/playground
[nushell]: https://github.com/nushell/nushell
[highlights queries]: https://tree-sitter.github.io/tree-sitter/syntax-highlighting#highlights
