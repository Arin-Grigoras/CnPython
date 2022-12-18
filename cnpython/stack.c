#include "./include/datastructures/stack.h"



snode_t *stack_newNode(int data){
    snode_t *stack_node = (snode_t *)malloc(sizeof(snode_t));
    stack_node->data = data;
    stack_node->next = None;

    return stack_node;
}


int stack_isEmpty(snode_t *root){
    return !root;
}

void stack_push(snode_t **root, int data){
    snode_t *stack_node = struct_newNode(data);
    stack_node->next = *root;
    *root = stack_node;

    //print("%d pushed to the stack", data);
}

int stack_pop(snode_t **root){
    if(stack_isEmpty(*root)){
        return INT_MIN;
    }
    snode_t *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}


int peek(snode_t *root){
    if(stack_isEmpty(root)){
        return INT_MIN;
    }
    return root->data;
}