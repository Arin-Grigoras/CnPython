#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *This ones scraped cuz just now i realized that fopen does the same exact thing.
 I have brain damage.
 * */

FILE* open(char *filename, char mode[2]){
	FILE *fptr;
	fptr = fopen(filename, mode);

	if(!fptr){
		printf("\n\nERROR: open()\nCouldn't open file\n\n");
		exit(1);
	}

	return fptr;
}

int main(void){
	FILE* fptr = open("test.txt", "r");
}
