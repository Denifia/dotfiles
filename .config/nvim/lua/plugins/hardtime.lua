return {
  -- https://github.com/m4xshen/hardtime.nvim
  -- Reinforces good neovim motions/behaviours
  'm4xshen/hardtime.nvim',
  dependencies = { 'MunifTanjim/nui.nvim' },
  opts = {
    restricted_keys = {
      ['h'] = { 'n', 'x' },
      ['n'] = { 'n', 'x' },
      ['e'] = { 'n', 'x' },
      ['i'] = { 'n', 'x' },

      -- jump down to the first non-whitespace character
      ['+'] = { 'n', 'x' },
      -- ['gj'] = { 'n', 'x' },
      -- ['gk'] = { 'n', 'x' },
      -- ['<C-M>'] = { 'n', 'x' },
      -- ['<C-N>'] = { 'n', 'x' },
      -- ['<C-P>'] = { 'n', 'x' },
    },
  },
}
