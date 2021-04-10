#include "cnpython.h"


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




void help(void){
        printf("\n\t\tCNPYTHON HELP\n\n");
        printf("\ntype -> type(var) returns a value from -1 to 10\n");
        printf("\nbin -> bin(decimal) converts a decimal number into binary form\n");
        printf("\nhex -> hex(decimal) converts a decimal number into hexadecimal form\n");
        printf("\noct -> oct(decimal) converts a decimal number into an octal\n");
        printf("\npow -> pow(base, exponent), multiplies base by itself as many times as the exponent says\n");
        printf("\nstr -> str(number) converts from an int to a string\n");
        printf("\n_int -> _int(string) converts from a string to an int\n");
        printf("\ninput -> input(prompt) prints out the prompt and takes input from the user\n");
        printf("\nreverse -> reverse(arr, size) reverses an array\n");
        printf("\nmin -> min(arr, size) gets the smallest element in an array\n");
        printf("\nmax -> max(arr, size) gets the biggest element in an array\n");
        printf("\nprint -> print(format, ...) printf but with the ability to print arrays built in\n");
        printf("\nsorted -> sorted(arr, size) sorts an array using timsort\n");
        printf("\nsum -> sum(arr, size) gets the sum of all the element in an array\n");
        printf("\nstr_len -> str_len(str) returns the length of a string\n");
        printf("\nstr_count -> str_count(str, find) returns how many times a character was found in a string\n");
	printf("\nendswith -> endswith(str, element) returns 0 if the string ends with the specified element\n");
	printf("\nreplace -> replace(str, find, repl) replaces all occurences of a character in a string\n");
	printf("\nfind -> find(str, element) returns the index of the element if it found it.\n");
	printf("\nstartswith -> startswith(str, element) returns 0 if it starts with the specified element\n");
        printf("\nstr_split -> str_split(arr, str, del) isn't really useful on it's own\n");
        printf("\nprintSplit -> printSplit(str, del) prints the array that is created after splitting a string\n");
        printf("\nchr -> chr(ascii) returns the character represented by a number\n");
        printf("\nord -> ord(char) returns the number represented by a character(opposite of chr)\n");
        printf("\nisin -> isin(str, value) returns 0 if the value specified was in the array\n");
        printf("\nrem - > rem(a, b) returns the remainder of a division between 2 numbers\n");
        printf("\npercentage -> percentage(p, n) returns the percentage\n");
        printf("\niappend -> iappend(arr, value, size) adds a value at the end of an array\n");
        printf("\ncopy -> copy(arr, dest, size) copies an array to another array\n");
        printf("\narr_count -> arr_count(arr, value, size) counts how many times a specified value was found\n");
        printf("\narr_find -> arr_find(arr, value, size) returns the index of the specified value\n");
        printf("\npop -> pop(arr, size) pops the last element from the array\n");
        

}



/*Converts any decimal value to a hexadecimal value*/
void hex(long n)
{
        char *hexaDeciNum = (char*)malloc(sizeof(char) * 100);

        if(!hexaDeciNum){
                printf("\n\n%s\n\n", strerror(errno));
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



int factorial(int n){
        if(n == 0){
                return 1;
        }

        return n * factorial(n - 1);
}



/*Converts a number to a string*/
char *str(int number){
        int size = (int)((ceil(log10(number))+1)*sizeof(char));
        char *buffer = (char*)malloc(sizeof(size));

        if(!buffer){
                printf("\n\n%s\n\n", strerror(errno));
                exit(1);
        }

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

        if(!return_arr){
                printf("\n\n%s\n\n", strerror(errno));
                exit(1);
        }

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



/*Gets the sum of all the elements in an array*/
long sum(int *arr, int size){  
        long sum = 0;

        for(int i = 0; i < size; i++){
                sum += arr[i];
        }

        return sum;
}



int str_len(char *str){
	//exists already but decided to put this here cuz why not
	return strlen(str);
}


/*Counts how many times the program found a character in a given string*/
int str_count(char *str, char find){
        
        int count = 0;
        
        for(int i = 0; i < strlen(str); i++){
                if(str[i] == find){
                        count++;
                }
        }

        return count;
}



int endswith(char *str, char element){
        if(str[strlen(str)-1] == element){
                return 0;
        }

        return -1;
}



char *join(char *str1, char *str2){
        char *str3 = (char*)malloc(sizeof(str1) + sizeof(str2));

        if(!str3){
                printf("\n\nERROR: join() function error\nCouldn't allocate memory\n\n");
                exit(1);
        }

        strcpy(str3, str1);
        strcat(str3, str2);

        return str3;
}



char *replace(char *str, char find, char repl){
        char *ret_string = (char*)malloc(sizeof(str));
        
        if(!ret_string){
                printf("\nERROR: replace() function error\nCouldn't allocate memory\n\n");
                exit(1);
        }

        strcpy(ret_string, str);


        for(int i = 0; i < strlen(ret_string); i++){
                if(ret_string[i] == find){
                        ret_string[i] = repl;
                }
        }

        return ret_string;
}



int find(char *str, char find){
        for(int i = 0; i < strlen(str); i++){
                if(str[i] == find){
                        return i;
                }
        }

        return -1;
}



int startswith(char *str, char element){
        if(str[0] == element){
                return 0;
        }
        return -1;
}



char *read_file(char *filename){
        FILE *fptr = fopen(filename, "rb");

        if(!fptr){
                printf("\n\nERROR: read_file() function error\nCouldn't open file\n\n");
                exit(1);
        }

        fseek(fptr, 0, SEEK_END);
        long fptr_size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        char *buffer = malloc(fptr_size + 1);
        fread(buffer, 1, fptr_size, fptr);
        fclose(fptr);

        buffer[fptr_size] = 0;

        return buffer;
}



size_t str_split(char ***array, char *str, const char *del) {
    	char *token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
        	*array = realloc(*array, sizeof(char *) * (i + 1));
		(*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return i;
}



void printSplit(char *str, const char *del){
    	char **split = NULL;
   	size_t count = str_split(&split, str, del);

    	for(size_t i = 0; i < count; i++) {
        	printf("[%s], ", split[i]);
    	}

    	free(split);
}



char **split(char **array, char *str, const char *del){
	char *token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
        	*array = realloc(*array, sizeof(char *) * (i + 1));
        	(*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return array;
}



int ord(char c) {
    return (int) c;
}



int isin(char *str, char value){
    for(int i = 0; i < strlen(str); i++){
        if(str[0] == value){
            return 0;
        }
    }

    return -1;
}



int rem(int a, int b){
        return a - (a/b*b);
}



double percentage(float p, float n){
        return p * n / 100;
}


void iappend(int *arr, int value, int size){
	arr[size] = value;
}


int *copy(int *arr, int *dest, int size){
    for(int i = 0; i < size; i++){
        dest[i] = arr[i];
    }

    return dest;
}


int arr_count(int *arr, int value, int size){
    int count = 0;
    
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            count++;
        }
    }

    return count;
}


int arr_find(int *arr, int value, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }

    return -1;
}


void pop(int *arr, int size){
    arr[size-1] = 0;
}


char chr(int ascii) {
    return (char) ascii;
}
