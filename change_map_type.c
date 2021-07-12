/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** change_map_type.c
*/

#include "include/bsq.h"
#include <stdio.h>

int *buffer_into_buffi(char *buffer)
{
    int *buffi = malloc(sizeof(int) * my_strlen(buffer) + 1);
    int i, j;

    for (j = 0; buffer[j] != '\n'; j++);
    j++;
    for (i = 0; buffer[j] != '\0'; i++, j++) {
        if (buffer[j] == '.')
            buffi[i] = 1;
        if (buffer[j] == 'o')
            buffi[i] = 0;
        if (buffer[j] == '\n')
            buffi[i] = -1;
    }
    buffi[i] = -84;
    return buffi;
}

int **buffi_into_tab(int *buffi, int nb_lines, int nb_cols)
{
    int **tab = malloc(sizeof(int *) * nb_lines);
    int i = 0;
    int j = 0;

    for (int i = 0; i < nb_lines; i++)
        tab[i] = malloc(sizeof(int) * nb_cols + 1);
    for (int k = 0; buffi[k] != -84; k++) {
        tab[i][j] = buffi[k];
        j++;
        if (buffi[k] == -1) {
            i++;
            j = 0;
        }
    }
    return tab;
}

char *tab_into_buffer(int **tab, int nb_line, int nb_cols)
{
    int k = 0;
    char *res = malloc(sizeof(char) * (nb_line * (nb_cols + 1)));

    for (int i = 0; i < nb_line; i++) {
        for (int j = 0; j <= nb_cols; j++, k++) {
            if (tab[i][j] == -2)
                res[k] = 'x';
            if (tab[i][j] == 0)
                res[k] = 'o';
            if (tab[i][j] == -1)
                res[k] = '\n';
            if (tab[i][j] != -2 && tab[i][j] != 0 &&
            tab[i][j] != -1 && tab[i][j] != -84)
                res[k] = '.';
            if (tab[i][j] == -84)
                res[k] = '\0';
        }
    }
    return res;
}