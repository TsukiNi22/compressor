/*
** EPITECH PROJECT, 2025
** init_flag.c
** File description:
** Init the flag option
*/

#include "write.h"
#include "my_string.h"
#include "compressor.h"
#include "error.h"
#include <stdbool.h>

static int full_flag(main_data_t *data,
    int const argc, char const *argv[], int const i)
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: full_flag", KO);
    for (int j = 0; full_flags[j]; j++) {
        if (my_strcmp(argv[i], full_flags[j]) == 0)
            return flag_functions[j](data, argc, &(argv[i]), -1);
    }
    data->err_sys = true;
    my_printf("%Obinary: Unrecognized option \'%s\'.\n", 2, argv[i]);
    return KO;
}

static int is_flag_char(char const c, int *index)
{
    if (!index)
        return err_prog(PTR_ERR, "In: is_flag_char", false);
    for (int i = 0; flags[i]; i++) {
        if (c == flags[i]) {
            *index = i;
            return true;
        }
    }
    return false;
}

static int flag(main_data_t *data,
    int const argc, char const *argv[], int const i)
{
    int index = 0;

    if (!data || !argv)
        return err_prog(PTR_ERR, "In: flag", KO);
    for (int j = 1; argv[i][j]; j++) {
        if (!is_flag_char(argv[i][j], &index)) {
            data->err_sys = true;
            my_printf("%Obinary: Invalid option \'%c\'.\n", 2, argv[i][j]);
            return KO;
        }
        if (flags_argc[index] != 0 && (j > 1 || argv[i][j + 1])) {
            data->err_sys = true;
            my_printf("%Obinary: \'%c\' can't be combined with other.\n",
            2, argv[i][j]);
            return KO;
        }
        if (flag_functions[j](data, argc - j, &(argv[i]), j) == KO)
            return err_prog(UNDEF_ERR, "In: flag", KO);
    }
    return OK;
}

int init_flag(main_data_t *data, int const argc, char const *argv[])
{
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: init_flag", KO);
    for (int i = 0; i < argc; i++) {
        if ((argv[i][0] == '-' && argv[i][1] == flags[0] && !argv[i][2])
            || my_strcmp(argv[i], full_flags[0]) == 0)
            return flag_help();
    }
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] != '-')
            continue;
        if (argv[i][1] == '-' && argv[i][2]
            && full_flag(data, argc, argv, i) == KO)
            return err_prog(UNDEF_ERR, "In: init_flag 2", KO);
        if (argv[i][1] != '-' && argv[i][1]
            && flag(data, argc, argv, i) == KO)
            return err_prog(UNDEF_ERR, "In: init_flag 3", KO);
    }
    return OK;
}
