#include <stdio.h>

int	main(){
	int s;
	scanf("%d", &s);

	for(int i = 0; i < s; i++){
		for(int j = 0; j < i; j++){
			printf(" ");
		}
		for(int j = 0; j < s-i; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
