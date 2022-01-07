#include <stdio.h>

void	main(){

	char arr[16] = {0};
	int idx = 10;

	printf("short형의 sizeof : %d\n", sizeof(short));		// 자료형 크기 short인 2 출력
	printf("(short)100의 sizeof : %d\n", sizeof((short)100));	// 100은 정수지만 short인 2출력
	
	printf("숫자 100의 sizeof : %d\n", sizeof 100);			// 100은 정수이므로 자료형 크기 4 출력
	printf("int형의 sizeof : %d\n", sizeof(int));			// int형 4 출력
	printf("변수 idx의 sizeof : %d\n", sizeof(idx));		// 변수의 자료형에 주목, 4 
	
	printf("100.0의 sizeof : %d\n", sizeof(100.0));			// 100.0은 double 8
	printf("100.0f의 sizeof : %d\n", sizeof(100.0f));		// 100.0f은 float 4
	printf("10.0 / 10의 sizeof : %d\n", sizeof(10.0 / 10)); // 결과 값 double 8
	printf("10 / 10의 sizeof : %d\n", sizeof(10 / 10));		// 결과 값 정수 4

	
	printf("char* 의 sizeof : %d\n", sizeof(char *));		// 포인터는 32에서 4 64에서 8
	printf("배열 arr[16]의 sizeof : %d\n", sizeof(arr));	// 배열의 총길이 char*16 = 16

	/*
		포인터 변수는 메모리의 주소를 저장하는 변수

		32bit 운영체제에서 포인터의 크기는 4byte
		64bit 운영체제에서 포인터의 크기는 8byte
	*/

}
