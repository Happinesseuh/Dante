##
## EPITECH PROJECT, 2021
## project_name
## File description:
## Makefile
##

SRC	=	src/solver.c \
		src/my_str_to_word_array.c \
		src/print_maze.c \
		src/init_int_map.c \

OBJ_SRC	=	$(TEST_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

NAME_TEST	=	unit_tests

TEST_FLAGS	=	--coverage -lcriterion

CFLAGS	=	-Wextra -Wall -g3 -I./include

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

tests_fclean: tests_clean
	rm -f $(NAME_TEST)

tests_clean:
	rm -f *.gcno*
	rm -f *.gcda*

clean:
	rm -f $(OBJ)

fclean:	clean tests_fclean
	rm -f $(NAME)

tests_run:
	$(CC) -o unit_tests $(TESTS_SRC) $(TEST_FLAGS) $(CFLAGS)
	./unit_tests

re:	fclean all

.PHONY:	all tests_run clean fclean re