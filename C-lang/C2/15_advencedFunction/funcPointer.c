#include <stdio.h>

int	func(int data)
{
	puts("print string");
	return 0;
}

int	main(){
	int	(*pfunc)(int);		// error : *pfunc(int)
	pfunc = func;
	pfunc(10);
	return 0;
}

	/*
	   함수 포인터는 프로그램이 실행되는 도중에 호출할 함수가 달라져야할 때 사용

	   예)
	   프로그램이 실행될 운영체제의 버전에 따라 호출할 시스템 함수가 달라져야할 때
	   운영체제의 버전에 따라 지원하는 시스템 함수가 다를 수 있기 때문에
	 
		호출할 함수가 시스템에 있는지 검사 -> 해당 함수의 주소를 알아낸 후 호출
	 */
