#include <stdio.h>

/*
 *Code does not work, please create PR if you know the answer.
 * */

int* id(int var){
	return (&var);
}

int main(void){
	int a = 10;
	printf("%ls", id(a));
	printf("%p", &a);
}
