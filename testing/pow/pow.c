#include <stdio.h>

double pow(double base, double exponent){
	double result = 1;
	for(exponent; exponent > 0; exponent--){
		result *= base;
	}

	return result;
}

int main(void){
	
	printf("%f", pow(2, 3));
}
