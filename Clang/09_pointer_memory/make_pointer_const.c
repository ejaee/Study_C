#include <stdio.h>

int	main(){

	int nb = 10;
	
	const int* p = &nb;
	int* const pp = &nb;

	// p 포인터 변수에 저장된 주소를 가리키는 메모리를 상수화한다
	p = NULL;
	//오류 : p = 20;

	// ppkㄹ는 이름의 메모리 자체를 상수화한다
	*pp = 20;
	//오류 : *pp = NULL;

	/*
		정리
		const형 한정어 바로 오른쪽에 위치한 대상을 상수화한다
	*/


	return 0;
}
