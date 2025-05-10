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
##  init_flag.c

File Description:
##  Init the flag option
\**************************************************************/

#include "compressor.h"
#include "error.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* check for the flag who start with '--' is there in the list of knowed flag */
static int full_flag(main_data_t *data, int const argc, char const *argv[], int const i)
{
    /* function argument check */
    if (!data || !argv)
        return KO;
    
    /* check for each full flag if it's correpond to the one given */
    for (int j = 0; full_flags[j]; j++) {
        if (strcmp(argv[i], full_flags[j]) == 0)
            return flag_functions[j](data, argc - i, &(argv[i]));
    }

    /* retrun an error if it's not a flag in the list */
    data->err_sys = true;
    fprintf(stderr, "%s: Unknow option.\n", argv[i]);
    return KO;
}

/* check for the flag who start with '-' is there in the list of knowed flag */
static int is_flag_char(char const c, int *index)
{
    /* function argument check */
    if (!index)
        return false;

    /* check for each flag char if it's correpond to the one given */
    for (int i = 0; flags[i]; i++) {
        if (c == flags[i]) {
            *index = i;
            return true;
        }
    }
    return false;
}

/* check the arg who start with '-' or '--' is valid flag */
static int flag(main_data_t *data, int const argc, char const *argv[], int const i)
{
    int index = 0;

    /* function argument check */
    if (!data || !argv)
        return KO;

    /* check if the arg with '-' or '--' is a valid flag if it is than call the appropriate function */
    for (int j = 1; argv[i][j]; j++) {
        if (!is_flag_char(argv[i][j], &index)) {
            data->err_sys = true;
            fprintf(stderr, "%c: Unknow option.\n", argv[i][j]);
            return KO;
        }
        if (flags_argc[index] != 0 && (j > 1 || argv[i][j + 1])) {
            data->err_sys = true;
            fprintf(stderr, "%c: Can't be combined with other.\n", argv[i][j]);
            return KO;
        }
        if (flag_functions[index](data, argc - i, &(argv[i])) == KO)
            return KO;
    }
    return OK;
}

/* check the argv for any flag with '-' or '--' */
int init_flag(main_data_t *data, int const argc, char const *argv[])
{
    /* function argument check */
    if (!data || !argv)
       return KO;
    
    /* check for the help flag */
    for (int i = 0; i < argc; i++) {
        if ((argv[i][0] == '-' && argv[i][1] == flags[0] && !argv[i][2])
            || strcmp(argv[i], full_flags[0]) == 0) {
            data->help = true;
            return flag_help();
        }
    }

    /* check for the other flags */
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] != '-')
            continue;
        if (argv[i][1] == '-' && argv[i][2] && full_flag(data, argc, argv, i) == KO)
            return KO;
        if (argv[i][1] != '-' && argv[i][1] && flag(data, argc, argv, i) == KO)
            return KO;
    }
    return OK;
}
