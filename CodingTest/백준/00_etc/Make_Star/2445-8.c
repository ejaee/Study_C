#include <stdio.h>

int main(){
	int nb, turn;
	scanf ("%d", &nb);
	turn = nb;
	for(int idx = 1; idx <= turn; idx++){
		for(int j = idx; j > 0; j--)
			printf("*");
		for(int j = turn - idx; j > 0; j--)
			printf(" ");
		for(int j = turn - idx; j > 0; j--)
            printf(" ");
		for(int j = idx; j > 0; j--)
            printf("*");
		printf("\n");
	}
	for(int idx = 1; idx < turn; idx++){
		for(int k = turn - idx; k > 0; k--)
			printf("*");
		for(int k = 0; k < 2 * idx; k++)
			printf(" ");
		for(int k = turn - idx; k > 0; k--)
            printf("*");
		printf("\n");
	}
}
