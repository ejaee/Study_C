#include <stdio.h>

void	main(){

	int idx1 = 0, idx2 = 0;
	scanf("%d %d", &idx1, &idx2);

	printf("%d\n", idx1 > 10 && idx2 > 10 ? 1 : 0);
}
