

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



//Own includes

#include "./exceptions.h"
#include "./print.h"


//#define tuple(...)


/*DEFINES*/
#define and &&
#define or ||
#define not !
#define is ==
#define isnt != 
#define in ,
#define elif else if


#define True 1
#define False 0
#define None ((void*)0) //basically NULL


//Really bad class definition but howdy, it works
#define class struct




/*STRUCTS*/
typedef void* var;

extern var Int;
extern var String;
extern var Double;
extern var Float;
extern var Char;
extern var Long;
extern var Function;
//extern var Tuple;


struct Int{
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
};


/*New datatypes*/
int new_Int(int integer);
char *new_String(char *str);
double new_Double(double dou);
float new_Float(float flot);
char new_Char(char chr);
long new_Long(long lon);



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
long long bin(long decimal);

/*This functions gives a summary of all the functions that are in this project*/
void help();


/*Converts any decimal value to a hexadecimal value*/
void hex(long n);


/*Converts any decimal value to an octal value*/
long oct(long dec);


/*Power function*/
double power(double base, double exponent);


/*Factorial function*/
int factorial(int n);


/*Converts a number to a string*/
char *str(int number);




/*Converts a string to an integer*/
int _int(char *str);


/*Converts a number into a boolean*/
int _bool(int n);



/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
char *input(char *str);



/*Reverses an int array*/
int* reversed(int* arr, int size);




/*Returns the biggest element in an array*/
double max (double numbers[], int arrlen);



/*Returns the smallest element in an array*/
double min(double numbers[], int arrlen);



const int RUN = 32;
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


/*Reads the whole entire file you pass it*/
char *read_file(char *filename);

size_t str_split(char ***array, char *str, const char *del);

/*Prints the splited string*/
void printSplit(char *str, const char *del);

/*Splits a string and returns an array*/
char **split(char **array, char *str, const char *del);


/* Returns the char for the ASCII code */
char chr(int ascii);

/* Returns the ASCII code for the char */
int ord(char c);

/*Returns 0 of the value was found it the specified string*/
int isin(char *str, char value);

/*Returns the remainder of the division of 2 numbers*/
int rem(int a, int b);

/*Returns the percentage*/
double percentage(float p, float n);

/*Adds a new value to the end of a string*/
void iappend(int *arr, int value, int size);

/*Copies the elements of an array to another array*/
int *copy(int *arr, int *dest, int size);

/*Returns how many times a value was found inside an array*/
int arr_count(int *arr, int value, int size);


/*Returns the index at which it found a specified value, if it didn't find it, returns -1*/
int arr_find(int *arr, int value, int size);

/*Pops out the last element of an array*/
void pop(int *arr, int size);


/*Returns the absolute value of an integer number*/
int i_abs(int number);

/*Returns the absolute value of a double number*/
double d_abs(double number);

/*Returns True if all the elements in the array are True*/
int all(int *arr, int size);

/*Returns True if all the elements in the array are True. For double type arrays*/
int d_all(double *arr, int size);

/*Returns True if one of the elements in the array is True for int arrays*/
int any(int *arr, int size);

/*Returns true if one of the elements in the array is True for double arrays*/
int d_any(double *arr, int size);


#endif /*CYTHON_H*/
/*End of header guard*/
