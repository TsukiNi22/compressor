/*
** EPITECH PROJECT, 2025
** my_atoi.c
** File description:
** Str to int
*/

#include "my_string.h"
#include "my_math.h"
#include "error.h"
#include <stdbool.h>

long long my_atoi(const char *str)
{
    long long my_int = 0.0;
    long long mult = 0.0;
    int array_size = 0;
    bool negatif = false;

    if (!str)
        return err_prog(PTR_ERR, "In: my_atoi", 0);
    array_size = my_strlen(str);
    if (array_size < 0)
        return err_prog(UNDEF_ERR, "In: my_atoi", 0);
    negatif = (str[0] == '-');
    for (int i = negatif; str[i]; i++) {
        mult = my_pow(10, array_size - 1 - (i - negatif) - negatif);
        my_int += ((long long) str[i] - 48) * mult;
    }
    if (negatif)
        my_int *= -1;
    if (((!negatif && my_int < 0) || (negatif && my_int >= 0)) && my_int != 0)
        return err_prog(OVERFLOW, "In: my_atoi", 0);
    return my_int;
}
