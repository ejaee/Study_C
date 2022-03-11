#include <stdio.h>
#include <math.h>
int	main(){
	int cnt, num;
	long long sum;
	scanf("%d", &cnt);
	while(cnt--){
		sum = 0;
		scanf("%d", &num);
		while(num){
			for(long long idx = 1; idx <= num/2; idx++){
				if(num % idx == 0){ 
					sum += idx;
				}
			}
				sum += num;
			num--;
		}
		printf("%lld\n", sum);	
	}
	return 0;
}
