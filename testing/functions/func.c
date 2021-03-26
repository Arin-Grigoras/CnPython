#include <stdio.h>
#include "../../cnpython/cnpython.h"


var name(var name){
    return name;
}

var add(int a, int b){
    return a + b;
}


var main(void){

    print("Hello world");

    printf("%d\n", add(1, 2));

    return 0;
}