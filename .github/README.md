# Denifia's Dotfiles

This repository contains my personal configuration files for various development tools and applications. It uses a bare git repository approach to manage dotfiles directly in the home directory.

## What's Included

- **Shell Configuration**: Fish shell with oh-my-posh prompt styling
- **Editor**: Neovim with Lua-based configuration and plugins
- **Git**: Global git configuration and aliases
- **Keyboard**: Custom keyboard layouts and mappings
  - Kanata configuration for advanced key remapping
  - QMK firmware configuration for custom keyboards

## Quick Setup

Choose your platform and run the appropriate setup script:

### Linux/macOS
```bash
curl -fsSL https://raw.githubusercontent.com/denifia/dotfiles/main/scripts/setup-unix.sh | bash
```

Or download and run manually:
```bash
wget https://raw.githubusercontent.com/denifia/dotfiles/main/scripts/setup-unix.sh
chmod +x setup-unix.sh
./setup-unix.sh
```

### Windows (PowerShell as Administrator)
```powershell
irm https://raw.githubusercontent.com/denifia/dotfiles/main/scripts/setup-windows.ps1 | iex
```

Or download and run manually:
```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/denifia/dotfiles/main/scripts/setup-windows.ps1" -OutFile "setup-windows.ps1"
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
.\setup-windows.ps1
```

## Managing Dotfiles

After setup, you can manage your dotfiles using the `cgit` command (or the full git command):

```bash
# Check status of tracked files
cgit status

# Add a new file to be tracked
cgit add ~/.config/newfile

# Commit changes
cgit commit -m "Update configuration"

# Push changes to GitHub
cgit push

# Pull latest changes
cgit pull
```

**Note**: The `cgit` alias needs to be added to your shell configuration permanently. It's already included in the fish config in this repo.

## Key Features

### Fish Shell
- Custom aliases and functions
- Integration with zoxide for smart directory jumping
- oh-my-posh for beautiful prompts

### Neovim
- Modern Lua-based configuration
- Telescope for fuzzy finding
- LSP support for development
- Custom keybindings and plugins

### Keyboard Configuration
- **Kanata**: Advanced key remapping for any keyboard
  - Run `sudo .keyboard/kanata/setup-kanata-hardened.sh` to install
  - Update config with `sudo .keyboard/kanata/update-kanata-hardened.sh`
- **QMK**: Custom firmware for supported keyboards
  - See `.keyboard/qmk/README.md` for build instructions

## Manual Installation (Advanced)

If you prefer to set up manually or understand what the scripts do:

1. **Create the bare repository:**
   ```bash
   git clone --bare https://github.com/denifia/dotfiles $HOME/.cfg
   ```

2. **Set up the alias:**
   ```bash
   alias cgit='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'
   ```

3. **Checkout the files:**
   ```bash
   cgit checkout
   ```

4. **Configure git to ignore untracked files:**
   ```bash
   cgit config --local status.showUntrackedFiles no
   ```

5. **Windows only - Create symlinks:**
   ```powershell
   # Neovim
   New-Item -Path ~\AppData\Local\nvim -ItemType SymbolicLink -Value ~\.config\nvim
   
   # Oh-my-posh
   New-Item -Path ~\AppData\Local\oh-my-posh -ItemType SymbolicLink -Value ~\.config\ohmyposh
   ```
