#include <stdio.h>

int	main(){
	int p;
	for(int idx = 1; idx <=  25; idx++){
		if (idx%10 == 1)
			for(int idx1 = 1; idx1 <= 5; idx1++){
				printf("%d\t", idx);
				if (idx1 == 5)
					printf("\n");
			}
		else
			for(int idx1 = 1; idx1 <= 5; idx1++){
				p = 2*idx + 4;
				printf("%d\t", p - idx);
				if (idx1 == 5)
					printf("\n");
			}
	}


	return 0;
}
