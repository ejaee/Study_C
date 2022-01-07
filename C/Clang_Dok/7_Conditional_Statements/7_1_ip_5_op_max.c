#include <stdio.h>

int	main(){

	int idx1, idx2, idx3, idx4, idx5, max = 0;
	scanf("%d", &idx1);
	if(max < idx1)	max = idx1;

	scanf("%d", &idx2);
	if(max < idx2)	max = idx2;
	
	scanf("%d", &idx3);
	if(max < idx3)	max = idx3;
	
	scanf("%d", &idx4);
	if(max < idx4)	max = idx4;
	
	scanf("%d", &idx5);
	if(max < idx5)	max = idx5;

	printf("max number : %d\n", max);

	return 0;
}
