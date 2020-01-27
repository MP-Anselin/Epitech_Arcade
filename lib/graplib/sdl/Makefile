##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	lib_arcade_sdl.so

SRC		=	src/InterfaceSDL.cpp \
			../../../src/Event.cpp

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++
CXXFLAGS	=	-I include -W -Wall -Werror -Wextra -fPIC
LDFLAGS		=	-L ./lib/ -shared -lSDL

RM		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re: fclean all
