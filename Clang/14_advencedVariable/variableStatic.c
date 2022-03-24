#include <stdio.h>

int	testFunc(){
	static int rst = 10;
	rst++;
	return rst;
}

int	main(){
	printf("%d\n", testFunc());
	printf("%d\n", testFunc());
	printf("%d\n", testFunc());
	return 0;
}
	/*
	   rst는 초기화되지 않는다
	*/
