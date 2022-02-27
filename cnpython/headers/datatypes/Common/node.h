#ifndef NODE_H
#define NODE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    void *data;

    struct Node *next;
    struct Node *previous;
};


/*Constructor for node struct used to create nodes*/
struct Node node_constructor(void *data, unsigned long size);

/*Destructor for node struct used to delete nodes*/
void node_destructor(struct Node *node);


#endif //NODE_H