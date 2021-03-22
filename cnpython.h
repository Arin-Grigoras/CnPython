#ifndef CYTHON_H
#define CYTHON_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

/*Converts any decimal value to a binary value*/
long long bin(long decimal){
        long long bin = 0;
        int rem, i = 1, step = 1;
        while (decimal != 0) {
                rem = decimal % 2;
                decimal /= 2;
                bin += rem * i;
                 i *= 10;
         }
        printf("0b");
        return bin;
}



/*This functions gives a summary of all the functions that are in this project*/
void help(){
        printf("\n\t\tCYTHON HELP\n\n");
        printf("\n*bin -> bin(decimal) converts a decimal number into binary form\n");
        printf("\nhex -> hex(decimal) converts a decimal number into hexadecimal form\n");
}



/*Converts any decimal value to a hexadecimal value*/
void hex(long n)
{
        char *hexaDeciNum = (char*)malloc(sizeof(char) * 100);

        if(!hexaDeciNum){
                printf("\n\nERROR: hex() function error\nCouldn't allocate memory\n\n");
                exit(1);
        }
 
        int i = 0;
        while (n != 0) {
                int temp = 0;
 
                temp = n % 16;
 
                if (temp < 10) {
                        hexaDeciNum[i] = temp + 48;
                        i++;
                }
                else {
                        hexaDeciNum[i] = temp + 55;
                        i++;
                }
 
                        n = n / 16;
                }

        printf("0x");

        for(int j = i - 1; j >= 0; j--){
                printf("%c", hexaDeciNum[j]);
        }

}


/*Converts any decimal value to an octal value*/
long oct(long dec){
        long octalNumber = 0; 
        int i = 1;

        while (dec != 0){
                octalNumber += (dec % 8) * i;
                dec /= 8;
                i *= 10;
        }

        return octalNumber;
}


/*Power function*/
double pow(double base, double exponent){
        double result = 1;
        for(exponent; exponent > 0; exponent--){
                result *= base;
        }

        return result;
}



/*Converts a number to a string*/
char *str(int number){
        int size = (int)((ceil(log10(number))+1)*sizeof(char));
        char *buffer = (char*)malloc(sizeof(size));

        sprintf(buffer, "%d", number);

        return buffer;

}




/*Converts a string to an integer*/
int _int(char *str){
        return atoi(str);
}




/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
char *input(char *str){
        int bufsize = 100;
        int position = 0;
        char *buffer = (char*)malloc(sizeof(char) * bufsize);
        int c;

        if (!buffer) {
                printf("\n\nERROR: input() function error\nCouldn't alocate memory\n\n");
                exit(1);
        }

        printf("%s", str);

        while (1) {

                c = getchar();

                if (c == EOF || c == '\n') {
                        buffer[position] = '\0';
                        return buffer;
                } else {
                        buffer[position] = c;

                }

                position++;

                if (position >= bufsize) {
                bufsize += 100;
                buffer = (char*)realloc(buffer, bufsize);
                        if (!buffer) {
                                printf("\n\nError: REALLOCATION error\n\n");
                                exit(EXIT_FAILURE);
                        }
                }
        }

        return buffer; 
}



/*Reverses an int array*/
int* reversed(int* arr, int size){
        int *return_arr = calloc(size, sizeof(int));
        for(int c = size - 1, d = 0; c >= 0; c--, d++){     
                return_arr[d] = arr[c];
        }

        return return_arr;
        
}




/*Returns the biggest element in an array*/
double max (double numbers[], int arrlen) {
	double maxitem = numbers[0];
	for(int i=1; i<arrlen; i++) {
		if (numbers[i] > maxitem) {
			maxitem = numbers[i];
		}
	}
	return maxitem;
}



/*Returns the smallest element in an array*/
double min(double numbers[], int arrlen) {
	double minitem = numbers[0];
	for(int i=1; i < arrlen; i++) {
		if (numbers[i] < minitem) {
			minitem = numbers[i];
		}
	}
	return minitem;
}



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





/*Basically printf but can print arrays as well*/
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




const int RUN = 32;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
 
/*Used in tim sort algorithm*/
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
/*Merge function is used in the tim sort algorithm*/
void merge(int arr[], int l, int m, int r){
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 

    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 

/*Tim Sort algorithm*/
void timSort(int arr[], int n){
     
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, MIN((i+RUN-1), 
                                    (n-1)));
 
    for (int size = RUN; size < n; 
                             size = 2*size)
    {
         
        for (int left = 0; left < n; 
                             left += 2*size)
        {
            int mid = left + size - 1;
            int right = MIN((left + 2*size - 1), 
                                            (n-1));
 

              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}



/*uses timSort algorithm to sort an array*/
int* sorted(int *arr, int size){
	timSort(arr, size);

	return arr;
}





#endif //CYTHON_H
