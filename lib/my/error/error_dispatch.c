/*
** EPITECH PROJECT, 2025
** error_dispatch.c
** File description:
** Printf / Dispatch error message (type)
*/

#include "write.h"
#include "error.h"

static char const *error_message[] = {
    "An Error have ocured in the error return.",
    "Undefinied Error.",
    "The given pointer is NULL.",
    "The allocation attempt with malloc have fail.",
    "The write function have failed.",
    "Incorrect number of argument given to main.",
    "Incorrect input in the given argument.",
    "Unknow flag given for execution.",
    "Overflow on a variable.",
    "'Invalid Permision' or 'No Existant File'.",
    "'Can't' or 'Fail' to read the file.",
    "'Invalid Permision' or 'No Existant Directory.'",
    "'Can't' or 'Fail' to read the directory."
};

int dispatch(error_code_t code)
{
    int res = 0;

    if (!PUT_ERROR)
        return OK;
    if (code < MIN_ERROR_CODE || code > MAX_ERROR_CODE) {
        res = my_putnbr(2, code);
        res += my_putstr(2, ": Unknow error code\n");
    } else {
        res = my_putstr(2, "Error: ");
        res += my_putstr(2, error_message[code]);
    }
    if (res != OK)
        return KO;
    return OK;
}
