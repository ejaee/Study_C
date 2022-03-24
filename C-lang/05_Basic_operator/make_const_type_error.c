#include <stdio.h>

void	main(){

	char arr[128] = "A";
	const int idx = 10;

	arr = 'B';	// 주소 상수에 문자 상수를 저장하라는 의미이므로 불가
	idx = 20;	// 상수화 된 메모리의 값을 바꿀 수 없음

	/*
		<대입연산자>
		l-value = r-value

		l-value는 쓰기가 허용되는 메모리가 되어야 함
		위와 같이 쓰기가 불가한 메모리가 올 경우 오류
		모든 l-value 는 r-value가 될 수 있음

		변수를 정의할 때 '='는 문법 (대입연산자가 아님)
		like pointer *
	*/

}
