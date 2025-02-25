/*
** EPITECH PROJECT, 2025
** identifier.c
** File description:
** Specifier that print the identifier
*/

#include "printf.h"
#include "write.h"
#include "error.h"

int specifiers_identifier(printf_data_t *data)
{
    if (!data)
        return err_prog(PTR_ERR, "In: specifiers_identifier", KO);
    if (my_putchar(data->fd, IDENTIFIER) == KO)
        return err_prog(UNDEF_ERR, "In: specifiers_identifier", KO);
    return OK;
}
