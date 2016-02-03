##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Wed Feb  3 15:59:49 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	libmy.a

CREATE		=	ar rc

SRCS		=	$(wildcard ./src/*.c)

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW		=	"\033[01;33m"

ECHO		=	/bin/echo -e

LINE1		=	" _   _ ____  _____ ____ _____ ___     _\n"
LINE2		=	"| | | | __ )| ____|  _ |_   _|_ _|   | |\n"
LINE3		=	"| | | |  _ \|  _| | |_) || |  | |    | |\n"
LINE4		=	"| |_| | |_) | |___|  _ < | |  | |    | |___\n"
LINE5		=	" \___/|____/|_____|_| \_\|_| |___|   |_____|\n"
LINE6		=	"                               |_____|"

RUN		=	ranlib

CFLAGS		=	-W -Wall -Werror -Wextra -ansi -pedantic

CREATE		=	ar rc


## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)LIB$(RED)MY $(DEFAULT)
		@$(ECHO) $(GREEN)$(LINE1)$(LINE2)$(LINE3)$(LINE4)$(LINE5) \
		 $(LINE6) $(DEFAULT)

$(NAME):	$(OBJS)
		@$(CREATE) $(NAME) $(OBJS) 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[LIB]" $(BLUE) $(NAME) $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $(NAME)
		@ranlib $(NAME) && \
		 $(ECHO) $(GREEN) "[LIB]" $(BLUE) $(NAME) $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(RED) $(NAME)

.c.o:
		@$(CC) $(INC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all

.PHONY:		 fclean clean all re
