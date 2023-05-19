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
    | default ($env.HOME | path join ".local" "share")
    | path join "nvim" "lazy" "nvim-treesitter" "queries" "nu"
)

let file = "highlights.scm"

mkdir $local
http get ([$remote $file] | str join "/") | save --force ($local | path join $file)
```

[tree-sitter]: https://tree-sitter.github.io/tree-sitter/
[nvim-treesitter]: https://github.com/nvim-treesitter/nvim-treesitter
[nvim-treesitter/playground]: https://github.com/nvim-treesitter/playground
[nushell]: https://github.com/nushell/nushell
[highlights queries]: https://tree-sitter.github.io/tree-sitter/syntax-highlighting#highlights
