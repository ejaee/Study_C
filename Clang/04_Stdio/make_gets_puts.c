#include <stdio.h>

void	main(){

	char buffer[128] = {0};

	printf("Input your name : ");
	gets(buffer);

	printf("Your name is ");
	puts(buffer);
}
