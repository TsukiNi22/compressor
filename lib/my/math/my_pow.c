/*
** EPITECH PROJECT, 2025
** my_pow.c
** File description:
** My pow made with the Series of Taylor for (u + 1)^a
*/

#include "my_math.h"

static long double my_pow_float_aproximation(double n, double power)
{
    long double aprox = 1;
    double stockage_aprox = 1;
    double r1 = 0.0;
    double r2 = 0.0;
    double u = n - 1;

    if (n > 2) {
        r1 = my_pow_float_aproximation(n / 2, power);
        r2 = my_pow_float_aproximation(2, power);
        return r1 * r2;
    }
    for (int i = 1; i < ACCURATE; i++) {
        stockage_aprox *= ((power - (i - 1)) / i) * u;
        aprox += stockage_aprox;
    }
    return aprox;
}

long double my_pow(double n, double power)
{
    long long ll_power = power;
    double double_power = power - ll_power;
    long double new_n = 1;

    for (long long i = 0; i < ll_power * (1 - 2 * (power < 0)); i++)
        new_n *= n;
    if (double_power != 0)
        new_n = my_pow_float_aproximation(n, double_power);
    if (power < 0)
        new_n = 1 / new_n;
    return new_n;
}
