#include <stdio.h>

int	main(){
	int N;
	scanf("%d", &N);

	for(int idx = 0; idx < N; idx++){
		
		for(int space = idx; space > 0; space--){
			printf(" ");
		}	
		for(int j = 2 *( N - idx) - 1; j > 0; j--){
			printf("*");
		}
		if(idx == N) return 0;
		printf("\n");
	}
}
