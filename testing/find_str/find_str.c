#include <string.h>
#include <stdio.h>
#include "../../cnpython/include/cnpython.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * @brief Find the substring inside a string. Supporting search zone feature. Set negative value at end offset for end of the string
 * 
 * @param str The given string
 * @param value The substring to be found inside str
 * @param start The offset of when to start
 * @param end The end range
 * @return ptrdiff_t Return the index of the first character of the substring when found. Else, -1 is returned
 */
ptrdiff_t find_str(string str, string value, const unsigned int start, const int end){
    if (end > 0){
        size_t strLen = strlen(str);
        string copy = malloc(strLen);

        strncpy(copy, str, strLen);
        //Since we only find until "end" index
        copy[end] = '\0';
        
        char* strstrRet = strstr(copy + start, value);
        return strstrRet == NULL ? -1 : strstrRet - copy;
    }

    char* strstrRet = strstr(str + start, value);
    return strstrRet == NULL ? -1 : strstrRet - str;
}

/**
 * @brief Works just like the find method. However, an error is thrown when not found then given value
 */
ptrdiff_t index_str(string str, string value, const unsigned int start, const int end){
    char* strstrRet;
    if (end > 0){
        size_t strLen = strlen(str);
        string copy   = malloc(strLen);

        strncpy(copy, str, strLen);
        //Since we only find until "end" index
        copy[end] = '\0';
        
        strstrRet = strstr(copy + start, value);
        if (strstrRet == NULL){
            fprintf(stderr, "ValueError: substring not found, given: \"%s\"\n", value);
            exit(1);
        }
    }else{
        strstrRet = strstr(str + start, value);
        if (strstrRet == NULL){
            fprintf(stderr, "ValueError: substring not found, given: \"%s\"\n", value);
            exit(1);
        }
    }

    return strstrRet - str;
}

int main(){
    int pos = find_str("This is a string", "is", 5, -1);
    printf("The first postion of the string \"is\" is %d\n", pos);

    int not_real_pos = find_str("This is a string", "zer", 5, -1);
    printf("The first postion of the string \"zer\" is %d\n", not_real_pos);

    pos = index_str("This is a string", "is", 5, -1);
    printf("The first postion of the string \"is\" is %d\n", pos);

    not_real_pos = index_str("This is a string", "zer", 5, -1);
    printf("The first postion of the string \"zer\" is %d\n", not_real_pos);

    return 0;
}