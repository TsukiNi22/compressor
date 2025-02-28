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

/* compress the file */
static int compress(main_data_t *data)
{
    /* function argument check */
    if (!data)
        return KO;


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
    if (compress(data) == KO)
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
