return {
  -- https://github.com/tris203/hawtkeys.nvim
  'tris203/hawtkeys.nvim',
  enabled = true,
  dependencies = {
    'nvim-lua/plenary.nvim',
    'nvim-treesitter/nvim-treesitter',
  },
  config = {
    -- an empty table will work for default config
    --- if you use functions, or whichkey, or lazy to map keys
    --- then please see the API below for options
    keyboardLayout = 'colemak',
    customMaps = {
      -- If you use whichkey.register with an alias eg wk.register
      ['wk.register'] = {
        method = 'which_key',
      },
      -- If you use lazy.nvim's keys property to configure keymaps in your plugins
      ['lazy'] = {
        method = 'lazy',
      },
    },
  },
}
