/*
** EPITECH PROJECT, 2019
** matchstick_bs
** File description:
** main
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int main(int ac, char **av)
{
    int *sm = malloc(sizeof(int) * 3);

    srandom(time(0));
    if (check_num(av) || ac != 3)
        return (84);
    sm[0] = my_getnbr(av[1]);
    sm[1] = my_getnbr(av[2]);
    sm[2] = 0;
    if (sm[0] <= 1 || sm[0] >= 100 || sm[1] < 1)
        return (84);
    return (matchstick(sm));
}