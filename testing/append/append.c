#include <stdio.h>
#include "../../src/cnpython.h"

char **arrs_append(char **arr, char *value, int size){
	arr[size] = value;

	return arr;
}


int *arri_append(int *arr, int value, int size){
	arr[size] = value;

	return arr;
}

int main(void){
	char *str_arr[] = {"Hello"};
	int int_arr[] = {1};

	int_arr = arri_append(int_arr, 2, 1);
	str_arr = arrs_append(str_arr, "World", 1);

	print("int array: %t\nstring array: %r\n", int_arr, str_arr);

