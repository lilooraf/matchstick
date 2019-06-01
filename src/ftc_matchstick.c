/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** ftc_matchstick
*/

#include <stdlib.h>
#include "my.h"

int *sticks(int x)
{
    int *line = malloc(sizeof(int) * x + 1);
    int val = 1;
    int i;

    for (i = 0; i != x; i++) {
        line[i] = val;
        val += 2;
    }
    line[i] = -1;
    return (line);
}

int check_line(char *file, int *sm)
{
    if (my_getnbr(file) < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_getnbr(file) > sm[0] || my_getnbr(file) == 0) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int check_nb(char *file)
{
    for (int i = 0; file[i] != 0; i++) {
        if ((file[i] < 48 || file[i] > 57) && file[i + 1] != 0) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    return (0);
}

int check_matches(char *file, int *sm, int *line, int i)
{
    if (my_getnbr(file) < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_getnbr(file) > sm[1]) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(sm[1]);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (my_getnbr(file) > line[i - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    if (my_getnbr(file) == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    return (0);
}

int check_win_lose(int j)
{
    if (j % 2 == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    my_putstr("You lost, too bad...\n");
    return (2);
}