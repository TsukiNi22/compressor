/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Transpose a matrice
*/

#include "define.h"
#include "matrice.h"
#include "error.h"

matrice_t *transpose_matrice(matrice_t *matrice)
{
    matrice_t *transposed_matrice = NULL;

    if (!matrice)
        return err_prog_n(PTR_ERR, "In: multiplie_matrice");
    transposed_matrice = init_matrice(matrice->y, matrice->x);
    if (!matrice)
        return err_prog_n(UNDEF_ERR, "In: multiplie_matrice");
    for (int i = 0; i < matrice->y; i++) {
        for (int j = 0; j < matrice->x; j++) {
            transposed_matrice->matrice[j][i] =
            matrice->matrice[i][j];
        }
    }
    return transposed_matrice;
}
