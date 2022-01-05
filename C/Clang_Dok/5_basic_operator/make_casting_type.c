#include <stdio.h>

void	main(){

	int idx = 15;
	float fdx1 = 1.5f, fdx2 = 3.4f;

	// 정수끼리의 연산 결과 값인 정수를  %f로 출력 불가
	printf("오류 : %f\n", idx * 100 / 100);
	printf("정답 : %d\n", idx * 100 / 100);

	// 형변환 연산자의 활용
	printf("오류 : %f\n",				idx / 10 * 100.0f);
	printf("정답 : %d\n", (int)((float)idx / 10 * 100.0f));// 결과값 형변환


	/*
		<형변환 연산자>
		결합성 :  오른쪽에서 왼쪽

		자료형의 승격과 관련한 처리 때문에 형 변환 연산자 사용 발생


	*/
}
