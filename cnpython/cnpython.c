#include "./include/cnpython.h"



//the second arguments value determines the binary notation should be printed or not
long long bin(long decimal, ...){
        long long bin = 0;
        int rem, i = 1, step = 1;
        va_list valist;
	while (decimal != 0) {
                rem = decimal % 2;
                decimal /= 2;
                bin += rem * i;
                 i *= 10;
         }

	va_start(valist, decimal);

	if(va_arg(valist, int) == True){
		print("0b%lld", bin);
	}

	va_end(valist);

        return bin;
}






/*Converts any decimal value to a hexadecimal value*/
string hex(long n, ...)
{
        string hexaDeciNum = (char*)malloc(sizeof(char) * 100);
	va_list valist;

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

	va_start(valist, n);

	if(va_arg(valist, int) == True){
		print("0x");
		for(int j = i - 1; j >= 0; j--){
			print("%c", hexaDeciNum[j]);
		}
		free(hexaDeciNum);
	}

	else{
		return hexaDeciNum;
	}

}



/*Converts any decimal value to an octal value*/
long oct(long dec, ...){
        long octalNumber = 0;
        int i = 1;
	va_list valist;

        while (dec != 0){
            octalNumber += (dec % 8) * i;
            dec /= 8;
            i *= 10;
        }


	va_start(valist, dec);

	if(va_arg(valist, int) == True){
		print("0o%ld", octalNumber);
	}

	va_end(valist);

        return octalNumber;
}


/*Power function*/
double power(double base, double exponent){
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
string str(int number){
        int size = (int)((ceil(log10(number))+1)*sizeof(char));
        string buffer = (char*)malloc(sizeof(size));

        if(!buffer){
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

        sprintf(buffer, "%d", number);

        return buffer;

}




/*Converts a string to an integer*/
int _int(string str){        return atoi(str);		}
//converts from int to bool
int _bool(int n){	return n == 0 ? False : True;	}



/*Takes as a parameter the prompt for the user and reads the input byte by byte and returns it*/
string input(string str){
        int bufsize = 100;
        int position = 0;
        string buffer = (char*)malloc(sizeof(char) * bufsize);
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



int str_len(string str){
	//exists already but decided to put this here cuz why not
	return strlen(str);
}


/*Counts how many times the program found a character in a given string*/
int str_count(string str, char find){

        int count = 0;

        for(int i = 0; i < strlen(str); i++){
                if(str[i] == find){
                        count++;
                }
        }

        return count;
}



int endswith(string str, char element){
        if(str[strlen(str)-1] == element){
                return 0;
        }

        return -1;
}



string join(string str1, string str2){
        string str3 = (char*)malloc(sizeof(str1) + sizeof(str2));

        if(!str3){
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

        strcpy(str3, str1);
        strcat(str3, str2);

        return str3;
}



string replace(string str, char find, char repl){
        string ret_string = (char*)malloc(sizeof(str));

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



int find(string str, char find){
        for(int i = 0; i < strlen(str); i++){
                if(str[i] == find){
                        return i;
                }
        }

        return -1;
}



int startswith(string str, char element){
        if(str[0] == element){
                return 0;
        }
        return -1;
}



string read_file(string filename){
        FILE *fptr = fopen(filename, "rb");

        if(!fptr){
                raise_exception(FileOpenError, __FILE__, __LINE__);
        }

        fseek(fptr, 0, SEEK_END);
        long fptr_size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        string buffer = (char*)malloc(fptr_size + 1);

        if(!buffer){
                raise_exception(AllocationError, __FILE__, __LINE__);
        }

        fread(buffer, 1, fptr_size, fptr);
        fclose(fptr);

        buffer[fptr_size] = 0;

        return buffer;
}


/*
size_t str_split(string **array, string str, const string del) {
    	string token;
    	size_t i = 0;

    	token = strtok(str, del);

    	while(token != NULL) {
        	*array = realloc(*array, sizeof(string ) * (i + 1));

                if(!array){
                        raise_exception(ReallocationError, __FILE__, __LINE__);
                }

		    (*array)[i++] = token;
        	token = strtok(NULL, del);
    	}

    	return i;
}*/


/*
void printSplit(string **split, string str, const char del){
   	size_t count = str_split(&split, del);

    	for(size_t i = 0; i < count; i++) {
        	printf("[%s], ", split[i]);
    	}

    	free(split);
}
*/




void str_split(string str, const string del)
{
    string token;

    token = strtok(str, del);

    while(token != None){
        print(token);

        token = strtok(None, del);
    }
}



int ord(char c) {
    return (int) c;
}



int isin(string str, char value){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == value){
            return 0;
        }
    }

    return -1;
}



int rem(int a, int b){
        return a % b;
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

/*returns absolute value*/
int i_abs(int number){
    return (((number) < (0)) ? (-number) : (number));
}

double d_abs(double number){
    return (((number) < (0)) ? (-number) : (number));
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


int str_islower(string str){
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(islower(str[i])){
            total++;
        }elif(isupper(str[i])){
            return False;
        }elif(isspace(str[i])){
            whitespaces++;
        }
    }

    if(total == str_size - whitespaces){
        return True;
    }

    return False;
}


int str_isupper(string str){
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(isupper(str[i])){
            total++;
        }elif(islower(str[i])){
            return False;
        }elif(isspace(str[i])){
            whitespaces++;
        }
    }

    if(total == str_size - whitespaces){
        return True;
    }

    return False;
}


int str_isspace(string str){
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++){
        if(isspace(str[i])){
            whitespaces++;
        }elif(isspace(str[i] == 0)){
            return False;
        }
    }

    if(whitespaces == str_size){
        return True;
    }
}


int str_isalpha(string str)
{
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++)
    {
        if(isalpha(str[i]))
        {
            total++;
        }
        elif(isspace(str[i]))
        {
            whitespaces++;
        }
        else
        {
            return False;
        }
    }


    if(total == str_size - whitespaces){
        return True;
    }

    return False;
}


int str_isdigit(string str)
{
    int total = 0;
    int whitespaces = 0;
    int str_size = strlen(str);

    for(int i = 0; i < str_size; i++)
    {
        if(isdigit(str[i]))
        {
            total++;
        }
        elif(isspace(str[i]))
        {
            whitespaces++;
        }
        else
        {
            return False;
        }
    }

    if(total == str_size - whitespaces){
        return True;
    }


    return False;
}


void str_splitlines(string str)
{
    str_split(str, " ");
}



float CNPY_rsqrt(float number){
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs) - (x2 * y * y);


    return y;
}


