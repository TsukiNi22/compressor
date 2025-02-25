/*
** EPITECH PROJECT, 2025
** const.c
** File description:
** Global const
*/

#include "compressor.h"

char const flags[] = {
    'h',
    'p',
    'r',
    'c'
};

char const *full_flags[] = {
    "--help",
    "--precision",
    "--round",
    "--calculate"
};

int const flags_argc[] = {
    -1,  // h
    1,   // p
    1,   // r
    -1   // c
};

int (* const flag_functions[])(main_data_t *, int const, char const *[]) = {
    &flag_null,         // h
    &flag_precision,    // p
    &flag_round,        // r
    &flag_calculate     // c
};
