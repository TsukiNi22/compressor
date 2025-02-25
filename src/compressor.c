/*
** EPITECH PROJECT, 2025
** compressor.c
** File description:
** Compressor
*/

#include "compressor.h"
#include "write.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

static unsigned int set_info(double percent, int precision, int max, bool overflow)
{
    unsigned int zero_nb = 0;
    unsigned int info = 0;

    for (zero_nb = 0; percent * 10 < max; percent *= 10.0, zero_nb++);
    info = overflow << (precision + 5);
    info += zero_nb << precision;
    info += (int) percent;
    return info;
}

static int get_nb(int precision, int max, unsigned int info, unsigned int c, unsigned int *a, unsigned int *b)
{
    unsigned long long total = c;
    unsigned int zero_nb = (info >> precision) & 31;
    double percent = info & max;
    bool overflow = (info >> (precision + 5)) & 1;

    if (!a || !b)
        return err_prog(PTR_ERR, "In: get_nb", KO);
    for (; zero_nb > 0; percent /= 10.0, zero_nb--);
    if (overflow)
        total += UINT_MAX;
    total += overflow;
    printf("%llu|%.30f\n", total , (double)total * (percent));
    printf("%llu|%.30f\n\n", total , (double)total * (1 - percent));
    if (percent <= 0.5) {
        *a = round((double) total * percent);
        if (total - *a > UINT_MAX)
            *a += (total - *a) % UINT_MAX;
        if (total - *a > UINT_MAX)
            *a += (total - *a) % UINT_MAX;
        *b = total - *a;
    } else  {
        *b = round((double) total * (1 - percent));
        if (total - *b > UINT_MAX)
            *b += (total - *b) % UINT_MAX;
        if (total - *b > UINT_MAX)
            *b += (total - *b) % UINT_MAX;
        *a = (total - *b);
    }
    return OK;
}

int compressor(int const argc, char const *argv[], main_data_t *data)
{
    double percent = 0.0;
    char precision = atoi(argv[1]); // 1 <-> 26
    unsigned int info = 0;
    unsigned int a = UINT_MAX - 1;
    unsigned int b = UINT_MAX ;
    unsigned long long c = 0;
    unsigned int max = 0;
    unsigned int n = 1;

    if (!data || !argv)
        return err_prog(PTR_ERR, "In: compressor", KO);
    if (init_data(data) == KO)
        return err_custom("Data initialisation error", FATAL_ERR);
    if (init_flag(data, argc, argv) == KO)
        return err_custom("Flag initialisation error", KO);
    for (int i = 0; i < precision; n <<= 1, i++)
        max += n;
    c = (unsigned long long) a + (unsigned long long) b;
    printf("C:\t\t|%llu|\n\n", c);
    percent = (double) a / (double) c;
    printf("A:\t\t|%u|\n", a);
    printf("B:\t\t|%u|\n\n", b);
    info = set_info(percent, precision, max, a > UINT_MAX - b);
    printf("Percent:\t|%.30f|\n\n", percent);
    get_nb(precision, max, info, c & UINT_MAX, &a, &b);
    printf("A:\t\t|%u|\n", a);
    printf("B:\t\t|%u|\n", b);
    return OK;
}
