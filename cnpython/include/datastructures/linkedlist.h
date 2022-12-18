#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "../cnpython.h"


class node_t{
    int data;
    struct node* next;
};

void ll_print(node_t *head);
void ll_push_end(node_t *head, int data);
void ll_push_beg(node_t **head, int data);
int ll_pop_first(node_t **head);
int ll_pop_last(node_t *head);
int ll_pop_index(node_t **head, int n);



#endif //LINKEDLIST_H