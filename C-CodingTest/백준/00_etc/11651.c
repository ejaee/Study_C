#include <stdio.h>

int	main(){
	int N, min = 0, num[200002] = {0};

	scanf("%d", &N);
	for(int idx = 0; idx < N/2; idx++){
		scanf("%d %d", &num[idx], &num[idx + 1]);
		if(min > num[idx]) min = num[idx];
	}
	



	return 0;
}
