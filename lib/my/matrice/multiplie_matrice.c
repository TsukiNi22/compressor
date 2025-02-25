/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Mutiplie two matrice
*/

#include "define.h"
#include "matrice.h"
#include "error.h"

matrice_t *multiplie_matrice(matrice_t *matrice_a, matrice_t *matrice_b)
{
    matrice_t *matrice = NULL;

    if (!matrice_a || !matrice_b)
        return err_prog_n(PTR_ERR, "In: multiplie_matrice");
    if (matrice_a->x != matrice_b->y)
        return err_prog_n(ARGV_ERR, "In: multiplie_matrice");
    matrice = init_matrice(matrice_b->x, matrice_a->y);
    if (!matrice)
        return err_prog_n(UNDEF_ERR, "In: multiplie_matrice");
    for (int i = 0; i < matrice->x * matrice->y; i++) {
        for (int j = 0; j < matrice_a->x; j++) {
            matrice->matrice[i / matrice->x][i % matrice->x] +=
            matrice_a->matrice[i / matrice->x][j]
            * matrice_b->matrice[j][i % matrice->x];
        }
    }
    return matrice;
}
