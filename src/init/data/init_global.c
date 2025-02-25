/*
** EPITECH PROJECT, 2025
** init_global.c
** File description:
** Init global variable
*/

#include "compressor.h"
#include "error.h"
#include <stdbool.h>

int init_global(main_data_t *data)
{
    unsigned int n = 1;

    if (!data)
        return err_prog(PTR_ERR, "In: init_global", KO);   
    if (!data->b_precision)
        data->precision = 17;
    if (!data->b_round)
        data->round = -1;
    data->max = 0;
    for (int i = 0; i < data->precision; n <<= 1, i++)
        data->max += n;
    data->redution_size = INT_BITS_SIZE + data->precision + ZERO_NB_SIZE + OVERFLOW_SIZE;
    data->err_sys = false;
    return OK;
}