/**
 * @brief Find the substring inside a string. Supporting search zone feature. Set negative value at end offset for end of the string
 * 
 * @param str The given string
 * @param value The substring to be found inside str
 * @param start The offset of when to start
 * @param end The end range
 * @return ptrdiff_t Return the index of the first character of the substring when found. Else, -1 is returned
 */
ptrdiff_t find_str(string str, string value, const unsigned int start, const int end){
    if (end > 0){
        size_t strLen = strlen(str);
        string copy = malloc(strLen);

        strncpy(copy, str, strLen);
        //Since we only find until "end" index
        copy[end] = '\0';
        
        char* strstrRet = strstr(copy + start, value);
        return strstrRet == NULL ? -1 : strstrRet - copy;
    }

    char* strstrRet = strstr(str + start, value);
    return strstrRet == NULL ? -1 : strstrRet - str;
}

/**
 * @brief Works just like the find method. However, an error is thrown when not found then given value
 */
ptrdiff_t index_str(string str, string value, const unsigned int start, const int end){
    char* strstrRet;
    if (end > 0){
        size_t strLen = strlen(str);
        string copy   = malloc(strLen);

        strncpy(copy, str, strLen);
        //Since we only find until "end" index
        copy[end] = '\0';
        
        strstrRet = strstr(copy + start, value);
        if (strstrRet == NULL){
            fprintf(stderr, "ValueError: substring not found, given: \"%s\"\n", value);
            exit(1);
        }
    }else{
        strstrRet = strstr(str + start, value);
        if (strstrRet == NULL){
            fprintf(stderr, "ValueError: substring not found, given: \"%s\"\n", value);
            exit(1);
        }
    }

    return strstrRet - str;
}

/**
 * @brief Justify the given string to the right of a new string
 * 
 * @param str The string to be justified
 * @param len The len of the fill offset and the string itself
 * @param fill The character to be filled
 * @return string The new string that right-justified the old string
 */
string rjust(string str, const size_t len, const char fill){
    size_t strLen = strlen(str);
    if (len < strLen)
        return NULL;

    string ret    = malloc(len + 1);

    if (!ret){
        fprintf(stderr, "ERROR: rjust function: Can't allocating memory");
        exit(1);
    }
    memset(ret, fill, len - strLen);
    memcpy(ret + (len - strLen), str, strLen);

    return ret;
}


/**
 * @brief Justify the given string to the left of a new string
 * 
 * @param str The string to be justified
 * @param len The len of string and the fill offset
 * @param fill The character to be filled
 * @return string The new string that left-justified the old string
 */
