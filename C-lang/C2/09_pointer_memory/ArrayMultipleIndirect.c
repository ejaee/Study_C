#include <stdio.h>

int	main(){
	char name[2][16] = {"e-jae", "gil-dong"};
	char (*pname)[16] = name;		//char형, 열 크기 16인 2차원 배열에 대해 포인터 변수 선언

	printf("%c, %c\n", name[1][3], pname[1][3]);	//	&&
	printf("%p, %p\n", name, name + 1);				//	+16
	printf("%p\n", *(name + 1) + 4);				//	addr
	printf("%c\n", *(*(name +  1) + 4));			//	memory

	/*
		2차원배열에서 포인터는 char (*p)[columnSize]로 선언
		offset으로 값에 접근하고 싶다면 *(*(arr+ offset) + offset)
	
		2차원 배열의 이름을 이중포인터에 저장하는 것이 아 니 다
		char	arr[row][column];
		char	(*p)[columnSize] = arr;
	 */
	return 0;
}
