/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-ines.maaroufi
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

typedef struct coord_s
{
    int x;
    int y;
} coord_t;

void gen_maze(char **maze, int row, int col);

int gen_rand_coord(int lim);
bool is_in_bound(coord_t pos, coord_t dim);
int get_adjacent(char **maze, coord_t pos, coord_t dim);
int get_empty_adjacent(char **maze, coord_t pos, coord_t dim);
bool is_way(char **maze, coord_t pos, coord_t dim);

#endif /* !GENERATOR_H_ */
