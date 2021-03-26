#include <stdio.h>

int arr_count(int *arr, int value, int size){
    int count = 0;
    
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            count++;
        }
    }

    return count;
}

int main(void){
    int arr[] = {1, 1, 2};

    printf("%d\n", arr_count(arr, 1, 3));
}