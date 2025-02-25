/*
** EPITECH PROJECT, 2025
** my_isneg.c
** File description:
** Write P when the given parameter is greter than 0 or N in oser cases
*/

#include "write.h"
#include "error.h"

int my_isneg(int n)
{
    char c = 'P';

    if (n < 0)
        c = 'N';
    if (my_putchar(1, c) == KO)
        return err_prog(UNDEF_ERR, "In: my_isneg", KO);
    return OK;
}
