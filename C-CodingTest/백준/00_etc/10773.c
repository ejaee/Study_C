#include <stdio.h>

int	main(){
	int k, idx = 0, sum = 0, arr[1000000] = {0};
	scanf("%d", &k);

	while(k--){
		scanf("%d", &arr[idx]);
		if(arr[idx] == 0){
			while(arr[idx] == 0)
				idx--;
			sum -= arr[idx];
			arr[idx] = 0;
		}
		else
			sum += arr[idx];
		idx++;
	}
	printf("%d\n", sum);
	return 0;
}
