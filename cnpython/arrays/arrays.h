#include <stdlib.h>

/*Reverses an int array*/
int* reversed(int* arr, int size){
        int *return_arr = (int*)calloc(size, sizeof(int));
        for(int c = size - 1, d = 0; c >= 0; c--, d++){     
                return_arr[d] = arr[c];
        }

        return return_arr;
        
}




/*Returns the biggest element in an array*/
double max (double numbers[], int arrlen) {
	double maxitem = numbers[0];
	for(int i=1; i<arrlen; i++) {
		if (numbers[i] > maxitem) {
			maxitem = numbers[i];
		}
	}
	return maxitem;
}



/*Returns the smallest element in an array*/
double min(double numbers[], int arrlen) {
	double minitem = numbers[0];
	for(int i=1; i < arrlen; i++) {
		if (numbers[i] < minitem) {
			minitem = numbers[i];
		}
	}
	return minitem;
}