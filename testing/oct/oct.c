#include <stdio.h>

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

int main(void){
	printf("%ld", oct(78));
}
