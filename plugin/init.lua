vim.filetype.add({ extension = { nu = "nu" }, filename = { ["nurfile"] = "nu" } })

vim.api.nvim_create_autocmd("FileType", {
	pattern = "nu",
	callback = function(event)
		vim.bo[event.buf].commentstring = "# %s"
	end,
})
