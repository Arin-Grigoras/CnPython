#include <stdio.h>
#include <stdlib.h>

char *input(char *str){
    	int bufsize = 100;
    	int position = 0;
    	char *buffer = malloc(sizeof(char) * bufsize);
    	int c;

    	if (!buffer) {
        	printf("\n\nERROR: input() function error\nCouldn't alocate memory\n\n");
        	exit(1);
    	}

    	printf("%s", str);

    	while (1) {

        	c = getchar();

        	if (c == EOF || c == '\n') {
            		buffer[position] = '\0';
            		return buffer;
        	} else {
            		buffer[position] = c;

		}

        	position++;

        	if (position >= bufsize) {
            	bufsize += 100;
            	buffer = realloc(buffer, bufsize);
            		if (!buffer) {
                		printf("\n\nError: REALLOCATION error\n\n");
                		exit(EXIT_FAILURE);
            		}
        	}
    	}

    	return buffer; 
}

int main(void){
	char *test = input("enter input here -> ");
	printf("%s", test);
}
