# CnPython

  ![alt text](https://github.com/koreaneggroll/CnPython/blob/main/CnPython.png?raw=true)

  Implementing most of pythons builtin functions in C, making it easier to read.

  ## Compile
  	gcc filename.c cnpython.c -o filename -lm
  or

    make test

  or

    gcc filename.c -o filename.o

  if you are using just one module of the library

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
   * endswith(str, element),
   * replace(str, find, repl),
   * find(str, find),
   * startswith(str, element),
   * str_split(arr, str, del),
   * printSplit(str, del),
   * split(arr, str, del)
   * chr(ascii)
   * ord(char)
   * isin(str, value)
   * rem(a, b)
   * percentage(p, n)
   * iappend(arr, value, size)
   * copy(arr, dest, size)
   * arr_count(arr, value, size)
   * arr_find(arr, value, size)
   * pop(arr, size)

  ## License

   This code is under a MIT license. This means you can do whatever you want with the code but the same license has to be in your project if you want to use this in your project.


  ## Idea
   Idea came from @midnqp, make sure to check his repository as well [https://github.com/midnqp/libavoidrepetition-c]

   ## Contact
   
   [Official Discord Server](https://discord.gg/PHmZyqgz8A) &nbsp;&nbsp;|&nbsp;&nbsp;  [Instagram](https://www.instagram.com/arngdesignnofficial/)
   
