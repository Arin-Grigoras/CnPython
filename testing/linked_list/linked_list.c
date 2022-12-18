#include "../../cnpython/include/datastructures/linkedlist.h"



void ll_remove_by_value(node_t **head, int val){
    node_t *temp = *head, *prev;

    if(temp != NULL && temp->data == val){
        *head = temp->next;
        free(temp);
    }

    while(temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;

    free(temp);
}



int main(void){

    node_t *head = NULL;


    ll_push_beg(&head, 7);
    ll_push_beg(&head, 2);
    ll_push_beg(&head, 3);
    ll_push_beg(&head, 8);
    ll_push_beg(&head, 10);

    print("Created linked list: ");
    ll_print(head);
    ll_remove_by_value(&head, 3);
    print("Linked list after deletion of '3'");
    ll_print(head);

    return 0;
}