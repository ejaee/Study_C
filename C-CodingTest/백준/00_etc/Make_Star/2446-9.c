#include <stdio.h>

int	main(){
	int nb, turn;
	scanf("%d", &nb);
	turn = nb;

	for(int idx = 0; idx < turn; idx++){
		for(int j = 0; j < idx; j++)
			printf(" ");
		for(int j = (2 * (turn - idx)) - 1; j > 0; j--)
			printf("*");
        printf(" \n");
	}
	for(int idx = 1; idx < turn; idx++){
        for(int j = turn - idx; j > 1; j--)
			printf(" ");
		for(int j = 1; j <= (2 * idx) + 1; j++)
			printf("*");
		if(idx+1 == turn) return 0;
        printf(" \n");
	}
}
