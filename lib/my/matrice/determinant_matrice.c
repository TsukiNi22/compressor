/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Mutiplie two matrice
*/

#include "define.h"
#include "matrice.h"
#include "error.h"

float determinant_matrice_2(matrice_t *matrice)
{
    float result = 0.0;

    if (!matrice)
        return err_prog(PTR_ERR, "In: determinant_matrice_2", 0.0);
    if (matrice->x != 2 || matrice->y != 2)
        return err_prog(ARGV_ERR, "In: determinant_matrice_2", 0.0);
    result = matrice->matrice[0][0] * matrice->matrice[1][1]
    - matrice->matrice[0][1] * matrice->matrice[1][0];
    return result;
}

float determinant_matrice(matrice_t *matrice)
{
    matrice_t *matrice_reduce = NULL;
    float det = 0.0;

    if (!matrice)
        return err_prog(PTR_ERR, "In: determinant_matrice", 0.0);
    if (matrice->x != matrice->y)
        return err_prog(ARGV_ERR, "In: determinant_matrice", 0.0);
    if (matrice->x == 1 && matrice->y == 1)
        return matrice->matrice[0][0];
    for (int i = 0; i < matrice->y; i++) {
        matrice_reduce = reduce_matrice(matrice, 0, i);
        if (!matrice_reduce)
            return err_prog(UNDEF_ERR, "In: determinant_matrice", 0.0);
        det += matrice->matrice[0][i] * determinant_matrice(matrice_reduce)
        * (1 - 2 * (i % 2 != 0));
        free_matrice(&matrice_reduce);
    }
    return det;
}
