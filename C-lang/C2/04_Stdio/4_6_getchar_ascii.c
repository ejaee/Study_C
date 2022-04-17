#include <stdio.h>

void	main(){
	char ch;

	ch = getchar();
	printf("%c\n", ch - 32);

	/*
	ASCII에서
	A : 65
	a : 97
	차이 : 32
	*/
}
