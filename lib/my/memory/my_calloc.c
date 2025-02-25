/*
** EPITECH PROJECT, 2025
** my_calloc.c
** File description:
** Set to zero every byte of the given array
*/

#include "error.h"
#include <stdbool.h>

int my_calloc_b(bool **ptr, int size)
{
    if (!ptr || !(*ptr))
        return err_prog(PTR_ERR, "In: my_calloc_b", KO);
    if (size < 0)
        return err_prog(ARGV_ERR, "In: my_calloc_b", KO);
    for (int i = 0; i < size; i++)
        (*ptr)[i] = false;
    return OK;
}

int my_calloc_c(char **ptr, int size)
{
    if (!ptr || !(*ptr))
        return err_prog(PTR_ERR, "In: my_calloc_c", KO);
    if (size < 0)
        return err_prog(ARGV_ERR, "In: my_calloc_c", KO);
    for (int i = 0; i < size; i++)
        (*ptr)[i] = '\0';
    return OK;
}

int my_calloc_i(int **ptr, int size)
{
    if (!ptr || !(*ptr))
        return err_prog(PTR_ERR, "In: my_calloc_i", KO);
    if (size < 0)
        return err_prog(ARGV_ERR, "In: my_calloc_i", KO);
    for (int i = 0; i < size; i++)
        (*ptr)[i] = 0;
    return OK;
}

int my_calloc_f(float **ptr, int size)
{
    if (!ptr || !(*ptr))
        return err_prog(PTR_ERR, "In: my_calloc_f", KO);
    if (size < 0)
        return err_prog(ARGV_ERR, "In: my_calloc_f", KO);
    for (int i = 0; i < size; i++)
        (*ptr)[i] = 0.0;
    return OK;
}
