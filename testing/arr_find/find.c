#include <stdio.h>

int arr_find(int *arr, int value, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }

    return -1;
}

int main(void){
    int arr[] = {1, 2, 3};
    printf("%d\n", arr_find(arr, 2, 3));
}