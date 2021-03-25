#include <stdio.h>
#include "../../cnpython/print.h"

char **arrs_append(char **arr, char *value, int size){
	arr[size] = value;

	return arr;
}


int *arri_append(int *arr, int value, int size){
	arr[size] = value;

	return arr;
}

void iappend(int *arr, int value, int size){
	arr[size] = value;
}


int main(void){
	char *str_arr[] = {"Hello"};
	int int_arr[] = {1};

	iappend(int_arr, 2, 1);

}