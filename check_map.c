/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** check_map.c
*/

#include "include/bsq.h"
#include <stdio.h>

int check_lines_length(char *buffer)
{
    int i, j;
    int nb_cols = 0;
    int check = 0;

    for (i = 0; buffer[i] != '\n'; i++);
    for (i = i + 1; buffer[i] != '\n'; i++, nb_cols++);
    for (i = i + 1; buffer[i] != '\0'; i++, check++) {
        if (buffer[i] == '\n') {
            if (nb_cols != check)
                return -4;
            check = -1;
        }
    }
    return 0;
}

int check_number_and_lines(char *buffer)
{
    int count = -1;
    int lines = my_getnbr(buffer);

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count++;
    if (count != lines)
        return -3;
    return 0;
}

int check_number(char *buffer)
{
    for (int i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] < '0' || buffer[i] > '9')
            return -2;
    return 0;
}

int check_map(char *buffer)
{
    if (check_number(buffer) == -2)
        return -1;
    if (check_number_and_lines(buffer) == -3)
        return -1;
    if (check_lines_length(buffer) == -4)
        return -1;
    return 0;
}