#include <stdio.h>

#define and &&

int main(void){
    int a, b;
    a = 10;
    b = 10;
    if(a == b and b == a){
        printf("Works");
    }
}