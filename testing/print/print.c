#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*
 *The print function is very tricky for me and I couldn't find the actual code for this function so I have to do this myself
 * */


//PROTOTYPES
void print_int(int int_to_print);
void print_int_arr(int *arr, int size);
void print_double_arr(double *arr, int size);
void print_long_arr(long *arr, int size);
void print(char *format, ...);


void print_int(int int_to_print){
	int a = int_to_print;

    	if (int_to_print < 0){
       		putchar('-');
       		int_to_print = -int_to_print;
	}

    	if (int_to_print > 9) print_int(int_to_print/10);

    	putchar('0'+ (a%10));
}


void print_int_arr(int *arr, int size){
	for(int i = 0; i < size; i++){
		printf("[%d], ", arr[i]);
	}
}


void print_double_arr(double *arr, int size){
	for(int i = 0; i < size; i++){
		printf("[%f], ", arr[i]);
	}
}


void print_long_arr(long *arr, int size){
	for(int i = 0; i < size; i++){
		printf("[%ld], ", arr[i]);
	}
}


void print(char *format, ...){
	va_list argp;
  	va_start(argp, format);
  	while (*format != '\0') {
    		if (*format == '%') {
      				format++;
      			if (*format == '%') {
        			putchar('%');
      			} else if (*format == 'c') { //this is for a character
        			char char_to_print = va_arg(argp, int);
        			putchar(char_to_print);
      			}else if(*format == 's'){ //this is for a string
				char* string_to_print = va_arg(argp, char*);
				for(int i = 0; i < strlen(string_to_print); i++){
						putchar(string_to_print[i]);
				}
			}else if(*format == 'd'){ //this is for an integer
				int int_to_print = va_arg(argp, int);
				print_int(int_to_print);
			}else if(*format == 't'){ //this is for an integer array
				int *int_arr_to_print = va_arg(argp, int*);
				int size = sizeof(int_arr_to_print)/sizeof(int_arr_to_print[0]);
				print_int_arr(int_arr_to_print, size);
			}else if(*format == 'e'){
				double *double_arr_to_print = va_arg(argp, double*);
				int size = sizeof(double_arr_to_print)/sizeof(double_arr_to_print[0]);
				print_double_arr(double_arr_to_print, size);
			}else if(*format == 'g'){ //for long arrays
				long *long_arr_to_print = va_arg(argp, long*);
				int size = sizeof(long_arr_to_print)/sizeof(long_arr_to_print[0]);
				print_long_arr(long_arr_to_print, size);
			}


			else {
        			fputs("Not implemented", stdout);
      			}

		} else {
      			putchar(*format);
		}
    			format++;
  		}
  		va_end(argp);	
}



int main(void){
	char *str = "world";
	int n = 12;
	int arr[] = {1, 2};
	double arr2[] = {1.2, 2.2};
	long arr3[] = {12, 12};
	print("Hello %s %d %t %e %g", str, n, arr, arr2, arr3);
}
