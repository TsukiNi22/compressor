/*
** EPITECH PROJECT, 2025
** round.c
** File description:
** Do nothing
*/

#include "compressor.h"
#include "error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* check the syntax and set the new value for the '-r' or '--round' flag */
int flag_round(main_data_t *data, int const argc, char const *argv[])
{
    /* function argument check */
    if (!data || !argv)
        return KO;

    /* check the syntax of the parameter */
    if (1 >= argc) {
        data->err_sys = true;
        fprintf(stderr, "round: The flag need an argument.\n");
        return KO;
    }
    if (strspn(argv[1], "0123456789") != strlen(argv[1])) {
        data->err_sys = true;
        fprintf(stderr, "round: The argument can only be composed of digit (0-9).\n");
        return KO;
    }

    /* set the new value for round */
    data->b_round = true;
    data->round = atoi(argv[1]);
    return OK;
}
