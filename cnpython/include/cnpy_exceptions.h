#ifndef CNPY_EXCEPTIONS_H
#define CNPY_EXCEPTIONS_H


#include "./cnpython.h"


/*Exceptions*/
#define AllocationError 1
#define ReallocationError 2
#define MemoryError 3
#define ZeroDivisionError 4
#define FileOpenError 5
#define NullError 6



void raise_exception(int except, char *file, int line);


#endif //CNPY_EXCEPTIONS_H