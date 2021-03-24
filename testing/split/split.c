
#include <string.h>
#include "../../src/cnpython.h"
#include <stdlib.h>

size_t str_split(char ***array, char *str, const char *del) {
    	char *token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
        	*array = realloc(*array, sizeof(char *) * (i + 1));
		(*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return i;
}



void printSplit(char *str, const char *del){
    	char **split = NULL;
   	size_t count = str_split(&split, str, del);

    	for(size_t i = 0; i < count; i++) {
        	printf("[%s], ", split[i]);
    	}

    	free(split);
}



char **split(char **array, char *str, const char *del){
	char *token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
        	*array = realloc(*array, sizeof(char *) * (i + 1));
        	(*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return array;
}


int main(void){
	char *str = "this-is-cool";
	char *arr[3];

	printSplit(str, "-");
}
