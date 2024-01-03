vim.filetype.add({ extension = { nu = "nu" } })

vim.api.nvim_create_autocmd("FileType", {
  pattern = "nu",
  callback = function(event) vim.bo[event.buf].commentstring = "# %s" end,
})

require("nvim-treesitter.parsers").get_parser_configs().nu = {
  install_info = {
    url = "https://github.com/aserowy/tree-sitter-nu",
    files = { "src/parser.c" },
    branch = "main",
  },
  filetype = "nu",
}
