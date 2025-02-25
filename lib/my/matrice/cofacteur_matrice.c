/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Mutiplie two matrice
*/

#include "define.h"
#include "matrice.h"
#include "error.h"

matrice_t *cofacteur_matrice(matrice_t *matrice)
{
    matrice_t *matrice_cofacteur = NULL;
    matrice_t *matrice_re = NULL;
    float det = 0.0;

    if (!matrice)
        return err_prog_n(PTR_ERR, "In: cofacteur_matrice");
    if (matrice->x != matrice->y)
        return err_prog_n(ARGV_ERR, "In: cofacteur_matrice");
    matrice_cofacteur = init_matrice(matrice->x, matrice->x);
    for (int i = 0; i < matrice->x * matrice->y; i++) {
        matrice_re = reduce_matrice(matrice, i / matrice->x, i % matrice->x);
        if (!matrice_re)
            return err_prog_n(UNDEF_ERR, "In: cofacteur_matrice 1");
        det = determinant_matrice(matrice_re);
        matrice_cofacteur->matrice[i / matrice->x][i % matrice->x] =
        (1 - 2 * ((i / matrice->x + i % matrice->x) % 2 != 0)) * det;
        free_matrice(&matrice_re);
    }
    return matrice_cofacteur;
}
