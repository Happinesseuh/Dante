/*
** EPITECH PROJECT, 2021
** dante
** File description:
** algo
*/

#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"

static const coord_t directions[] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

void hunt(char **maze, coord_t *pos, coord_t dim, int *nb_node)
{
    coord_t new_pos = {gen_rand_coord(dim.x), gen_rand_coord(dim.y)};
    coord_t dir = directions[rand() % 4];

    while (maze[new_pos.y][new_pos.x] == '*' ||
        get_empty_adjacent(maze, new_pos, dim) == 4
    )
        new_pos = (coord_t) {gen_rand_coord(dim.x), gen_rand_coord(dim.y)};
    *pos = new_pos;
    while (!is_in_bound((coord_t){
            new_pos.x + dir.x * 2,
            new_pos.y + dir.y * 2
        }, dim) ||
        maze[new_pos.y + dir.y * 2][new_pos.x + dir.x * 2] != '*'
    )
        dir = directions[rand() % 4];
    maze[pos->y + dir.y][pos->x + dir.x] = '*';
    maze[pos->y][pos->x] = '*';
    *nb_node -= 1;
}

void kill(char **maze, coord_t *pos, coord_t dim, int *nb_node)
{
    coord_t dir = {0, 0};

    while (get_adjacent(maze, *pos, dim) != 4) {
        dir = directions[rand() % 4];
        while (is_way(maze, (coord_t){
                pos->x + dir.x * 2,
                pos->y + dir.y * 2
        }, dim))
            dir = directions[rand() % 4];
        *pos = (coord_t) {pos->x + dir.x, pos->y + dir.y};
        maze[pos->y][pos->x] = '*';
        *pos = (coord_t) {pos->x + dir.x, pos->y + dir.y};
        maze[pos->y][pos->x] = '*';
        *nb_node -= 1;
    }
}

void gen_maze(char **maze, int row, int col)
{
    coord_t curr_pos = {gen_rand_coord(col), gen_rand_coord(row)};
    coord_t dim = {col, row};
    int nb_node = (col / 2 + (col % 2)) * (row / 2 + (row % 2));

    maze[curr_pos.y][curr_pos.x] = '*';
    nb_node -= 1;

    kill(maze, &curr_pos, dim, &nb_node);
    while (nb_node > 0) {
        hunt(maze, &curr_pos, dim, &nb_node);
        kill(maze, &curr_pos, dim, &nb_node);
    }
    maze[row - 1][col - 1] = '*';
    maze[row - 2][col - 1] = '*';
    maze[row - 1][col - 2] = '*';
}