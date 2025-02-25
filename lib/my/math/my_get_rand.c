/*
** EPITECH PROJECT, 2025
** my_get_rand.c
** File description:
** Obtain a random number between min and max
*/

#include <stdlib.h>

float get_rand(float min, float max)
{
    return ((float) rand() / (float) RAND_MAX) * (max + 1 - min) + min;
}
