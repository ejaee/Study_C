#include <stdio.h>

void	main(){

	char buf[128] = {0};

	gets(buf);

	printf("%s\n", buf);
	puts(buf);

	/*
		gets으로 입력을 받을 때
		space에서 입력이 끝나지 않고 게속 입력을 이어가다 enter에서 입력이 종료된다

		printf에서 출력되는 string은 space에 영향을 받지 않고 버퍼의 모든 내용이 다 출력된다
		puts으로 출력해도 모든 버퍼의 내용이 다 출력된다

		이전의 예제에서 scanf로 입력을 받을 경우 space의 영향을 미침을 확인했다
	*/
}
