/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** Get the len of a string
*/

#include "error.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return err_prog(PTR_ERR, "In: my_strlen", KO);
    for (; str[len]; len++);
    return len;
}
