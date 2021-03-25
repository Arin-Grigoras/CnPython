#include <stdio.h>
#include <string.h>

int isin(char *str, char value){
    for(int i = 0; i < strlen(str); i++){
        if(str[0] == value){
            return 0;
        }
    }

    return -1;
}

int main(void){
    char *str = "hello world";
    printf("%d", isin(str, 'h'));
}