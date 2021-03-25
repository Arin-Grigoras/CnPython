#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*Converts a number to a string*/
char *str(int number){
        int size = (int)((ceil(log10(number))+1)*sizeof(char));
        char *buffer = (char*)malloc(sizeof(size));

        sprintf(buffer, "%d", number);

        return buffer;

}


/*Converts a string to an integer*/
int _int(char *str){
        return atoi(str);
}


int str_len(char *str){
	//exists already but decided to put this here cuz why not
	return strlen(str);
}


/*Counts how many times the program found a character in a given string*/
int str_count(char *str, char find){
        
        int count = 0;
        
        for(int i = 0; i < strlen(str); i++){
                if(str[i] == find){
                        count++;
                }
        }

        return count;
}



int endswith(char *str, char element){
        if(str[strlen(str)-1] == element){
                return 0;
        }

        return -1;
}



char *join(char *str1, char *str2){
        char *str3 = (char*)malloc(sizeof(str1) + sizeof(str2));

        if(!str3){
                printf("\n\nERROR: join() function error\nCouldn't allocate memory\n\n");
                exit(1);
        }

        strcpy(str3, str1);
        strcat(str3, str2);

        return str3;
}



char *replace(char *str, char find, char repl){
        char *ret_string = (char*)malloc(sizeof(str));
        
        if(!ret_string){
                printf("\nERROR: replace() function error\nCouldn't allocate memory\n\n");
                exit(1);
        }

        strcpy(ret_string, str);


        for(int i = 0; i < strlen(ret_string); i++){
                if(ret_string[i] == find){
                        ret_string[i] = repl;
                }
        }

        return ret_string;
}



int find(char *str, char find){
        for(int i = 0; i < strlen(str); i++){
                if(str[i] == find){
                        return i;
                }
        }

        return -1;
}



int startswith(char *str, char element){
        if(str[0] == element){
                return 0;
        }
        return -1;
}



char *read_file(char *filename){
        FILE *fptr = fopen(filename, "rb");

        if(!fptr){
                printf("\n\nERROR: read_file() function error\nCouldn't open file\n\n");
                exit(1);
        }

        fseek(fptr, 0, SEEK_END);
        long fptr_size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        char *buffer = (char*)malloc(fptr_size + 1);
        fread(buffer, 1, fptr_size, fptr);
        fclose(fptr);

        buffer[fptr_size] = 0;

        return buffer;
}



size_t str_split(char ***array, char *str, const char *del) {
    	char *token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
            *array = (char**)realloc(*array, sizeof(char *) * (i + 1));
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
        	*array = (char*)realloc(*array, sizeof(char *) * (i + 1));
        	(*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return array;
}


int ord(char c) {
    return (int) c;
}


char chr(int ascii) {
    return (char) ascii;
}



int isin(char *str, char value){
    for(int i = 0; i < strlen(str); i++){
        if(str[0] == value){
            return 0;
        }
    }

    return -1;
}