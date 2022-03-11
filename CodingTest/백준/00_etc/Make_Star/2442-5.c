#include <stdio.h>

int	main(){
	int star, line, space;
	scanf("%d", &star);
	line = star;
	for(int idx = 1; idx <= star; idx++)
	{
		space = line - ((2 * idx) - 1)/2 - 1;
		while(space--)
			printf(" ");
		for(int j = 1; j <= (2 * idx) - 1; j++)
			printf("*");
		if(idx == star) return 0;
		printf(" ");
		printf("\n");
	}
}
