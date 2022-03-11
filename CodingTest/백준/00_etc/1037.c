#include <stdio.h>

int	main(){
	int cnt, idx, min = 1000000, max = 2;

	scanf("%d", &cnt);
	while(cnt--){
		scanf("%d", &idx);
		if (min >= idx) min = idx;
		if (max <= idx) max = idx;
	}
	printf("%d", min * max);
	return 0;
}
