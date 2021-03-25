#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 *	Failed Capitalize function
 * */

void capitalize(char *str){
	toupper(str[0]);
}

int main(void){

	char *str = "hello world";

	

	printf("%s", str);
}
