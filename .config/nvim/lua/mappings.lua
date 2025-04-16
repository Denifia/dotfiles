-- [[ Key Mappings ]]

--[[
-- NOTE:
-- * My keyboard layout is Colemak
-- * CTRL mappings are case-insensitive
--]]

--[[
-- TODO:
-- * Write a helper function to set the key mappings
--]]

-- Up/down/left/right
vim.keymap.set({ 'n', 'x' }, 'h', 'h', { desc = 'Left (h)' })
vim.keymap.set({ 'n', 'x' }, 'n', 'j', { desc = 'Down (j)' })
vim.keymap.set({ 'n', 'x' }, 'N', 'J', { desc = '' })
vim.keymap.set({ 'n', 'x' }, 'e', 'k', { desc = 'Up (k)' })
vim.keymap.set({ 'n', 'x' }, 'E', 'K', { desc = '' })
vim.keymap.set({ 'n', 'x' }, 'i', 'l', { desc = 'Right (l)' })

-- Moving around
-- vim.keymap.set({ 'n', 'x' }, 'H', 'b', { desc = 'Word backwords (b)' })
-- vim.keymap.set({ 'n', 'x' }, 'I', 'w', { desc = 'Word forwards (w)' })
-- these aren't working :(
-- vim.keymap.set({ 'n', 'x' }, '<C-h>', '^', { desc = 'Start of line (^)' })
-- vim.keymap.set({ 'n', 'x' }, '<C-i>', '$', { desc = 'Start of line ($)' })

-- move <insert> to k from i
vim.keymap.set({ 'n', 'x' }, 'k', 'i', { desc = 'Put after (i)' })
vim.keymap.set({ 'n', 'x' }, 'K', 'I', { desc = 'Put before (I)' })

-- move "got to previous item" to CTRL-e from CTRL-p
vim.keymap.set('', '<C-e>', '<C-p>')

-- Disable arrow keys for navigation
vim.keymap.set('n', '<left>', '<cmd>echo "Use h to move!!"<CR>')
vim.keymap.set('n', '<right>', '<cmd>echo "Use l to move!!"<CR>')
vim.keymap.set('n', '<up>', '<cmd>echo "Use k to move!!"<CR>')
vim.keymap.set('n', '<down>', '<cmd>echo "Use j to move!!"<CR>')

-- Clear highlights on search when pressing <Esc> in normal mode
vim.keymap.set('n', '<Esc>', '<cmd>nohlsearch<CR>')

-- Diagnostic keymaps
vim.keymap.set('n', '<leader>q', vim.diagnostic.setloclist, { desc = 'Open diagnostic [Q]uickfix list' })

-- Exit terminal mode
vim.keymap.set('t', '<Esc><Esc>', '<C-\\><C-n>', { desc = 'Exit terminal mode' })

-- Open file explorer
vim.keymap.set('n', '-', '<CMD>Oil --float<CR>', { desc = 'Open parent directory' })

-- Repeat last / or ? search
vim.keymap.set('n', 'l', 'n', { desc = 'Repeat last / or ? search (forwards)' })
vim.keymap.set('n', 'L', 'N', { desc = 'Repeat last / or ? search (backwards)' })

-- Jump locations becomes CTRL-O (backwards) and CTRL-M (forwards)
vim.keymap.set('n', '<C-m>', '<C-i>', { desc = 'Move to newer jump location' })

-- Move window movements to colemak
vim.keymap.set('n', '<C-h>', '<C-w><C-h>', { desc = 'Move focus to the left window' })
vim.keymap.set('n', '<C-i>', '<C-w><C-l>', { desc = 'Move focus to the right window' })
vim.keymap.set('n', '<C-n>', '<C-w><C-j>', { desc = 'Move focus to the lower window' })
vim.keymap.set('n', '<C-e>', '<C-w><C-k>', { desc = 'Move focus to the upper window' })

-- Helpers
-- vim.keymap.set({ 'n' }, '<C-X>', '<cmd>.lua<CR>', { desc = 'Execute selected lua' })
-- vim.keymap.set({ 'v' }, '<C-X>', "<cmd>'<,'>lua<CR>", { desc = 'Execute selected lua' })

-- Code refactoring
-- [G]o [R]efactoring
-- - [R]eference
-- - re[N]ame
vim.keymap.set({ 'n', 'i' }, '<C-Space>', vim.lsp.buf.signature_help, { desc = 'Code hover information' })
vim.keymap.set('n', '<leader>rr', 'grr', { desc = 'Go to references' })
vim.keymap.set('n', '<leader>rn', 'grn', { desc = 'Rename' })
vim.keymap.set('n', '<leader>ri', 'gri', { desc = 'Go to implementation' })
vim.keymap.set('n', '<leader>rd', 'gd', { desc = 'Go to definition' })
vim.keymap.set('n', '<leader>rD', 'gD', { desc = 'Go to declaration' })
-- vim.keymap.del('n', '<leader>D')

-- temp
vim.keymap.set('n', '<leader>z', '<cmd>source %<CR>')
