source ~/.profile
alias pogo='ping google.com'
alias blih='/Users/uberti_l/rendu/./blih.py'
alias clone='/Users/uberti_l/rendu/./clone'
alias prepare='/Users/uberti_l/rendu/./prepare_my_repo.sh'
alias push='/Users/uberti_l/rendu/./push_that.sh'
alias lapin='/Users/uberti_l/rendu/./lapin.sh'
alias ne='emacs -nw'
alias emacs='emacs -nw'
alias clear='printf "\033c"'
alias supervalgrind='valgrind --tool=memcheck --leak-check=yes'
alias ..='cd ..'
alias cd..='cd ..'
alias ngrok='./ngrok http 8080'
alias ls='ls -GFh'
alias python='python3'
alias la='ls -la'
alias ll='ls -l'
alias phantomjs='phantomjs --ssl-protocol=any --web-security=false'
alias rmds='sudo find / -name ".DS_Store" -depth -exec rm {} \;'
alias gdb='sudo gdb'
alias ldd='otool -L'
alias droit='/Users/uberti_l/rendu/./droit'

export LD_LIBRARY_PATH="/Users/uberti_l/.froot/lib/"
export C_INCLUDE_PATH="/Users/uberti_l/.froot/include/"
export CPLUS_INCLUDE_PATH="/Users/uberti_l/.froot/include/"
export PATH="/usr/local/bin:/usr/local/bin/sublime:/Library/Frameworks/Python.framework/Versions/3.5/bin:${PATH}/"
export PS1='\[\e[0;31m\][\A]\u@\h:\[\e[0m\e[0;32m\]\W\[\e[1;33m\]\[\e[0;37m\]\$\[\e[0m\] '
export EDITOR='emacs'
export CLICOLOR=1
export LSCOLORS=ExFxBxDxCxegedabagacad
export SHODAN_TEAM='leavemebe'
