/*
** EPITECH PROJECT, 2025
** init_data.c
** File description:
** Init the main data
*/

#include "compressor.h"
#include "error.h"

int init_data(main_data_t *data)
{
    if (!data)
        return err_prog(PTR_ERR, "In: init_data", KO);
    if (init_global(data) == KO)
        return err_prog(UNDEF_ERR, "In: init_data", KO);
    return OK;
}
