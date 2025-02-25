/*
** EPITECH PROJECT, 2025
** display_matrice.c
** File description:
** Display a matrice
*/

#include "write.h"
#include "matrice.h"
#include "error.h"

int display_matrice(matrice_t *matrice)
{
    int res = OK;

    if (!matrice)
        return err_prog(PTR_ERR, "In: display_matrice", KO);
    for (int i = 0; i < matrice->y; i++) {
        for (int j = 0; j < matrice->x; j++) {
            res += my_printf("[%d]\t", matrice->matrice[i][j]);
        }
        res += my_putchar(1, '\n');
        if (res != OK)
            return err_prog(UNDEF_ERR, "In: display_matrice", KO);
    }
    return OK;
}
