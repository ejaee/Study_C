#include <stdio.h>

void	main(){

	char ch;

	ch = getchar();
	ch = getchar();
	printf("%c\n", ch);
	/*
	getchar 함수는 버퍼에 값이 없으면 입력을 받고, 있으면 버퍼에서 한 글자를 저장한다
	getchar 함수를 한번 더 사용하면 그 다음의 값을 저장한다

	getch()
	버퍼를 거치지 않고 
	문자 하나만 입력받는다

	gets(&)
	가변인수를 저장할 주소로 받고
	입력 문자열을 해당 주소에 저장한다
	space에 영향을 받지 않고 모두 다 저장된다

	scanf(&)
	space에 영향을 받는다
}
