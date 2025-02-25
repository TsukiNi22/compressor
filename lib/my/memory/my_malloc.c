/*
** EPITECH PROJECT, 2025
** my_malloc.c
** File description:
** For malloc function and calloc
*/

#include "memory.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

int my_malloc_b(bool **ptr, int size)
{
    if (!ptr)
        return err_prog(PTR_ERR, "In: my_malloc_b", KO);
    if (size < 1)
        return err_prog(ARGV_ERR, "In: my_malloc_b", KO);
    (*ptr) = malloc(sizeof(bool) * size);
    if (!(*ptr))
        return err_prog(MALLOC_ERR, "In: my_malloc_b", KO);
    if (my_calloc_b(ptr, size) == ERROR)
        return err_prog(UNDEF_ERR, "In: my_malloc_b", KO);
    return OK;
}

int my_malloc_c(char **ptr, int size)
{
    if (!ptr)
        return err_prog(PTR_ERR, "In: my_malloc_c", KO);
    if (size < 1)
        return err_prog(ARGV_ERR, "In: my_malloc_c", KO);
    (*ptr) = malloc(sizeof(char) * size);
    if (!(*ptr))
        return err_prog(MALLOC_ERR, "In: my_malloc_c", KO);
    if (my_calloc_c(ptr, size) == ERROR)
        return err_prog(UNDEF_ERR, "In: my_malloc_c", KO);
    return OK;
}

int my_malloc_i(int **ptr, int size)
{
    if (!ptr)
        return err_prog(PTR_ERR, "In: my_malloc_i", KO);
    if (size < 1)
        return err_prog(ARGV_ERR, "In: my_malloc_i", KO);
    (*ptr) = malloc(sizeof(int) * size);
    if (!(*ptr))
        return err_prog(MALLOC_ERR, "In: my_malloc_i", KO);
    if (my_calloc_i(ptr, size) == ERROR)
        return err_prog(UNDEF_ERR, "In: my_malloc_i", KO);
    return OK;
}

int my_malloc_f(float **ptr, int size)
{
    if (!ptr)
        return err_prog(PTR_ERR, "In: my_malloc_f", KO);
    if (size < 1)
        return err_prog(ARGV_ERR, "In: my_malloc_f", KO);
    (*ptr) = malloc(sizeof(float) * size);
    if (!(*ptr))
        return err_prog(MALLOC_ERR, "In: my_malloc_f", KO);
    if (my_calloc_f(ptr, size) == ERROR)
        return err_prog(UNDEF_ERR, "In: my_malloc_f", KO);
    return OK;
}
