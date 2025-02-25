/*
** EPITECH PROJECT, 2025
** my_atof.c
** File description:
** Return the float of a string
*/

#include "my_math.h"
#include "my_string.h"
#include "error.h"
#include <stdbool.h>

static long double my_atof_basic(const char *str)
{
    long double my_double = 0.0;
    long double mult = 0.0;
    int size = 0;
    bool diff = false;

    if (!str)
        return err_prog(PTR_ERR, "In: my_atof > my_atof_basic", 0.0);
    if (!str[0])
        return OK;
    size = my_strlen(str) - 1;
    for (int i = 0; str[i]; i++) {
        if (str[size - i] == '-' && size - i == 0)
            diff = true;
        else {
            mult = my_pow(10, i - diff);
            my_double += (((long double) str[size - i]) - 48) * mult;
        }
    }
    my_double *= 1 - 2 * (str[0] && str[0] == '-' && my_double > 0);
    return my_double;
}

static int my_atof_second(const char *str, long double *my_float)
{
    int size = my_strlen(str) - 1;
    int cut_place = my_strfind(str, '.');
    char *first_array = my_cut_str(str, 1, cut_place);
    char *second_array = my_cut_str(str, 0, cut_place);
    int second_size = my_strlen(second_array);
    long double mult = my_pow(10, second_size * -1);
    long double first_int = my_atof_basic(first_array);
    long double second_int = my_atof_basic(second_array);

    if (!str || !my_float || !first_array || !second_array
        || size < 0 || cut_place == KO || second_size < 0)
        return err_prog(UNDEF_ERR, "In: my_atof > my_atof_second", KO);
    if (first_int < 0)
        *my_float = first_int + second_int * mult * -1;
    else
        *my_float = first_int + second_int * mult;
    return OK;
}

long double my_atof(const char *str)
{
    long double my_float = 0.0;

    if (!str || my_atof_second(str, &my_float) == KO)
        return err_prog(PTR_ERR, "In: my_atof", 0.0);
    return my_float;
}
