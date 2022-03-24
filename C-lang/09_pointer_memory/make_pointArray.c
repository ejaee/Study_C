#include <stdio.h>

int	main(){
	char *Data[] = {"string", "Data", "Test"};
	int i = 0;

	for (i = 0; i < 3; i++)
		puts(Data[i]);		//	주소를 인자로 받는다
	return 0;
}
