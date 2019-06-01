/*
** EPITECH PROJECT, 2019
** my_putstrn
** File description:
** my_putstrn
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstrn(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
}
