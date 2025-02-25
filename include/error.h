/*
** EPITECH PROJECT, 2025
** error.h
** File description:
** Header for the error handling / error code
*/

#ifndef ERROR_H
    #define ERROR_H

    //----------------------------------------------------------------//
    /* DEFINE */

    /* error_return_write */
    #define PUT_ERROR 0
    #define CUSTOM_PUT_ERROR 0
    #define SYSTEM_PUT_ERROR 1

    /* error_return */
    #ifndef KO
        #define KO -1
    #endif /* KO */
    #ifndef OK
        #define OK 0
    #endif /* OK */
    #ifndef FATAL_ERR
        #define FATAL_ERR 255
    #endif /* FATAL_ERR */
    #ifndef ERROR
        #define ERROR 84
    #endif /* ERROR */
    #ifndef ERR
        #define ERR 84
    #endif /* ERR */
    #define EPITECH_ERR 84

    /* error_code */
    #define MIN_ERROR_CODE ERROR_ERR
    #define MAX_ERROR_CODE FLAG_ERR

    //----------------------------------------------------------------//
    /* MACRO */

    /* err_macro */
    #define ERR_D(er, msg, ret, c) if (c) return err_prog(er, msg, ret)
    #define ERR_DN(err, msg, c) if (c) return err_prog_n(err, msg)
    #define ERR_DV(err, msg, c) if (c) return err_prog_v(err, msg)
    #define ERR_C(msg, ret, c) if (c) return err_custom(msg, ret)
    #define ERR_CN(msg, c) if (c) return err_custom_n(msg)
    #define ERR_CV(msg, c) if (c) return err_custom_v(msg)
    #define ERR_S(msg, c) if (c) return err_system(msg)
    #define ERR_SN(msg, c) if (c) return err_system_n(msg)
    #define ERR_SV(msg, c) if (c) return err_system_v(msg)

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "compressor.h" // main_data_t
    #include <stdbool.h> // boolean

//----------------------------------------------------------------//
/* TYPDEF */

/* error_code */
typedef enum error_code_e {
    ERROR_ERR = -2,
    UNDEF_ERR = -1,
    PTR_ERR = 0,
    MALLOC_ERR,
    WRITE_ERR,
    ARGC_ERR,
    ARGV_ERR,
    FLAG_ERR,
    OVERFLOW,
    OP_FILE_ERR,
    READ_FILE_ERR,
    OP_DIR_ERR,
    READ_DIR_ERR
} error_code_t;

/*
** For more detail in the error, look in /lib/my/error/error_dispatch.c
*/

//----------------------------------------------------------------//
/* PROTOTYPE */

/* error_handling */ // Error: None
void err_prog_v(error_code_t code, char *error_info);
void *err_prog_n(error_code_t code, char *error_info);
int err_prog(error_code_t code, char *error_info, int to_return);
void err_custom_v(char *error_info);
void *err_custom_n(char *error_info);
int err_custom(char *error_info, int to_return);
void err_system_v(main_data_t *data, char *error_info);
void *err_system_n(main_data_t *data, char *error_info);
int err_system(main_data_t *data, char *error_info, int to_return);

/* print_error_ouput */
void error_error(void); // Error: None
void print_error(error_code_t code); // Error: None
void print_error_info(char *error_info, bool custom); // Error: None
int dispatch(error_code_t code); // Error: KO

#endif /* ERROR_H */
