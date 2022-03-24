#include <stdio.h>
#include "UsefulHeap.h"

int	DataPriorityComp(char ch1, char ch2)	// 우선순위 비교함수
{
	// 아스키 코드 값이 작은 문자의 우선순위가 더 높다
	return	ch2 - ch1;
}

int	main()
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);		// 우선순위 비교함수 등록

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
