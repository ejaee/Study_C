#include <stdio.h>
#include <stdlib.h>

int	main(){
	int N, check = 0;
	char arr[50] = {0};
	int stack[100] = {0};
	scanf("%d", &N);

	while(N--){
		scanf("%s", arr);
		check = 0;
		for(int idx = 0; arr[idx] != 0; idx++){
			if(arr[idx] == '(')
				check++;
			else if(arr[idx] == ')')
				check--;
			if(check < 0){	
				printf("NO\n");
				break;
			}
			else if(arr[idx+1] == 0 && check == 0)	printf("YES\n");
			else if(arr[idx+1] == 0 && check != 0)	printf("NO\n");
		}
	}
	return 0;
}
