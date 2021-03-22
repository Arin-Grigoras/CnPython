#include <stdio.h>

long sum(int *arr, int size){
	long sum = 0;

	for(int i = 0; i < size; i++){
		sum += arr[i];
	}

	return sum;
}

int main(void){
	int arr[] = {1, 2};
	printf("%ld", sum(arr, 2));
}
