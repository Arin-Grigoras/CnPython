

/*Header guards*/
#ifndef CYTHON_H
#define CYTHON_H

/*Standard includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <errno.h>
#include <stdint.h>
#include <ctype.h>



//Own includes

#include "./cnpy_exceptions.h"
#include "./cnpy_print.h"
#include "./cnpy_help.h"


//#define tuple(...)


/*DEFINES*/

//python 'and' logical operator implemented in C
#ifndef and
    #define and &&
#endif //and

//python 'or' logical operator implemented in C
#ifndef or
    #define or ||
#endif //or

//python 'not' logical operator implemented in C
#ifndef not
    #define not !
#endif //not

//python 'is' logical operator implemented in C
#ifndef is
    #define is ==
#endif //is

//python 'isnt' logical operator implemented in C
#ifndef isnt
    #define isnt != 
#endif //isnt

//supposed to be pythons 'in' operator but it's not really good implemented
#ifndef in
    #define in ,
#endif //in

//else if in python
#ifndef elif
    #define elif else if
#endif //elif

//if the True macro is not defined we define it and if it is we skip
#ifndef True
    #define True 1
#endif

//if the False macro is not defined we define it and if it is we skip
#ifndef False
    #define False 0
#endif

//None = NULL
#ifndef None
    #define None ((void*)0) //basically NULL
#endif //None

//Really bad class definition but howdy, it works
#define class struct



#define RUN 32

//MAX and MIN macro functions
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



/*STRUCTS*/


/*
typedef void* var;
*/

//typedefs the char array datatype to a custom one called 'string'
typedef char* string;


/*extern var Int;
extern var String;
extern var Double;
extern var Float;
extern var Char;
extern var Long;
extern var Function;
//extern var Tuple;
*/

/*struct Int{
    int val;
};
//typedef Int inte;



struct String{
    char *val;
};
//typedef String string;



struct Double{
    double val;
};
//typedef Double dbl;



struct Float{
    float val;
};
//typedef Float flt;



struct Char{
    char val;
};
//typedef Char character;



struct Long{
    long val;
};
//typedef Long lng;



struct Function{
    var (*func)(var);
};*/






/*struct Tuple{
    const var* val;
};*/



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
extern long long bin(long decimal);

/*Converts any decimal value to a hexadecimal value*/
extern void hex(long n);

/*Converts any decimal value to an octal value*/
extern long oct(long dec);

/*Power function*/
extern double power(double base, double exponent);

/*Factorial function*/
extern int factorial(int n);


/*Converts a number to a string*/
extern char *str(int number);

/*Converts a string to an integer*/
extern int _int(char *str);

/*Converts a number into a boolean*/
extern int _bool(int n);


/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
extern char *input(char *str);

/*Reverses an int array*/
extern int* reversed(int* arr, int size);

//! TODO: Make reversed functions for other array data types as well




/*Returns the biggest element in an array*/
extern double max (double numbers[], int arrlen);

/*Returns the smallest element in an array*/
extern double min(double numbers[], int arrlen);
 

/*Used in tim sort algorithm*/
extern void insertionSort(int arr[], int left, int right);
 
/*Merge function is used in the tim sort algorithm*/
extern void merge(int arr[], int l, int m, int r);
 
/*Tim Sort algorithm*/
extern void timSort(int arr[], int n);

/*uses timSort algorithm to sort an array*/
extern int* sorted(int *arr, int size);



/*Gets the sum of all the elements in an array*/
extern long sum(int *arr, int size);

/*Returns the length of a string*/
extern int str_len(char *str);

/*Counts how many times the program found a character in a given string*/
extern int str_count(char *str, char find);

/*Returns 0 if the certain string ends with the element provided*/
extern int str_endswith(char *str, char element);

/*Joins 2 strings togheter and returns a third string*/
extern char *str_join(char *str1, char *str2);

/*Replaces all found occurunces of a character with another character
 * and returns a new string*/
extern char *str_replace(char *str, char find, char repl);

/*Returns the index of the character if it was found in the string, if not it returns -1*/
extern int str_find(char *str, char find);

/*Returns 0 if the string starts with the specified element*/
extern int str_startswith(char *str, char element);


extern size_t str_split(char ***array, char *str, const char *del);


/*Reads the whole entire file you pass it*/
extern char *read_file(char *filename);


/*Prints the splited string*/
extern void printSplit(char *str, const char *del);

/*Splits a string and returns an array*/
extern char **split(char **array, char *str, const char *del);


/* Returns the char for the ASCII code */
extern char chr(int ascii);

/* Returns the ASCII code for the char */
extern int ord(char c);

/*Returns 0 of the value was found it the specified string*/
extern int isin(char *str, char value);

/*Returns the remainder of the division of 2 numbers*/
extern int rem(int a, int b);

/*Returns the percentage*/
extern double percentage(float p, float n);

/*Adds a new value to the end of a string*/
extern void iappend(int *arr, int value, int size);

/*Copies the elements of an array to another array*/
extern int *copy(int *arr, int *dest, int size);

/*Returns how many times a value was found inside an array*/
extern int arr_count(int *arr, int value, int size);


/*Returns the index at which it found a specified value, if it didn't find it, returns -1*/
extern int arr_find(int *arr, int value, int size);

/*Pops out the last element of an array*/
extern void pop(int *arr, int size);


/*Returns the absolute value of an integer number*/
extern int i_abs(int number);

/*Returns the absolute value of a double number*/
extern double d_abs(double number);

/*Returns True if all the elements in the array are True*/
extern int all(int *arr, int size);

/*Returns True if all the elements in the array are True. For double type arrays*/
extern int d_all(double *arr, int size);

/*Returns True if one of the elements in the array is True for int arrays*/
extern int any(int *arr, int size);

/*Returns true if one of the elements in the array is True for double arrays*/
extern int d_any(double *arr, int size);

/*Returns True if all the elements in a string are lowercase*/
extern int str_islower(char *str);

/*Returns True if all the elemenets in a string are uppercase*/
extern int str_isupper(char *str);

/*Returns True if all the elements in the string are whitespaces*/
extern int str_isspace(char *str);

/*Returns True if all the elements in the string are from the alphabet*/
extern int str_isalpha(char *str);

/*Returns True if all the elements in the string are digits*/
extern int str_isdigit(char *str);

/*Splits the string at line breaks and returns an array*/
extern char **str_splitlines(char *str);

#endif /*CYTHON_H*/
/*End of header guard*/
