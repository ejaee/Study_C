#include <stdio.h>

void	main(){
	char arr[128] = {0};

	gets(arr);
	printf("%s\n", arr);
	/*
		gets는 scanf와 다르게 space에 국한되지 않고 모든 input string을 저장한다
	*/

	//심화
	puts(arr);	// printf와 같다
}
