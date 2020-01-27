##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	../lib_arcade_pacman.so

SRC		=	src/Pacman.cpp		\
			src/PersonagePacman.cpp \
			src/Enemy.cpp \
			src/Food.cpp \
			src/Energy.cpp \
			src/TeleportationPortal.cpp \
			../common/src/Wall.cpp	\
			../common/src/Personage.cpp	\
			../common/src/ElementGame.cpp	\
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

re:	 		fclean all
