/*
** EPITECH PROJECT, 2025
** my_cut_str.c
** File description:
** Return the array after or befor the given point
*/

#include "my_string.h"
#include "memory.h"
#include "define.h"
#include "error.h"

static int get_size(char const *str, int before, int cut_place)
{
    int res = my_strlen(str);

    if (!str)
        return err_prog(PTR_ERR, "In: my_cut_str > get_alloc_size", KO);
    if (res < 0)
        return err_prog(UNDEF_ERR, "In: my_cut_str > get_alloc_size", KO);
    if (before)
        return cut_place;
    return res - (cut_place - 1);
}

char *my_cut_str(const char *str, const int before, int cut_place)
{
    char *new_str = NULL;
    int actual_place = 0;
    int res = 0;

    if (!str)
        return err_prog_n(PTR_ERR, "In: my_cut_str");
    res = my_strlen(str);
    if (res < 0)
        return err_prog_n(UNDEF_ERR, "In: my_cut_str");
    if (1 > cut_place || cut_place > res)
        return err_prog_n(ARGV_ERR, "In: my_cut_str");
    if (my_malloc_c(&new_str, get_size(str, before, cut_place) + 1) == KO)
        return err_prog_n(MALLOC_ERR, "In: my_cut_str");
    for (int i = 0; str[i]; i++) {
        if ((i < cut_place && before) || (i > cut_place && !before)) {
            new_str[actual_place] = str[i];
            actual_place++;
        }
    }
    return new_str;
}
