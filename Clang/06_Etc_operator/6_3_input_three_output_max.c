#include <stdio.h>

void	main(){
	int idx1, idx2, idx3;
	int a;
	scanf("%d %d %d", &idx1, &idx2, &idx3);
	/* 내 정답

	a = idx1 > idx2 ? idx1 : idx2;
	printf("%d\n", a > idx3 ? a : idx3);
	*/

	//개선안

	printf("%d\n", idx1 > idx2 ? (idx1 > idx3 ? idx1 : idx3) : (idx2 > idx3 ? idx2 : idx3));
	
}
