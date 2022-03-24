#include <stdio.h>
#include <stdlib.h>
int	main(){
	int N;
	scanf("%d", &N);
	int *arr = malloc(sizeof(int*)*N);
	int *stack = malloc(sizeof(int*)*2*N);
	char *plma = malloc(sizeof(int*)*N);

	for(int idx = 0; idx < N; idx++)
		scanf("%d", &arr[idx]);

	int num = 1, top = -1, rst = 0, idx = 0;
	while(1){
		if(top == -1 || stack[top] < arr[idx]){
			stack[++top] = num++;
			plma[rst++] = '+';
		}
		else if(stack[top] == arr[idx]){
			stack[top--] = 0;
			plma[rst++] = '-';
			idx++;
		}
		else{
			printf("NO");
			return 0;
		}
		if(rst  == 2*N)	break;
	}
	for(int idx = 0; idx < rst; idx++)
		printf("%c\n", plma[idx]);
	return 0;
}
