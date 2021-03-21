#include <stdio.h>
#include <math.h>


long long dec_to_bin(long decimal){
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


int main(void){
	printf("%lld", dec_to_bin(10));
}
