#include <stdio.h>
#include <string.h>

int endswith(char *str, char element){
	if(str[strlen(str)-1] == element){
		return 0;
	}

	return -1;
}

int main(void){
	char *str = "hello worlo";
	if(endswith(str, 'd') == 0){
		printf("%s ends with 'd'\n", str);
	}
	else{
		printf("%s doesn't end with 'd'\n", str);
	}
}
