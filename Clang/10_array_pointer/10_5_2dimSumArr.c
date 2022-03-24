#include <stdio.h>

int	main(){
	char arr[4][5] = {0};
	int idx = 0, jdx = 0;
	int num = 1, sum;

	while (idx < 4){
		sum = 0;
		while (jdx < 4){
			arr[idx][jdx++] = num;
			sum += num;
			num++;
		}
		arr[idx][jdx] = sum;
		idx++;
		jdx = 0;
	}
	for (idx = 0; idx < 4; idx++){
		for (jdx = 0; jdx < 5; jdx++){
			if (arr[idx][jdx] < 10)
				printf(" %d  ", arr[idx][jdx]);
			else
				printf("%d  ", arr[idx][jdx]);
		}
		printf("\n\n");
	}
	return 0;
}
