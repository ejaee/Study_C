#include <stdio.h>
void	Quick(int arr[], int left, int right){
	int L = left, R =right;
	int temp;
	int pivot = arr[(left + right) /2];
	while(L<=R){
		while(arr[L] < pivot)
			L++;
		while(arr[R] > pivot)
			R--;
		if(L <= R){
			if(L != R){
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			}
			L++;
			R++;
			for(int idx = 0; idx < right; idx++){
				printf("%d\n", arr[idx]);
			}
		}
	}
}


int	main(){
	int N, arr[1000000];
	scanf("%d", &N);
	while(N--){
		scanf("%d", &N);
	}
	arr[N] = 0;
	Quick(arr, 0, N-1);

	return 0;
}
