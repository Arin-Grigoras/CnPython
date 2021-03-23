# CnPython

  ![alt text](https://github.com/koreaneggroll/CnPython/blob/main/CnPython.png?raw=true)

  Implementing most of pythons builtin functions in C, making it easier to read.

  ## Compile
  	gcc filename.c cnpython.c -o filename -lm

  ## Template Code
  	
	#include <stdio.h>
	#include "cnpython.h>

	int main(){
		print("Hello world");


		return 0;
	}


  ## How to contribute

   Just create an issue if you have an idea for a builtin function or create a new pull request if you can also write the code for that.

  ## Implemented functions
   * type(var),
   * bin(decimal),
   * hex(decimal),
   * oct(decimal),
   * pow(base, exponent),
   * str(number),
   * _int(string),
   * input(prompt),
   * reverse(arr, size),
   * min(arr, size),
   * max(arr, size),
   * print(*format, ...),	
   * sorted(arr, size),
   * sum(arr, size),
   * str_len(str),
   * str_count(str, find),

  ## License

   This code is licensed under an unlicensed license. Feel free to use it however you want.


  ## Idea
   Idea came from @midnqp, make sure to check his repository as well [https://github.com/midnqp/libavoidrepetition-c]
