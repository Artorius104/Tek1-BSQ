/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_str_islower
*/

#include <stddef.h>

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 97 || str[i] > 122)
            return 0;
    if (str == NULL)
        return 1;

    return 1;
}
