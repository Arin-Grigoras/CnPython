#include <stdio.h>
#include "../../cnpython/print.h"

int *copy(int *arr, int *dest, int size){
    for(int i = 0; i < size; i++){
        dest[i] = arr[i];
    }

    return dest;
}

int main(void){
    int arr[] = {1, 2, 3, 4};
    int dest[4];

    copy(arr, dest, 4);

    print_int_arr(arr, 4);
    print("\n");
    print_int_arr(dest, 4);
}