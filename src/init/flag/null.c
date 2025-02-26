/*
** EPITECH PROJECT, 2025
** null.c
** File description:
** Do nothing
*/

#include "macro.h"
#include "compressor.h"
#include "error.h"

/* do nothing */
int flag_null(main_data_t *data, UNUSED int const argc, char const *argv[])
{
    /* function argument check */
    if (!data || !argv)
        return KO;
    
    /* do nothing */
    return OK;
}