string ljust(string str, const size_t len, const char fill){
    size_t strLen = strlen(str);
    if (len < strLen)
        return NULL;

    string ret    = malloc(len + 1);

    if (!ret){
        fprintf(stderr, "ERROR: ljust function: Can't allocating memory");
        exit(1);
    }

    memcpy(ret, str, strLen);
    memset(ret + strLen, fill, len - strLen);

    return ret;
}


/**
 * @brief Basically right-justified but auto fill with zero (ascii value) instead 
 * 
 * @param str The string to be justified
 * @param len The len of string and the fill offset
 * @return char* The new string that right-justified and fills with zero
 */
char* zfill(string str, size_t len){
    string ret = rjust(str, len, '0');

    return ret;
}


//Some more checking method for string

bool isspace_str(string str){
    bool ret = true;
    size_t i = 0;

    while (str[i] != '\0'){
        if (str[i] != ' ')
            ret = false;
        i++;
    }

    return ret;
}

bool isprintable_str(string str){
    size_t strLen = strlen(str);
    bool ret = true;

    for (int i = 0; i < strLen; i++)
        if (!isprint(str[i]))
            ret = false;

    return ret;
}

bool isdigit_str(string str){
    size_t strLen = strlen(str);
    bool ret = true;

    for (int i = 0; i < strLen; i++)
        if (!isdigit(str[i]))
            ret = false;

    return ret;
}

bool isidentifier_str(string str){
    size_t strLen = strlen(str);
    bool ret = true;

    if (isdigit(str[0]))
        return false;
    else{
        for (int i = 0; i < strLen; i++){
            if (str[i] == ' ')
                return false;

            if (!isalnum(str[i]) && str[i] != '_')
                ret = false;
        }
    }
    return ret;
}


/**
 * @brief Trim of the heading and the trailing of any character that met inside the strip_content
 * 
 * @param str The string to be trimmed
 * @param strip_content The delimiter for trimming
 * @return string The new string that got trimmed the heading and the trailing
 */
string strip(string str, string strip_content){
    size_t start  = 0;
    size_t strLen = strlen(str);
    size_t end    = strLen - 1;
    string ret   = calloc(strLen, 1);
    int    i;

    //Trim the leading
    while (strchr(strip_content, str[end]))
        end--;
    
    //Trim the trailing
    while (strchr(strip_content, str[start]))
        start++;

    //Start copying data
    for (i = 0; i <= end - start; i++)
        ret[i] = str[i + start];
    
    ret[i] = '\0';

    ret = realloc(ret, strlen(ret) + 1);

    return ret;
}


/**
 * @brief Check whether the string is of title type (First character of all word must be uppercase)
 * 
 * @param str The string to be checked
 * @return true When the string obeys the rule, false when the string not obeys the rule or only contains number
 */
bool istitle(string str){
    bool           ret    = true;
    bool           char_flag = false; //Check the case where there's no character and only number
    size_t         len    = strlen(str);
    size_t         offsetS = 0;
    size_t         offsetE = 0;
    string         token;

    while (offsetE < len){
        while (isalpha(str[offsetE])){
            offsetE++;
            char_flag = true;
        }

        // Reach here when the delimiter was found
        for (int i = 0; i < offsetE - offsetS; i++){
                if (isalpha((str + offsetS)[i])){
                    if (i > 0){
                        if (!islower((str + offsetS)[i]))
                            return false;       
                    }   
                    else{
                        if (!isupper((str + offsetS)[i]))
                            return false;
                    }
                }
        }

        while (!isalpha(str[offsetE]))
            offsetE++;

        offsetS = offsetE;
    }

    return char_flag ? ret : false;
}

/**
 * @brief Turn the string to become title
 * 
 * @param str The string to be transform
 * @return string The new string that is obeys title form
 */
string title(string str){ 
    size_t len   = strlen(str);
    size_t i     = 0;
    string ret    = malloc(len + 1);

    if (!ret){
        fprintf(stderr, "ERROR: title function: Can't allocating memory");
        exit(1);
    }
    strncpy(ret, str, len);

    while (i < len){
        //Cycle through the non-alpha character
        while (!isalpha(str[i])){
            i++;

            if (i >= len)
                goto CHECK_DONE;
        }
        
        //And upper case the first one
        ret[i] = toupper(ret[i]);

        //Then cycle through until meeting a non-alpha again
        while (isalpha(str[i])){
            i++;

            if (i >= len)
                goto CHECK_DONE;
        }
        i++;
    }

    
    CHECK_DONE:
    return ret;    
}



float rsqrt(float number){
    float result = CNPY_rsqrt(number);
    return result;
}
