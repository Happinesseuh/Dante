/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-ines.maaroufi
** File description:
** init_int_map
*/

#include "solver.h"

void init_col_row(maze_t *maze)
{
    int i = 0;
    int j = 0;

    for (; maze->maze[i] != NULL; i++);
    maze->row = i;
    for (; maze->maze[0][j] != '\0'; j++);
    maze->col = j;
}

void border_map(maze_t *maze)
{
    for (int i = 0; i < maze->col + 2; i++) {
        maze->visited[0][i] = 1;
        maze->visited[maze->row + 1][i] = 1;
    }
    for (int i = 0; i < maze->row + 2; i++) {
        maze->visited[i][0] = 1;
        maze->visited[i][maze->col + 1] = 1;
    }
}

void init_visited(maze_t *maze)
{
    int i = 0;

    maze->visited = malloc(sizeof(int *) * (maze->row + 2));
    for (int j = 0; j < (maze->row + 2); j++) {
        maze->visited[j] = malloc(sizeof(int) * (maze->col + 2));
    }
    border_map(maze);
    for (; i < maze->row; i++) {
        for (int j = 0; j < maze->col; j++) {
            if (maze->maze[i][j] == 'X') {
                maze->visited[i + 1][j + 1] = WALL;
            } else if (i == maze->row - 1 && j == maze->col - 1) {
                maze->visited[i + 1][j + 1] = END;
            } else {
                maze->visited[i + 1][j + 1] = EMPTY;
            }
        }
    }
}

void add_way(maze_t *maze)
{
    int i = 0;
    int j = 0;

    for (i = 1; i < maze->row + 1; i++) {
        for (j = 1; j < maze->col + 1; j++) {
            if (maze->visited[i][j] == WAY) {
                maze->maze[i - 1][j - 1] = 'o';
            }
            if (maze->visited[i][j] == END) {
                maze->maze[i - 1][j - 1] = 'o';
            }
        }
    }
}

char *read_maze(char *path)
{
    int fd = 0;
    struct stat stack;
    char *buffer = NULL;
    int len = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    if (stat(path, &stack))
        return (NULL);
    buffer = malloc(sizeof(char) * stack.st_size + 1);
    len = read(fd, buffer, stack.st_size + 1);
    if (len == -1)
        return (NULL);
    buffer[len] = '\0';
    return (buffer);
}