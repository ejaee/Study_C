#include <stdio.h>

int	main(){
	char arr[10000] = {0};
	int cnt = 0;
	int jdx = 0;

	while(scanf("%c", &arr[jdx]) && arr[jdx] != '/'){
		if(arr[jdx] == 't')
			cnt++;
		jdx++;
	}
	//printf("string : %s\n\n", arr);
	printf("t's count : %d", cnt);

	return 0;

/*
	while문 안에 조건식을 다음과 같이 활용할 수 있다
	특정 문자가 나올때까지 입력을 받도록 하는 프로그램에서 사용가능
*/

}
