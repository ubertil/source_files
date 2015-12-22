## -----------------------------------------------------------------------------
## --Jason Brillante "Damdoshi" 2015------- ---   -   --- ---- --  --   - --- --
## ---------------------------------------- ---- --- - -- --- - - - -- --  -- --
## ---------------------------------------- ---- --- - -- --- - - - -- --  -- --
## -----|\-//------------------------------ ---- ---   -- --- - -  --- -- - - --
## -----||//___---------------------------- ---- --- - -- ---   - ---- -- - - --
## ----O  /    \--------------------------- ---- --- - -- --- - - ---- -- --  --
## ---<________/---------------------------   -   -   ---   - - - ---   - --- --
## -----------------------------------------------------------------------------

LIBNAME		=	lapin
NAME		=	lib$(LIBNAME).a
ERRLOG		=	errors~

CC		=	g++
FLAGS		=	-W -Wall -Werror -fPIC -std=gnu++03 -D_GLIBCXX_USE_CXX11_ABI=0 -fnothrow-opt -O2
ECHO		=	/bin/echo -e

DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

INC		=	-I./include/ -I/home/${USER}/.froot/include/
DEPS		=	$(wildcard ./deps/*/*.cpp)
MAIN		=	$(wildcard ./src/*.cpp)
SRC		=	$(DEPS) $(MAIN)
OBJ		=	$(SRC:.cpp=.o)
XOBJ		=	$(XSRC:.cpp=.o)

#all:		title erase $(NAME) anim
all:		title erase $(NAME)
all-quiet:	$(NAME)
title:
		@$(ECHO) $(GREEN)LIB$(TEAL)LAPIN$(DEFAULT)
erase:
		@rm -f $(ERRLOG)
clean:		erase
		@rm -f $(OBJ) $(XOBJ)
fclean:		clean
		@rm -f $(NAME) $(XNAME)
re:		fclean all
anim:
		@./bunny.sh

## Compile ---------------------------------------------------------------------
$(NAME):	$(OBJ)
		@ar r $(NAME) $(OBJ) 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[AR]" $(TEAL) $(NAME) $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)
		@ranlib $(NAME) && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)
.cpp.o:
		@$(CC) $(INC) $(FLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OKI]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

## Install ---------------------------------------------------------------------
install:
		@cp -f ./include/$(LIBNAME).h /usr/local/include/
		@cp -f ./include/$(LIBNAME)_enum.h /usr/local/include/
		@cp -f $(NAME) /usr/local/lib/
