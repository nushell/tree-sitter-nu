vim.filetype.add({ extension = { nu = "nu" }, filename = { ["nurfile"] = "nu" } })

vim.api.nvim_create_autocmd("FileType", {
  pattern = "nu",
  callback = function(event) vim.bo[event.buf].commentstring = "# %s" end,
})

require("nvim-treesitter.parsers").get_parser_configs().nu = {
  install_info = {
    url = "https://github.com/nushell/tree-sitter-nu",
  },
  filetype = "nu",
		files = { "src/parser.c", "src/scanner.c" },
}
