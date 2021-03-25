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


int main(void){
    var w = 20;
    var str = "hello";
    print("%s", str);
}