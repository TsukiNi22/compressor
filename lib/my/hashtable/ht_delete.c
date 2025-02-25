/*
** EPITECH PROJECT, 2025
** ht_delete.c
** File description:
** Delete a element in the ht
*/

#include "my_string.h"
#include "linked.h"
#include "define.h"
#include "hashtable.h"
#include "error.h"
#include <stdlib.h>

int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t *linked = NULL;
    int index = 0;

    if (!ht || !key)
        return err_prog(PTR_ERR, "In: ht_delete", KO);
    index = ht->hash(key, ht->len);
    linked = ht->linked[index % ht->len];
    for (; linked && (((hash_linked_data_t *) linked->data)->index != index
    || my_strcmp(((hash_linked_data_t *) linked->data)->key, key) != 0);
    linked = linked->next);
    if (!linked)
        return err_custom("There is no data for this key", KO);
    ht->keys_nbr--;
    if (linked_pop_this(&free_hash_data, &(ht->linked[index % ht->len]),
        linked) == KO)
        return err_custom("There is no data for this key", KO);
    return OK;
}
