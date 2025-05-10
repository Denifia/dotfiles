-- return {
--   -- https://github.com/folke/tokyonight.nvim
--   -- Blue-ish theme for neovim
--   'folke/tokyonight.nvim',
--   enabled = true,
--   lazy = false, -- make sure we load this during startup if it is your main colorscheme
--   priority = 1000, -- make sure to load this before all the other start plugins
--   config = function()
--     -- load the colorscheme here
--     vim.cmd [[colorscheme tokyonight]]
--   end,
-- }

return {
  'catppuccin/nvim',
  name = 'catppuccin',
  priority = 1000,
  config = function()
    vim.cmd.colorscheme 'catppuccin-frappe'
  end,
}
