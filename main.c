/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** main.c
*/

#include "include/bsq.h"
#include <stdio.h>

void print_bsq(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
}

void start_bsq(char *buffer, int nb_lines)
{
    int *buffi;
    int **tab;
    int nb_cols = get_nb_cols(buffer);

    buffi = buffer_into_buffi(buffer);
    tab = buffi_into_tab(buffi, nb_lines, nb_cols);
    tab = execute_bsq(tab, nb_lines, nb_cols);
    buffer = tab_into_buffer(tab, nb_lines, nb_cols);
    print_bsq(buffer);
}

int main(int ac, char const *av[])
{
    char *buffer;
    int nb_lines = 0;
    int fd;

    if (ac != 2)
        return 84;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return 84;
    buffer = get_map(fd, av[1]);
    if (buffer == NULL)
        return 84;
    if (check_map(buffer) == -1)
        return 84;
    if (special_cases(buffer) == 1)
        return 0;
    nb_lines = my_getnbr(buffer);
    start_bsq(buffer, nb_lines);
    return 0;
}
