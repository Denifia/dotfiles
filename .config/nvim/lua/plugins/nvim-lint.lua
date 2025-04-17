return {
	-- https://github.com/mfussenegger/nvim-lint
	-- Enable linting
	"mfussenegger/nvim-lint",
	config = function()
		require("lint").linters_by_ft = {
			markdown = { "alex", "write_good" },
		}
	end,
}
