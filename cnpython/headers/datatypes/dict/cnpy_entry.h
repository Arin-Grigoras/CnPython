//Header guard start

#ifndef CNPY_DICTIONARY_H
#define CNPY_DICTIONARY_H


//Includes
#include <stdlib.h>
#include <string.h>





struct Entry
{
    void *key;
    void *value;
};

struct Entry entry_constructor(void *key, int key_size, void *value, int value_size);
void entry_destructor(struct Entry *entry);


#endif //CNPY_DICTIONARY_H

//Header guard end