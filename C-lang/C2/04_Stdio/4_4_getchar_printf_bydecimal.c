#include <stdio.h>

void	main(){
	char ch;

	ch = getchar();
	printf("%c\n", ch);
	printf("%d\n", ch);

	/*
		getch 함수는 컴파일러에서 제외되었음
		#include <conio.h>의 _getch 함수를 사용할 수 있음
		(즉각적인 반응을 보이는 콘솔 입력 함수)
	
		char 자료형에 저장된 문자는 십진수와 아스키코드 문자 둘다 출력할 수 있다
	 */
}
