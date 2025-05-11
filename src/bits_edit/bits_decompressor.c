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
##  bits_decompressor.c

File Description:
##  Decompress the bits compressed
\**************************************************************/

#include "compressor.h"
#include "error.h"
#include <math.h>
#include <limits.h>

/* decompress the bits of a single compresion */
int bits_decompressor(int precision, int max, info_t *info, unsigned int *a, unsigned int *b)
{
    /* extract the value from the information value */
    unsigned long long c = info->value & UINT_MAX;
    double percent = (info->value >> INT_BITS_SIZE) & max;
    unsigned int zero_nb = (info->value >> (INT_BITS_SIZE + precision)) & 31; // 11111 -> 5 bytes
    bool overflow = (info->value >> (INT_BITS_SIZE + precision + ZERO_NB_SIZE)) & 1;
    bool a_greater = (info->value >> (INT_BITS_SIZE + precision + ZERO_NB_SIZE + OVERFLOW_SIZE)) & 1;

    /* function argument check */
    if (!info || !a || !b)
        return KO;

    /* retrive the value in the 2 variable a and b */
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
    } else {
        *b = round((double) c * percent);
        if (c - *b > UINT_MAX)
            *b += (c - *b) % UINT_MAX;
        if (c - *b > UINT_MAX)
            *b += (c - *b) % UINT_MAX;
        *a = (c - *b);
    }
    return OK;
}
