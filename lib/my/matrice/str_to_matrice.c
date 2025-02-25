/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Convert a str to a quare matrice
*/

#include "my_math.h"
#include "my_string.h"
#include "define.h"
#include "matrice.h"
#include "error.h"

matrice_t *str_to_square_matrice(char const *str)
{
    matrice_t *new = NULL;
    float sqrt = 0.0;
    int len = 0;
    int x = 0;

    if (!str)
        return err_prog_n(PTR_ERR, "In: str_to_matrice");
    len = my_strlen(str);
    if (len < 0)
        return err_prog_n(UNDEF_ERR, "In: str_to_matrice 1");
    sqrt = (int) my_sqrt((float) len);
    x = (int) sqrt + ((int) (sqrt * sqrt) != len);
    new = init_matrice(x, x);
    if (!new)
        return err_prog_n(UNDEF_ERR, "In: str_to_matrice 2");
    for (int i = 0; i < x * x; i++)
        new->matrice[i / x][i % x] = (float) str[i * (i < len)] * (i < len);
    return new;
}

matrice_t *str_to_n_matrice(char const *str, int n)
{
    matrice_t *matrice = NULL;
    int len = 0;
    int i = 0;

    if (!str)
        return err_prog_n(PTR_ERR, "In: str_to_matrice");
    if (n < 1)
        return err_prog_n(ARGV_ERR, "In: str_to_matrice");
    len = my_strlen(str);
    if (len < 0)
        return err_prog_n(UNDEF_ERR, "In: str_to_matrice 1");
    matrice = init_matrice(n, len / n + ((float) len / (float) n > len / n));
    if (!matrice)
        return err_prog_n(UNDEF_ERR, "In: str_to_matrice 2");
    for (i = 0; i < len; i++)
        matrice->matrice[i / n][i % n] = (float) str[i];
    for (; i < matrice->x * matrice->y; i++)
        matrice->matrice[i / n][i % n] = 0.0;
    return matrice;
}
