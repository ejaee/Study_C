#include <stdio.h>
int main(){
	int	k, n, idx, idx2, test;
	int apt[15][15] = {0};
	for(idx = 0; idx < 15; idx++)
		apt[0][idx] = idx;
	for(idx = 1; idx < 15; idx++)
		for(idx2 = 1; idx2 < 15; idx2++)
			apt[idx][idx2] = apt[idx-1][idx2] + apt[idx][idx2-1];
	
	scanf("%d", &test);
	while(test--){
		scanf("%d %d", &k, &n);
		printf("%d\n", apt[k][n]);
	}
	return 0;
}
