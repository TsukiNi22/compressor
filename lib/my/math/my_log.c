/*
** EPITECH PROJECT, 2025
** my_log.c
** File description:
** Log with my formula
*/

#include "my_math.h"

long double my_log(double x, double base)
{
    return (my_pow(x, H_ZERO) - 1) / (my_pow(base, H_ZERO) - 1);
}
