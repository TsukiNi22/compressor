/*
** EPITECH PROJECT, 2025
** my_putnbr_base.c
** File description:
** Convert the given number in the given base
*/

#include "my_string.h"
#include "write.h"
#include "error.h"

int my_putnbr_base(int fd, unsigned long long nbr, char const *base)
{
    int base_size = 0;

    if (!base)
        return err_prog(PTR_ERR, "In: my_putnbr_base", KO);
    base_size = my_strlen(base);
    if (base_size < 0)
        return err_prog(UNDEF_ERR, "In: my_putnbr_base", KO);
    if (base_size == 0)
        return err_prog(ARGV_ERR, "In: my_putnbr_base", KO);
    for (int i = 0; nbr >= 1; i++) {
        my_putchar(fd, base[nbr % base_size]);
        nbr /= base_size;
    }
    return OK;
}
