/*
** EPITECH PROJECT, 2025
** my_strcat.c
** File description:
** Concatenates two string
*/

#include "my_string.h"
#include "define.h"
#include "error.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = 0;

    if (!dest || !src)
        return err_prog_n(PTR_ERR, "In: my_strncat");
    len = my_strlen(dest);
    if (len < 0)
        return err_prog_n(UNDEF_ERR, "In: my_strncat");
    for (int i = 0; src[i] && i < nb; i++)
        dest[len + i] = src[i];
    return dest;
}
