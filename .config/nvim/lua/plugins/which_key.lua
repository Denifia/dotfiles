return {
  -- https://github.com/folke/which-key.nvim
  -- Shows keybindings in popup as you type
  'folke/which-key.nvim',
  enabled = true,
  event = 'VeryLazy',
  lazy = true,
  init = function()
    vim.o.timeout = true
    vim.o.timeoutlen = 300

    local presets = require 'which-key.plugins.presets'

    -- Disable all plugin presets, before calling `setup(opts)`.
    --
    -- This is done because I use my `colemak.nvim` plugin, where
    -- there are some mappings (e.g. `y` replacing `w`), which get a
    -- slight delay added to them. This would make sense with default
    -- Neovim mappings (i.e. it's OK for a 300ms pause after `y`),
    -- but with my altered mappings (navigating words with `y`
    -- instead), the delay becomes irritating. The setting of
    -- operators to `nil` is done to prevent all default
    -- configuration of these mappings.

    presets.operators = {
      preset = false,
      mode = { 'n', 'x' },
    }

    require('which-key').setup {
      ---@type false | "classic" | "modern" | "helix"
      preset = 'helix',
      spec = {},
      -- show a warning when issues were detected with your mappings
      notify = true,
      -- use nerd fonts for icons
      mappings = vim.g.have_nerd_font,
      -- change the up/down keys to CTRL-ArrowKeys
      keys = {
        scroll_down = '<c-down>', -- binding to scroll down inside the popup
        scroll_up = '<c-up>', -- binding to scroll up inside the popup
      },
      -- Enable/disable WhichKey for certain mapping modes
      triggers = {
        -- Default value. Will setup keymap triggers for every mode
        -- automatically and will trigger during `ModeChanged`.
        { '<auto>', mode = 'nixsotc' },

        -- Auto triggers will never be created for existing
        -- keymaps. That includes every valid single key Neovim
        -- builtin mapping. If you want to trigger on a builtin
        -- keymap, you have to add it manually. Example:
        -- { "a", mode = { "n", "v" } },
      },
      plugins = {
        -- shows a list of your marks on ' and `
        marks = true,
        -- shows your registers on " in NORMAL or <C-r> in INSERT mode
        registers = true,
        spelling = {
          -- enabling this will show WhichKey when pressing
          -- z= to select spelling suggestions
          --
          -- note: disabled, because this plugin is hard-coded to
          -- trigger on z=, which in my Colemak configuration
          -- should be b= instead.
          enabled = true,
          -- how many suggestions should be shown in the list?
          suggestions = 20,
        },
        -- the presets plugin, adds help for a bunch of default
        -- keybindings in Neovim. No actual key bindings are created
        --
        -- note: many of the following features are disabled due to
        -- them conflicting with my Colemak configuration, causing
        -- delays in input and help on the wrong (default) mappings.
        presets = {
          -- adds help for operators like d, y, ...
          operators = true,
          -- adds help for motions
          motions = true,
          -- help for text objects triggered after entering an operator
          text_objects = true,
          -- default bindings on <c-w>
          windows = true,
          -- misc bindings to work with windows
          nav = true,
          -- bindings for folds, spelling and others prefixed with z
          z = true,
          -- bindings for prefixed with g
          g = true,
        },
      },
    }

    local wk = require 'which-key'

    wk.add {
      {
        mode = { 'n' },
        { '<leader>c', group = 'Code' },
        { '<leader>s', group = 'Search (Telescope)' },
        { '<leader>w', group = 'Window' },
      },
      {
        mode = { 'v' },
      },
    }
  end,
}
