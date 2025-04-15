return {
  -- https://github.com/ThePrimeagen/harpoon
  -- Provides quick access to a set of pinned/recent files
  'ThePrimeagen/harpoon',
  enabled = false,
  branch = 'harpoon2',
  dependencies = { 'nvim-lua/plenary.nvim' },
  config = function()
    local harpoon = require 'harpoon'
    harpoon:setup()

    vim.keymap.set('n', '<leader>a', function()
      harpoon:list():add()
    end, { desc = '[A]dd buffer to harpoon list' })

    vim.keymap.set('n', '<leader>e', function()
      harpoon.ui:toggle_quick_menu(harpoon:list())
    end, { desc = 'Toggle quick m[e]nu' })

    vim.keymap.set('n', '<leader><A-1>', function()
      harpoon:list():replace_at(1)
    end, { desc = 'Harpoon replace 1' })

    vim.keymap.set('n', '<leader>p1', function()
      harpoon:list():replace_at(1)
    end, { desc = 'Harpoon replace 1' })

    vim.keymap.set('n', '<A-1>', function()
      harpoon:list():select(1)
    end)

    vim.keymap.set('n', '<leader><A-2>', function()
      harpoon:list():replace_at(2)
    end, { desc = 'Harpoon replace 2' })

    vim.keymap.set('n', '<A-2>', function()
      harpoon:list():select(2)
    end)

    vim.keymap.set('n', '<leader><A-3>', function()
      harpoon:list():replace_at(3)
    end, {
      desc = 'Harpoon replace 3',
    })

    vim.keymap.set('n', '<A-3>', function()
      harpoon:list():select(3)
    end)

    vim.keymap.set('n', '<leader><A-4>', function()
      harpoon:list():replace_at(4)
    end, { desc = 'Harpoon replace 4' })

    vim.keymap.set('n', '<A-4>', function()
      harpoon:list():select(4)
    end)
  end,
}
