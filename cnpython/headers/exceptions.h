#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include "./cnpython.h"


/*Exceptions*/
#define AllocationError 1
#define ReallocationError 2
#define MemoryError 3
#define ZeroDivisionError 4
#define FileOpenError 5




void raise_exception(int except, char *file, int line);


#endif //EXCEPTIONS_H