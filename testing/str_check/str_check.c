#include <string.h>
#include <stdio.h>
#include "../../cnpython/include/cnpython.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//Some more checking method for string

bool isspace_str(string str){
    bool ret = true;
    size_t i = 0;

    while (str[i] != '\0'){
        if (str[i] != ' ')
            ret = false;
        i++;
    }

    return ret;
}

bool isprintable_str(string str){
    size_t strLen = strlen(str);
    bool ret = true;

    for (int i = 0; i < strLen; i++)
        if (!isprint(str[i]))
            ret = false;

    return ret;
}

bool isdigit_str(string str){
    size_t strLen = strlen(str);
    bool ret = true;

    for (int i = 0; i < strLen; i++)
        if (!isdigit(str[i]))
            ret = false;

    return ret;
}

bool isidentifier_str(string str){
    size_t strLen = strlen(str);
    bool ret = true;

    if (isdigit(str[0]))
        return false;
    else{
        for (int i = 0; i < strLen; i++){
            if (str[i] == ' ')
                return false;

            if (!isalnum(str[i]) && str[i] != '_')
                ret = false;
        }
    }
    return ret;
}

int main(){
    bool space_check = isspace_str("         ");
    bool printable_check = isprintable_str("AllIsPrintable"); 
    bool digit_check = isdigit_str("09084823217");
    bool identifier_check = isidentifier_str("THIS2_"); 

    printf("%s\n%s\n%s\n%s\n", space_check ? "True" : "False", printable_check ? "True" : "False",  digit_check ? "True" : "False", identifier_check ? "True" : "False" );
    return 0;
}