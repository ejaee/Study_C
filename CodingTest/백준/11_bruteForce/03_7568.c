#include <stdio.h>

int	main(){
	int turn = 0, rank;
	int w[50] = {0}, l[50] = {0};
    scanf("%d", &turn);

	for(int idx = 0; idx < turn; idx++){
		scanf("%d %d", &w[idx], &l[idx]);
	}
	for(int i = 0; i < turn; i++){
		rank  = 0;
		for(int j = 0; j < turn; j++){
			if(w[i] < w[j] && l[i] < l[j])	rank++;
		}
	printf("%d ", rank+1);
	}
	return 0;
}
