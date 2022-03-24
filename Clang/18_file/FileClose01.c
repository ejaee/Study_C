#include <stdio.h>

// 문제있음

int main()
{
	FILE *fp = NULL;
	
	int nClosed = 0;
	fopen("Test1.txt", "w");
	fopen("Test2.txt", "w");
	fopen("Test3.txt", "w");

	nClosed = fclose();			//_fcloseall 함수가 안써진다
	printf("%d\n", nClosed);
	return 0;
}
