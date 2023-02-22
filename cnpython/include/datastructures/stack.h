#ifndef STACK_H
#define STACK_H


#include "../cnpython.h"


typedef struct StackNode{
    int data;
    struct StackNode *next;
}snode_t;


struct StackNode *stack_newNode(int data);
int stack_isEmpty(snode_t *root);
void stack_push(snode_t **root, int data);
int stack_pop(snode_t **root);
int stack_peek(snode_t *root);






#endif //STACK_H