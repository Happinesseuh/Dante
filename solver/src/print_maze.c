/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-ines.maaroufi
** File description:
** print_maze
*/

#include "solver.h"

void print_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        printf("%s%s", maze[i], (maze[i + 1] ? "\n" : ""));
}

void print_int_maze(maze_t *maze)
{
    for (int i = 0; i < maze->row + 2; i++) {
        for (int j = 0; j < maze->col + 2; j++) {
            printf("%d", maze->visited[i][j]);
        }
        printf("\n");
    }
}