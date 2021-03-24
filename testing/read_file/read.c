#include <stdio.h>
#include <stdlib.h>

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


int main(void){
	printf("%s", read_file("test.txt"));
}
