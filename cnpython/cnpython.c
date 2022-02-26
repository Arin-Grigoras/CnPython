#include "./headers/cnpython.h"



int new_Int(int integer){
        return integer;
}


char *new_String(char *str){
        return str;
}


double new_Double(double dou){
        return dou;
}


float new_Float(float flot){
        return flot;
}


char new_Char(char chr){
        return chr;
}


long new_Long(long lon){
        return lon;
}



long long bin(long decimal){
        long long bin = 0;
        int rem, i = 1, step = 1;
        while (decimal != 0) {
                rem = decimal % 2;
                decimal /= 2;
                bin += rem * i;
                 i *= 10;
         }
        print("0b");
        return bin;
}





/*Converts any decimal value to a hexadecimal value*/
void hex(long n)
{
        char *hexaDeciNum = (char*)malloc(sizeof(char) * 100);

        if(!hexaDeciNum){
                raise_exception(AllocationError, __FILE__, __LINE__);
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

        print("0x");

        for(int j = i - 1; j >= 0; j--){
                printf("%c", hexaDeciNum[j]);
        }

        free(hexaDeciNum);

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
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

        sprintf(buffer, "%d", number);

        return buffer;

}




/*Converts a string to an integer*/
int _int(char *str){
        return atoi(str);
}


int _bool(int n){
        if(n == 0){
                return False;
        }
        return True;
}



/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
char *input(char *str){
        int bufsize = 100;
        int position = 0;
        char *buffer = (char*)malloc(sizeof(char) * bufsize);
        int c;

        if (!buffer) {
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

        printf("%s", str);

        while (True) {

                c = getchar();

                if (c == EOF or c == '\n') {
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
                                raise_exception(ReallocationError, __FILE__, __LINE__);
                        }
                }
        }

        return buffer; 
}



/*Reverses an int array*/
int* reversed(int* arr, int size){
        int *return_arr = calloc(size, sizeof(int));

        if(!return_arr){
                raise_exception(AllocationError, __FILE__, __LINE__);
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


 
/*Used in tim sort algorithm*/
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left and arr[j] > temp)
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
 
    while (i < len1 and j < len2)
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
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

        strcpy(str3, str1);
        strcat(str3, str2);

        return str3;
}



char *replace(char *str, char find, char repl){
        char *ret_string = (char*)malloc(sizeof(str));
        
        if(!ret_string){
                raise_exception(AllocationError, __FILE__, __LINE__);
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
                raise_exception(FileOpenError, __FILE__, __LINE__);
        }

        fseek(fptr, 0, SEEK_END);
        long fptr_size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        char *buffer = (char*)malloc(fptr_size + 1);

        if(!buffer){
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

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

                if(!array){
                        raise_exception(ReallocationError, __FILE__, __LINE__);
                }

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



/*

! We have to make this function work in the near future

char **split(char **array, char *str, const char *del){
	char *token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
        	*array = realloc(*array, sizeof(char *) * (i + 1));

                if(!array){
                        raise_exception(ReallocationError, __FILE__, __LINE__);
                }

        	(*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return array;
}*/



int ord(char c) {
    return (int) c;
}



int isin(char *str, char value){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == value){
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


int i_abs(int number){
    if(number < 0){
        return -number;
    }

    return number;
}

double d_abs(double number){
    if(number < 0){
        return -number;
    }

    return number;
}


int all(int *arr, int size){
    //int total_nulls = 0;
    int total_trues = 0;

    for(int i = 0; i < size; i++){
        /*if(arr[i] == NULL){
            total_nulls++;
        }*/
        
        if(arr[i] != 0){
            total_trues++;
        }
    }

    /*if(total_trues == size && total_nulls == size){
        return True;
    }*/

    if(total_trues == size){
        return True;
    }

    return False;
}


int d_all(double *arr, int size){
    int total_trues = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            total_trues++;
        }
    }

    if(total_trues == size){
        return True;
    }

    return False;
}


int any(int *arr, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            return True;
        }
    }


    return False;
}

int d_any(double *arr, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            return True;
        }
    }

    return False;
}


int str_islower(char *str){
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(islower(str[i])){
            total++;
        }elif(isupper(str[i])){
            return False;
        }else{
            whitespaces++;
        }
    }

    if(total = str_size - whitespaces){
        return True;
    }

    return False;
}


int str_isupper(char *str){
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(isupper(str[i])){
            total++;
        }else if(islower(str[i])){
            return False;
        }else{
            whitespaces++;
        }
    }

    if(total == str_size - whitespaces){
        return True;
    }

    return False;
}