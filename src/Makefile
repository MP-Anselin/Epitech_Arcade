##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##



NAME		=	../arcade

SRC		=	main.cpp	\
			Event.cpp	\
			Core.cpp

OBJ	=	$(SRC:.cpp=.o)

CXX		=	g++
CXXFLAGS	=	-W -Wall -Werror -Wextra -fPIC
LDFLAGS		=	-ldl

RM		=	rm -rf

all:			$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
test:		re
		g++ main.cpp -W -Wall -Werror -Wextra -ldl
		./a.out
re: fclean all
