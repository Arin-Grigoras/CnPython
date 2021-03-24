#ifndef CYTHON_H
#define CYTHON_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>


/*Is used to determine the type of a variable */
enum types{
        TYPE_INT = 0,
        TYPE_CHAR = 1,
        TYPE_STRING = 2,
        TYPE_LONG = 3,
        TYPE_DOUBLE = 4,
        TYPE_FLOAT = 5,
        TYPE_INT_ARR = 6,
        TYPE_STRING_ARR = 7,
        TYPE_LONG_ARR = 8,
        TYPE_DOUBLE_ARR = 9,
        TYPE_FLOAT_ARR = 10,
        TYPE_UNKNOWN = -1
};

/*Returns a number from -1 to 10 depending on the variable data type*/
#define type(X) \
        _Generic(X, \
                        int: TYPE_INT, \
                        char: TYPE_CHAR, \
                        char*: TYPE_STRING, \
                        char**: TYPE_STRING_ARR, \
                        long: TYPE_LONG, \
                        double: TYPE_DOUBLE, \
                        float: TYPE_FLOAT, \
                        int*: TYPE_INT_ARR, \
                        long*: TYPE_LONG_ARR, \
                        double*: TYPE_DOUBLE_ARR, \
                        float*: TYPE_FLOAT_ARR, \
                        default: TYPE_UNKNOWN   )



/*Converts any decimal value to a binary value*/
long long bin(long decimal);

/*This functions gives a summary of all the functions that are in this project*/
void help();


/*Converts any decimal value to a hexadecimal value*/
void hex(long n);


/*Converts any decimal value to an octal value*/
long oct(long dec);


/*Power function*/
double pow(double base, double exponent);



/*Converts a number to a string*/
char *str(int number);




/*Converts a string to an integer*/
int _int(char *str);



/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
char *input(char *str);



/*Reverses an int array*/
int* reversed(int* arr, int size);




/*Returns the biggest element in an array*/
double max (double numbers[], int arrlen);



/*Returns the smallest element in an array*/
double min(double numbers[], int arrlen);



/*Prints integers*/
void print_int(int int_to_print);


/*Prints an integer array*/
void print_int_arr(int *arr, int size);


/*Prints a double array*/
void print_double_arr(double *arr, int size);

/*Prints a long array*/
void print_long_arr(long *arr, int size);


/*Basically printf but has array printing built in*/
void print(char *format, ...);



//const int RUN = 32;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
 
/*Used in tim sort algorithm*/
void insertionSort(int arr[], int left, int right);
 
/*Merge function is used in the tim sort algorithm*/
void merge(int arr[], int l, int m, int r);
 

/*Tim Sort algorithm*/
void timSort(int arr[], int n);



/*uses timSort algorithm to sort an array*/
int* sorted(int *arr, int size);



/*Gets the sum of all the elements in an array*/
long sum(int *arr, int size);


/*Returns the length of a string*/
int str_len(char *str);


/*Counts how many times the program found a character in a given string*/
int str_count(char *str, char find);


/*Returns 0 if the certain string ends with the element provided*/
int endswith(char *str, char element);


/*Joins 2 strings togheter and returns a third string*/
char *join(char *str1, char *str2);


/*Replaces all found occurunces of a character with another character
 * and returns a new string*/
char *replace(char *str, char find, char repl);


/*Returns the index of the character if it was found in the string, if not it returns -1*/
int find(char *str, char find);


/*Returns 0 if the string starts with the specified element*/
int startswith(char *str, char element);



#endif //CYTHON_H
