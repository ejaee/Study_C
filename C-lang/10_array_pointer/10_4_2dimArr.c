#include <stdio.h>

int	main(){
	char	arr[5][5] = {0};
	int		idx = 0;
	int		num = 1;
	int		cnt = 4;

	while (1){
		if (cnt == 2){
			arr[2][2] = num;
			break;
		}
		while (idx < cnt)
			arr[4-cnt][idx++] = num++;
		idx = 4-cnt;
		while (idx < cnt)
			arr[idx++][cnt] = num++;
		while (idx > 4-cnt)
			arr[cnt][idx--] = num++;
		idx = cnt;
		while (idx > 4-cnt)
			arr[idx--][4-cnt] = num++;
		cnt -=1;
		idx = 1;
	}
	
	for (int jdx = 0; jdx < 5; jdx++)
	{
		for(int kdx =0; kdx < 5; kdx++){
			if(arr[jdx][kdx] < 10)
				printf(" %d  ", arr[jdx][kdx]);
			else
				printf("%d  ", arr[jdx][kdx]);
		}
		printf("\n\n");
	}
	return 0;
}
