#include <string.h>
#include <stdio.h>
#include "../../cnpython/include/cnpython.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/**
 * @brief Check whether the string is of title type (First character of all word must be uppercase)
 * 
 * @param str The string to be checked
 * @return true When the string obeys the rule, false when the string not obeys the rule or only contains number
 */
bool istitle(string str){
    bool           ret    = true;
    bool           char_flag = false; //Check the case where there's no character and only number
    size_t         len    = strlen(str);
    size_t         offsetS = 0;
    size_t         offsetE = 0;
    string         token;

    while (offsetE < len){
        while (isalpha(str[offsetE])){
            offsetE++;
            char_flag = true;
        }

        // Reach here when the delimiter was found
        for (int i = 0; i < offsetE - offsetS; i++){
                if (isalpha((str + offsetS)[i])){
                    if (i > 0){
                        if (!islower((str + offsetS)[i]))
                            return false;       
                    }   
                    else{
                        if (!isupper((str + offsetS)[i]))
                            return false;
                    }
                }
        }

        while (!isalpha(str[offsetE]))
            offsetE++;

        offsetS = offsetE;
    }

    return char_flag ? ret : false;
}

/**
 * @brief Turn the string to become title
 * 
 * @param str The string to be transform
 * @return string The new string that is obeys title form
 */
string title(string str){ 
    size_t len   = strlen(str);
    size_t i     = 0;
    string ret    = malloc(len + 1);

    if (!ret){
        fprintf(stderr, "ERROR: title function: Can't allocating memory");
        exit(1);
    }
    strncpy(ret, str, len);

    while (i < len){
        //Cycle through the non-alpha character
        while (!isalpha(str[i])){
            i++;

            if (i >= len)
                goto CHECK_DONE;
        }
        
        //And upper case the first one
        ret[i] = toupper(ret[i]);

        //Then cycle through until meeting a non-alpha again
        while (isalpha(str[i])){
            i++;

            if (i >= len)
                goto CHECK_DONE;
        }
        i++;
    }

    
    CHECK_DONE:
    return ret;    
}

int main(){
    string str = "hello b2b2b2 and 3g3g3g";

    string title_str = title(str);

    bool is_title_form = istitle(title_str);

    printf("%s\n", is_title_form ? "True" : "False");

    return 0;
}