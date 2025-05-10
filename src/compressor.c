/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  11/05/2025 by Tsukini

File Name:
##  compressor.c

File Description:
##  Compressor
\**************************************************************/

#include "compressor.h"
#include "error.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

/* check the given file is there are file and accesible */
static int check_file(int const argc, char const *argv[], main_data_t *data)
{
    struct stat st = {0};
    bool file = false;

    /* function argument check */
    if (!data || !argv)
        return KO;
    
    for (int i = 1; i < argc && argv[i][0] != '-'; i++) {
        if (access(argv[i], F_OK) == KO) {
            data->err_sys = true;
            fprintf(stderr, "%s: The file or directory doesn't exist.\n", argv[i]);
            return KO;
        } else if (access(argv[i], R_OK) == KO) {
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
        file = true;
    }

    /* check if a file have been detected */
    if (!file) {
        data->err_sys = true;
        fprintf(stderr, "compressor: No file given.\n");
        return KO;
    }
    return OK;
}

/* main function of the compressor */
int compressor(int const argc, char const *argv[], main_data_t *data)
{
    int res = OK;

    /* function argument check */
    if (!data || !argv)
        return KO;

    /* initialisation */
    if (init_data(data) == KO)
        return FATAL_ERR;
    if (init_flag(data, argc, argv) == KO)
        return FATAL_ERR;
    if (data->help)
        return OK;
    if (check_file(argc, argv, data) == KO)
        return KO;
    
    /* set the max variable with the precision */
    for (unsigned int n = 1, i = 0; i < (unsigned int) data->precision; n <<= 1, i++)
        data->max += n;

    /* main execution */
    for (int i = 1; i < argc && argv[i][0] != '-'; i++) {
        if (data->calculate)
            res = calculate(data, argv[i]);
        else if (data->undo)
            res = decompress_file(data, argv[i]);
        else
            res = compress_file(data, argv[i]);
        if (res == KO)
            return KO;
    }
    return OK;
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
