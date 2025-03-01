/*
** EPITECH PROJECT, 2025
** calculate.c
** File description:
** Do nothing
*/

#include "macro.h"
#include "compressor.h"
#include "error.h"

/* activate the calculate option */
int flag_calculate(main_data_t *data, UNUSED int const argc, char const *argv[])
{
    /* function argument check */
    if (!data || !argv)
        return KO;

    /* set the value of the boolean to true */
    data->calculate = true;
    return OK;
}
