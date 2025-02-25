/*
** EPITECH PROJECT, 2025
** ht_insert.c
** File description:
** Insert a element in the ht
*/

#include "my_string.h"
#include "linked.h"
#include "define.h"
#include "hashtable.h"
#include "error.h"
#include <stdlib.h>

static int set_value(hash_linked_data_t *data, char *key, char *value,
    int index)
{
    if (!data || !key || !value)
        return err_prog(PTR_ERR, "In: set_value", KO);
    data->index = index;
    data->key = key;
    data->value = value;
    return OK;
}

int new_value(linked_list_t *linked, char *value)
{
    if (!linked || !value)
        return err_prog(PTR_ERR, "In: new_value", KO);
    free(((hash_linked_data_t *) linked->data)->value);
    ((hash_linked_data_t *) linked->data)->value = value;
    return OK;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    linked_list_t *linked = NULL;
    hash_linked_data_t *data = NULL;
    int index = 0;

    if (!ht || !key || !value)
        return err_prog(PTR_ERR, "In: ht_insert", KO);
    index = ht->hash(key, ht->len);
    for (linked = ht->linked[index % ht->len]; linked
    && (((hash_linked_data_t *) linked->data)->index != index
    || my_strcmp(((hash_linked_data_t *) linked->data)->key, key) != 0);
    linked = linked->next);
    if (linked)
        return new_value(linked, value);
    ht->keys_nbr++;
    data = malloc(sizeof(hash_linked_data_t));
    if (set_value(data, key, value, index) == KO)
        return err_prog(UNDEF_ERR, "In: ht_insert 1", KO);
    if (linked_add(&(ht->linked[index % ht->len]), data) == KO)
        return err_prog(UNDEF_ERR, "In: ht_insert 2", KO);
    return OK;
}
