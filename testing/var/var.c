#include <stdio.h>
#include <stdint.h>
#include "../../cnpython/headers/cnpython.h"

typedef void* var;

extern var Int;
extern var String;
extern var Double;
extern var Float;
extern var Char;
extern var Long;
extern var Int_Arr;
extern var Function;

struct Int{
    int64_t val;
};

struct String{
    char *val;
};

struct Double{
    double val;
};

struct Float{
    float val;
};

struct Char{
    char val;
};

struct Long{
    long val;
};


struct Function{
    var (*func)(var);
};

var hello(){
    print("Hello world");
}

/*
Doesn't really work
*/
var add(var a, var b){
    var result = a + b;
    return result;
}

int main(void){
    print("%d", add(1, 2));
}
