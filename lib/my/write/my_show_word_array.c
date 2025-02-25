/*
** EPITECH PROJECT, 2025
** my_show_word_array.c
** File description:
** Show the tab given
*/

#include "my_string.h"
#include "write.h"
#include "error.h"
#include <unistd.h>

int my_show_word_array(char **array)
{
    if (!array)
        return err_prog(PTR_ERR, "In: show_word_array", KO);
    for (int i = 0; array[i]; i++) {
        if (my_printf("array[%d]=\"%s\"\n", i, array[i]) == KO)
            return err_prog(WRITE_ERR, "In: show_word_array", KO);
    }
    return OK;
}
