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
    /* DEFINE */    

    /* size */
    #define GREATER_SIZE 1
    #define OVERFLOW_SIZE 1
    #define ZERO_NB_SIZE 5
    #define INT_BITS_SIZE 32

//----------------------------------------------------------------//
/* TYPEDEF */

/* info */
typedef union info_u {
    unsigned long long value;
    char str[7];
} info_t;

/* data */
typedef struct main_data_s {
    /* init_status */
    bool b_precision;
    bool b_round;
    bool calculate;

    /* global const */
    char precision; // 1 <-> 17 // 25
    unsigned int round;
    unsigned int max;
    unsigned int redution_size;

    /* error / help */
    bool help;
    bool err_sys;
} main_data_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* compressor */ // Error: KO
int compressor(int const argc, char const *argv[], main_data_t *data);
int compress_data(int precision, int max, info_t *info, unsigned int a, unsigned int b);
int decompress_data(int precision, int max, info_t *info, unsigned int *a, unsigned int *b);

    /* init_data */
int init_data(main_data_t *data); // Error: KO
int init_global(main_data_t *data); // Error: KO

/* init_flag */
int init_flag(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_help(void); // Error: KO
int flag_null(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_precision(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_round(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_calculate(main_data_t *data, int const argc, char const *argv[]); // Error: KO

/* exit */
int free_data(main_data_t *data); // Error: EPITECH_ERR

//----------------------------------------------------------------//
/* GLOBAL_CONST */

/* flag */
extern char const flags[];
extern char const *full_flags[];
extern int const flags_argc[];
extern int (* const flag_functions[])(main_data_t *, int const, char const *[]);

#endif /* COMPRESSOR_H */
