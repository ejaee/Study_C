#include <stdio.h>

int	main()
{
	char c = 65;
	char *cp = &c;
	char **cpp = &cp;
	// 포인터 연산
	// cp +1 은 cp가 포인터이나, 해당 값에 집중한다면
	// &c 주소값을 가지고 c는 char형 메모리 이므로 + char

	// &cp +1 은 포인터의 주소이므로 char *형 포인터 크기만큼 +
	printf("\n포인터 연산\n");
	printf("c : %d\ncp : %x\ncpp : %x\n" , c, cp, cpp);
	printf(" c+1 : %d\n cp+1 : %x\n cpp+1 : %x\n", c+1, cp+1, cpp+1);

	printf("\n포인터 연산\n");
	printf("&c : %x\n&cp : %x\n&cpp : %x\n" , &c, &cp, &cpp);
	printf(" &c+1 : %x\n &cp+1 : %x\n &cpp+1 : %x\n", &c+1, &cp+1, &cpp+1);
}
