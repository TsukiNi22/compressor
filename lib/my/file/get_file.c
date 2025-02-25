/*
** EPITECH PROJECT, 2025
** get_file.c
** File description:
** Read and put a file in a str
*/

#include "my_string.h"
#include "memory.h"
#include "define.h"
#include "error.h"
#include <fcntl.h>
#include <unistd.h>

static int get_file_size(char const *file)
{
    char tmp[4096] = {0};
    int size = 0;
    int res = 4096;
    int fd = 0;

    if (!file)
        return err_prog(PTR_ERR, "In: get_file_size", KO);
    fd = open(file, O_RDONLY);
    if (fd == KO)
        return err_prog(OP_FILE_ERR, "In: get_file_size", KO);
    while (res == 4096) {
        res = read(fd, tmp, 4096);
        if (res == KO)
            return err_prog(READ_FILE_ERR, "In: get_file_size", KO);
        size += res;
    }
    close(fd);
    return size;
}

char *get_file(char const *file)
{
    char *file_c = NULL;
    int size = 0;
    int fd = 0;

    if (!file)
        return err_prog_n(PTR_ERR, "In: get_file");
    size = get_file_size(file);
    if (size == KO)
        return err_prog_n(UNDEF_ERR, "In: get_file 1");
    if (my_malloc_c(&file_c, size + 1) == KO)
        return err_prog_n(UNDEF_ERR, "In: get_file 2");
    fd = open(file, O_RDONLY);
    if (fd == KO)
        return err_prog_n(OP_FILE_ERR, "In: get_file");
    if (read(fd, file_c, size) != size)
        return err_prog_n(READ_FILE_ERR, "In: get_file");
    close(fd);
    return file_c;
}
