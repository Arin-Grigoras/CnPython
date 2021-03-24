#include <stdio.h>
#include <string.h>


int find(char *str, char find){
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == find){
			return i;
		}
	}

	return -1;
}


int main(void){
	char *str = "Hello world";
	printf("%d", find(str, 'e'));
}
