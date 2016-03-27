##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Mar 27 01:44:24 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	libmy.a

CREATE		=	ar rc

SRCS		=

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
ECHO		=	/bin/echo -e

RUN		=	ranlib

CFLAGS		+=	-W -Wall -Werror -Wextra -ansi -pedantic

CREATE		=	ar rc


## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) "Compiled with" "$(CFLAGS)"
		@$(ECHO) $(BLUE)LIB$(RED)MY $(GREEN)BY UBERTI_L$(DEFAULT)

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
