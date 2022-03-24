#include <stdio.h>
#include <math.h>

int	main(){
	int N, cnt = 0, num = 665;
	scanf("%d", &N);

	while(1){
		if(cnt == N){
			printf("%d", num);
			return 0;
		}
		num++;
		for(int idx = 0; idx < 4; idx++){
			if(num /(int)pow(10, idx) % 1000 == 666){
				cnt++;
				break;
			}
		}
	}
}
