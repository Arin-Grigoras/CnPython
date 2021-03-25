#include <stdio.h>
#include <stdint.h>
#include "../../cnpython/print.h"

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

int main(void){
    hello();
}
