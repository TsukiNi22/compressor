/*
** EPITECH PROJECT, 2025
** undo.c
** File description:
** Do nothing
*/

#include "macro.h"
#include "compressor.h"
#include "error.h"

/* activate the undo option */
int flag_undo(main_data_t *data, UNUSED int const argc, char const *argv[])
{
    /* function argument check */
    if (!data || !argv)
        return KO;

    /* change the boolean value of the undo option to true */
    data->undo = true;
    return OK;
}
