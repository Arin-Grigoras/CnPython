#include <stdio.h>
#include <stdlib.h>

void hex(int n)
{
    	char *hexaDeciNum = (char*)malloc(sizeof(char) * 100);

	if(!hexaDeciNum){
		printf("\n\nERROR: Hex() function error\nCouldn't allocate memory\n\n");
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


int main(void){
	hex(2545);
}
