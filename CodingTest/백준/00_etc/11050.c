#include <stdio.h>
int	main(){
	int N, K, rst1 = 1, rst2 = 1;
	scanf("%d %d", &N, &K);

	while(K){
		rst1 *= N;
		rst2 *= K;
		N--;
		K--;
	}
	int sum = rst1/rst2;
	printf("%d\n", sum);

	return 0;
}
