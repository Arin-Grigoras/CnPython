#ifndef CNPY_BINARY_SEARCH_TREE
#define CNPY_BINARY_SEARCH_TREE


//Standard Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//Own Includes
#include "../Common/node.h"





struct BinarySearchTree
{
    struct Node *head;

    int (*compare)(void *data1, void *data2);
    void * (*search)(struct BinarySearchTree *tree, void *data);
    void (*insert)(struct BinarySearchTree *tree, void *data, int size);
};

/*BinarySearchTree constructor*/
struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data1, void *data2));


/*Common things people might want to compare*/
int binary_search_tree_int_compare(void *data_one, void *data_two);
int binary_search_tree_float_compare(void *data_one, void *data_two);
int binary_search_tree_char_compare(void *data_one, void *data_two);
int binary_search_tree_str_compare(void *data_one, void *data_two);


#endif //CNPY_BINARY_SEARCH_TREE