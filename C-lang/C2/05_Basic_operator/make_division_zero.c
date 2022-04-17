#include <stdio.h>

void	main(){
	int idx = 20;

	printf("%d\n", idx/0);
	printf("%d\n", idx%0);
	printf("%d\n", idx/6);
	printf("%d\n", idx%6);

	/*
	division(reminder) by zero is undefined
	*/
}
