#ifndef CYTHON_H
#define CYTHON_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Converts any decimal value to a binary value*/
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



/*This functions gives a summary of all the functions that are in this project*/
void help(){
        printf("\n\t\tCYTHON HELP\n\n");
        printf("\n*bin -> bin(decimal) converts a decimal number into binary form\n");
        printf("\nhex -> hex(decimal) converts a decimal number into hexadecimal form\n");
}



/*Converts any decimal value to a hexadecimal value*/
void hex(long n)
{
        char *hexaDeciNum = (char*)malloc(sizeof(char) * 100);

        if(!hexaDeciNum){
                printf("\n\nERROR: hex() function error\nCouldn't allocate memory\n\n");
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



/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
char *input(char *str){
        int bufsize = 100;
        int position = 0;
        char *buffer = (char*)malloc(sizeof(char) * bufsize);
        int c;

        if (!buffer) {
                printf("\n\nERROR: input() function error\nCouldn't alocate memory\n\n");
                exit(1);
        }

        printf("%s", str);

        while (1) {

                c = getchar();

                if (c == EOF || c == '\n') {
                        buffer[position] = '\0';
                        return buffer;
                } else {
                        buffer[position] = c;

                }

                position++;

                if (position >= bufsize) {
                bufsize += 100;
                buffer = (char*)realloc(buffer, bufsize);
                        if (!buffer) {
                                printf("\n\nError: REALLOCATION error\n\n");
                                exit(EXIT_FAILURE);
                        }
                }
        }

        return buffer; 
}




#endif //CYTHON_H
