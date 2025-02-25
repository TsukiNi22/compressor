/*
** EPITECH PROJECT, 2025
** ht_search.c
** File description:
** Retrive the data of the given key
*/

#include "my_string.h"
#include "define.h"
#include "hashtable.h"
#include "error.h"

char *ht_search(hashtable_t *ht, char *key)
{
    linked_list_t *linked = NULL;
    int index = 0;

    if (!ht || !key)
        return err_prog_n(PTR_ERR, "In: ht_delete");
    index = ht->hash(key, ht->len);
    linked = ht->linked[index % ht->len];
    for (; linked && (((hash_linked_data_t *) linked->data)->index != index
    || my_strcmp(((hash_linked_data_t *) linked->data)->key, key) != 0);
    linked = linked->next);
    if (!linked)
        return err_custom_n("There is no data for this key");
    return ((hash_linked_data_t *) linked->data)->value;
}
