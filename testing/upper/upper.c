#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    FAILED AS WELL
*/

char *upper(char *str){
    char *upper;

    strcpy(upper, str);

    while(*upper){
        *upper = toupper((unsigned char) *upper);
        upper++;
    }

    return upper;
}

int main(void){
    char *str = "hello world";
    printf("%s", upper(str));
}