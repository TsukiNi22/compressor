/*
** EPITECH PROJECT, 2025
** compress_files.c
** File description:
** Compress the given files
*/

#include "compressor.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* compress the files given */
int compress_files(main_data_t *data, char const *file_path)
{
    FILE *file = NULL;

    /* function argument check */
    if (!data || !file_path)
        return KO;
    file = fopen(file_path, "rb");
    if (!file) {
        data->err_sys = true;
        perror(file_path);
        return KO;
    }
    fclose(file);
    return OK;
}
