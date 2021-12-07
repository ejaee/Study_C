#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data, sum = 0;
	ListInit(&list);

	/*** 정수 1~9의 데이터 저장 ***/
	for(int idx= 1; idx < 10; idx++)
		LInsert(&list, idx);

	/*** 저장값 순차적으로 참조하여 합하기 ***/
	if(LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		sum += data;
		
		while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회
			sum += data;
	}
	printf("SUM = %d\n\n", sum);

	/*** 숫자 2의 배수와 3의배수를 탐색하여 모두 삭제 ***/
	if(LFirst(&list, &data))
	{
		if(data%2 == 0 || data%3 == 0)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data%2 == 0 || data%3 == 0)
				LRemove(&list);
		}
	}

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
