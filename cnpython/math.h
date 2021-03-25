#include <stdio.h>
#include <stdlib.h>


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


long oct(long dec){
        long octalNumber = 0; 
        int i = 1;

        while (dec != 0){
                octalNumber += (dec % 8) * i;
                dec /= 8;
                i *= 10;
        }

        return octalNumber;
}


double pow(double base, double exponent){
        double result = 1;
        for(exponent; exponent > 0; exponent--){
                result *= base;
        }

        return result;
}



int factorial(int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n - 1);
}



int rem(int a, int b){
        return a - (a/b*b);
}


double percentage(float p, float n){
        return p * n / 100;
}