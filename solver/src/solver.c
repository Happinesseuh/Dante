/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-dante-ines.maaroufi
** File description:
** solver
*/

#include "solver.h"
#include <time.h>
#include <sys/resource.h>

void limit(void)
{
    struct rlimit lim;
    getrlimit(RLIMIT_STACK, &lim);
    lim.rlim_cur = 16000000000;
    setrlimit(RLIMIT_STACK, &lim);
}

int make_way(maze_t *maze, int row, int col)
{
    maze->visited[row][col] = WAY;
    return (1);
}

int solver(maze_t *maze, int row, int col)
{
    if (maze->visited[row][col] == END)
        return (1);
    if (maze->visited[row][col] == EMPTY) {
        maze->visited[row][col] = PASSED;
        if (solver(maze, row + 1, col)) {
            return (make_way(maze, row, col));
        }
        if (solver(maze, row, col + 1)) {
            return (make_way(maze, row, col));
        }
        if (solver(maze, row, col - 1)) {
            return (make_way(maze, row, col));
        }
        if (solver(maze, row - 1, col)) {
            return (make_way(maze, row, col));
        }
    }
    return (0);
}

void free_all(maze_t *maze)
{
    for (int i = 0; i < maze->row; ++i)
        free(maze->maze[i]);
    free(maze->maze);
    for (int i = 0; i < maze->row + 2; ++i)
        free(maze->visited[i]);
    free(maze->visited);
}

int main(int ac, char **av)
{
    maze_t maze;
    char *file = read_maze(av[1]);

    if (ac != 2 || !file)
        return (84);
    maze.maze = my_str_to_word_array(file);
    init_col_row(&maze);
    init_visited(&maze);
    limit();
    if (!solver(&maze, 1, 1))
        printf("no solution found");
    else {
        add_way(&maze);
        print_maze(maze.maze);
    }
    free_all(&maze);
    free(file);
    return (0);
}