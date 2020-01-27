##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

all:
	make -C ./lib/
	make -C ./games/
	make -C ./src/

core:
	make -C ./src/

games:
	make -C ./games/

graphicals:
	make -C ./lib/

re:	fclean all

clean:
	make clean -C ./lib/
	make clean -C ./games/
	make clean -C ./src/

fclean:
	make fclean -C ./lib/
	make fclean -C ./games/
	make fclean -C ./src/

.PHONY:	 all clean fclean re games graphicals core