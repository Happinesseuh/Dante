##
## EPITECH PROJECT, 2021
## B-CPE-200-PAR-2-1-dante-ines.maaroufi
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./$(INCLUDE_DIR)

SRC_DIR	=	sources

INCLUDE_DIR	=	include

SRC_FILES	=	algo_maze	\
				algo_tools	\

SRC	=	${addprefix $(SRC_DIR)/, ${addsuffix .c, $(SRC_FILES)}}

SRC	+= main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re