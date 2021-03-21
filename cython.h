#ifndef CYTHON_H
#define CYTHON_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long bin(long decimal){
        long long bin = 0;
        int rem, i = 1, step = 1;
        while (decimal != 0) {
                rem = decimal % 2;
                decimal /= 2;
                bin += rem * i;
                 i *= 10;
         }
        printf("0b");
        return bin;
}




void help(){
        printf("\n\t\tCYTHON HELP\n\n");
        printf("*bin -> bin(decimal) converts a decimal number into binary form\n");
        
}





#endif //CYTHON_H
