##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Mon Apr 25 14:43:06 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	a.out

SRCS		=	srcs/main.cpp \

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -f

CC		=	g++

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI"

CXXFLAGS	+=	-W -Wall -Werror -Wextra -I./include -std=c++17

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CXXFLAGS)" $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "["$(NAME)" COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re