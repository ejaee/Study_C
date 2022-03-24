#include <stdio.h>
int	main(){
	int	idx = 0, A, B, V, day = 0;

	scanf("%d %d %d", &A, &B, &V);
	V -= A;
	day = V / (A - B);
	if ( V % (A - B) != 0)
		day++;
	day++;
	printf("%d", day);
	return 0;
}
