#include <stdio.h>

void pop(int *arr, int size){
    arr[size-1] = 0;
}

int main(void){
    int arr[] = {1, 2};
    pop(arr, 2);

    for(int i = 0; i < 2; i++){
        printf("%d\n", arr[i]);
    }
}