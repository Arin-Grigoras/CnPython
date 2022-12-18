#ifndef STACK_H
#define STACK_H


#include "../cnpython.h"


typedef struct StackNode{
    int data;
    snode_t *next;
}snode_t;


snode_t *stack_newNode(int data);
int stack_isEmpty(snode_t *root);
void stack_push(snode_t **root, int data);
int stack_pop(snode_t **root);
int stack_peek(snode_t *root);






#endif //STACK_H