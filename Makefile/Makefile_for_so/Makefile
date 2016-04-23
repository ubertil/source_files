##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Thu Apr 14 10:09:18 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	libmy.so

SRCS		=	my_putchar.c \

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC1		=	gcc -c -fPIC
CC2		=	gcc -shared

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

LINE1           =       " _   _ ____  _____ ____ _____ ___     _\n"
LINE2           =       "| | | | __ )| ____|  _ |_   _|_ _|   | |\n"
LINE3           =       "| | | |  _ \|  _| | |_) || |  | |    | |\n"
LINE4           =       "| |_| | |_) | |___|  _ < | |  | |    | |___\n"
LINE5           =       " \___/|____/|_____|_| \_\|_| |___|   |_____|\n"
LINE6           =       "                               |_____|"

CFLAGS		+=	-W -Wall -Werror -Wextra

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) "Compiled with" "$(CFLAGS)"
		@$(ECHO) $(GREEN)$(LINE1)$(LINE2)$(LINE3)$(LINE4)$(LINE5) \
		 $(LINE6) $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC2) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "[.SO BUILT]" $(DEFAULT)

.c.o:
		@$(CC1) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) *~
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re