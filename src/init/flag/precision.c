/*
** EPITECH PROJECT, 2025
** precision.c
** File description:
** Check the precision flag
*/

#include "compressor.h"
#include "error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* check the syntax and set the new value for precision */
int flag_precision(main_data_t *data, int const argc, char const *argv[])
{
    /* function argument check */
    if (!data || !argv)
        return KO;

    /* check the syntax of the parameter given to '-p' or '--precision' */
    if (1 >= argc) {
        data->err_sys = true;
        fprintf(stderr, "precision: The flag need an argument.\n");
        return KO;
    }
    if (strspn(argv[1], "0123456789") != strlen(argv[1])) {
        data->err_sys = true;
        fprintf(stderr, "precision: The argument can only be composed of digit (0-9).\n");
        return KO;
    }

    /* set the new precision defined */
    data->precision = atoi(argv[1]);
    if (data->precision < 1 || data->precision > 25) {
        data->err_sys = true;
        fprintf(stderr, "precision: The precision can only be between \'1\' and \'25\'.\n");
        return KO;
    }
    return OK;
}
