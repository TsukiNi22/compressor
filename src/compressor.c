/*
** EPITECH PROJECT, 2025
** compressor.c
** File description:
** Compressor
*/

#include "macro.h"
#include "compressor.h"
#include "error.h"

int compressor(int const argc, char const *argv[], main_data_t *data)
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: compressor", KO);
    if (init_data(data) == KO)
        return err_custom("Data initialisation error", FATAL_ERR);
    if (init_flag(data, argc, argv) == KO)
        return err_custom("Flag initialisation error", KO);
    return OK;
}
