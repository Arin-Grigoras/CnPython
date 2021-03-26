#include <stdio.h>
#include <string.h>
#include "../../cnpython/print.h"

/*Doesn't */

void clear(int *arr){
     memset(arr, 0, sizeof(arr));
}

int main(void){
    int arr[4] = {1, 2, 3, 4};

    print_int_arr(arr, 4);
    print("\n");
    
    clear(arr);

    print("%d\n", arr[0]);
}