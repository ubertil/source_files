ulimit -c 0


export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:/usr/heimdal/sbin:/home/uberti_l/rendu/"

export EDITOR='emacs'
export HISTSIZE=1000
export MAIL="/u/all/${USER}/mail/${USER}"
export PAGER='more'
export PS1='\e[1;31m\u:\h : \e[1;34m'
export SAVEHIST=1000
export WATCH='all'
export LD_LIBRARY_PATH="/home/uberti_l/.froot/lib/"
export C_INCLUDE_PATH="/home/uberti_l/.froot/include/"
export CPLUS_INCLUDE_PATH="/home/uberti_l/.froot/include/"

alias ll='ls -l'
alias la='ls -la'
alias j='jobs'
alias emacs='emacs -nw'
alias ne='emacs'
alias ²='xlock -mod blank -geometry 1x1'
alias ns='ns_auth -v'
alias push='push_that.sh "$1"'
alias prepare='prepare_my_repo.sh'
alias wpa='wpa_gui'
alias unzip='unzip_my_tgz.sh'
alias clear='printf "\033c"'

if [ -f ${HOME}/.mybashrc ]
then
    . ${HOME}/.mybashrc
fi
