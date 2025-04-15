return {
  -- https://github.com/nvim-treesitter/nvim-treesitter-textobjects
  -- Understands language syntax to improve movtions, etc
  'nvim-treesitter/nvim-treesitter-textobjects',
  enabled = true,
  dependencies = { 'nvim-treesitter/nvim-treesitter' },
  init = function()
    local config = require 'nvim-treesitter.configs'
    config.setup {
      textobjects = {
        select = {
          enable = true,

          -- Auto jump forward like other textobjects
          lookahead = true,

          keymaps = {
            ['if'] = '@function.inner',
            ['af'] = { query = '@function.outer', desc = 'Select [a]round [f]unction' },
            ['ac'] = { query = '@class.outer', desc = 'Select [a]round [c]lass' },
            ['ic'] = '@class.inner',
          },
        },
        move = {
          enable = true,
          set_jumps = true, -- whether to set jumps in the jumplist
          goto_next_start = {
            [']m'] = { query = '@function.outer', desc = 'Next function start' },
            [']]'] = { query = '@class.outer', desc = 'Next class start' },
          },
          goto_next_end = {
            [']M'] = '@function.outer',
            [']['] = '@class.outer',
          },
          goto_previous_start = {
            ['[m'] = '@function.outer',
            ['[['] = '@class.outer',
          },
          goto_previous_end = {
            ['[M'] = '@function.outer',
            ['[]'] = '@class.outer',
          },
        },
      },
    }
  end,
}
