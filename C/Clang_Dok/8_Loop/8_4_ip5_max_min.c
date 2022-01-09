#include <stdio.h>

int	main(){
	int idx, idx2, idx3, idx4, idx5, max, min;

	scanf("%d %d %d %d %d", &idx, &idx2, &idx3, &idx4, &idx5);

	// max
	for(int cnt = 0; cnt < 5; cnt++){
		if (max < idx)	max = idx;
		if (max < idx2)	max = idx2;
		if (max < idx3)	max = idx3;
		if (max < idx4)	max = idx4;
		if (max < idx5)	max = idx5;
	}
	// min
	for(int cnt = 0; cnt < 5; cnt++){
		if (min > idx)  min = idx;
		if (min > idx2) min = idx2;
		if (min > idx3) min = idx3;
		if (min > idx4) min = idx4;
		if (min > idx5) min = idx5;
	}

	printf("max = %d min = %d\n", max, min);
	return 0;
}
