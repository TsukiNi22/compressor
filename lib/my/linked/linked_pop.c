/*
** EPITECH PROJECT, 2025
** linked_pop.c
** File description:
** Pop the last node
*/

#include "define.h"
#include "linked.h"
#include "error.h"
#include <stdlib.h>

static int pop_last(int (*free_func)(void *), linked_list_t **head)
{
    if (!free_func || !head)
        return err_prog(PTR_ERR, "In: pop_last", KO);
    free((*head)->acendant);
    free((*head)->size);
    free((*head)->mid_index);
    free((*head)->head);
    free((*head)->mid);
    free((*head)->tail);
    if (free_func((*head)->data) == KO)
        return err_prog(UNDEF_ERR, "In: pop_last", KO);
    free(*head);
    *head = NULL;
    return OK;
}

static int pop(int (*free_func)(void *), linked_list_t **head)
{
    linked_list_t *tmp = NULL;

    if (!free_func || !head)
        return err_prog(PTR_ERR, "In: pop", KO);
    tmp = *head;
    if (*((*head)->mid) == *head)
        *((*head)->mid) = (*head)->next;
    *head = (*head)->next;
    *((*head)->head) = *head;
    (*head)->previous = NULL;
    if (free_func(tmp->data) == KO)
        return err_prog(UNDEF_ERR, "In: pop", KO);
    free(tmp);
    return OK;
}

int linked_pop(int (*free_func)(void *), linked_list_t **head)
{
    if (!free_func || !head)
        return err_prog(PTR_ERR, "In: linked_pop", KO);
    if (!(*head))
        return OK;
    (*((*head)->size))--;
    (*((*head)->mid_index))--;
    if (linked_upd_mid(*head) == KO)
        return err_prog(UNDEF_ERR, "In: linked_pop 1", KO);
    if (!(*head)->next) {
        if (pop_last(free_func, head) == KO)
            return err_prog(UNDEF_ERR, "In: linked_pop 2", KO);
    } else {
        if (pop(free_func, head) == KO)
            return err_prog(UNDEF_ERR, "In: linked_pop 3", KO);
    }
    return OK;
}
