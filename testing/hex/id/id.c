#include <stdio.h>

/*
 *Code does not work, please create PR if you know the answer.
 * */


/*
 *26/2/2022 EDIT: This is basically useless because you can just print out '&var'
*/

int* id(int var){
	return (&var);
}

int main(void){
	int a = 10;
	printf("%ls", id(a));
	printf("%p", &a);
}
