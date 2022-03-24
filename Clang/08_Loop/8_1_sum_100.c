#include <stdio.h>

int	main(){
	int idx = 0, sum = 0;

	while(++idx <=  100){
		sum +=idx;
	//	idx++;
	}
	printf("%d", sum);

	return 0;
}
