/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** Get the len of a string
*/

#include "error.h"

int my_strlen_stop_at(char const *str, char c)
{
    int len = 0;

    if (!str)
        return err_prog(PTR_ERR, "In: my_strlen_stop_at", KO);
    for (; str[len] && str[len] != c; len++);
    return len;
}
