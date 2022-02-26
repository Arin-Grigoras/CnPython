#include "../../../cnpython/headers/cnpython.h"


int main(void){
    //Allocates memory on the heap
    string str = new_String("hello, world!");

    print(str);

    if(str_islower(str) == True){
        print("Variable 'str' is all lowercase");
    }
    else{
        print("Variable 'str' isn't all lowercase");
    }

    return 0;
}