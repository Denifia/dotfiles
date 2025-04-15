return {
  'nvimdev/dashboard-nvim',
  enabled = true,
  event = 'VimEnter',
  config = function()
    require('dashboard').setup {
      shortcut_type = 'number',
      change_to_vcs_root = true,
      theme = 'hyper',
      config = {
        header = {},
        shortcut = {
          { desc = '󰊳 Update Lazy', group = '@property', action = 'Lazy update', key = 'u' },
          { desc = '󰊳 Update Mason', group = '@property', action = 'MasonUpdate', key = 'm' },
        },
        project = { enable = false },
        mru = { enable = true, limit = 10, cwd_only = false },
      },
    }
  end,
  dependencies = { { 'nvim-tree/nvim-web-devicons' } },
}
