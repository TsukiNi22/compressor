/*
** EPITECH PROJECT, 2025
** compressor.c
** File description:
** Compressor
*/

#include "compressor.h"
#include "error.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

/* check the given file is there are file and accesible */
static int check_file(int const argc, char const *argv[], main_data_t *data)
{
    /* init of the struct used for the lstat function */
    struct stat st = {0};

    /* function argument check */
    if (!data || !argv)
        return KO;
    
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            continue;
        if (access(argv[i], F_OK) == KO) {
            data->err_sys = true;
            fprintf(stderr, "%s: The file or directory doesn't exist.\n", argv[i]);
            return KO;
        } else if (access(argv[i], X_OK) == KO) {
            data->err_sys = true;
            fprintf(stderr, "%s: Can't access file or directory.\n", argv[i]);
            return KO;
        }
        if (lstat(argv[i], &st) == KO) {
            data->err_sys = true;
            perror("lstat");
            return KO;
        }
        if (!S_ISREG(st.st_mode)) {
            data->err_sys = true;
            fprintf(stderr, "%s: This is definitly not a normal file.\n", argv[i]);
            return KO;
        }
    }
    return OK;
}

/* main function of the compressor */
int compressor(int const argc, char const *argv[], main_data_t *data)
{
    /* function argument check */
    if (!data || !argv)
        return KO;

    /* initialisation */
    if (init_flag(data, argc, argv) == KO)
        return FATAL_ERR;
    if (data->help)
        return OK;
    if (check_file(argc, argv, data) == KO)
        return KO;
    if (init_data(data) == KO)
        return FATAL_ERR;

    /* main execution */
    if (data->calculate)
        return calculate(data);
    if (data->undo)
        return decompress_files(data);
    return compress_files(data);

    /*
    unsigned int a = 145252;
    unsigned int b = 6234621;
    info_t info = {0};

    // compresion //
    if (compress_data(data->precision, data->max, &info, a, b) == KO)
        return err_prog(UNDEF_ERR, "In: compressor 1", KO);
    #include <stdio.h>
    printf("%u | %u\n", a, b);

    // decompresion //
    if (decompress_data(data->precision, data->max, &info, &a, &b) == KO)
        return err_prog(UNDEF_ERR, "In: compressor 2", KO);
    printf("%u | %u\n", a, b);
    */
}
