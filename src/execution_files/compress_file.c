/*
** EPITECH PROJECT, 2025
** compress_file.c
** File description:
** Compress the given file
*/

#include "compressor.h"
#include "error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdbool.h>

void print_binary(long long n) {
    for (int i = 63; i >= 0; i--) {  // Parcourir les 32 bits (pour un int)
        putchar((n & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' ');  // Espacement pour lisibilité
    }
    putchar('\n');
}

/* compress the file */
static int compress(main_data_t *data, int size)
{
    unsigned int compressed_index = 5;
    unsigned int a, b = 0;
    info_t info = {0};

    /* function argument check */
    if (!data)
        return KO;

    /* compress file */
    data->round_nb++;
    for (int i, index = 0; i < size / 8; i++) {
        index = i * 8;
        a = 0;
        b = 0;
        for (int j = 0; j < 4; j++) {
            a += data->file[index + j];
            a <<= 8;
        }
        for (int j = 0; j < 4; j++) {
            b += data->file[index + j + 4];
            b <<= 8;
        }
        if (bits_compressor(data->precision, data->max, &info, a, b) == KO)
            return KO;
        print_binary(info.value);
        for (int j = 0; j < 8; j++, compressed_index++)
            data->compressed_file[compressed_index] = (info.value >> 8 * (7 - j)) & 255;
    }

    /* set the number of round + precision used */
    for (int j = 0; j < 4; j++)
        data->compressed_file[j] = (data->round_nb >> 8 * (3 - j)) & 255;
    data->compressed_file[4] = data->precision;
    return OK;
}

/* get the new path to a file with the new extension */
static char *get_file_path_compressed(char const *file_path)
{
    char *path = NULL;
    char *ptr = NULL;
    int len[2] = {0};
    int i = 0;

    /* function argument check */
    if (!file_path)
        return NULL;

    /* get the right malloced space for the new path */
    for (char *c = (char *) file_path; *c; c++) {
        if (*c == '.')
            ptr = c;
    }
    for (len[0] = 0; file_path[len[0]] && &(file_path[len[0]]) != ptr; len[0]++);
    for (len[1] = 0; EXTENSION[len[1]]; len[1]++);
    path = malloc(sizeof(char) * (len[0] + len[1] + 1));
    if (!path)
        return NULL;

    /* set the new path with the right extension */
    memset(path, 0, (len[0] + len[1] + 1));
    for (int j = 0; file_path[j] && &(file_path[j]) != ptr; i++, j++)
        path[i] = file_path[j];
    for (int j = 0; EXTENSION[j]; i++, j++)
        path[i] = EXTENSION[j];
    return path;
}

/* compress the files given */
int compress_file(main_data_t *data, char const *file_path)
{
    FILE *file = NULL;
    struct stat st = {0};
    char *file_path_compressed = NULL;

    /* function argument check */
    if (!data || !file_path)
        return KO;

    /* obtain the size of the file */
    if (lstat(file_path, &st) == KO) {
        data->err_sys = true;
        perror("lstat");
        return KO;
    }

    /* obtain the content of the file */
    if (data->file)
        free(data->file);
    if (data->compressed_file)
        free(data->compressed_file);
    data->file = malloc(sizeof(char) * (st.st_size + 1));
    data->compressed_file = malloc(sizeof(char) * (st.st_size + 1));
    if (!data->file || !data->compressed_file) {
        data->err_sys = true;
        perror("malloc");
        return KO;
    }
    memset(data->file, 0, (st.st_size + 1));
    memset(data->compressed_file, 0, (st.st_size + 1));
    file = fopen(file_path, "rb");
    if (!file) {
        data->err_sys = true;
        perror(file_path);
        return KO;
    }
    if (fread(data->file, 1, st.st_size, file) != (size_t) st.st_size) {
        data->err_sys = true;
        perror("read");
        return KO;
    }
    fclose(file);

    /* compress file */
    if (compress(data, st.st_size) == KO)
        return KO;

    /* write the compressed file */
    file_path_compressed = get_file_path_compressed(file_path);
    if (!file_path_compressed)
        return KO;
    file = fopen(file_path_compressed, "wb");
    if (!file) {
        data->err_sys = true;
        perror(file_path_compressed);
        return KO;
    }
    if (fwrite(data->compressed_file, 1, st.st_size, file) != (size_t) st.st_size) {
        data->err_sys = true;
        perror("write");
        return KO;
    }
    free(file_path_compressed);
    fclose(file);

    /* free file content */
    free(data->file);
    free(data->compressed_file);
    return OK;
}
