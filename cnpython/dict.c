#include "./headers/datatypes/dict/cnpy_dict.h"



void insert(struct Dictionary *dict, void *key, int key_size, void *value, int size_value);
void * search(struct Dictionary *dict, void *key);



struct Dictionary dictionary_constructor(int (*compare)(void *key1, void *key2))
{
    struct Dictionary dict;

    dict.binary_search_tree = binary_search_tree_constructor(compare);
    dict.insert = insert;
    dict.search = search;


    return dict;
}


void insert(struct Dictionary *dict, void *key, int key_size, void *value, int size_value)
{
    
}