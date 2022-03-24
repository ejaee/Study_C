#include <stdio.h>

int	main(){
	int t, num, numm, cnt, arr[6] = {0};
	
	while(1){
		scanf("%d", &num);
		if(num == 0) return 0;
		numm = num;
		cnt = 0;

		while(num){
			num /=10;
			cnt++;
		}

		for(int idx = 0; idx < cnt; idx++){
			arr[idx] = numm % 10;
			numm /= 10;
		}
		arr[cnt] = 0;
		
		if(arr[1] == 0){
			printf("yes\n");
			continue;
		}		

		for(int idx = 0; idx < cnt/2; idx++){
			if(arr[idx] != arr[cnt - idx - 1])
				arr[0] = 0;
		}
		if(arr[0] != 0) printf("yes\n");
		else if(arr[0] == 0) printf("no\n");
	}
	return 0;
}
