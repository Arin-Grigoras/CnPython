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
        printf("\n*bin -> bin(decimal) converts a decimal number into binary form\n");
        printf("\nhex -> hex(decimal) converts a decimal number into hexadecimal form\n");
}




void hex(int n)
{
        char *hexaDeciNum = (char*)malloc(sizeof(char) * 100);

        if(!hexaDeciNum){
                printf("\n\nERROR: Hex() function error\nCouldn't allocate memory\n\n");
                exit(1);
        }
 
        int i = 0;
        while (n != 0) {
                int temp = 0;
 
                temp = n % 16;
 
                if (temp < 10) {
                        hexaDeciNum[i] = temp + 48;
                        i++;
                }
                else {
                        hexaDeciNum[i] = temp + 55;
                        i++;
                }
 
                        n = n / 16;
                }

        printf("0x");

        for(int j = i - 1; j >= 0; j--){
                printf("%c", hexaDeciNum[j]);
        }

}





#endif //CYTHON_H
