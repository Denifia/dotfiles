#!/bin/bash

# Setup script for dotfiles on Linux/macOS
# This script sets up a bare git repository to manage dotfiles

set -e

echo "Setting up dotfiles using bare git repository..."

# Create temporary alias to work with the bare repo
alias cgit='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'

# Clone the repo (does not pull down tracked files)
echo "Cloning dotfiles repository..."
if [ -d "$HOME/.cfg" ]; then
    echo "Directory $HOME/.cfg already exists. Please remove it first or backup your existing dotfiles."
    exit 1
fi
cgit clone --bare https://github.com/denifia/dotfiles $HOME/.cfg

# Checkout the main branch (pulls down tracked files)
echo "Checking out dotfiles..."
cgit checkout

# Make 'cgit status' ignore untracked files
echo "Configuring git to ignore untracked files..."
cgit config --local status.showUntrackedFiles no

echo ""
echo "✅ Dotfiles setup complete!"
echo ""
echo "You can now use the 'cgit' command to manage your dotfiles:"
echo "  cgit status    - Check status of tracked files"
echo "  cgit add <file> - Add a file to be tracked"
echo "  cgit commit -m 'message' - Commit changes"
echo "  cgit push      - Push changes to GitHub"
echo ""
echo "Note: The 'cgit' alias is temporary. Add it to your shell config to make it permanent:"
echo "  alias cgit='/usr/bin/git --git-dir=\$HOME/.cfg/ --work-tree=\$HOME'"