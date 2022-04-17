#include <stdio.h>

int	main(){

	int nb = 10;
	
	int *p = &nb;
	int **pp = &p;
	int ***ppp = &pp;

	// p에 저장된 주소
	printf("p에 저장된 주소 :[%p]\n", p);			// & + *p = p
	printf("*pp에 저장된 주소 :[%p]\n", *pp);		// & + **pp = *pp
	printf("**ppp에 저장된 주소 :[%p]\n", **ppp);	// & + ***ppp = **ppp

	// p의 주소
	printf("%p\n", &p);
	printf("%p\n", pp);
	printf("%p\n", *ppp);

	// 메모리의 위치는 모두 스택 구조로 관리되는 메모리 영역에 존재한다
	return 0;
}
