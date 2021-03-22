#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _int(char *str){
	return atoi(str);
}

int main(void){
	//INSERT FUNCTION HERE
	int number = _int("20");
	printf("%d", number);
}
