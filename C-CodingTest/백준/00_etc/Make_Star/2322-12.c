#include <stdio.h>

int	main(){
	int N, turn;
	scanf("%d", &N);
	turn = N;
	
	for(int idx = 1; idx <= 2*N-1; idx++){
		for(int j = N-idx; j > 0; j--)
			printf(" ");
		for(int j = idx; j <= N; j++)
			printf("*");



	return 0;
}
