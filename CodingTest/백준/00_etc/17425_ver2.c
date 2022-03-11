#include <stdio.h>
#define MAX 1000001
int	main(){
	int num, T, sum; 
	long long arr[MAX];
	for(int idx = 1; idx <= MAX; idx++){
		for(int j = idx; j <= MAX; j += idx)
			arr[j] += idx;
		arr[idx] += arr[idx - 1];
	}
	scanf("%d", &T);
	while(T--){
		scanf("%d", &num);
		printf("%lld\n", arr[num]);
	}
	return 0;
}
