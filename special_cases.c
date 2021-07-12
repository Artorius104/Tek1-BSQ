/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** special_cases.c
*/

#include "include/bsq.h"
#include <stdio.h>

void print_special_case(char *res)
{
    for (int k = 0; res[k] != '\0'; k++)
        my_putchar(res[k]);
}

void empty_one_case(char *res, int nb_lines)
{
    res[0] = 'x';
    print_special_case(res);
}

int filled_map_case(char *buffer)
{
    int j, i;
    int nb_lines = my_getnbr(buffer);
    char *res = malloc(sizeof(char) * my_strlen(buffer));

    if (check_empty_spaces(buffer) == 0)
        return 0;
    for (j = 0; buffer[j] != '\n'; j++);
    j++;
    for (i = 0; buffer[j] != '\0'; i++, j++)
        res[i] = buffer[j];
    res[i] = '\0';
    print_special_case(res);
    return 1;
}

int empty_map_case(char *buffer)
{
    int j, i;
    int nb_lines = my_getnbr(buffer);
    char *res = malloc(sizeof(char) * my_strlen(buffer));

    if (check_obstacles(buffer) == 0)
        return 0;
    for (j = 0; buffer[j] != '\n'; j++);
    j++;
    for (i = 0; buffer[j] != '\0'; i++, j++)
        res[i] = buffer[j];
    if (nb_lines == 1 || get_nb_cols(res) == 1) {
        empty_one_case(res, nb_lines);
        return 1;
    } else {
        start_bsq(buffer, nb_lines);
        return 1;
    }
    return 1;
}

int special_cases(char *buffer)
{
    if (filled_map_case(buffer) == 1)
        return 1;
    if (empty_map_case(buffer) == 1)
        return 1;
    return 0;
}