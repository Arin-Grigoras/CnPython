#include <stdio.h>

int startswith(char *str, char element){
	if(str[0] == element){
		return 0;
	}
	return -1;
}

int main(void){
	char *str = "Hello world";

	printf("%d", startswith(str, 'H'));

}
