//Header guard start

#ifndef CNPY_PRINT_H
#define CNPY_PRINT_H


#include "./cnpython.h"



/*Prints integers*/
void print_int(int int_to_print);


/*Prints an integer array*/
void print_int_arr(int *arr, int size);


/*Prints a double array*/
void print_double_arr(double *arr, int size);

/*Prints a long array*/
void print_long_arr(long *arr, int size);

/*Prints string array*/
void print_str_arr(char **arr, int size);

/*Basically printf but has array printing built in*/
void print(char *format, ...);


#endif //CNPY_PRINT_H


//Header guard end