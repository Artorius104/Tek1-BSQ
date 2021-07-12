/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** check_special_cases.c
*/

#include "include/bsq.h"
#include <stdio.h>

int check_empty_spaces(char *buffer)
{
    int count = 0;
    int i;

    for (i = 0; buffer[i] != '\n'; i++);
    i++;
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '.')
            count++;
    }
    if (count == 0)
        return 1;
    return 0;
}

int check_obstacles(char *buffer)
{
    int count = 0;
    int i;

    for (i = 0; buffer[i] != '\n'; i++);
    i++;
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'o')
            count++;
    }
    if (count == 0)
        return 1;
    return 0;
}