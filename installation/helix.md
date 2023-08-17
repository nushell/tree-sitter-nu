Helix has built-in support for tree-sitter grammars and installations from
most sources have grammars for common languages (including nu!) built in.

### Using built-in helix grammars
Version from master branch of helix or any release after (not including) 23.05
will have this grammar and queries preinstalled. Hovewer due to rapid
development pace of nushell they might be severly out of date.

### Installing up to date grammar from this repo
Following [official guide](https://docs.helix-editor.com/languages.html#tree-sitter-grammar-configuration)
grammar may be updated to track specific revision (or main branch) of this 
repo. In file `languages.toml` add
```toml
[[grammar]]
name = "nu"
source = { git = "https://github.com/nushell/tree-sitter-nu", rev = "<revision hash or main>" }
```

Then downaload and install up-to-date grammar:
```nu
hx -g fetch
hx -g build
```

These actions only install grammar. Queries are handled
[separately](https://docs.helix-editor.com/guides/adding_languages.html#queries).
To install queries copy them from `queries` directory of this repo to
`runtime/queries/nu` in [configuration directory](https://docs.helix-editor.com/configuration.html)
of helix (i.e. `~/.config/helix/runtime/queries/nu` on Linux and Mac,
`%AppData%\helix\runtime\queries\nu` on windows).

> **Warning**  
> In helix there are several configuration (and thus `runtime`)
> [directories](https://docs.helix-editor.com/install.html#configuring-helixs-runtime-files).
> One of them is located in the directory with installation of binary and
> contains queries shipped with pre-built binary. For example when installing
> on windows with scoop it will be located in `~\scoop\apps\helix\current\runtime\`
> 
> Before commit [1077630](https://github.com/helix-editor/helix/commit/107763083405868f3679d8e12476ed0688896f87)
> helix used [different grammar](https://github.com/LhKipp/tree-sitter-nu)
> which is incompatible with this one and contained some additional queries.
> These queries will not work correctly with new grammar and helix will error
> not applying correct queries either.
>
> To fix this issue users that are running helix versions 23.05 or older
> and in generally any users installing queries manually are advised to remove
> contents of `<helix install dir>/runtime/queries/nu`.
