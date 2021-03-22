#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *_str(int number){
	int size = (int)((ceil(log10(number))+1)*sizeof(char));
	char *buffer = (char*)malloc(sizeof(size));

	sprintf(buffer, "%d", number);

	return buffer;

}


int main(void){
	int number = 200;
	printf("%s", _str(number));
}
