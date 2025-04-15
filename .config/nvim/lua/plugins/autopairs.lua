return {
  -- https://github.com/windwp/nvim-autopairs
  -- Adds companion ]})"' when you use the matching symbol
  'windwp/nvim-autopairs',
  enabled = false,
  event = 'InsertEnter',
  -- Optional dependency
  dependencies = { 'hrsh7th/nvim-cmp' },
  config = function()
    require('nvim-autopairs').setup {}
    -- If you want to automatically add `(` after selecting a function or method
  end,
}
