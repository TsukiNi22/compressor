/*
** EPITECH PROJECT, 2025
** init_matrice.c
** File description:
** Setup a matrice of x, y size
*/

#include "define.h"
#include "matrice.h"
#include "error.h"
#include <stdlib.h>

matrice_t *init_matrice(int x, int y)
{
    matrice_t *matrice = malloc(sizeof(matrice_t));

    if (!matrice)
        return err_prog_n(MALLOC_ERR, "In: init_matrice 1");
    matrice->matrice = malloc(sizeof(float *) * (y + 1));
    if (!(matrice->matrice))
        return err_prog_n(MALLOC_ERR, "In: init_matrice 2");
    matrice->matrice[y] = NULL;
    for (int i = 0; i < y; i++) {
        matrice->matrice[i] = malloc(sizeof(float) * x);
        if (!(matrice->matrice[i]))
            return err_prog_n(MALLOC_ERR, "In: init_matrice 3");
        for (int j = 0; j < x; j++)
            matrice->matrice[i][j] = 0.0;
    }
    matrice->x = x;
    matrice->y = y;
    return matrice;
}
