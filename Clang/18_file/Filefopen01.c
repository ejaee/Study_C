#include <stdio.h>

int	main()
{
	FILE *fp = NULL;

	fp = fopen("Test.txt", "w");
	if (fp == NULL)
	{
		puts("ERROR: Failed to open file!");
		return 0;
	}

	fclose(fp);
}

	/*
		FILE 구조체를 사용하여 변수 선언
		FILE 구조체는 stdio.h에 정의되어있음

		fopen 함수를 통해 FILE 구조체의 주소값이 반환

		기존에 Test.txt 파일이 있다면 영구 삭제되고 새로 만들어진다
	   */
