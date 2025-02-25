/*
** EPITECH PROJECT, 2025
** calculate.c
** File description:
** Do nothing
*/

#include "macro.h"
#include "compressor.h"
#include "error.h"

int flag_calculate(main_data_t *data, UNUSED int const argc, char const *argv[])
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: flag_calculate", KO);
    data->calculate = true;
    return OK;
}
