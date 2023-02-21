#include <string.h>
#include <stdio.h>
#include "../../cnpython/include/cnpython.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * @brief Justify the given string to the right of a new string
 * 
 * @param str The string to be justified
 * @param len The len of the fill offset and the string itself
 * @param fill The character to be filled
 * @return string The new string that right-justified the old string
 */
string rjust(string str, const size_t len, const char fill){
    size_t strLen = strlen(str);
    if (len < strLen)
        return NULL;

    string ret    = malloc(len + 1);

    if (!ret){
        fprintf(stderr, "ERROR: rjust function: Can't allocating memory");
        exit(1);
    }
    memset(ret, fill, len - strLen);
    memcpy(ret + (len - strLen), str, strLen);

    return ret;
}


/**
 * @brief Justify the given string to the left of a new string
 * 
 * @param str The string to be justified
 * @param len The len of string and the fill offset
 * @param fill The character to be filled
 * @return string The new string that left-justified the old string
 */
string ljust(string str, const size_t len, const char fill){
    size_t strLen = strlen(str);
    if (len < strLen)
        return NULL;

    string ret    = malloc(len + 1);

    if (!ret){
        fprintf(stderr, "ERROR: ljust function: Can't allocating memory");
        exit(1);
    }

    memcpy(ret, str, strLen);
    memset(ret + strLen, fill, len - strLen);

    return ret;
}


/**
 * @brief Basically right-justified but auto fill with zero (ascii value) instead 
 * 
 * @param str The string to be justified
 * @param len The len of string and the fill offset
 * @return char* The new string that right-justified and fills with zero
 */
char* zfill(string str, size_t len){
    string ret = rjust(str, len, '0');

    return ret;
}

int main(){
    string strL = "To The Left";
    string strR = "To The Right";
    string strZ = "Put Zero";

    string strL_just = ljust(strL, 20, '-');
    string strR_just = rjust(strR, 20, '-');
    string strZ_just = zfill(strR, 20);

    printf("%s\n%s\n%s\n", strL_just, strR_just, strZ_just);

    return 0;
}