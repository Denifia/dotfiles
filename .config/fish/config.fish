if status is-interactive
    # Commands to run in interactive sessions can go here
end

alias cd="z"

# Setup git bare repo for dotfiles
alias config='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'
alias cgit='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'


oh-my-posh init fish --config ~/.config/ohmyposh/config.json | source
zoxide init fish | source
