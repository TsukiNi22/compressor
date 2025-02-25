/*
** EPITECH PROJECT, 2025
** hashtable.h
** File description:
** Header for the hashtable function
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "linked.h" // linked_list_t

//----------------------------------------------------------------//
/* TYPDEF */

/* linked_data */
typedef struct hash_linked_data_s {
    int index;
    char *key;
    char *value;
} hash_linked_data_t;

/* hash_table */
typedef struct hashtable_s {
    int keys_nbr;
    int len;
    int (*hash)(char *, int);
    linked_list_t **linked;
} hashtable_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* hash_function */
int hash(char *key, int len); // Error: KO

/* edit */
hashtable_t *new_hashtable(int (*hash_function)(char *, int),
    int len); // Error: NULL
int delete_hashtable(hashtable_t *ht); // Error: KO
int ht_insert(hashtable_t *ht, char *key, char *value); // Error: KO
int ht_delete(hashtable_t *ht, char *key); // Error: KO
int free_hash_data(void *data); // Error: KO
int free_hash_keys(char **keys); // Error: KO

/* retrieve */
char **ht_keys(hashtable_t *ht); // Error: NULL
char *ht_search(hashtable_t *ht, char *key); // Error: NULL

#endif /* HASHTABLE_H */
