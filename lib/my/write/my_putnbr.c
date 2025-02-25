/*
** EPITECH PROJECT, 2025
** my_put_nbr.c
** File description:
** Display the given number
*/

#include "write.h"
#include "error.h"

int my_putnbr(int fd, long long nb)
{
    for (; nb > 0; nb /= 10) {
        if (my_putchar(fd, (nb % 10) + 48) == KO)
            return err_prog(UNDEF_ERR, "In: my_putnbr", KO);
    }
    return OK;
}
