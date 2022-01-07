#include <stdio.h>

void	main(){

	int idx1 = 0, idx2 = 0;
	idx1 = (idx2 = 5, idx2 + 5);

	printf("idx1 : %d, idx2 : %d\n", idx1, idx2);

}
