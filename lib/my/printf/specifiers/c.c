/*
** EPITECH PROJECT, 2025
** c.c
** File description:
** 'c' specifier
*/

#include "printf.h"
#include "my_string.h"
#include "memory.h"
#include "write.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>

static int set_str(printf_data_t *data, char *str, char *c)
{
    if (!data || !str || !c)
        return err_prog(PTR_ERR, "In: set_str", KO);
    if (my_get_index(data->info_flags, '-') != -1) {
        my_strcat(str, c);
        for (int i = 0; i < data->field - 1; i++)
            my_strcat(str, " ");
    } else {
        for (int i = 0; i < data->field - 1; i++)
            my_strcat(str, " ");
        my_strcat(str, c);
    }
    return OK;
}

int specifiers_c(printf_data_t *data)
{
    char *str = NULL;
    char c[2] = {'\0'};

    if (!data)
        return err_prog(PTR_ERR, "In: specifiers_c", KO);
    c[0] = va_arg(data->ap, i_t);
    if (my_malloc_c(&str, data->field + 2) == KO)
        return err_prog(UNDEF_ERR, "In: specifiers_c 1", KO);
    if (set_str(data, str, c) == KO)
        return err_prog(UNDEF_ERR, "In: specifiers_c 2", KO);
    if (my_putstr(data->fd, str) == KO)
        return err_prog(UNDEF_ERR, "In: specifiers_c 3", KO);
    free(str);
    return OK;
}
