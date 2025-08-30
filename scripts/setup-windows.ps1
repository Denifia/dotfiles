# Setup script for dotfiles on Windows
# This script sets up a bare git repository and creates necessary symlinks

Write-Host "Setting up dotfiles on Windows..." -ForegroundColor Green

# Function to create alias (temporary for this session)
function Set-GitAlias {
    Set-Alias -Name cgit -Value "git --git-dir=$HOME\.cfg\ --work-tree=$HOME" -Scope Global
}

try {
    # Set up temporary alias
    Set-GitAlias
    
    # Clone the repo (does not pull down tracked files)
    Write-Host "Cloning dotfiles repository..." -ForegroundColor Yellow
    if (Test-Path "$HOME\.cfg") {
        Write-Host "Directory $HOME\.cfg already exists. Please remove it first or backup your existing dotfiles." -ForegroundColor Red
        exit 1
    }
    & git --git-dir="$HOME\.cfg\" --work-tree="$HOME" clone --bare https://github.com/denifia/dotfiles "$HOME\.cfg"
    
    # Checkout the main branch (pulls down tracked files)
    Write-Host "Checking out dotfiles..." -ForegroundColor Yellow
    & git --git-dir="$HOME\.cfg\" --work-tree="$HOME" checkout
    
    # Make git ignore untracked files
    Write-Host "Configuring git to ignore untracked files..." -ForegroundColor Yellow
    & git --git-dir="$HOME\.cfg\" --work-tree="$HOME" config --local status.showUntrackedFiles no
    
    Write-Host ""
    Write-Host "Setting up Windows-specific symlinks..." -ForegroundColor Yellow
    
    # Create symlinks for apps that use %localappdata% instead of ~/.config
    
    # Neovim symlink
    $nvimTarget = "$HOME\.config\nvim"
    $nvimLink = "$HOME\AppData\Local\nvim"
    if (Test-Path $nvimTarget) {
        if (!(Test-Path $nvimLink)) {
            New-Item -Path $nvimLink -ItemType SymbolicLink -Value $nvimTarget -Force
            Write-Host "✅ Created Neovim symlink" -ForegroundColor Green
        } else {
            Write-Host "⚠️  Neovim symlink already exists" -ForegroundColor Yellow
        }
    }
    
    # Oh-my-posh symlink
    $poshTarget = "$HOME\.config\ohmyposh"
    $poshLink = "$HOME\AppData\Local\oh-my-posh"
    if (Test-Path $poshTarget) {
        if (!(Test-Path $poshLink)) {
            New-Item -Path $poshLink -ItemType SymbolicLink -Value $poshTarget -Force
            Write-Host "✅ Created Oh-my-posh symlink" -ForegroundColor Green
        } else {
            Write-Host "⚠️  Oh-my-posh symlink already exists" -ForegroundColor Yellow
        }
    }
    
    Write-Host ""
    Write-Host "✅ Dotfiles setup complete!" -ForegroundColor Green
    Write-Host ""
    Write-Host "You can now use git commands to manage your dotfiles:" -ForegroundColor Cyan
    Write-Host "  git --git-dir=`$HOME\.cfg\ --work-tree=`$HOME status" -ForegroundColor White
    Write-Host "  git --git-dir=`$HOME\.cfg\ --work-tree=`$HOME add <file>" -ForegroundColor White
    Write-Host "  git --git-dir=`$HOME\.cfg\ --work-tree=`$HOME commit -m 'message'" -ForegroundColor White
    Write-Host "  git --git-dir=`$HOME\.cfg\ --work-tree=`$HOME push" -ForegroundColor White
    Write-Host ""
    Write-Host "Or add this alias to your PowerShell profile for easier access:" -ForegroundColor Cyan
    Write-Host "  function cgit { git --git-dir=`$HOME\.cfg\ --work-tree=`$HOME @args }" -ForegroundColor White
    
} catch {
    Write-Host "❌ Error during setup: $($_.Exception.Message)" -ForegroundColor Red
    exit 1
}