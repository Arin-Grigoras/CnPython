#include <stdio.h>
#include "../../cnpython.h"

int* reversed(int* arr, int size){
	int *return_arr = calloc(size, sizeof(int));
	for(int c = size - 1, d = 0; c >= 0; c--, d++){
		return_arr[d] = arr[c];
	}

	return return_arr;

}

int main(void){
	int arr[] = {1, 2};
	print("%t", reversed(arr, 2));
}
