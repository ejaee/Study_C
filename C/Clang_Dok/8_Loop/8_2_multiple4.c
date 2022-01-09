#include <stdio.h>

int	main(){
	int idx = 10, cnt = 0, sum = 0;
	while(idx <= 100){
		if(idx % 4 == 0){
			printf("%d\t", idx);
			cnt++;
			sum += idx;
		}
		idx++;
	}

	printf("\n%d\n", sum);
	return 0;
}
