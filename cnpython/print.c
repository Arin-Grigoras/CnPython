#include "./headers/cnpy_print.h"



/*Prints integers*/
void print_int(int int_to_print){
        int a = int_to_print;

        if (int_to_print < 0){
                putchar('-');
                int_to_print = -int_to_print;
        }

        if (int_to_print > 9) print_int(int_to_print/10);

        putchar('0'+ (a%10));
}


/*Prints an integer array*/
void print_int_arr(int *arr, int size){
        for(int i = 0; i < size; i++){
                printf("[%d], ", arr[i]);
        }
}


/*Prints a double array*/
void print_double_arr(double *arr, int size){
        for(int i = 0; i < size; i++){
                printf("[%f], ", arr[i]);
        }
}

/*Prints a long array*/
void print_long_arr(long *arr, int size){
        for(int i = 0; i < size; i++){
                printf("[%ld], ", arr[i]);
        }
}



/*Prints a string array*/
void print_str_arr(char **arr, int size){
	for(int i = 0; i < size+1; i++){
		printf("[%s], ", arr[i]);
	}
}




/*Basically printf but has array printing built in*/
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
                        }else if(*format == 'e'){ //for double arrays
                                double *double_arr_to_print = va_arg(argp, double*);
                                int size = sizeof(double_arr_to_print)/sizeof(double_arr_to_print[0]);
                                print_double_arr(double_arr_to_print, size);
                        }else if(*format == 'g'){ //for long arrays
                                long *long_arr_to_print = va_arg(argp, long*);
                                int size = sizeof(long_arr_to_print)/sizeof(long_arr_to_print[0]);
                                print_long_arr(long_arr_to_print, size);
                        }else if(*format == 'r'){
				char **str_arr_to_print = va_arg(argp, char**);
				int size = sizeof(str_arr_to_print)/sizeof(str_arr_to_print[0]);

				print_str_arr(str_arr_to_print, size);
			}


                        else {
                                fputs("Not implemented", stdout);
                        }

                } else {
                        putchar(*format);
                }
                        format++;
                }
                putchar('\n');
                va_end(argp);   
}
