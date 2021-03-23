#include <stdio.h>
#include <string.h>

int str_count(char *str, char find){
	
	int count = 0;
	
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == find){
			count++;
		}
	}

	return count;
}

int main(void){
	char *str = "test";
	printf("Found 't' %d times", str_count(str, 't'));
	
}
