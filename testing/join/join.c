#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(void){
	char *str = "Hello ";
	char *str1 = "World";

	char *str2 = join(str, str1);

	printf("%s\n", str2);
}
