#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../../cnpython/include/cnpython.h"

/*
    Worked now :)))
*/

string upper(string str){
    size_t strLen = strlen(str);
    string upperStr = malloc(strLen);
    //Or: char upperStr[strLen];

    strcpy(upperStr, str);

    for (size_t i = 0; i < strLen; i++)
        upperStr[i] = toupper(upperStr[i]);

    return upperStr;
}

int main(void){
    string str = "hello world";
    printf("%s", upper(str));
}
