/*
** EPITECH PROJECT, 2025
** write.h
** File description:
** Header for all function who print something
*/

#ifndef WRITE_H
    #define WRITE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* function */
    #include "printf.h" // my_printf

    /* type */
    #include "linked.h" // linked_list_t
    #include "hashtable.h" // hashtable_t
    #include "matrice.h" // matrice_t

    //----------------------------------------------------------------//
    /* DEFINE */

    /* write */
    #define RESET 0

//----------------------------------------------------------------//
/* TYPEDEF */

/* color */
typedef enum color_e {
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
} color_t;

typedef enum back_color_e {
    B_BLACK = 40,
    B_RED,
    B_GREEN,
    B_YELLOW,
    B_BLUE,
    B_MAGENTA,
    B_CYAN,
    B_WHITE
} back_color_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* edit_ouput */
int reset_ouput(int fd); // Error: KO
int set_strong(int fd); // Error: KO
int set_color(int fd, color_t color); // Error: KO
int set_back_color(int fd, back_color_t back); // Error: KO
int set_color_rgb(int fd, unsigned char r, unsigned char g,
    unsigned char b); // Error: KO

/* string */
int my_putchar(int fd, char const c); // Error: KO
int my_putstr(int fd, char const *str); // Error: KO
int my_show_word_array(char **array); // Error: KO

/* math */
int my_putnbr(int fd, long long nb); // Error: KO
int my_putnbr_base(int fd, unsigned long long nbr,
    char const *base); // Error: KO
int display_matrice(matrice_t *matrice); // Error: KO

/* other */
int display_linked(int (*display_data)(void *data),
    linked_list_t *head); // Error: KO
int ht_dump(hashtable_t *ht); // Error: KO

#endif /* WRITE_H */
