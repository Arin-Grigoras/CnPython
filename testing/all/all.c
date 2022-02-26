#include <stdio.h>


int all(int *arr, int size){
    //int total_nulls = 0;
    int total_trues = 0;

    for(int i = 0; i < size; i++){
        /*if(arr[i] == NULL){
            total_nulls++;
        }*/
        if(arr[i] != 0){
            total_trues++;
        }
    }

    /*if(total_trues == size && total_nulls == size){
        return 1;
    }*/

    if(total_trues == size){
        return 1;
    }

    return 0;
}


int main(void){

    int arr2[5] = {1, 1, 1, 1, 2};
    int arr3[5] = {2, 0, 0, 2, 0};

    if(all(arr2, 5) == 1){
        printf("arr2: True\n");
    }

    else{
        printf("arr2: False\n");
    }

    if(all(arr3, 5) == 1){
        printf("arr3: True\n");
    }
    else{
        printf("arr3: False\n");
    }
}