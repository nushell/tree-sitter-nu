if vim.g.loaded_tree_sitter_nu then
  return
end
vim.g.loaded_tree_sitter_nu = true

pcall(function()
  require("nvim-treesitter.parsers").get_parser_configs().nu = {
    install_info = {
      url = "https://github.com/nushell/tree-sitter-nu",
      files = { "src/parser.c" },
      branch = "main",
    },
    filetype = "nu",
  }
end)
