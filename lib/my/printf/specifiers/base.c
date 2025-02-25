/*
** EPITECH PROJECT, 2025
** base.c
** File description:
** For specifiers 'o' 'u' 'x' 'X'
*/

#include "printf.h"
#include "my_math.h"
#include "my_string.h"
#include "memory.h"
#include "define.h"
#include "write.h"
#include "error.h"
#include <stdbool.h>
#include <stdlib.h>

static int set_str_left(printf_data_t *data, char **str, char *n, int size)
{
    int len = 0;

    if (!data || !str || !n)
        return err_prog(PTR_ERR, "In set_str_left", KO);
    len = my_strlen(n);
    for (int i = 0; i < data->precision - len; i++)
        my_strcat(*str, "0");
    my_strcat(*str, n);
    len = my_strlen(*str);
    for (int i = 0; i < size - len; i++)
        my_strcat(*str, " ");
    return OK;
}

static int set_str_right(printf_data_t *data, char **str, char *n, int size)
{
    int len = 0;

    if (!data || !str || !n)
        return err_prog(PTR_ERR, "In set_str_left", KO);
    len = my_strlen(n);
    for (int i = 0; i < size - data->precision * (data->precision > len)
        - len * !(data->precision > len); i++)
        my_strcat(*str, " ");
    len = my_strlen(n);
    for (int i = 0; i < data->precision - len; i++)
        my_strcat(*str, "0");
    my_strcat(*str, n);
    return OK;
}

static int set_str(printf_data_t *data, char **str, char *n, int size)
{
    if (!data || !str || !n)
        return err_prog(PTR_ERR, "In set_str", KO);
    if (my_get_index(data->info_flags, '-') != -1) {
        if (set_str_left(data, str, n, size) == KO)
            return err_prog(UNDEF_ERR, "In set_str 1", KO);
    } else {
        if (set_str_right(data, str, n, size) == KO)
            return err_prog(UNDEF_ERR, "In set_str 2", KO);
    }
    return OK;
}

static int get_str(printf_data_t *data, char **str, char *n)
{
    int size = 0;
    int len = 0;

    if (!data || !str || !n)
        return err_prog(PTR_ERR, "In get_str", KO);
    len = my_strlen(n);
    if (len < 0)
        return err_prog(UNDEF_ERR, "In get_str 1", KO);
    if (len >= data->field && len >= data->precision)
        size = len;
    if (data->field >= len && data->field >= data->precision)
        size = data->field;
    if (data->precision >= data->field && data->precision >= len)
        size = data->precision;
    if (my_malloc_c(str, size + 2) == KO)
        return err_prog(UNDEF_ERR, "In get_str 2", KO);
    if (set_str(data, str, n, size) == KO)
        return err_prog(UNDEF_ERR, "In get_str 3", KO);
    return OK;
}

static int get_nbr(printf_data_t *data, char **n, const char authorized_char[])
{
    if (!data || !n || !authorized_char)
        return err_prog(PTR_ERR, "In: get_nbr", KO);
    if (my_strcmp(data->info_modifier, "l") == 0)
        *n = my_convertnbr_base(va_arg(data->ap, llu_t), authorized_char);
    if (my_strcmp(data->info_modifier, "ll") == 0)
        *n = my_convertnbr_base(va_arg(data->ap, lu_t), authorized_char);
    else
        *n = my_convertnbr_base(va_arg(data->ap, u_t), authorized_char);
    if (!(*n))
        return err_prog(UNDEF_ERR, "In: get_nbr", KO);
    return OK;
}

int specifiers_base(printf_data_t *data)
{
    char *str = NULL;
    char *n = NULL;
    int res = OK;

    if (!data)
        return err_prog(PTR_ERR, "In specifiers_base", KO);
    if (data->info_specifiers == 'o')
        res += get_nbr(data, &n, "01234567");
    if (data->info_specifiers == 'u')
        res += get_nbr(data, &n, "0123456789");
    if (data->info_specifiers == 'x')
        res += get_nbr(data, &n, "0123456789abcdef");
    if (data->info_specifiers == 'X')
        res += get_nbr(data, &n, "0123456789ABCDEF");
    if (data->info_specifiers == 'b')
        res += get_nbr(data, &n, "01");
    if (res != OK || get_str(data, &str, n) == KO
    || my_putstr(data->fd, str) == KO)
        return err_prog(UNDEF_ERR, "In: specifiers_base", KO);
    return OK;
}
