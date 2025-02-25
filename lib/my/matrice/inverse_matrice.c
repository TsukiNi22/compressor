/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Mutiplie two matrice
*/

#include "my_math.h"
#include "define.h"
#include "matrice.h"
#include "error.h"

matrice_t *inverse_matrice_2(matrice_t *matrice)
{
    matrice_t *matrice_inv = NULL;
    float det = 0.0;

    if (!matrice)
        return err_prog_n(PTR_ERR, "In: inverse_matrice_2");
    if (matrice->x != 2 || matrice->y != 2)
        return err_prog_n(ARGV_ERR, "In: inverse_matrice_2");
    matrice_inv = init_matrice(2, 2);
    if (!matrice_inv)
        return err_prog_n(UNDEF_ERR, "In: inverse_matrice_2 1");
    det = determinant_matrice_2(matrice);
    if (det == 0.0)
        return err_prog_n(UNDEF_ERR, "The matrice is not invertible / Error");
    det = 1.0 / det;
    matrice_inv->matrice[0][0] = matrice->matrice[0][0] * det;
    matrice_inv->matrice[0][1] = -matrice->matrice[0][1] * det;
    matrice_inv->matrice[1][0] = -matrice->matrice[1][0] * det;
    matrice_inv->matrice[1][1] = matrice->matrice[1][1] * det;
    return matrice_inv;
}

static matrice_t *clean_matrice(matrice_t *matrice_cofacteur,
    matrice_t *matrice_transposed, matrice_t *matrice_inv)
{
    if (!matrice_cofacteur || !matrice_transposed || !matrice_inv)
        return err_prog_n(PTR_ERR, "In: clean_matrice");
    if (free_matrice(&matrice_cofacteur) == KO)
        return err_prog_n(UNDEF_ERR, "In: clean_matrice 1");
    if (free_matrice(&matrice_transposed) == KO)
        return err_prog_n(UNDEF_ERR, "In: clean_matrice 2");
    return matrice_inv;
}

matrice_t *inverse_matrice(matrice_t *matrice)
{
    matrice_t *matrices[3] = {0};
    float det = 0.0;

    if (!matrice)
        return err_prog_n(PTR_ERR, "In: inverse_matrice");
    if (matrice->x != matrice->y)
        return err_prog_n(ARGV_ERR, "In: inverse_matrice");
    det = determinant_matrice(matrice);
    if (det == 0.0)
        return err_prog_n(UNDEF_ERR, "The matrice is not invertible / Error");
    det = 1.0 / det;
    matrices[0] = cofacteur_matrice(matrice);
    matrices[1] = transpose_matrice(matrices[0]);
    matrices[2] = init_matrice(matrice->x, matrice->y);
    if (!matrices[0] || !matrices[1] || !matrices[2])
        return err_prog_n(UNDEF_ERR, "In: inverse_matrice");
    for (int i = 0; i < matrice->x * matrice->y; i++)
        matrices[2]->matrice[i / matrice->x][i % matrice->x] =
        matrices[1]->matrice[i / matrice->x][i % matrice->x] * det;
    return clean_matrice(matrices[0], matrices[1], matrices[2]);
}
