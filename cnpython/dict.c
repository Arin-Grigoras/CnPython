#include "./headers/datatypes_implementation/dict/cnpy_dict.h"



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


void *search(struct Dictionary *dict, void *key)
{
    void *result = dict->binary_search_tree.search(&dict->binary_search_tree, key);

    if(result)
    {
        return ((struct Entry *)result)->value;
    }

    return NULL;
}


void insert(struct Dictionary *dict, void *key, int key_size, void *value, int value_size)
{
    struct Entry entry = entry_constructor(key, key_size, value, value_size);
    dict->binary_search_tree.insert(&dict->binary_search_tree, &entry, sizeof(entry));

}