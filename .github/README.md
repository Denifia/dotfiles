# Dotfiles

## New computer setup
<!-- instructions from https://www.atlassian.com/git/tutorials/dotfiles -->

```bash
# setup a temp alias to work with the bare repo
alias cgit='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'

# clone the repo (does not pull down tracked files)
cgit clone --bare https://github.com/denifia/dotfiles $HOME/.cfg

# checkout the main branch (pulls down tracked files)
cgit checkout

# make 'cgit status' ignore untracked files
cgit config --local status.showUntrackedFiles no
```

<!-- TODO: make the above into a install script -->

