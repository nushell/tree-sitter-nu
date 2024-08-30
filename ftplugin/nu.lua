local bufnr = vim.api.nvim_get_current_buf()
vim.bo[bufnr].commentstring = "# %s"
