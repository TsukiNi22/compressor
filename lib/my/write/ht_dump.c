/*
** EPITECH PROJECT, 2025
** ht_dump.c
** File description:
** Print the hashtable
*/

#include "write.h"
#include "hashtable.h"
#include "error.h"
#include "define.h"

static int print_linked(linked_list_t *temp)
{
    hash_linked_data_t *data = NULL;
    int res = OK;

    if (!temp)
        return err_prog(PTR_ERR, "In: print_linked", KO);
    data = (hash_linked_data_t *)temp->data;
    res += my_printf("> %d - \"%s\" - \"%s\"\n",
    data->index, data->key, data->value);
    if (res < 0)
            return err_prog(UNDEF_ERR, "In: print_linked", KO);
    return OK;
}

int ht_dump(hashtable_t *ht)
{
    int res = OK;

    if (!ht)
        return err_prog(PTR_ERR, "In: ht_dump", KO);
    for (int i = 0; i < ht->len; i++) {
        res += my_printf("[%d]:\n", i);
        for (linked_list_t *tmp = ht->linked[i]; tmp; tmp = tmp->next)
            res += print_linked(tmp);
        if (res < 0)
            return err_prog(UNDEF_ERR, "In: ht_dump", KO);
    }
    return OK;
}
