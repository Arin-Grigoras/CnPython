#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


struct Tuple
{
    void *values;
};


extern const struct Tuple new_Tuple(void *value, ...)
{

}


extern void del_Tuple(struct Tuple *tuple)
{
    free(tuple->values);
    free(tuple);

}



int main(void){

}