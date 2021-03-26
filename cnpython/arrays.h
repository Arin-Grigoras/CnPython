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



const int RUN = 32;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
 
/*Used in tim sort algorithm*/
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
/*Merge function is used in the tim sort algorithm*/
void merge(int arr[], int l, int m, int r){
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 

    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 

/*Tim Sort algorithm*/
void timSort(int arr[], int n){
     
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, MIN((i+RUN-1), 
                                    (n-1)));
 
    for (int size = RUN; size < n; 
                             size = 2*size)
    {
         
        for (int left = 0; left < n; 
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = MIN((left + 2*size - 1), 
                                            (n-1));
 

              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}



/*uses timSort algorithm to sort an array*/
int* sorted(int *arr, int size){
	timSort(arr, size);

	return arr;
}



/*Gets the sum of all the elements in an array*/
long sum(int *arr, int size){  
        long sum = 0;

        for(int i = 0; i < size; i++){
                sum += arr[i];
        }

        return sum;
}


void iappend(int *arr, int value, int size){
	arr[size] = value;
}


int *copy(int *arr, int *dest, int size){
    for(int i = 0; i < size; i++){
        dest[i] = arr[i];
    }

    return dest;
}


int arr_count(int *arr, int value, int size){
    int count = 0;
    
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            count++;
        }
    }

    return count;
}