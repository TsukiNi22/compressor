/*
** EPITECH PROJECT, 2025
** my_convertnbr_base.c
** File description:
** Convert the given number in the given base
*/

#include "my_string.h"
#include "write.h"
#include "memory.h"
#include "define.h"
#include "error.h"

char *my_convertnbr_base(unsigned long long nbr, char const *base)
{
    char *my_nbr = NULL;
    int base_size = 0;
    int size = 0;

    if (!base)
        return err_prog_n(PTR_ERR, "In: my_convertnbr_base");
    base_size = my_strlen(base);
    if (base_size < 0)
        return err_prog_n(UNDEF_ERR, "In: my_convertnbr_base 1");
    if (base_size == 0)
        return err_prog_n(ARGV_ERR, "In: my_convertnbr_base");
    for (int n = nbr; n >= 1; size++)
        n /= base_size;
    if (my_malloc_c(&my_nbr, size + 1) == KO)
        return err_prog_n(UNDEF_ERR, "In: my_convertnbr_base 2");
    for (int i = 0; nbr >= 1; i++) {
        my_nbr[size - i - 1] = base[nbr % base_size];
        nbr /= base_size;
    }
    return my_nbr;
}
