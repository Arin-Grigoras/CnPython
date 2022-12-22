#include <stdio.h>
#include <math.h>
#include <stdarg.h>


#define true 1
#define false 0


long long dec_to_bin(long decimal, ...){
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

	if(va_arg(valist, int) == 1){
		printf("0b%lld\n", bin);
	}


	va_end(valist);



	return bin;
}


int main(void){
	printf("%lld\n", dec_to_bin(10, false));
	long long test = dec_to_bin(10, false);

	printf("%lld\n", test);


}
