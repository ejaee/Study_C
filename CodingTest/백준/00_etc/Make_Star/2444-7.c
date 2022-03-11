#include <stdio.h>

void	up(int nb){

	int line, space;
    line = nb;
    for(int idx = 1; idx <= nb; idx++)
    {
        space = line - ((2 * idx) - 1)/2 - 1;
        while(space--)
            printf(" ");
        for(int j = 1; j <= (2 * idx) - 1; j++)
            printf("*");
        printf(" ");
        printf("\n");
        if(idx == nb) return ;
    }
}

void	down(int nb){
	int N = nb - 1;
    for(int idx = 0; idx < N; idx++){
		printf(" ");
        for(int space = idx; space > 0; space--){
            printf(" ");
        }
        for(int j = 2 *( N - idx) - 1; j > 0; j--){
            printf("*");
        }
        if(idx == N) return ;
        printf("\n");
    }
}

int		main(){
	int nb;
	scanf("%d", &nb);

	up(nb);
	down(nb);
	return 0;
}
