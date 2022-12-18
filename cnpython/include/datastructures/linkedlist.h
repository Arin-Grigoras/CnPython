#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "../cnpython.h"

/*struct*/
typedef class node{
    int data;
    struct node* next;
}node_t;


void ll_print(node_t *head);
void ll_push_end(node_t *head, int data);
void ll_push_beg(node_t **head, int data);
int ll_pop_first(node_t **head);
int ll_pop_last(node_t *head);
int ll_remove_by_index(node_t **head, int n);
void ll_remove_by_value(node_t **head, int val);



#endif //LINKEDLIST_H