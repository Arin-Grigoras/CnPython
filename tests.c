#include <stdio.h>
#include "cnpython.h"


void test_input(){
	char *test = input("Test: ");
	print("%s", test);
}


void test_print(){
	int arr[] = {1, 2};
	char *str = "hello";
	char c = 'c';
	print("%s %c %t", str, c, arr);
}





int main(void){
	int ch;
	printf("[1]. test-input\n[2].test-print");

	scanf("%d", &ch);

	switch(ch){
		case 1: test_input(); break;
		case 2: test_print(); break;
	}
}
