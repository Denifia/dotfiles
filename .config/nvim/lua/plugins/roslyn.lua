return {
  -- https://github.com/seblyng/roslyn.nvim
  -- Dotnet LSP
  'seblyng/roslyn.nvim',
  enabled = true,
  ft = 'cs',
  ---@module 'roslyn.config'
  ---@type RoslynNvimConfig
  opts = {
    -- your configuration comes here; leave empty for default settings
    broad_search = true,
    lock_target = true,
  },
}
