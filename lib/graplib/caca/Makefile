##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	lib_arcade_libcaca.so

SRC		=	src/InterfaceCaca.cpp \
			../../../src/Event.cpp

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++
CXXFLAGS	=	-I include -W -Wall -Werror -Wextra -fPIC
LDFLAGS		=	-L ./lib/ -shared -lcaca

RM		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re: fclean all
