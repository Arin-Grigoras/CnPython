#include <stdio.h>
#include "../../cnpython.h"


/*This doesn't work lmao, PR if you can fix it pls*/
int* range(int start, int stop, int step){
	int *arr = calloc(stop, sizeof(int));
	for(int i = start; i < stop; i+=step){
		arr[i] = i;
	}

	return arr;
}

int main(void){
	print("%t", range(1, 10, 1));
}
