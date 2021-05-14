/*
** EPITECH PROJECT, 2021
** dante
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>

void gen_maze(char **maze, int row, int col);

void init_srand(void){
    int init_rand = 0;
    srand((unsigned long) &init_rand);
}

char **create_map(int row, int col, char c)
{
    char **map = malloc(sizeof(char *) * (row + 1));
    int i = 0;
    int j = 0;

    for (i = 0; i < row; ++i) {
        map[i] = malloc(sizeof(char) * (col + 1));
        for (j = 0; j < col; ++j)
            map[i][j] = c;
        map[i][j] = '\0';
    }
    map[i] = NULL;
    return map;
}

int main(int ac, char **av)
{
    char **map = NULL;
    int row = 0;
    int col = 0;

    if (ac != 3 && ac != 4)
        return 84;
    init_srand();
    row = atoi(av[2]);
    col = atoi(av[1]);
    map = create_map(row, col, 'X');

    gen_maze(map, row, col);

    for (int i = 0; map[i]; ++i)
        printf("%s%s", map[i], map[i + 1] ? "\n" : "");
    for (int i = 0; map[i]; ++i)
        free(map[i]);
    free(map);
    return 0;
}