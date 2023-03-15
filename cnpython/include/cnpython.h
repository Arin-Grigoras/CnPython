

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
#include <limits.h>
//not previously included for `ptrdiff_t`
#include <stddef.h>
#include <stdbool.h>



//Own includes

#include "./cnpy_exceptions.h"
#include "./cnpy_print.h"
#include "./cnpy_help.h"




//#define tuple(...)


/*DEFINES*/

/*
    `and`, `or`, `not` are all operators in C++ and
    will give an error if trying to compile
*/
#ifndef __cplusplus
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
#endif

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

#ifndef class
    #define class struct
#endif


//used in timsort function in 'cnpython.c'
#ifndef RUN
    #define RUN 32
#endif //RUN

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







/*Converts any decimal value to a binary value*/
extern unsigned long long bin(long decimal, ...);

/*Converts any decimal value to a hexadecimal value*/
extern string hex(long n, ...);

/*Converts any decimal value to an octal value*/
extern long oct(long dec, ...);

/*Power function*/
extern double power(double base, double exponent);

/*Factorial function*/
extern int factorial(int n);


/*Converts a number to a string*/
extern string str(int number);

/*Converts a string to an integer*/
extern int _int(string str);

/*Converts a number into a boolean*/
extern int _bool(int n);


/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
extern string input(string str);

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
extern int str_len(string str);

/*Counts how many times the program found a character in a given string*/
extern int str_count(string str, char find);

/*Returns 0 if the certain string ends with the element provided*/
extern int str_endswith(string str, char element);

/*Joins 2 strings togheter and returns a third string*/
extern string str_join(string str1, string str2);

/*Replaces all found occurunces of a character with another character
 * and returns a new string*/
extern string str_replace(string str, char find, char repl);

/*Returns the index of the character if it was found in the string, if not it returns -1*/
extern int str_find(string str, char find);

/*Returns 0 if the string starts with the specified element*/
extern int str_startswith(string str, char element);


/*Idk what this was*/
//extern size_t str_split(string **array, string str, const string del);


/*Reads the whole entire file you pass it*/
extern string read_file(string filename);


/*Prints the splited string*/
//extern void printSplit(string str, const char del);

/*Splits a string and returns an array*/
extern void str_split(string str, const string del);


/* Returns the char for the ASCII code */
extern char chr(int ascii);

/* Returns the ASCII code for the char */
extern int ord(char c);

/*Returns 0 of the value was found it the specified string*/
extern int isin(string str, char value);

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
extern int str_islower(string str);

/*Returns True if all the elemenets in a string are uppercase*/
extern int str_isupper(string str);

/*Returns True if all the elements in the string are whitespaces*/
extern int str_isspace(string str);

/*Returns True if all the elements in the string are from the alphabet*/
extern int str_isalpha(string str);

/*Returns True if all the elements in the string are digits*/
extern int str_isdigit(string str);

/*Splits the string at line breaks and returns an array*/
extern void str_splitlines(string str);

/**
 * @brief Find the substring inside a string. Supporting search zone feature. Set negative value at end offset for end of the string
 * 
 * @param str The given string
 * @param value The substring to be found inside str
 * @param start The offset of when to start
 * @param end The end range
 * @return ptrdiff_t Return the index of the first character of the substring when found. Else, -1 is returned
 */
extern ptrdiff_t find_str(string str, string value, const unsigned int start, const int end);

/**
 * @brief Works just like the find method. However, an error is thrown when not found then given value
 */
extern ptrdiff_t index_str(string str, string value, const unsigned int start, const int end);

/**
 * @brief Justify the given string to the right of a new string
 * 
 * @param str The string to be justified
 * @param len The len of the fill offset and the string itself
 * @param fill The character to be filled
 * @return string The new string that right-justified the old string
 */
extern string rjust(string str, const size_t len, const char fill);


/**
 * @brief Justify the given string to the right of a new string
 * 
 * @param str The string to be justified
 * @param len The len of the fill offset and the string itself
 * @param fill The character to be filled
 * @return string The new string that right-justified the old string
 */
extern string rjust(string str, const size_t len, const char fill);

/**
 * @brief Justify the given string to the left of a new string
 * 
 * @param str The string to be justified
 * @param len The len of string and the fill offset
 * @param fill The character to be filled
 * @return string The new string that left-justified the old string
 */
extern string ljust(string str, const size_t len, const char fill);

/**
 * @brief Basically right-justified but auto fill with zero (ascii value) instead 
 * 
 * @param str The string to be justified
 * @param len The len of string and the fill offset
 * @return char* The new string that right-justified and fills with zero
 */
extern char* zfill(string str, size_t len);


//Some more checking method for string

extern bool isspace_str(string str);
extern bool isprintable_str(string str);
extern bool isdigit_str(string str);
extern bool isidentifier_str(string str);

/**
 * @brief Trim of the heading and the trailing of any character that met inside the strip_content
 * 
 * @param str The string to be trimmed
 * @param strip_content The delimiter for trimming
 * @return string The new string that got trimmed the heading and the trailing
 */
extern string strip(string str, string strip_content);

/**
 * @brief Check whether the string is of title type (First character of all word must be uppercase)
 * 
 * @param str The string to be checked
 * @return true When the string obeys the rule, false when the string not obeys the rule or only contains number
 */
extern bool istitle(string str);

/**
 * @brief Turn the string to become title
 * 
 * @param str The string to be transform
 * @return string The new string that is obeys title form
 */
extern string title(string str);

/*Returns the inverse square root*/
extern float rsqrt(float number);


#endif /*CYTHON_H*/
/*End of header guard*/
