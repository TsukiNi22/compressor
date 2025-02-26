/*
** EPITECH PROJECT, 2025
** init_data.c
** File description:
** Init the main data
*/

#include "compressor.h"
#include "error.h"

/* init the main struct with default value */
int init_data(main_data_t *data)
{
    unsigned int n = 1;

    /* function argument check */
    if (!data)
        return KO;

    /* init the main struct with default value */
    if (!data->b_precision)
        data->precision = 17;
    if (!data->b_round)
        data->round = -1;
    data->max = 0;
    for (int i = 0; i < data->precision; n <<= 1, i++)
        data->max += n;
    data->redution_size = INT_BITS_SIZE + data->precision + ZERO_NB_SIZE + OVERFLOW_SIZE;
    return OK;
}
