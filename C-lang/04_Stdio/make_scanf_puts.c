#include <stdio.h>

void	main(){

	char buf[128] = {0};

	scanf("%s", buf);	// 초기화 되어있으므로 문자열 입력 input "just do it"
	puts(buf);			// output "just"
	puts(buf);			// output "just"
	printf("%s\n", buf);
	
	/* 
	버퍼에 scanf를 활용하여 입력을 하는 경우 space의 영향으로 그 이전까지의 내용만 buf에 저장된다,


	따라서 puts, printf로 출력하면 space 이전까지 출력이 되고
	이어서 puts을 사용하더라도 저장된 값은 just 이므로
	just 단어가 연속적으로 출력된다

	\n를 적지 않았지만 puts의 특징으로 줄바꿈이 나타난다
	*/

	scanf("%s", buf);	// 추가적인 입력 없이도 buffer에 do it이 남아 있으므로 자동으로 do가 저장
	puts(buf);
	scanf("%s", buf);	// 상기 내용으로 it이 저장
	puts(buf);
	
	/*
	scanf는 버퍼가 비었으면 입력을 받고 space 기준으로 끊어 입력을 받는다
	space 이후의 입력 값은 여전히 buffer에 남아있다
	scanf를 하면 버퍼에 남은 값이 남아 있으므로 추가적으로 입력을 받지 않고 남아있는 문자열을
	space 기준으로 끊어 입력 받는다

	정리 
	scanf - buffer에 저장된 값 없으면 입력받고 있으면 저장 - 저장했다면 buffer에서 저장된 값 빠지기 - 이후 scanf 시,
	남은 buffer에 값이 남아있다면 입력을 받지 않고 해당 값을 space 기준으로 잘라 저장 - 이후 연속
	*/

}
