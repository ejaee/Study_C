#include <stdio.h>

void	main(){

	int idx;

	scanf("%d", &idx);

	printf("Use operator '&' = %d\n", idx & 8);

	printf("Use operator '&' = %p\n", idx & 8);
}
