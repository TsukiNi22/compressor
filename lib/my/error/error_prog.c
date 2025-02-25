/*
** EPITECH PROJECT, 2025
** error_prog.c
** File description:
** Error print for prog version
*/

#include "define.h"
#include "error.h"
#include <stdbool.h>

void err_prog_v(error_code_t code, char *error_info)
{
    if (!PUT_ERROR)
        return;
    print_error_info(error_info, false);
    print_error(code);
}

void *err_prog_n(error_code_t code, char *error_info)
{
    if (!PUT_ERROR)
        return NULL;
    print_error_info(error_info, false);
    print_error(code);
    return NULL;
}

int err_prog(error_code_t code, char *error_info, int to_return)
{
    if (!PUT_ERROR)
        return to_return;
    print_error_info(error_info, false);
    print_error(code);
    return to_return;
}
