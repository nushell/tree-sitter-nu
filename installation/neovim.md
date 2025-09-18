# neovim

## Installation with a plugin manager, e.g. lazy.nvim

Extend your lazy config with treesitter and the nu parser.

```lua
{
    "nvim-treesitter/nvim-treesitter",
    config = function()
        require("nvim-treesitter.configs").setup {
            ensure_installed = { "nu" }, -- Ensure the "nu" parser is installed
            highlight = {
                enable = true,            -- Enable syntax highlighting
            },
            -- OPTIONAL!! These enable ts-specific textobjects.
            -- So you can hit `yaf` to copy the closest function,
            -- `dif` to clear the content of the closest function,
            -- or whatever keys you map to what query.
            textobjects = {
                select = {
                    enable = true,
                    keymaps = {
                        -- You can use the capture groups defined in textobjects.scm
                        -- For example:
                        -- Nushell only
                        ["aP"] = "@pipeline.outer",
                        ["iP"] = "@pipeline.inner",

                        -- supported in other languages as well
                        ["af"] = "@function.outer",
                        ["if"] = "@function.inner",
                        ["al"] = "@loop.outer",
                        ["il"] = "@loop.inner",
                        ["aC"] = "@conditional.outer",
                        ["iC"] = "@conditional.inner",
                        ["iS"] = "@statement.inner",
                        ["aS"] = "@statement.outer",
                    }, -- keymaps
                }, -- select
            }, -- textobjects
        }
    end,
    build = ":TSUpdate",
},
```

## Manual installation

> [!CAUTION]
>
> This repository is now tracked in [nvim-treesitter].
> Therefore, manual installation is not recommended for normal users.
>
> This section is for advanced users/parser developers to test different revs of the parser/query files.
> Here are the overall steps, each of which is described in the following sub sections with more details:
>
> 1. Override the `install_info` in the configuration of [nvim-treesitter].
> 2. Download the compatible query files.

### Override the install_info

Add something similar to the following snippet to the lua code above:

```lua
{
    -- from
    "nvim-treesitter/nvim-treesitter",
    config = function(_, opts)
      -- ...
      ---@type table<string, any>
      local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
      parser_config.nu = {
        install_info = {
          url = "https://github.com/nushell/tree-sitter-nu", -- local path or git repo
          files = { "src/parser.c", "src/scanner.c" }, -- note that some parsers also require src/scanner.c or src/scanner.cc
          branch = "main", -- default branch in case of git repo if different from master
          generate_requires_npm = false, -- if stand-alone parser without npm dependencies
          requires_generate_from_grammar = false, -- if folder contains pre-generated src/parser.c
        },
        filetype = "nu", -- if filetype does not match the parser name
      }
      vim.treesitter.language.register("nu", "nushell")
      require("nvim-treesitter.configs").setup(opts)
      -- ...
    end,
}
```

Restart neovim and run `:TSUpdate nu` to update the parser.

### Download the query files

This is for testing the query files maintained by this repo, which can be slightly different from those of [nvim-treesitter].

```nu
let remote = "https://raw.githubusercontent.com/nushell/tree-sitter-nu/main/queries/nu/"
let local = (
    $env.XDG_DATA_HOME?
    | default ($env.HOME | path join ".local" "share")
    | path join "nvim" "lazy" "nvim-treesitter" "queries" "nu"
)

let files = ["folds.scm" "highlights.scm" "indents.scm" "injections.scm" "textobjects.scm"]

mkdir $local
$files | par-each {|file| http get ([$remote $file] | str join "/") | save --force ($local | path join $file) }
```

> **Note**
> To get an overview of how [tree-sitter] is parsing [nushell] code, I recommend
> poking around with [nvim-treesitter/playground].

[tree-sitter]: https://tree-sitter.github.io/tree-sitter/
[nvim-treesitter]: https://github.com/nvim-treesitter/nvim-treesitter
[nvim-treesitter/playground]: https://github.com/nvim-treesitter/playground
[nushell]: https://github.com/nushell/nushell
