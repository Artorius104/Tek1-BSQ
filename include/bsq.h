/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-BSQ-gilbert.badiabo
** File description:
** bsq.h
*/

#ifndef BSQ_H
#define BSQ_H

#include "my.h"
#include "my_macro.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char *get_map(int fd, char const *filepath);
int get_nb_cols(char *buffer);
int check_incrementation(int **tab, int i, int j);
int biggest_square_value(int **tab, int nb_line, int nb_cols);
int *buffer_into_buffi(char *buffer);
int **buffi_into_tab(int *buffi, int nb_lines, int nb_cols);
char *tab_into_buffer(int **tab, int nb_line, int nb_cols);
int **execute_bsq(int **tab, int nb_line, int nb_cols);
int filled_map_case(char *buffer);
int empty_map_case(char *buffer);
int check_empty_spaces(char *buffer);
int check_obstacles(char *buffer);
int special_cases(char *buffer);
void start_bsq(char *buffer, int nb_lines);
void empty_one_case(char *res, int nb_lines);
int check_map(char *buffer);
int check_number(char *buffer);
int check_number_and_lines(char *buffer);
int check_lines_length(char *buffer);

#endif