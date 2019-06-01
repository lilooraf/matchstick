/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** ftc_map
*/

#include <stdlib.h>
#include "my.h"

char **map_change(char **map, int line, int supp)
{
    int j;
    int i = my_strlen(map[line]);

    while (map[line][i] != '|')
        i--;
    for (j = 0; j != supp; j++, i--)
        map[line][i] = ' ';
    return (map);
}

char **create_map(int *line, int size)
{
    int i = 1;
    char **map = malloc(sizeof(char *) * (size + 2));

    map[0] = my_calloc(sizeof(char), (size * 2 + 2));
    map[size + 1] = my_calloc(sizeof(char), (size * 2 + 2));
    for (int j = 0; j != size * 2 + 1; j++)
        map[0][j] = map[size + 1][j] = '*';
    for (int j = 1, k = 0; i != size + 1; i++) {
        map[i] = my_calloc(sizeof(char), (size * 2 + 2));
        map[i][0] = '*';
        for (j = 1, k = 0; k != ((size * 2) - line[i - 1]) / 2; j++, k++)
            map[i][j] = ' ';
        for (k = 0; k != line[i-1]; j++, k++)
            map[i][j] = '|';
        for (k = 0; k != ((size * 2) - line[i - 1]) / 2; j++, k++)
            map[i][j] = ' ';
        map[i][j] = '*';
    }
    map[i + 1] = NULL;
    return (map);
}

int check_end(int *line, int size)
{
    for (int i = 0; i != size + 1; i++)
        if (line[i] > 0) {
            my_putchar('\n');
            return (1);
        }
    return (0);
}

void disp_player(int *res)
{
    if (res[0] != -1) {
        my_putstr("Player removed ");
        my_put_nbr(res[1]);
        my_putstr(" match(es) from line ");
        my_put_nbr(res[0]);
        my_putchar('\n');
    }
}

void disp_ia(int *res)
{
    my_putstr("AI removed ");
    my_put_nbr(res[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(res[0]);
    my_putchar('\n');
}