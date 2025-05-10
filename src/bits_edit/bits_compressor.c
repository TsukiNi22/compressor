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
##  bits_compressor.c

File Description:
##  Compress the bits
\**************************************************************/

#include "compressor.h"
#include "error.h"
#include <limits.h>

/* compress 64 bits with the given precision */
int bits_compressor(int precision, int max, info_t *info, unsigned int a, unsigned int b)
{
    /* n°1: obtain the value needed for the compresion */
    unsigned long long c = (unsigned long long) a + (unsigned long long) b;
    unsigned int zero_nb = 0;
    double percent = (double) a / (double) c;
    bool overflow = (a > UINT_MAX - b);
    bool a_greater = a > b;

    /* function argument check */
    if (!info)
        return KO;

    /* n°2: obtain the value needed for the compresion */
    if (a_greater)
        percent = (double) b / (double) c;
    for (zero_nb = 0; percent * 10 < max; percent *= 10.0, zero_nb++);

    /* set the information value with the calculated value */
    info->value = c & UINT_MAX;
    info->value += ((unsigned long long) percent) << INT_BITS_SIZE;
    info->value += ((unsigned long long) zero_nb) << (INT_BITS_SIZE + precision);
    info->value += ((unsigned long long) overflow) << (INT_BITS_SIZE + precision + ZERO_NB_SIZE);
    info->value += ((unsigned long long) a_greater) << (INT_BITS_SIZE + precision + ZERO_NB_SIZE + OVERFLOW_SIZE);
    return OK;
}
