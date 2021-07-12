/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** get_arg.c
*/

#include "include/bsq.h"
#include <stdio.h>

char *get_map(int fd, char const *filepath)
{
    struct stat statbuf;
    char *buffer = NULL;
    int size = 0;

    stat(filepath, &statbuf);
    buffer = malloc(statbuf.st_size + 1);
    buffer[statbuf.st_size + 1] = '\0';
    size = read(fd, buffer, statbuf.st_size);
    if (size == -1)
        return NULL;
    close(fd);
    return buffer;
}

int get_nb_cols(char *buffer)
{
    int count = 0;
    int j = 0;

    for (j = 0; buffer[j] != '\n'; j++);
    j++;
    for (count = 0; buffer[j] != '\n'; count++, j++);
    return count;
}

int check_incrementation(int **tab, int i, int j)
{
    if (tab[i - 1][j] <= tab[i][j - 1] && tab[i - 1][j] <= tab[i - 1][j - 1])
        return tab[i - 1][j] + 1;
    if (tab[i][j - 1] <= tab[i - 1][j] && tab[i][j - 1] <= tab[i - 1][j - 1])
        return tab[i][j - 1] + 1;
    if (tab[i - 1][j - 1] <= tab[i][j - 1] &&
    tab[i - 1][j - 1] <= tab[i - 1][j])
        return tab[i - 1][j - 1] + 1;
}

int biggest_square_value(int **tab, int nb_line, int nb_cols)
{
    int value = 0;

    for (int i = 1; i < nb_line; i++) {
        for (int j = 1; j < nb_cols; j++) {
            if (tab[i][j] > value)
                value = tab[i][j];
        }
    }
    return value;
}
