#include <stdio.h>

typedef	struct	DATA
{
	unsigned	char	main : 1;
	unsigned	char	left : 1;
	unsigned	char	rignt : 3;
	unsigned	char	top : 2;
}	DATAFLAG;
	//	비트의 크기 1, 2, 3, 2

int	main(){
	DATAFLAG	flagSwitch = {0, 3, 7, 4};

	printf("%d\n", flagSwitch.main);
	printf("%d\n", flagSwitch.left);
	printf("%d\n", flagSwitch.rignt);
	printf("%d\n\n", flagSwitch.top);

	printf("%x\n", *((unsigned char *)&flagSwitch));
	// 구조체를 형변환할 수 없기 때문에 (unsigned char *)flagSwitch 하면 안됨
	printf("%d\n", sizeof(flagSwitch));
	// 각 멤버들의 값과 이들 갑을 합쳐서 1바이트 메모리의 내용의 값
	printf("%d\n", sizeof(DATAFLAG));

	return 0;
}
