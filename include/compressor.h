/*
** EPITECH PROJECT, 2025
** compressor.h
** File description:
** Compressor header
*/

#ifndef COMPRESSOR_H
    #define COMPRESSOR_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stdbool.h> // boolean

//----------------------------------------------------------------//
/* TYPEDEF */

/* data */
typedef struct main_data_s {
    /* error */
    bool err_sys;
} main_data_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* compressor */ // Error: KO
int compressor(int const argc, char const *argv[], main_data_t *data);

/* init_data */
int init_data(main_data_t *data); // Error: KO
int init_global(main_data_t *data); // Error: KO

/* init_flag */
int init_flag(main_data_t *data,
    int const argc, char const *argv[]); // Error: KO
int flag_help(void); // Error: KO
int flag_null(main_data_t *data,
    int const argc, char const *argv[], int const i); // Error: KO

/* exit */
int free_data(main_data_t *data); // Error: EPITECH_ERR

//----------------------------------------------------------------//
/* GLOBAL_CONST */

/* flag */
extern char const flags[];
extern char const *full_flags[];
extern int const flags_argc[];
extern int (* const flag_functions[])(main_data_t *,
    int const, char const *[], int const);

#endif /* COMPRESSOR_H */
