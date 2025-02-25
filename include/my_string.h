/*
** EPITECH PROJECT, 2025
** char.h
** File description:
** Header for all thing who have a link with str
*/

#ifndef STRING_H
    #define STRING_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stdbool.h> // boolean

//----------------------------------------------------------------//
/* PROTOTYPE */

/* char_gestion */ // Error: NULL
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *concat_params(int argc, char **agrv);
char **my_str_to_str_array(char const *str, char const *identifier, bool take);
char *my_cut_str(const char *char_array, int before, int cut_place);
char *get_full_path(char const *cr_path, char const *file);

/* char_information  */
int my_strlen(char const *str); // Error: -1
char *my_strstr(char *str, char const *to_find); // Error: NULL
int count_occurence(char const *str, char const c); // Error: -1
int my_strfind(const char *char_array, const char find_char); // Error: -2
int my_get_index(char const *str, char const c); // Error: -2

/* char_comparaison */
int my_strcmp(char const *s1, char const *s2); // Error: 501
int my_strncmp(char const *s1, char const *s2, int n); // Error: 501
bool my_str_isalpha(char const *str); // Error: false
bool my_str_isnum(char const *str); // Error: false
bool my_str_isnumber(char const *str); // Error: false
bool my_str_islower(char const *str); // Error: false
bool my_str_isupper(char const *str); // Error: false
bool my_str_isprintable(char const *str); // Error: false
bool my_char_islower(char const c); // Error: false
bool my_char_isupper(char const c); // Error: false
bool my_str_is(char const *str, char const *char_in); // Error: false

/* int_float_to_str */
char *my_itoa(long long n); // Error: NULL
char *my_ftoa(long double n); // Error: NULL

/* str_to_int_float */
long long my_atoi(const char *char_array); // Error: 0
long double my_atof(const char *char_array); // Error: 0

#endif /* STRING_H */
