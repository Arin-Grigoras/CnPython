#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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



int main(void){
	char *str = "hello worls";
	str = replace(str, 's', 'd');

	printf("%s", str);
}
