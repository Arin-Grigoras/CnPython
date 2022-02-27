#ifndef CNPY_DICT
#define CNPY_DICT


#include "./cnpy_entry.h"
#include "../binarySearchTree/cnpy_BinarySearchTree.h"


struct Dictionary
{
    struct BinarySearchTree binary_search_tree;

    void (*insert)(struct Dictionary *dict, void *key, int key_size, void *value, int size_value);
    void *(*search)(struct Dictionary *dict, void *key);
};


struct Dictionary dictionary_constructor(int (*compare)(void *key1, void *key2));
struct Dictionary dictionary_destructor(struct Dictionary *dict);

#endif //CNPY_DICT