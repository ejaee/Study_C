#include <stdio.h>

int	main(){
	int idx2 = 0, sum = 0, cnt = 0, tmp = 0, N, check;
	scanf("%d", &N);
	check = N;

	while(check){
		check /= 10;
		cnt++;
	}
	
	for(int idx = N - 9*cnt; idx <= N; idx++){
		sum = 0;
		tmp = idx;
		idx2 = idx;
		while(idx2){
			sum += idx2 % 10;
			idx2 /= 10;
		}	
		sum += tmp;
		if(N == sum){
			printf("%d\n", idx);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
