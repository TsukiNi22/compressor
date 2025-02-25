/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Mutiplie two matrice
*/

#include "define.h"
#include "matrice.h"
#include "error.h"

matrice_t *reduce_matrice(matrice_t *matrice, int y_remove, int x_remove)
{
    matrice_t *matrice_reduce = NULL;
    int y_b = 0;
    int x_b = 0;

    if (!matrice)
        return err_prog_n(PTR_ERR, "In: reduce_matrice");
    matrice_reduce = init_matrice(matrice->x - 1, matrice->y - 1);
    if (!matrice_reduce)
        return err_prog_n(UNDEF_ERR, "In: reduce_matrice");
    for (int i = 0; i < matrice->y * matrice->x; i++) {
        if (i / matrice->x != y_remove && i % matrice->x != x_remove) {
            matrice_reduce->matrice[y_b][x_b] =
            matrice->matrice[i / matrice->x][i % matrice->x];
            x_b++;
        }
        y_b += (x_b == matrice->y - 1);
        x_b = x_b * !(x_b == matrice->y - 1);
    }
    return matrice_reduce;
}
