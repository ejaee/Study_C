#include <stdio.h>
void	check(int arr[], int N){
	int min, temp;

	for(int idx = 0; idx < N-1; idx++){
		min = idx;
		for(int idx2 = idx + 1; idx2 < N; idx2++){
			if(arr[min] > arr[idx2])
				min = idx2;
		}
		temp = arr[idx];
		arr[idx] = arr[min];
		arr[min] = temp;
	}
	for(int idx = 0; idx < N; idx++){
		printf("%d\n", arr[idx]);
	}
}
	
int	main(){
	int N, arr[1000] = {0};
	scanf("%d", &N);
	for(int idx = 0; idx < N; idx++){
		scanf("%d", &arr[idx]);
	}
	arr[N] = 0;
	check(arr, N);
	return 0;
}
