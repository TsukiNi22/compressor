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
##  compressor.h

File Description:
##  Compressor header
\**************************************************************/

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

    /* extension */
    #define EXTENSION_CR ".crped"
    #define EXTENSION_UCR ".ucrped"

//----------------------------------------------------------------//
/* TYPEDEF */

/* info */
typedef union info_u {
    unsigned long long value;
    unsigned char str[8];
} info_t;

/* data */
typedef struct main_data_s {
    /* init_status */
    bool calculate;
    bool undo;

    /* global const */
    char precision; // 1 <-> 17 // 24
    unsigned int round;
    unsigned int max;
    unsigned int redution_size;
    
    /* global var */
    unsigned int octet;
    int round_nb;
    unsigned char *file;
    unsigned char *compressed_file;
    unsigned char *decompressed_file;

    /* help */
    bool help;
    
    /* error */
    bool err_sys;
} main_data_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* compressor */
int compressor(int const argc, char const *argv[], main_data_t *data); // Error: KO
int bits_compressor(int precision, int max, info_t *info, unsigned int a, unsigned int b); // Error: KO
int bits_decompressor(int precision, int max, info_t *info, unsigned int *a, unsigned int *b); // Error: KO
int calculate(main_data_t *data, char const *file_path); // Error: KO
int decompress_file(main_data_t *data, char const *file_path); // Error: KO
int compress_file(main_data_t *data, char const *file_path); // Error: KO

/* init_data */
int init_data(main_data_t *data); // Error: KO

/* init_flag */
int init_flag(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_help(void); // Error: KO
int flag_null(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_undo(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_precision(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_round(main_data_t *data, int const argc, char const *argv[]); // Error: KO
int flag_calculate(main_data_t *data, int const argc, char const *argv[]); // Error: KO

/* exit */
int free_data(main_data_t *data); // Error: KO

//----------------------------------------------------------------//
/* GLOBAL_CONST */

/* flag */
extern char const flags[];
extern char const *full_flags[];
extern int const flags_argc[];
extern int (* const flag_functions[])(main_data_t *, int const, char const *[]);

#endif /* COMPRESSOR_H */
