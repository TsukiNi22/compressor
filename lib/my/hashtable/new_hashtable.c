/*
** EPITECH PROJECT, 2025
** new_hashtable.c
** File description:
** Create a new hashtable
*/

#include "linked.h"
#include "define.h"
#include "hashtable.h"
#include "error.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash_function)(char *, int), int len)
{
    hashtable_t *ht = NULL;

    if (!hash_function)
        return err_prog_n(PTR_ERR, "In: new_hashtable");
    if (len < 1)
        return err_prog_n(ARGV_ERR, "In: new_hashtable");
    ht = malloc(sizeof(hashtable_t));
    if (!ht)
        return err_prog_n(MALLOC_ERR, "In: new_hashtable 1");
    ht->keys_nbr = 0;
    ht->len = len;
    ht->hash = hash_function;
    ht->linked = malloc(sizeof(linked_list_t *) * len);
    for (int i = 0; i < len; i++)
        ht->linked[i] = NULL;
    if (!ht->linked)
        return err_prog_n(MALLOC_ERR, "In: new_hashtable 2");
    return ht;
}
