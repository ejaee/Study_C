#include <stdio.h>
int main(){
	int M, N, idx;
	int	arr[1000001] = {0, };
	arr[1] = 1;

	scanf("%d %d", &M, &N);

	for(idx = 2; idx < N; idx++){
		for(int idx2 = 2; idx * idx2 <= N; idx2++)
			arr[idx * idx2] = 1;
	}
	
	for(idx = M; idx <= N; idx++)
		if(arr[idx] == 0) printf("%d\n", idx);

	return 0;
}
