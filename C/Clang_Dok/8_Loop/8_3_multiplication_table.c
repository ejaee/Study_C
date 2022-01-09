#include <stdio.h>

int	main(){

	for(int idx = 2; idx <= 9; idx++){
		printf("%d의 배수\n", idx);
		for(int idx2 = 1; idx2 <= 9; idx2++){
			printf("%d x %d = %d\n", idx, idx2, idx*idx2);
		}
	}


	return 0;
}
