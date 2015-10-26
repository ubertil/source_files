##
## Makefile for Makefile in /home/uberti_l/rendu/Piscine_C_evalexpr
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:25:02 2015 louis-emile uberti-ares
## Last update Mon Oct 26 10:08:33 2015 louis-emile uberti-ares
##

NAME	= eval_expr

SRCS	= is_expr_valid.c \
	  get_expr.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall

LIB	= -lmy -L./lib/my

RM	= rm -rf

CC	= cc

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
