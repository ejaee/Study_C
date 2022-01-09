#include <stdio.h>

int	main(){

	char* arr[3] = {"Test", "String", "Data"};	// char*형으로 주소가 3개 저장
	char** parr = arr;

	char buf[32]= {"TestString"};
	char* pbuf = buf;

	printf("%c\n", **arr);
	printf("%c\n", *arr[1]);
	printf("%c\n", *pbuf);
	
	printf("%s\n", arr[0]);
	printf("%s\n", *(parr + 1));

	/*
		<핵심>
		sizeof(char*), sizeof(char**), sizeof(char***) 결과 모두 같다
		어짜피 시스템에서 메모리의 간격은 일정하다
	 */

	return 0;
}
