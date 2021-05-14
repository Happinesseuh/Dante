##
## EPITECH PROJECT, 2021
## B-CPE-200-PAR-2-1-dante-ines.maaroufi
## File description:
## Makefile
##

all:
	make -C ./solver
	make -C ./generator

clean:
		make -C ./solver clean
		make -C ./generator clean

fclean:
		make -C ./solver fclean
		make -C ./generator fclean

re:
	make -C ./solver re
	make -C ./generator re

.PHONY: all clean fclean re