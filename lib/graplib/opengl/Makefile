##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	lib_arcade_opengl.so

SRC		=	src/InterfaceOpenGl.cpp	\
			../../../src/Event.cpp

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++
CXXFLAGS	=	-I include -W -Wall -Werror -Wextra -fPIC
LDFLAGS		=	-L ./lib/ -shared -lSDL -lGL -lGLU

RM		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re: fclean all
