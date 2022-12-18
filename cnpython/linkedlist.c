#include "./include/datastructures/linkedlist.h"


/*print the linked list*/
void ll_print(node_t *head){
    node_t *c = head;
    //looping through the linked list
    while(c != NULL){
        //printing every node's data
        print("%d", c->data);
        c = c->next;
    }
}



/*push to the linked list a value*/
void ll_push_end(node_t *head, int data){
    node_t *c = head;
    //looping to the end of the linked list
    while(c->next != NULL){
        c = c->next;
    }

    //creating a new node at the end of the list
    c->next = (node_t*)malloc(sizeof(node_t));
    //sets the new node's value
    c->next->data = data;
    c->next->next = NULL;
}


void ll_push_beg(node_t **head, int data){
    //creating a new node
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    //setting it's value
    new_node->data = data;
    //setting it's position at the beggining
    new_node->next = *head;
    *head = new_node;
}



/*pop from the linked list*/
int ll_pop_first(node_t **head){
    int retval = -1;
    node_t *next_node = NULL;

    //if head == NULL
    if(!*head){
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->data;
    free(*head);
    *head = next_node;

    return retval;
}

int ll_pop_last(node_t *head)
{
    int retval = 0;

    // if there's only one element in the list it removes it
    if (head->next == NULL){
        retval = head->data;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */

    node_t *c = head;
    while(c->next->next != NULL){
        c = c->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = c->next->data;
    free(c->next);
    c->next = NULL;
    return retval;
}


int remove_by_index(node_t **head, int n){
    int retval = -1;
    node_t *c = *head;
    node_t *temp = NULL;

    if(n == 0){
        return ll_pop_first(head);
    }

    for(int i = 0; i < n-1; i++){
        if(c->next == NULL){
            return -1;
        }
        c = c->next;
    }

    if(c->next == NULL){
        return -1;
    }

    temp = c->next;
    retval = temp->data;
    c->next = temp->next;
    free(temp);


    return retval;
}