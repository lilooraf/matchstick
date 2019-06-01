/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int *get_args_matches(int *line, int *sm, int *res)
{
    char *file = NULL;
    size_t len = 0;

    my_putstr("Matches: ");
    getline(&file, &len, stdin);
    if (file[0] == 0) {
        res[0] = -1;
        return (res);
    }
    if (check_nb(file) || check_matches(file, sm, line, res[0]))
        return (get_args(line, sm, res));
    res[1] = my_getnbr(file);
    return (res);
}

int *get_args(int *line, int *sm, int *res)
{
    char *file = NULL;
    size_t len = 0;

    if (sm[3] % 2 != 0)
        return res;
    my_putstr("Line: ");
    getline(&file, &len, stdin);
    if (file[0] == 0) {
        res[0] = -1;
        return (res);
    }
    if (check_nb(file) || check_line(file, sm))
        return (get_args(line, sm, res));
    res[0] = my_getnbr(file);
    res = get_args_matches(line, sm, res);
    return (res);
}

int *ai_rules(int *sm, int *line, int *res, int x)
{
    int z = 0;
    int j = 0;

    if (x == 2) {
        for (j = 0; line[j] == 0; j++);
        for (z = j + 1; line[z] == 0; z++);
        if (line[j] == 1 && line[z] <= sm[1]) {
            res[0] = z + 1;
            res[1] = line[res[0] - 1];
        }
    }
    if (x == 1) {
        if (line[res[0] - 1] >= 2 && line[res[0] - 1] <= sm[1])
            res[1] = line[res[0] - 1] - 1;
        if (line[res[0] - 1] >= 2 && line[res[0] - 1] - sm[1] == 1)
            res[1] = sm[1];
    }
    return (res);
}

int *my_ai(int *sm, int *line, int j, int *res)
{
    int x = 0;

    if (j % 2 == 0)
        return res;
    my_putstr("AI's turn...\n");
    for (int i = 0; i != sm[0]; i++)
        if (line[i] > 0)
            x++;
    while (line[res[0] - 1] <= 0)
        res[0] = (random() % (sm[0])) + 1;
    res[1] = (random() % (sm[1])) + 1;
    if (line[res[0] - 1] < sm[1])
        res[1] = (random() % (line[res[0] - 1]) + 1);
    res = ai_rules(sm, line, res, x);
    disp_ia(res);
    return (res);
}

int matchstick(int *sm)
{
    int j = 0;
    int *rm = malloc(sizeof(int) * 2);
    int *line = sticks(sm[0]);
    char **map = create_map(line, sm[0]);

    for (int i = 0; map[i]; my_putstrn(map[i]), i++);
    for (j = 0; check_end(line, sm[0]); j++, sm[3] = j) {
        if (j % 2 == 0) {
            my_putstr("Your turn:\n");
            rm = get_args(line, sm, rm);
            disp_player(rm);
        }
        if (rm[0] == -1)
            return (0);
        rm = my_ai(sm, line, j, rm);
        map = map_change(map, rm[0], rm[1]);
        line[rm[0] - 1] -= rm[1];
        for (int i = 0; map[i]; my_putstrn(map[i]), i++);
    }
    return (check_win_lose(j));
}
