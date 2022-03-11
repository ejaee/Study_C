#include <stdio.h>
#include <stdlib.h>

int	main(){
	int *arr, n, max = -1;

	//수열 길이 입력
	scanf("%d", &n);
	char *plma = malloc(sizeof(char) * 2 * n);
	int *stack = malloc(sizeof(int) * n);
	
	//목표로하는 수열 입력
	arr = malloc(sizeof(int) * n);
	for(int idx = 0; idx < n; idx++)
		scanf("%d", &arr[idx]);
	
	int idx = 0, num = 1, rst_idx = 0;
	while(1){
		if(max == -1 || stack[max] < arr[idx]){
			stack[++max] = num++;
			plma[rst_idx++] = '+';
		}
		else if(stack[max] == arr[idx]){
			max--;
			plma[rst_idx++] = '-';
			idx++;
		}
		else{
			printf("NO\n");
			return 0;
		}
		if(rst_idx == 2 * n)	break;
	}

	for(int idx = 0; idx < rst_idx; idx++)
		printf("%c\n", plma[idx]);
	return 0;
}
