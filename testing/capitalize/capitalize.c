#include <stdio.h>
#include <ctype.h>

/*
 *	Failed Capitalize function
 * */

char *capitalize(char *str){
	char capitalized = str[0];
	
	capitalized = toupper(capitalized);

	str[0] = capitalized;

	return str;
}

int main(void){

	char *str = "hello world";

	str = capitalize(str);

	printf("%s", str);
}
