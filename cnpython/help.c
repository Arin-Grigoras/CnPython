#include "./include/cnpy_help.h"


void help(void){
    print("\n\t\tCNPYTHON HELP\n\n");
    print("\ntype -> type(var) returns a value from -1 to 10\n");
    print("\nbin -> bin(decimal) converts a decimal number into binary form\n");
    print("\nhex -> hex(decimal) converts a decimal number into hexadecimal form\n");
    print("\noct -> oct(decimal) converts a decimal number into an octal\n");
    print("\npow -> pow(base, exponent), multiplies base by itself as many times as the exponent says\n");
    print("\nstr -> str(number) converts from an int to a string\n");
    print("\n_int -> _int(string) converts from a string to an int\n");
    print("\ninput -> input(prompt) prints out the prompt and takes input from the user\n");
    print("\nreverse -> reverse(arr, size) reverses an array\n");
    print("\nmin -> min(arr, size) gets the smallest element in an array\n");
    print("\nmax -> max(arr, size) gets the biggest element in an array\n");
    print("\nprint -> print(format, ...) printf but with the ability to print arrays built in\n");
    print("\nsorted -> sorted(arr, size) sorts an array using timsort\n");
    print("\nsum -> sum(arr, size) gets the sum of all the element in an array\n");
    print("\nstr_len -> str_len(str) returns the length of a string\n");
    print("\nstr_count -> str_count(str, find) returns how many times a character was found in a string\n");
    print("\nendswith -> endswith(str, element) returns 0 if the string ends with the specified element\n");
    print("\nreplace -> replace(str, find, repl) replaces all occurences of a character in a string\n");
    print("\nfind -> find(str, element) returns the index of the element if it found it.\n");
    print("\nstartswith -> startswith(str, element) returns 0 if it starts with the specified element\n");
    print("\nstr_split -> str_split(arr, str, del) isn't really useful on it's own\n");
    print("\nprintSplit -> printSplit(str, del) prints the array that is created after splitting a string\n");
    print("\nchr -> chr(ascii) returns the character represented by a number\n");
    print("\nord -> ord(char) returns the number represented by a character(opposite of chr)\n");
    print("\nisin -> isin(str, value) returns 0 if the value specified was in the array\n");
    print("\nrem - > rem(a, b) returns the remainder of a division between 2 numbers\n");
    print("\npercentage -> percentage(p, n) returns the percentage\n");
    print("\niappend -> iappend(arr, value, size) adds a value at the end of an array\n");
    print("\ncopy -> copy(arr, dest, size) copies an array to another array\n");
    print("\narr_count -> arr_count(arr, value, size) counts how many times a specified value was found\n");
    print("\narr_find -> arr_find(arr, value, size) returns the index of the specified value\n");
    print("\npop -> pop(arr, size) pops the last element from the array\n");  
}
