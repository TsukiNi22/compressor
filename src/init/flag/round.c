/*
** EPITECH PROJECT, 2025
** round.c
** File description:
** Do nothing
*/

#include "my_string.h"
#include "compressor.h"
#include "error.h"
#include <stdlib.h>

int flag_round(main_data_t *data, int const argc, char const *argv[])
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: flag_round", KO);
    if (1 >= argc)
        return err_system(data, "round: The flag need an argument.", KO);
    if (!my_str_isnum(argv[1]))
        return err_system(data, "round: The argument can only be composed of digit (0-9).", KO);
    data->b_round = true;
    data->round = atoi(argv[1]);
    return OK;
}
