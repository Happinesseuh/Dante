/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-ines.maaroufi
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

enum terrain {
    EMPTY,
    WALL,
    START,
    WAY,
    END,
    PASSED
};

typedef struct maze_s {
    char **maze;
    int **visited;
    int row;
    int col;
    int start;
    int end_col;
    int end_row;
} maze_t;

/* PRINT MAZE */
void print_maze(char **maze);
void print_int_maze(maze_t *maze);
/* INIT_INT_MAZE */
void init_col_row(maze_t *maze);
void init_visited(maze_t *maze);
void border_map(maze_t *maze);
void add_way(maze_t *maze);
char *read_maze(char *path);
/* HANDLE MAZE */
char **my_str_to_word_array(char *str);
#endif /* !SOLVER_H_ */
