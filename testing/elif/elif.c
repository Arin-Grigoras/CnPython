#include <stdio.h>

#define elif else if

int main(void){
    if(1 < 0){
        printf("something");
    }
    elif(0 < 1){
        printf("Elif works");
    }
}