/*
** EPITECH PROJECT, 2025
** compressor.c
** File description:
** Compressor
*/

#include "compressor.h"
#include "write.h"
#include "error.h"
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdbool.h>

int compress_data(int precision, int max, info_t *info, unsigned int a, unsigned int b)
{
    unsigned long long c = (unsigned long long) a + (unsigned long long) b;
    unsigned int zero_nb = 0;
    double percent = (double) a / (double) c;
    bool overflow = (a > UINT_MAX - b);
    bool a_greater = a > b;

    if (a_greater)
        percent = (double) b / (double) c;
    if (!info)
        return err_prog(PTR_ERR, "In: compressor", KO);
    for (zero_nb = 0; percent * 10 < max; percent *= 10.0, zero_nb++);
    info->value = c & UINT_MAX;
    info->value += ((unsigned long long) percent) << INT_BITS_SIZE;
    info->value += ((unsigned long long) zero_nb) << (INT_BITS_SIZE + precision);
    info->value += ((unsigned long long) overflow) << (INT_BITS_SIZE + precision + ZERO_NB_SIZE);
    info->value += ((unsigned long long) a_greater) << (INT_BITS_SIZE + precision + ZERO_NB_SIZE + OVERFLOW_SIZE);
    return OK;
}

int decompress_data(int precision, int max, info_t *info, unsigned int *a, unsigned int *b)
{
    unsigned long long c = info->value & UINT_MAX;
    double percent = (info->value >> INT_BITS_SIZE) & max;
    unsigned int zero_nb = (info->value >> (INT_BITS_SIZE + precision)) & 31; // 11111
    bool overflow = (info->value >> (INT_BITS_SIZE + precision + ZERO_NB_SIZE)) & 1;
    bool a_greater = (info->value >> (INT_BITS_SIZE + precision + ZERO_NB_SIZE + OVERFLOW_SIZE)) & 1;

    if (!info || !a || !b)
        return err_prog(PTR_ERR, "In: decompressor", KO);
    for (; zero_nb > 0; percent /= 10.0, zero_nb--);
    if (overflow)
        c += UINT_MAX;
    c += overflow;
    if (!a_greater) {
        *a = round((double) c * percent);
        if (c - *a > UINT_MAX)
            *a += (c - *a) % UINT_MAX;
        if (c - *a > UINT_MAX)
            *a += (c - *a) % UINT_MAX;
        *b = c - *a;
    } else  {
        *b = round((double) c * percent);
        if (c - *b > UINT_MAX)
            *b += (c - *b) % UINT_MAX;
        if (c - *b > UINT_MAX)
            *b += (c - *b) % UINT_MAX;
        *a = (c - *b);
    }
    return OK;
}

static int check_file(int const argc, char const *argv[], main_data_t *data)
{
    struct stat st = {0};

    if (!data || !argv)
        return err_prog(PTR_ERR, "In: check_file", KO);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            continue;
        if (access(argv[i], F_OK) == KO) {
            my_printf("%s", argv[i]);
            return err_system(data, ": The file or directory doesn't exist.", KO);
        } else if (access(argv[i], X_OK) == KO) {
            my_printf("%s", argv[i]);
            return err_system(data, ": Can't access file or directory.", KO);
        }
        if (lstat(argv[i], &st) == KO)
            return err_prog(UNDEF_ERR, "In: check_file", KO);
        if (!S_ISREG(st.st_mode)) {
            my_printf("%s", argv[i]);
            return err_system(data, ": This is definitly not a normal file.", KO);
        }
    }
    return OK;
}

int compressor(int const argc, char const *argv[], main_data_t *data)
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: compressor", KO);
    if (init_flag(data, argc, argv) == KO)
        return err_custom("Flag initialisation error", FATAL_ERR);
    if (data->help)
        return OK;
    if (check_file(argc, argv, data) == KO)
        return err_custom("File initialisation error", KO);
    if (init_data(data) == KO)
        return err_custom("Data initialisation error", FATAL_ERR);
    
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
    return OK;
}
