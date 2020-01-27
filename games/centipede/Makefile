##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	../lib_arcade_centipede.so

SRC		=	src/Centipede.cpp		\
			src/Ship.cpp			\
			src/Mushroom.cpp		\
			src/Missile.cpp			\
			src/Millipede.cpp		\
			src/Bomber.cpp			\
			src/Paw.cpp			\
			src/Spider.cpp			\
			../common/src/Wall.cpp		\
			../common/src/Personage.cpp 	\
			../common/src/ElementGame.cpp 	\
			../../src/Event.cpp

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++
CXXFLAGS	=	-W -Wall -Werror -Wextra -fPIC -I include
LDFLAGS		=	-L ./lib/ -shared

RM		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re: fclean all
