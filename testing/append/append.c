#include <stdio.h>
#include "../../src/cnpython.h"

char **arrs_append(char **arr, char *value, int size){
	arr[size] = value;

	return arr;
}


int *arri_append(char *arr, int value, int size){
	arr[size] = value;

	return arr;
}

int main(void){
	char **str_arr = {"Hello"};

