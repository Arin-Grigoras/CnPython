#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/*

This approach doesn't work at all

int str_islower(char* str){
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            total++;
        }
        else{
            whitespaces++;
        }
    }

    if(total == str_size - whitespaces){
        return 1;
    }

    return 0;
}*/


int str_islower(char *str){
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(islower(str[i])){
            total++;
        }else if(isupper(str[i])){
            return 0;
        }else{
            whitespaces++;
        }
    }

    if(total = str_size - whitespaces){
        return 1;
    }

    return 0;
}


int main(void){
    char *str1 = malloc(sizeof(char) * 15);
    char *str2 = malloc(sizeof(char) * 15);

    if(!str1){
        printf("Error\n");
        return 1;
    }

    if(!str2){
        printf("Error\n");
        return 1;
    }

    strcpy(str1, "hello, there!");
    strcpy(str2, "HELLO THERE!");

    if(str_islower(str1) == 1){
        printf("str1: True\n");
    }

    else{
        printf("str1: False\n");
    }

    if(str_islower(str2) == 1){
        printf("str2: True\n");
    }

    else{
        printf("str2: False\n");
    }


    free(str1);
    free(str2);

    return 0;
}