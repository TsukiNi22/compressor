/*
** EPITECH PROJECT, 2025
** precision.c
** File description:
** Check the precision flag
*/

#include "my_string.h"
#include "compressor.h"
#include "error.h"
#include <stdlib.h>

int flag_precision(main_data_t *data, int const argc, char const *argv[])
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: flag_precision", KO);
    if (1 >= argc)
        return err_system(data, "precision: The flag need an argument.", KO);
    if (!my_str_isnum(argv[1]))
        return err_system(data, "precision: The argument can only be composed of digit (0-9).", KO);
    data->b_precision = true;
    data->precision = atoi(argv[1]);
    if (data->precision < 1 || data->precision > 25)
        return err_system(data, "precision: The precision can only be between \'1\' and \'25\'.", KO);
    return OK;
}
