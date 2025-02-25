/*
** EPITECH PROJECT, 2025
** error_custom.c
** File description:
** Error print for custom version
*/

#include "define.h"
#include "error.h"
#include <stdbool.h>

void err_custom_v(char *error_info)
{
    if (!CUSTOM_PUT_ERROR)
        return;
    print_error_info(error_info, true);
}

void *err_custom_n(char *error_info)
{
    if (!CUSTOM_PUT_ERROR)
        return NULL;
    print_error_info(error_info, true);
    return NULL;
}

int err_custom(char *error_info, int to_return)
{
    if (!CUSTOM_PUT_ERROR)
        return to_return;
    print_error_info(error_info, true);
    return to_return;
}
