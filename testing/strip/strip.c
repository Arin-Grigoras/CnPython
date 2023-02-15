#include <string.h>
#include <stdio.h>
#include "../../cnpython/include/cnpython.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * @brief Trim of the heading and the trailing of any character that met inside the strip_content
 * 
 * @param str The string to be trimmed
 * @param strip_content The delimiter for trimming
 * @return string The new string that got trimmed the heading and the trailing
 */
string strip(string str, string strip_content){
    size_t start  = 0;
    size_t strLen = strlen(str);
    size_t end    = strLen - 1;
    string ret   = calloc(strLen, 1);
    int    i;

    //Trim the leading
    while (strchr(strip_content, str[end]))
        end--;
    
    //Trim the trailing
    while (strchr(strip_content, str[start]))
        start++;

    //Start copying data
    for (i = 0; i <= end - start; i++)
        ret[i] = str[i + start];
    
    ret[i] = '\0';

    ret = realloc(ret, strlen(ret) + 1);

    return ret;
}

int main(){
    string str = "......,..:::,.!^^Trimmed all but this . (dot) right here..,...^^,,,::.";

    string trimmed_str = strip(str, ".,:!^");

    printf("%s\n", trimmed_str);
    return 0;
}