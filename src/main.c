/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** Main of the project
*/

#include "compressor.h"
#include "write.h"
#include "error.h"
#include <stdbool.h>

int main(int const argc, char const *argv[])
{
    main_data_t data = {0};
    int res = 0;

    if (!argv)
        return err_prog(PTR_ERR, "In: main", EPITECH_ERR);
    res = compressor(argc, argv, &data);
    if (res == KO || res == FATAL_ERR) {
        if (res != FATAL_ERR)
            free_data(&data);
        if (!data.err_sys)
            my_printf("%Obinary: An error has occurred, "
            "execution has been interrupted.", 2);
        return EPITECH_ERR;
    }
    return free_data(&data);
}
