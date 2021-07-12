/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** execute_bsq.c
*/

#include "include/bsq.h"
#include <stdio.h>

int **draw_square(int **tab, int nb_line, int nb_cols, int value_sq)
{
    int i, j;

    for (i = 1; i < nb_line; i++) {
        for (j = 1; j < nb_cols; j++) {
            if (tab[i][j] == value_sq)
                break;
        }
        if (tab[i][j] == value_sq)
            break;
    }
    for (int m = i; m > (i - value_sq); m--) {
        for (int n = j; n > (j - value_sq); n--)
            tab[m][n] = -2;
    }
    return tab;
}

int **find_biggest_square(int **tab, int nb_line, int nb_cols)
{
    int value_sq = biggest_square_value(tab, nb_line, nb_cols);

    tab = draw_square(tab, nb_line, nb_cols, value_sq);
    return tab;
}

int **inversed_deminor(int **tab, int nb_line, int nb_cols)
{
    for (int i = 1; i < nb_line; i++) {
        for (int j = 1; j < nb_cols; j++) {
            if (tab[i][j] == 1 && tab[i - 1][j] > 0 &&
            tab[i][j - 1] > 0 && tab[i - 1][j - 1] > 0)
                tab[i][j] = check_incrementation(tab, i, j);
        }
    }
    return tab;
}

int **execute_bsq(int **tab, int nb_line, int nb_cols)
{
    tab = inversed_deminor(tab, nb_line, nb_cols);
    tab = find_biggest_square(tab, nb_line, nb_cols);
    return tab;
}
