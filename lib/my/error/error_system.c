/*
** EPITECH PROJECT, 2025
** error_system.c
** File description:
** Error print for system version
*/

#include "compressor.h"
#include "write.h"
#include "define.h"
#include "error.h"

void err_system_v(main_data_t *data, char *error_info)
{
    if (data)
        data->err_sys = true;
    if (!SYSTEM_PUT_ERROR)
        return;
    if (my_putstr(2, error_info) == KO)
        error_error();
    if (my_putstr(2, "\n") == KO)
        error_error();
}

void *err_system_n(main_data_t *data, char *error_info)
{
    if (data)
        data->err_sys = true;
    if (!SYSTEM_PUT_ERROR)
        return NULL;
    if (my_putstr(2, error_info) == KO)
        error_error();
    if (my_putstr(2, "\n") == KO)
        error_error();
    return NULL;
}

int err_system(main_data_t *data, char *error_info, int to_return)
{
    if (data)
        data->err_sys = true;
    if (!SYSTEM_PUT_ERROR)
        return to_return;
    if (my_putstr(2, error_info) == KO)
        error_error();
    if (my_putstr(2, "\n") == KO)
        error_error();
    return to_return;
}
