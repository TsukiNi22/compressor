/*
** EPITECH PROJECT, 2025
** decompress_file.c
** File description:
** Decompress the given file
*/

#include "compressor.h"
#include "error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdbool.h>

void print_binary(unsigned long long val, int bits)
{
    for (int i = bits - 1; i >= 0; --i) {
        printf("%lld", (val >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

/* compress the file */
static int decompress(main_data_t *data, int size)
{
    unsigned int compressed_index = 0;
    unsigned int a, b = 0;
    info_t info = {0};

    /* function argument check */
    if (!data)
        return KO;

    /* set the number of round + precision used */
    data->round_nb = 0;
    for (int j = 0; j < 4; j++)
        data->round_nb += (data->file[j] << 8 * (3 - j)) & 0xFF;
    data->precision = data->file[4];

    /* compress file */
    data->round_nb--;
    for (int index, i = 0; i < (size - 5) / 8; i++) {
        index = i * 8;
        a = 0;
        b = 0;
        info.value = 0;
        for (int j = 0; j < 8; j++)
            info.value += (((unsigned long long) data->file[index + j + 5]) & 0xFF) << 8 * (7 - j);
        if (bits_decompressor(data->precision, data->max, &info, &a, &b) == KO)
            return KO;
        print_binary(a, 32);
        print_binary(b, 32);
        for (int j = 0; j < 4; j++, compressed_index++)
            data->decompressed_file[compressed_index] = (a >> 8 * (3 - j)) & 0xFF;
        for (int j = 0; j < 4; j++, compressed_index++)
            data->decompressed_file[compressed_index] = (b >> 8 * (3 - j)) & 0xFF;
        data->octet += 8;
    }

    /* set the number of octet to write in the compressed file */
    return OK;
}

/* get the new path to a file with the new extension */
static char *get_file_path_decompressed(char const *file_path)
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
    for (len[1] = 0; EXTENSION_UCR[len[1]]; len[1]++);
    path = malloc(sizeof(char) * (len[0] + len[1] + 1));
    if (!path)
        return NULL;

    /* set the new path with the right extension */
    memset(path, 0, (len[0] + len[1] + 1));
    for (int j = 0; file_path[j] && &(file_path[j]) != ptr; i++, j++)
        path[i] = file_path[j];
    for (int j = 0; EXTENSION_UCR[j]; i++, j++)
        path[i] = EXTENSION_UCR[j];
    return path;
}

/* decompress the files given */
int decompress_file(main_data_t *data, char const *file_path)
{
    FILE *file = NULL;
    struct stat st = {0};
    char *file_path_decompressed = NULL;

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
    if (data->decompressed_file)
        free(data->decompressed_file);
    data->file = malloc(sizeof(char) * (st.st_size + 1));
    data->decompressed_file = malloc(sizeof(char) * (st.st_size * 2 + 1));
    if (!data->file || !data->decompressed_file) {
        data->err_sys = true;
        perror("malloc");
        return KO;
    }
    memset(data->file, 0, (st.st_size + 1));
    memset(data->decompressed_file, 0, (st.st_size * 2 + 1));
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
    if (decompress(data, st.st_size) == KO)
        return KO;

    /* write the compressed file */
    file_path_decompressed = get_file_path_decompressed(file_path);
    if (!file_path_decompressed)
        return KO;
    file = fopen(file_path_decompressed, "wb");
    if (!file) {
        data->err_sys = true;
        perror(file_path_decompressed);
        return KO;
    }
    if (fwrite(data->decompressed_file, 1, data->octet, file) != (size_t) data->octet) {
        data->err_sys = true;
        perror("write");
        return KO;
    }
    free(file_path_decompressed);
    fclose(file);

    /* free file content */
    free(data->file);
    free(data->decompressed_file);
    return OK;
}
