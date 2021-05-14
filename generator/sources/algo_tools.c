/*
** EPITECH PROJECT, 2021
** dante
** File description:
** algo_tools
*/

#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"

int gen_rand_coord(int lim)
{
    int nb = rand() % lim;

    while (nb % 2)
        nb = rand() % lim;
    return nb;
}

bool is_in_bound(coord_t pos, coord_t dim)
{
    return pos.x >= 0 && pos.x < dim.x && pos.y >= 0 && pos.y < dim.y;
}

int get_adjacent(char **maze, coord_t pos, coord_t dim)
{
    return
        (!is_in_bound((coord_t){pos.x - 2, pos.y}, dim) ||
            maze[pos.y][pos.x - 2] == '*') +
        (!is_in_bound((coord_t){pos.x + 2, pos.y}, dim) ||
            maze[pos.y][pos.x + 2] == '*') +
        (!is_in_bound((coord_t){pos.x, pos.y - 2}, dim) ||
            maze[pos.y - 2][pos.x] == '*') +
        (!is_in_bound((coord_t){pos.x, pos.y + 2}, dim) ||
            maze[pos.y + 2][pos.x] == '*');
}

int get_empty_adjacent(char **maze, coord_t pos, coord_t dim)
{
    return
        (!is_in_bound((coord_t){pos.x - 2, pos.y}, dim) ||
            maze[pos.y][pos.x - 2] == 'X') +
        (!is_in_bound((coord_t){pos.x + 2, pos.y}, dim) ||
            maze[pos.y][pos.x + 2] == 'X') +
        (!is_in_bound((coord_t){pos.x, pos.y - 2}, dim) ||
            maze[pos.y - 2][pos.x] == 'X') +
        (!is_in_bound((coord_t){pos.x, pos.y + 2}, dim) ||
            maze[pos.y + 2][pos.x] == 'X');
}

bool is_way(char **maze, coord_t pos, coord_t dim)
{
    return !is_in_bound(pos, dim) || maze[pos.y][pos.x] == '*';
}
