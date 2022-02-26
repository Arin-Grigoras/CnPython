#include <stdio.h>


int int_abs(int);
double double_abs(double);


int main(void){
    int int_x = 10;
    int int_y = -10;

    printf("%d - and - %d\n", int_abs(int_x), int_abs(int_y));

    double double_x = 10.05;
    double double_y = -10.05;

    printf("%.2f - and - %.2f\n", double_abs(double_x), double_abs(double_y));


    return 0;
}


int int_abs(int number){
    if(number < 0){
        return -number;
    }

    return number;
}

double double_abs(double number){
    if(number < 0){
        return -number;
    }

    return number;
}
