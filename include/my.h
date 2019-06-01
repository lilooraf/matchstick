/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stddef.h>

#ifndef __MY_H__
#define __MY_H__

void my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *);
int my_getnbr(char const *str);
int my_strlen(char const *str);
void *my_calloc(size_t elem_size, size_t elems);
int check_num(char **av);
int *get_args(int *line, int *sm, int *res);
void my_putstrn(char const *str);
char **map_change(char **map, int line, int supp);
char **create_map(int *line, int size);
int check_end(int *line, int size);
int *sticks(int x);
int check_line(char *file, int *sm);
int check_nb(char *file);
int check_matches(char *file, int *sm, int *line, int i);
int check_win_lose(int j);
int *get_args_matches(int *line, int *sm, int *res);
int *get_args(int *line, int *sm, int *res);
int *my_ai(int *sm, int *line, int j, int *res);
int matchstick(int *sm);
void disp_player(int *res);
void disp_ia(int *res);
int check_end(int *line, int size);

#endif
